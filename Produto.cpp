#include "Produto.h"

using namespace std;

double Produto::getCodigo() const {
	return codigo;
}

string Produto::getNome() const {
	return nome;
}

float Produto::getPreco() const {
	return preco;
}

bool Produto::getPassivelReceita() const{
	return passivelReceita;
}

void Produto::changePreco(float preco) {
	this->preco = preco;
}

string Produto::getDescricao() const {
	return descricao;
}

Produto::Produto(double cod, string nome, float preco, string descricao) {
	this->codigo = cod;
	this->nome = nome;
	this->preco = preco;
	this->descricao = descricao;
	this->taxaDesconto = 0;
	this->vendaSemReceita = false;
	passivelReceita = false;
}

Produto::Produto(double cod, std::string nome, float preco, std::string desc, bool passivelReceita = false, float desconto = 0, bool semRec = false){
	this->codigo = cod;
		this->nome = nome;
		this->preco = preco;
		this->descricao = desc;
		this->passivelReceita = passivelReceita;
		if (this->passivelReceita) {
			this->taxaDesconto = desconto;
			this->vendaSemReceita = semRec;
		}
		else {
			this->taxaDesconto = 0;
			this->vendaSemReceita = false;
		}
		
}

bool Produto::getVendaSemReceita() const {
	return vendaSemReceita;
}

void Produto::setVendaSemReceita(bool vendaSemReceita) {
	this->vendaSemReceita = vendaSemReceita;
}

float Produto::getTaxaDesconto() const {
	return taxaDesconto;
}

void Produto::setTaxaDesconto(float taxaDesconto) {
	this->taxaDesconto = taxaDesconto;
}

bool Produto::operator< (const Produto &p1) const{
	if (nome < p1.getNome())
		return true;
	return false;
}

bool Produto::operator== (const Produto &p1) const{
	if (nome != p1.getNome())
		return false;
	if (codigo != p1.getCodigo())
		return false;
	if (preco != p1.getPreco())
		return false;

	return true;
}

std::ostream& operator<<(std::ostream &output, const Produto &p){
	output << p.codigo << endl;
	output << p.nome << endl;
	output << p.preco << endl;
	output << p.descricao << endl;
	output << p.passivelReceita << endl;
	output << p.vendaSemReceita << endl;
	output << p.taxaDesconto << endl;
	return output;
}


