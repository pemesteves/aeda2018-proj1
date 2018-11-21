#include "Venda.h"
#include <iomanip>
#include <iostream>

using namespace std;

Venda::Venda(){
	Data d; data = d;
	Hora h; hora = h;
	totalVenda = 0;
	temReceita = false;
	receitaVenda = NULL;
	clienteVenda = NULL;
}

Venda::Venda(Receita* receitaVenda, Cliente* clienteVenda){
	Data d; data = d;
	Hora h; hora = h;
	totalVenda = 0;
	temReceita = true;
	this->receitaVenda = receitaVenda;
	this->clienteVenda = clienteVenda;
}

Venda::Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short minutos, unsigned short segundos){
	Data d(dia,mes,ano);
	data = d;
	Hora h(horas,minutos,segundos);
	hora=h;
	totalVenda = 0;
	temReceita = false;
	receitaVenda = NULL;
	clienteVenda = NULL;
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

Cliente* Venda::getCliente(){
	return clienteVenda;
}

Receita* Venda::getReceita(){
	return receitaVenda;
}

double Venda::getTotalVenda() const{
	return totalVenda;
}

std::map<Produto, std::vector<float>> Venda::getProdutosVendidos() const{
	return produtosVendidos;
}

unsigned int Venda::getNumProdutos() const{
	return produtosVendidos.size();
}

Data Venda::getData() const{
	return data;
}

Hora Venda::getHora() const{
	return hora;
}

float Venda::getPrecoProduto(string nomeProd) const{
	map<Produto, vector<float>>::const_iterator it = produtosVendidos.begin();
	for (; it != produtosVendidos.end(); it++){
		if ((*it).first.getNome() == nomeProd)
			return (*it).first.getPreco();
	}
	return -1; //Se não houver um produto com o nome = nomeProd, retorna -1
}

void Venda::addProduto(Produto* prod, float quant, float iva){

	double precoAdd = 0; //valor a adicionar ao valor total da venda
	float precoProd=0; //valor por unidade de produto
	float comparticipacao = 0; //valor da comparticipacao do produto

	map<Produto, vector<float>>::iterator it;
	if ((it = produtosVendidos.find(*prod)) != produtosVendidos.end()){
		(*it).second.at(QUANTIDADE) += quant;
		Produto p = (*it).first;
		vector<float> v = (*it).second;
		precoProd += precoProd*v.at(PRECO_PAGO);
		precoAdd = precoProd * quant;
		totalVenda += precoAdd;
	}
	else{
		vector<float> v = {quant, iva};
		if (temReceita){
			if (prod->getPassivelReceita()){
				if(receitaVenda->existeProdReceita(prod))
					comparticipacao = prod->getTaxaDesconto();
			}
		}
		v.push_back(comparticipacao);
		precoProd = precoProd + precoProd*iva - precoProd*v.at(COMPARTICIPACAO);
		v.push_back(precoProd);
		produtosVendidos[*prod]=v;
		precoAdd = precoProd * quant;
		totalVenda += precoAdd;
		comparticipacao = 0;
	}
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
	cout << "Nome Produto" << setw(20) << "Quantidade" << setw(5) << "Preço"<< endl;
	for(map<Produto, vector<float>>::const_iterator it = produtosVendidos.begin(); it != produtosVendidos.end(); it++){
		cout << it->first.getNome() << setw(20) << it->second[0] << setw(5) << it->second.at(PRECO_PAGO) << endl;
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

