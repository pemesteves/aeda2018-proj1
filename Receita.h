/**
 * Header File que contem a classe Receita
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>

class Pessoa;
class Cliente;

/**
 * Classe Receita
 */
class Receita {
private:
	unsigned long numero; //Numero da Receita
	std::string medico; //Nome do medico que prescreveu a Receita
	std::map<Produto, unsigned long>  produtos; //Map com os Produtos contidos na receita e respetiva quantidade
	Cliente* cliente; //Apontador para o Cliente ao qual a receita foi prescrita

public:
	/**
	 * Construtor da classe Receita
	 * @param numero Numero da Receita
	 * @param medico Nome do medico que receitou
	 * @param cliente Apontador para objeto da classe Cliente ao qual a Receita foi prescrita
	 */
	Receita(unsigned long numero, std::string medico, Cliente* cliente);
	/**
	 * Metodo para obter o numero da Receita
	 * @return Numero da Receita
	 */
	unsigned long getNumero() const;
	/*
	 * Metodo para alterar o numero da receita
	 * @param n Novo numero da receita
	 */
	void setNumero(unsigned long n);
	/**
	 * Metodo para obter o Cliente ao qual a Receita foi prescrita
	 * @return Apontador para objeto da classe Cliente
	 */
	Cliente* getCliente() const;
	/*
	 * Metodo para alterar o cliente da receita
	 * @param c Apontador para novo cliente da receita
	 */
	void setCliente(Cliente* c);
	/**
	 * Metodo para obter o nome do medico
	 * @return Nome do Medico
	 */
	std::string getMedico() const;
	/*
	 * Metodo para alterar o medico da receita
	 * @param m Nome do novo medico da receita
	 */
	void setMedico(std::string m);
	/**
	 * Metodo para obter os produtos da receita
	 * @return Vetor de objetos da classe Produto
	 */
	std::vector<Produto> getProdutos() const;
	/**
	 * Metodo para obter o preco maximo de um produto
	 * @param nomeProd Nome do produto a procurar
	 * @return Retorna o preco maximo do produto. Caso nao exista, lanca uma excecao do tipo ProdutoInexistente
	 */
	double getPrecoMax(std::string nomeProd) const;
	/**
	 * Metodo para adicionar um Produto ao map de Produtos
	 * @param produto Apontador para objeto da classe Produto
	 * @param quant Quantidade do Produto
	 */
	void addProduto(Produto* produto, unsigned long quant);
	/**
	 * Metodo para remover um produto do map
	 * @param nome Nome do produto a remover
	 * @return Retorna o Produto removido. Caso nao exista, lanca uma excecao do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nome);
	/**
	 * Metodo que permite saber se um produto existe na receita
	 * @param prod Apontador para o produto que se pretende saber se existe
	 * @return True se produto existir, caso contrario retorna false
	 */
	bool existeProdReceita(std::string nome) const;
	/*
	 * Metodo que imprime receita no ecra
	 */
	void imprimeReceita() const;
	/**
	 * Overload do operador para exportar a receita
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param Receita que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Receita &r);
};

#endif
