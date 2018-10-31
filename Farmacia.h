#ifndef FARMACIA_H
#define FARMACIA_H

#include "Produto.h"
#include "Venda.h"
#include "Data.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Farmacia {
private:
	std::string nome;
	std::string morada;
	Funcionario* gerente;
	std::map<Produto*, int> produtosVender;
	std::vector<Venda*> vendas;
	//std::vector<Carrinha*> carrinhas;
	//bool entregaDomicilios;
public:
	Farmacia(std::string nome, std::string morada);
	std::string getNome() const;
	std::string getMorada() const;
	Funcionario* getGerente() const;
	std::vector<Venda*> getVendas() const;
	std::map<Produto*, int> getProdutosVender() const;
	unsigned int getNumProdutos() const;
	unsigned int getNumVendas() const;
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	std::vector<Venda*> getVendasTempo(Data d1, Data d2) const;
	unsigned int getNumVendasDia(Data d) const;
	std::vector<Venda*> getVendasDia(Data d) const;
	float getPrecoProduto(std::string nomeProd) const;
	void setGerente(Funcionario* gerente);	
	void addProdutosVender(std::vector<Produto*> produtosVender_new);
	bool addProdutoVender(Produto* produtoVender);
	void addVenda(Venda* venda);
	bool existeProduto(std::string nomeProduto) const;
	bool setQuantidade(std::string nomeProd, int quant);
	//bool getDomicilios();
	//bool carrinhasDisponiveis();
	//Carrinha* getCarrinha(bool disponibilidade);
	//unsigned int numCarrinhas();
	//void addCarrinha(Carrinha* carrinha);
	//Farmacia(std::string nome, std::string morada, bool entregaDomicilios);

};

class FarmaciaInexistente{
	std::string nome;
public:
	FarmaciaInexistente(std::string nomeF){nome = nomeF;}
	std::string getNome() const{return nome;}
};

#endif 
