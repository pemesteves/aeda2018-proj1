
#include "Venda.h"
#include "Data.h"
#include <iomanip>
#include <iostream>

using namespace std;

unsigned long Venda::codigo_sequencial = 0;

Venda::Venda(){
	Data d; data = d;
	Hora h; hora = h;
	totalVenda = 0;
	temReceita = false;
	receitaVenda = NULL;
	clienteVenda = NULL;
	codigo = codigo_sequencial;
	codigo_sequencial++;
}

Venda::Venda(Receita* receitaVenda, Cliente* clienteVenda){
	Data d; data = d;
	Hora h; hora = h;
	totalVenda = 0;
	temReceita = true;
	this->receitaVenda = receitaVenda;
	this->clienteVenda = clienteVenda;
	codigo = codigo_sequencial;
	codigo_sequencial++;
}

Venda::Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short minutos, unsigned short segundos, unsigned long codigo){
	Data d(dia,mes,ano);
	data = d;
	Hora h(horas,minutos,segundos);
	hora=h;
	totalVenda = 0;
	temReceita = false;
	receitaVenda = NULL;
	clienteVenda = NULL;
	this->codigo = codigo;
	codigo_sequencial = codigo;

}

bool Venda::setReceita(Receita* receitaVenda){
	if (temReceita)
		return false;
	temReceita = true;
	this->receitaVenda = receitaVenda;
	return true;
}

void Venda::setCliente(Cliente* clienteVenda){
	this->clienteVenda = clienteVenda;
}

double Venda::getTotalVenda() const{
	return totalVenda;
}

unsigned int Venda::getNumProdutos() const{
	return produtosVendidos.size();
}

Cliente* Venda::getCliente() {
	return clienteVenda;
}

Receita* Venda::getReceita() {
	return receitaVenda;
}

Data Venda::getData() const{
	return data;
}

Hora Venda::getHora() const{
	return hora;
}

unsigned long Venda::getCodigo() const{
	return codigo;
}

float Venda::getPrecoProduto(string nomeProd) const{
	map<Produto, vector<float>>::const_iterator it = produtosVendidos.begin();
	for (; it != produtosVendidos.end(); it++){
		if ((*it).first.getNome() == nomeProd)
			return (*it).first.getPreco();
	}
	return -1; //Se nao houver um produto com o nome = nomeProd, retorna -1
}

bool Venda::addProduto(Produto* prod, float quant, float iva){
	double precoAdd = 0; //valor a adicionar ao valor total da venda
	float precoProd=0; //valor por unidade de produto
	float comparticipacao = 0; //valor da comparticipacao do produto

	map<Produto, vector<float>>::iterator it;
	if ((it = produtosVendidos.find(*prod)) != produtosVendidos.end()){
		(*it).second.at(QUANTIDADE) += quant;
		Produto p = (*it).first;
		vector<float> v = (*it).second;
		precoAdd = precoProd * quant;
		totalVenda += precoAdd;
	}
	else{
		vector<float> v = { quant, iva };
		if (temReceita) {
			if (prod->getPassivelReceita()) {
				if (receitaVenda->existeProdReceita(prod->getNome()))
					comparticipacao = prod->getTaxaDesconto();
				else if (!prod->getVendaSemReceita())
					return false;
			}
		}
		v.push_back(comparticipacao);
		precoProd = prod->getPreco();
		precoProd += precoProd * iva - precoProd * v.at(COMPARTICIPACAO);
		v.push_back(precoProd);
		produtosVendidos[*prod] = v;
		precoAdd = precoProd * quant;
		totalVenda += precoAdd;
	}
	return true;
}

bool Venda::operator< (const Venda &v1) const{
	if (data < v1.getData())
		return true;
	if (data== v1.getData() && hora < v1.getHora())
		return true;
	return false;
}

void Venda::imprimeFatura() const{
	cout << data.getDia() << "-" << data.getMes() << "-" << data.getAno();
	cout << setw(15) << hora.getHora() << ":" << hora.getMinutos() << ":" << hora.getSegundos();
	cout << endl << endl << endl;
	cout << "Nome Produto" << setw(20) << "Quantidade" << setw(5) << "Preco"<< endl;
	for(map<Produto, vector<float>>::const_iterator it = produtosVendidos.begin(); it != produtosVendidos.end(); it++){
		cout << it->first.getNome() << setw(20) << it->second.at(QUANTIDADE) << setw(5) << it->second.at(PRECO_PAGO) << endl;
	}
	cout << setw(25) << totalVenda;
}

bool Venda::menorQue(const Venda &v1, enum tipoSort tipo, bool crescente) const{
	switch(tipo){
	case NUM_PROD:
		if (crescente)
			return getNumProdutos() < v1.getNumProdutos();
		else
			return getNumProdutos() > v1.getNumProdutos();
		break;
	case DATA:
		if (crescente)
			return data < v1.getData();
		else
			return !(data < v1.getData());
		break;
	case HORA:
		if (crescente)
			return hora < v1.getHora();
		else
			return !(hora < v1.getHora());
		break;
	case NUM_VENDA:
		if (crescente)
			return totalVenda < v1.getTotalVenda();
		else
			return totalVenda > v1.getTotalVenda();
		break;
	default:
		return (*this) < v1;
		break;
	}
}

map<Produto, vector<float>> Venda::getProdutosVendidos() const{
	return produtosVendidos;
}

std::ostream& operator<<(std::ostream &output, const Venda &v1){
	output << v1.codigo << " " << v1.data << " " << v1.hora << endl;
	output << v1.clienteVenda->getNoContribuinte() << endl;
	if (!v1.temReceita){
		output << "NULL" << endl;
	}
	else{
		output << &v1.receitaVenda << endl;
	}
	output << v1.totalVenda << endl;
	output << v1.produtosVendidos.size() << endl;
	map<Produto, std::vector<float>>::const_iterator it = v1.produtosVendidos.begin();
	for (; it != v1.produtosVendidos.end(); it++){
		output << it->first.getCodigo() << " " ;
		output << it->second.at(QUANTIDADE) << " " << it->second.at(IVA) << " " << it->second.at(COMPARTICIPACAO) << " " << it->second.at(PRECO_PAGO) << endl;
	}

	return output;
}


