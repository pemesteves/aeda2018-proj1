#include "Farmacia.h"

Farmacia::Farmacia(std::string nome, std::string morada) {
	this->nome = nome;
	this->morada = morada;
}

std::string Farmacia::getNome() const {
	return nome;
}

std::string Farmacia::getMorada() const {
	return morada;
}

Funcionario* Farmacia::getGerente() const {
	return gerente;
}

std::vector<Venda*> Farmacia::getVendas() const {
	return vendas;
}

std::vector<Produto*> Farmacia::getProdutosVender() const {
	return produtosVender;
}

unsigned int Farmacia::getNumProdutos() const {
	return produtosVender.size();
}

unsigned int Farmacia::getNumVendas() const {
	return vendas.size();
}

unsigned int Farmacia::getNumVendasTempo(Data d1, Data d2) const {
	for (size_t i = 0; i < vendas.size(); i++) {

	}
}

unsigned int Farmacia::getNumVendasDia(Data d) const {
}


int Farmacia::getPrecoProduto(std::string nomeProd) const {
}

void Farmacia::setGerente(Funcionario* gerente) {
}

void Farmacia::addProdutosVender(std::vector<Produto*> produtosVender) {
}

void Farmacia::addVenda(Venda* venda) {
}

bool Farmacia::existeProduto(std::string nomeProduto) const {
}
