#include "Receita.h"
using namespace std;

double Receita::getNumero() const{
	return numero;
}

Cliente* Receita::getCliente() const{
	return cliente;
}

string Receita::getMedico() const{
	return medico;
}

vector<Produto*> Receita::getProdutos() const{
	vector<Produto*> p;
	map<Produto*, double>::iterator it;
	for(it = produtos.begin(); it != produtos.end(); it++){
		p.push_back(it->first);
	}
	return p;
}

double Receita::getPrecoMax(string nomeProd) const{
	map<Produto*, double>::iterator it;
	for(it = produtos.begin(); it != produtos.end(); it++){
		if (it->first->getNome() == nomeProd) //Compara o nome de cada produto com o nome recebido como argumento
			return it->second;
	}
	throw ProdutoInexistente(nomeProd);
}

Receita::Receita(double numero, string medico, Cliente* cliente) {
	this->numero = numero;
	this->medico = medico;
	this->cliente = cliente;
}

void Receita::addProduto(Produto* produto, double quant){
	map<Produto*, double>::iterator it;
	if ((it = produtos.find(produto)) != produtos.end())
		it->second += quant;
	else{
		pair<Produto*, double> p = make_pair(produto, quant);
		produtos.insert(p);
	}
}


