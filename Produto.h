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
protected:
	double codigo; //Código do Produto
	std::string nome; //Nome do Produto
	float preco; //Preço do Produto
	std::string descricao; //Descrição do Produto
	bool passivelReceita; //true se produto for do tipo PassivelReceita
	float taxaDesconto; //Taxa de Desconto de um Medicamento passível de receita
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
	 * Método para saber se o produto é do tipo PassivelReceita
	 * @return true se for PassivelReceita, se não retorna false
	 */
	bool getPassivelReceita() const;
	/**
	 * Operador de igualdade: Compara dois produtos com regras pré-definidas
	 * @param p1 Produto que irá ser comparado
	 * @return Retorna true se o produto for igual a p1. Caso contrário, retorna false
	 */
	bool operator== (const Produto &p1) const;
	/**
	 * Método para obter a taxa de desconto com receita
	 * @return Taxa de Desconto
	 */
	virtual float getTaxaDesconto() const {return 0;};
};

/**
 * Class Medicamento, derivada publicamente de Produto
 */
class Medicamento : public Produto {
public:
	/**
	 * Construtor da classe Medicamento
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 */
	Medicamento(double cod, std::string nome, float preco, std::string desc);
};

class PassivelReceita : public Medicamento {
private:
	bool vendaSemReceita; //Booleano que indica se o medicamento pode ser vendido sem receita
public:
	/**
	 * Construtor da classe PassivelReceita
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 * @param desconto Taxa de Desconto
	 * @param semRec Booleano que indica se o produto pode ser vendido sem receita
	 */
	PassivelReceita(double cod, std::string nome, float preco, std::string desc, float desconto, bool semRec);
	/**
	 * Método para obter a taxa de desconto com receita
	 * @return Taxa de Desconto
	 */
	float getTaxaDesconto() const;
	/**
	 * Método para alterar a taxa de desconto de um produto com receita
	 * @param taxaDesconto Taxa de desconto a alterar
	 */
	void setTaxaDesconto(float taxaDesconto);
	/**
	 * Método utilizado para saber se o medicamento pode ser vendido sem receita
	 * @return True se puder ser vendido sem receita. Caso contrário, retorna false
	 */
	bool getVendaSemReceita() const;
	/**
	 * Método para alterar a venda sem receita
	 * @param vendaSemReceita Deve ser true se o medicamento passar a poder ser vendido sem receita
	 */
	void setVendaSemReceita(bool vendaSemReceita);
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
	 * Método para obter o nome do produto inexistente
	 * @return Nome do Produto
	 */
	std::string getNome() const { return nome; }
};


#endif
