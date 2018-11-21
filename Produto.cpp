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
	taxaDesconto = 0;
	passivelReceita = false;
}

Medicamento::Medicamento(double cod, string nome, float preco, string desc) : Produto(cod, nome, preco, desc) {
}

PassivelReceita::PassivelReceita(double cod, string nome, float preco, string desc, float desconto = 0, bool semRec = false) : Medicamento(cod, nome, preco, desc) {
	this->taxaDesconto = desconto;
	this->vendaSemReceita = semRec;
	passivelReceita = true;
}

bool PassivelReceita::getVendaSemReceita() const {
	return vendaSemReceita;
}

void PassivelReceita::setVendaSemReceita(bool vendaSemReceita) {
	this->vendaSemReceita = vendaSemReceita;
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

bool Produto::operator== (const Produto &p1) const{
	if (nome != p1.getNome())
		return false;
	if (codigo != p1.getCodigo())
		return false;
	if (preco != p1.getPreco())
		return false;

	return true;
}


