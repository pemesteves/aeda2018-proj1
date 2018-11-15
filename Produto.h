/**
 * Header File que contém as classes Produto, Medicamento, PassivelReceita e ProdutoInexistente
 *
 * @author Márcia, Pedro e Rita
 * @date Novembro, 2018
 */
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/**
 * Classe Produto
 */
class Produto {
private:
	double codigo; //Código do Produto
	std::string nome; //Nome do Produto
	float preco; //Preço do Produto
	std::string descricao; //Descrição do Produto
public:
	/**
	 * Construtor da classe Produto
	 * @param cod Código do Produto
	 * @param nome Nome do Produto
	 * @param preco Preço do Produto
	 * @param descricao Descrição do produto
	 */
	Produto(double cod, std::string nome, float preco, std::string descricao);
	/**
	 * Método para obter o código do Produto
	 * @return Código do Produto
	 */
	double getCodigo() const;
	/**
	 * Método para obter o nome do Produto
	 * @return Nome do Produto
	 */
	std::string getNome() const;
	/**
	 * Método para obter o preço do Produto
	 * @return Preço do Produto
	 */
	float getPreco() const;
	/**
	 * Método para obter a descrição do Produto
	 * @return Descrição do Produto
	 */
	std::string getDescricao() const;
	/**
	 * Método que permite alterar o preço de um Produto
	 * @param preco Preço a alterar
	 */
	void changePreco(float preco);
	/**
	 * Operador menor: Compara dois produtos com regras pré-definidas
	 * @param p1 Produto que irá ser comparado
	 * @return Retorna true se o produto for menor que p1. Caso contrário, retorna false
	 */
	bool operator< (const Produto &p1) const;
	/**
	 * Operador de igualdade: Compara dois produtos com regras pré-definidas
	 * @param p1 Produto que irá ser comparado
	 * @return Retorna true se o produto for igual a p1. Caso contrário, retorna false
	 */
	bool operator== (const Produto &p1) const;
};

/**
 * Class Medicamento, derivada publicamente de Produto
 */
class Medicamento : public Produto {
private:
	bool vendaSemReceita; //Booleano que indica se o medicamento pode ser vendido sem receita
public:
	Medicamento(bool receita, double cod, std::string nome, int preco, std::string desc);
	bool getVendaSemReceita() const;
	void setVendaSemReceita(bool vendaSemReceita);

};

class PassivelReceita : public Medicamento {
private:
	float taxaDesconto;
public:
	PassivelReceita(double cod, std::string nome, int preco, std::string desc, int desconto, bool semRec);
	float getTaxaDesconto() const;
	void setTaxaDesconto(float taxaDesconto);
};

class ProdutoInexistente {
	std::string nome;
public:
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	std::string getNome() const { return nome; }
};


#endif
