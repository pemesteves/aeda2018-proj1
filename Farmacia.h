#ifndef FARMACIA_H
#define FARMACIA_H

#include "Produto.h"
#include "Venda.h"
#include "Pessoa.h"
#include "Data.h"

#include <vector>
#include <string>
#include <algorithm>

class Farmacia {
private:
	std::string nome;
	std::string morada;
	Funcionario* gerente;
	std::vector<Produto*> produtosVender;
	std::vector<Venda*> vendas;
	//std::vector<Carrinha*> carrinhas;
	//bool entregaDomicilios;
public:
	Farmacia(std::string nome, std::string morada);
	std::string getNome() const;
	std::string getMorada() const;
	Funcionario* getGerente() const;
	std::vector<Venda*> getVendas() const;
	std::vector<Produto*> getProdutosVender() const;
	unsigned int getNumProdutos() const;
	unsigned int getNumVendas() const;
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	unsigned int getNumVendasDia(Data d) const;
	int getPrecoProduto(std::string nomeProd) const;
	void setGerente(Funcionario* gerente);	
	void addProdutosVender(std::vector<Produto*> produtosVender);
	void addVenda(Venda* venda);
	bool existeProduto(std::string nomeProduto) const;
	//bool getDomicilios();
	//bool carrinhasDisponiveis();
	//Carrinha* getCarrinha(bool disponibilidade);
	//unsigned int numCarrinhas();
	//void addCarrinha(Carrinha* carrinha);
	//Farmacia(std::string nome, std::string morada, bool entregaDomicilios);

};

#endif 
