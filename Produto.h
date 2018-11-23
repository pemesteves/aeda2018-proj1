/**
 * Header File que contem as classes Produto e ProdutoInexistente
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

/**
 * Classe Produto
 */
class Produto {
protected:
	double codigo; //Codigo do Produto
	std::string nome; //Nome do Produto
	float preco; //Preco do Produto
	std::string descricao; //Descricao do Produto
	bool passivelReceita; //Booleano que indica se o medicamento e passivel de receita
	bool vendaSemReceita; //Booleano que indica se o medicamento passivel de receita pode ser vendido sem receita
	float taxaDesconto; //Taxa de Desconto de um medicamento passivel de receita

public:
	/**
	 * Construtor da classe Produto
	 * @param cod Codigo do Produto
	 * @param nome Nome do Produto
	 * @param preco Preco do Produto
	 * @param descricao Descricao do Produto
	 */
	Produto(double cod, std::string nome, float preco, std::string descricao);
	/**
	 * Construtor da classe Produto
	 * @param cod Codigo do Produto
	 * @param nome Nome do Produto
	 * @param preco Preco do Produto
	 * @param desc Descricao do Produto
	 * @param passivelReceita Booleano que indica se o produto e passivel de receita
	 * @param desconto Taxa de Desconto
	 * @param semRec Booleano que indica se o produto pode ser vendido sem receita
	 */
	Produto(double cod, std::string nome, float preco, std::string desc, bool passivelReceita, float desconto, bool semRec);
	/**
	 * Metodo para alterar a taxa de desconto de um produto com receita
	 * @param taxaDesconto Taxa de desconto a alterar
	 */
	void setTaxaDesconto(float taxaDesconto);
	/**
	 * Metodo utilizado para saber se o medicamento pode ser vendido sem receita
	 * @return True se puder ser vendido sem receita. Caso contrario, retorna false
	 */
	bool getVendaSemReceita() const;
	/**
	 * Metodo para alterar a venda sem receita
	 * @param vendaSemReceita Deve ser true se o medicamento passar a poder ser vendido sem receita
	 */
	void setVendaSemReceita(bool vendaSemReceita);
	/**
	 * Metodo para obter o codigo do Produto
	 * @return Codigo do Produto
	 */
	double getCodigo() const;
	/**
	 * Metodo para obter o nome do Produto
	 * @return Nome do Produto
	 */
	std::string getNome() const;
	/**
	 * Metodo para obter o preco do Produto
	 * @return Preco do Produto
	 */
	float getPreco() const;
	/**
	 * Metodo para obter a descricao do Produto
	 * @return Descricao do Produto
	 */
	std::string getDescricao() const;
	/**
	 * Metodo que permite alterar o preco de um Produto
	 * @param preco Preco a alterar
	 */
	void changePreco(float preco);
	/**
	 * Operador menor: Compara dois produtos com regras pre-definidas
	 * @param p1 Produto que ira ser comparado
	 * @return Retorna true se o produto for menor que p1. Caso contrario, retorna false
	 */
	bool operator< (const Produto &p1) const;
	/**
	 * Metodo para saber se o produto e do tipo PassivelReceita
	 * @return true se for PassivelReceita, se nao retorna false
	 */
	bool getPassivelReceita() const;
	/**
	 * Operador de igualdade: Compara dois produtos com regras pre-definidas
	 * @param p1 Produto que ira ser comparado
	 * @return Retorna true se o produto for igual a p1. Caso contrario, retorna false
	 */
	bool operator== (const Produto &p1) const;
	/**
	 * Metodo para obter a taxa de desconto com receita
	 * @return Taxa de Desconto
	 */
	float getTaxaDesconto() const;
	/*
	 * Metodo que imprime no ecra os dados do produto
	 */
	void showInfo() const;
	/**
	 * Overload do operador para exportar o Produto
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param p Produto que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Produto &p);
};

/**
 * Classe ProdutoInexistente
 */
class ProdutoInexistente {
	std::string nome; //Nome do produto inexistente
public:
	/**
	 * Construtor da classe ProdutoInexistente
	 * @param nomeProd Nome do Produto
	 */
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	/**
	 * Metodo para obter o nome do produto inexistente
	 * @return Nome do Produto
	 */
	std::string getNome() const { return nome; }
};


#endif
