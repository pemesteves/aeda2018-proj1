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
}

bool Medicamento::getVendaSemReceita() const {
	return vendaSemReceita;
}

void Medicamento::setVendaSemReceita(bool vendaSemReceita) {
	this->vendaSemReceita = vendaSemReceita;
}

Medicamento::Medicamento(bool receita, double cod, string nome, int preco, string desc) : Produto(cod, nome, preco, desc) {
	this->vendaSemReceita = receita;
}

PassivelReceita::PassivelReceita(int desconto = 0, double cod, string nome, int preco, string desc, bool semRec = false) : Medicamento(semRec, cod, nome, preco, desc) {
	this->taxaDesconto = desconto;
}

float PassivelReceita::getTaxaDesconto() const {
	return taxaDesconto;
}

void PassivelReceita::setTaxaDesconto(float taxaDesconto) {
	this->taxaDesconto = taxaDesconto;
}

bool Produto::operator< (const Produto &p1) const{
	if (nome < p1.getNome())
		return true;
	return false;
}



