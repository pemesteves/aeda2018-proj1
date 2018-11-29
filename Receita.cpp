#include "Receita.h"
using namespace std;

unsigned long Receita::getNumero() const {
	return numero;
}

void Receita::setNumero(unsigned long n) {
	this->numero = n;
}

Cliente* Receita::getCliente() const {
	return cliente;
}

void Receita::setCliente(Cliente* c) {
	this->cliente=c;
}

string Receita::getMedico() const {
	return medico;
}

void Receita::setMedico(string m){
	this->medico = m;
}

vector<Produto> Receita::getProdutos() const {
	vector<Produto> p;
	map<Produto, unsigned long>::const_iterator it;
	for (it = produtos.begin(); it != produtos.end(); it++) {
		p.push_back(it->first);
	}
	return p;
}

double Receita::getPrecoMax(string nomeProd) const {
	map<Produto, unsigned long>::const_iterator it;
	for (it = produtos.begin(); it != produtos.end(); it++) {
		if (it->first.getNome() == nomeProd) //Compara o nome de cada produto com o nome recebido como argumento
			return it->second;
	}
	throw ProdutoInexistente(nomeProd);
}

Receita::Receita(unsigned long numero, string medico, Cliente* cliente) {
	this->numero = numero;
	this->medico = medico;
	this->cliente = cliente;
}

void Receita::addProduto(Produto* produto, unsigned long quant) {
	map<Produto, unsigned long>::iterator it;
	if ((it = produtos.find(*produto)) != produtos.end())
		(*it).second += quant;
	else {
		if (produto->getPassivelReceita())
			produtos[*produto]=quant;
	}
}

bool Receita::existeProdReceita(string nome) const{
	map<Produto, unsigned long>::const_iterator it = produtos.begin();
	for(; it != produtos.end(); it++){
		if ((*it).first.getNome() == nome){
			return true;
		}
	}
	return false;
}

Produto Receita::removeProduto(string nome){
	map<Produto, unsigned long>::iterator it = produtos.begin();
	for(; it != produtos.end(); it++){
		if ((*it).first.getNome() == nome){
			produtos.erase(it);
			return (*it).first;
		}
	}
	throw ProdutoInexistente(nome);
}

void Receita::imprimeReceita() const{
	cout << "Receita" << endl << endl;
	cout << "Numero da receita: " << numero << endl;
	cout << "Utente: ";
	cout << cliente->getNome() << "  " << cliente->getNoContribuinte() << endl;
	cout << "Prescrita por Dr./Dra. " << medico << endl;
	cout << "Produtos:" << endl;
	map<Produto, unsigned long>::const_iterator it = produtos.begin();
	for(; it != produtos.end(); it++){
		cout << it->first.getCodigo();
		cout << "  ";
		cout << it->first.getNome();
		cout << "    ";
		cout << it->second << " unidades";
		cout <<endl;
	}


}

ostream& operator<<(ostream &output, const Receita &r){
	output << r.numero << endl;
	output << r.medico << endl;
	map<Produto, unsigned long>::const_iterator it;
	output << r.cliente->getNoContribuinte() << endl;
	output << r.produtos.size() << endl;
	for(it = r.produtos.begin(); it != r.produtos.end(); it++){
		output << it->first.getCodigo();
		output << " ";
		output << it->second;
		output << endl;
	}
	return output;
}

