#include "Farmacia.h"
#include <iostream>

using namespace std;

Farmacia::Farmacia(string nome, string morada) {
	this->nome = nome;
	this->morada = morada;
	this->gerente = NULL;
	this->diretorTecnico = NULL;
	this->produtosVender.clear();
}

string Farmacia::getNome() const {
	return nome;
}

string Farmacia::getMorada() const {
	return morada;
}

Funcionario* Farmacia::getGerente() const {
	return gerente;
}

Funcionario* Farmacia::getDiretorTecnico() const{
	return diretorTecnico;
}

vector<Venda*> Farmacia::getVendas() const {
	return vendas;
}

map<Produto, int> Farmacia::getProdutosVender() const {
	return produtosVender;
}

unsigned int Farmacia::getNumProdutos() const {
	return produtosVender.size();
}

unsigned int Farmacia::getNumVendas() const {
	return vendas.size();
}

unsigned int Farmacia::getNumVendasTempo(Data d1, Data d2) const {
	unsigned int vendas_count = 0;
	for (size_t i = 0; i < vendas.size(); i++) {
		Data d = vendas.at(i)->getData();
		if ((d<d2 && d1<d) || d1 == d || d2 == d) {
			vendas_count++;
		}
	}

	return vendas_count;
}

vector<Venda*> Farmacia::getVendasTempo(Data d1, Data d2) const {
	vector<Venda*> vendas_tempo;
	for (size_t i = 0; i < vendas.size(); i++) {
		Data d = vendas.at(i)->getData();
		if ((d<d2 && d1<d) || d1 == d || d2 == d) {
			vendas_tempo.push_back(vendas.at(i));
		}
	}
	return vendas_tempo;
}

unsigned int Farmacia::getNumVendasDia(Data d) const {
	unsigned int vendas_count = 0;
	for (size_t i = 0; i < vendas.size(); i++) {
		Data d1 = vendas.at(i)->getData();
		if (d == d1)
			vendas_count++;
	}
	return vendas_count;
}

vector <Venda*> Farmacia::getVendasDia(Data d) const {
	vector<Venda*> vendas_dia;
	for (size_t i = 0; i < vendas.size(); i++) {
		Data d1 = vendas.at(i)->getData();
		if (d1 == d) {
			vendas_dia.push_back(vendas.at(i));
		}
	}
	return vendas_dia;
}


float Farmacia::getPrecoProduto(string nomeProd) const {
	map<Produto, int>::const_iterator it;
	for (it = produtosVender.begin(); it != produtosVender.end(); it++) {
		if (it->first.getNome() == nomeProd)
			return it->first.getPreco();
	}
	return -1;
}

void Farmacia::setGerente(Funcionario* gerente) {
	this->gerente = gerente;
}

void Farmacia::addProdutosVender(vector<Produto*> produtosVender_new) {
	Produto* p = NULL;
	for (size_t i = 0; i < produtosVender_new.size(); i++) {
		p = produtosVender_new.at(i);
		if (!existeProduto(p->getNome())) 
			produtosVender.insert(pair<Produto, int>(*p, 0));
		//adicionar exceçao ???
	}
}

Produto Farmacia::removeProduto(std::string nomeP){
	map<Produto, int>::iterator it =  produtosVender.begin();
	for(; it != produtosVender.end(); it++){
		if((*it).first.getNome() == nomeP){
			produtosVender.erase(it);
			return (*it).first;
		}
	}

	throw ProdutoInexistente(nomeP);
}

void Farmacia::addVenda(Venda* venda) {
	vendas.push_back(venda);
}

bool Farmacia::existeProduto(string nomeProduto) const {
	map<Produto, int>::const_iterator it = produtosVender.begin();
	for (; it != produtosVender.end(); it++) {
		if (it->first.getNome() == nomeProduto)
			return true;
	}
	return false;
}

bool Farmacia::addProdutoVender(Produto* produtoVender) {
	if (!existeProduto(produtoVender->getNome())) {
		produtosVender.insert(pair<Produto, int>(*produtoVender, 0));
		return true;
	}
	return false;
}

void Farmacia::sortVendas(enum tipoSort tipo, bool crescente){
	//sort(vendas.begin(), vendas.end(), funcSort<Venda>);
	quickSort(vendas, 0, vendas.size()-1, tipo, crescente);
}

bool Farmacia::setQuantidade(std::string nomeProd, int quant) {
	map<Produto, int>::iterator it;
	for (it = produtosVender.begin(); it != produtosVender.end(); it++) {
		if (nomeProd == it->first.getNome()) {
			it->second = quant;
			return true;
		}
	}
	return false;
}

bool Farmacia::operator< (const Farmacia &f1) const{
	if (nome < f1.getNome())
		return true;
	if (nome == f1.getNome() && produtosVender.size() > f1.getNumProdutos())
		return true;
	if (nome == f1.getNome() && produtosVender.size() == f1.getNumProdutos() && vendas.size() < f1.getNumVendas())
		return true;
	return false;
}

void Farmacia::imprimeFatura(Venda* v) const{
	cout << "Farmacia " << nome << endl;
	cout << morada << endl;
	cout << endl << "Gerente: " << gerente->getNome() << endl;
	cout << "Diretor Tecnico: " << diretorTecnico->getNome() << endl;
	v->imprimeFatura();

	cout << "Obrigado pela sua visita! Volte sempre." << endl << endl;
}

bool Farmacia::menorQue(const Farmacia &f1, enum tipoSort tipo, bool crescente) const{
	switch(tipo){
	case NOME:
		if (crescente)
			return nome < f1.getNome();
		else
			return nome > f1.getNome();
		break;
	case NUM_PROD:
		if (crescente)
			return produtosVender.size() < f1.getNumProdutos();
		else
			return produtosVender.size() > f1.getNumProdutos();
		break;
	case NUM_VENDA:
		if (crescente)
			return vendas.size() < f1.getNumVendas();
		else
			return vendas.size() > f1.getNumVendas();
		break;
	default:
		return (*this)<f1;
		break;
	}
}

