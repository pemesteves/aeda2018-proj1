#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>

class Pessoa;
class Cliente;

/**
 * Classe Receita
 */
class Receita {
private:
	double numero; //Número da Receita
	 //TODO criar classe medico para a receita
	std::string medico; //Nome do médico que prescreveu a Receita
	std::map<Produto, double>  produtos; //Map com os Produtos contidos na receita e respetiva quantidade
	Cliente* cliente; //Apontador para o Cliente ao qual a receita foi prescrita

public:
	/**
	 * Construtor da classe Receita
	 * @param numero Número da Receita
	 * @param medico Nome do médico que receitou
	 * @param cliente Apontador para objeto da classe Cliente ao qual a Receita foi prescrita
	 */
	Receita(double numero, std::string medico, Cliente* cliente);
	/**
	 * Método para obter o número da Receita
	 * @return Número da Receita
	 */
	double getNumero() const;
	/**
	 * Método para obter o Cliente ao qual a Receita foi prescrita
	 * @return Apontador para objeto da classe Cliente
	 */
	Cliente* getCliente() const;
	/**
	 * Método para obter o nome do médico
	 * @return Nome do Médico
	 */
	std::string getMedico() const;
	/**
	 * Método para obter os produtos da receita
	 * @return Vetor de objetos da classe Produto
	 */
	std::vector<Produto> getProdutos() const;
	/**
	 * Método para obter o preço máximo de um produto
	 * @param nomeProd Nome do produto a procurar
	 * @return Retorna o preço máximo do produto. Caso não exista, lança uma exceção do tipo ProdutoInexistente
	 */
	float getPrecoMax(std::string nomeProd) const;
	/**
	 * Método para adicionar um Produto ao map de Produtos
	 * @param produto Apontador para objeto da classe Produto
	 * @param quant Quantidade do Produto
	 */
	void addProduto(Produto* produto, double quant);
	/**
	 * Método para remover um produto do map
	 * @param nome Nome do produto a remover
	 * @return Retorna o Produto removido. Caso não exista, lança uma exceção do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nome);

	/**
	 * Método que permite saber se um produto existe na receita
	 * @param prod Apontador para o produto que se pretende saber se existe
	 * @return True se produto existir, caso contrário retorna false
	 */
	bool existeProdReceita(Produto* prod) const;
};

#endif
