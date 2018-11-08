/**
 * Header File que contém a classe Venda
 *
 * @author Márcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef VENDA_H
#define VENDA_H

#include "Data.h"
#include "Produto.h"

#include <vector>
#include <string>
#include <map>

/**
 * Declaração de uma enumeração: tipoSort
 * É utilizada para todas as operações de sort
 * Valores: NOME = ordenação por nome; CONTIBUINTE = ordenação por contribuinte; NUM_PROD = ordenação por número de produtos;
 * 			NUM_VENDA = ordenação por número de vendas/compras; SALARIO = ordenação por salário; DATA = ordenação por data;
 * 			HORA = ordenação por hora; DEFAULT = ordenação por um critério pré-definido
 */
enum tipoSort {NOME, CONTRIBUINTE, NUM_PROD, NUM_VENDA, SALARIO, DATA, HORA, DEFAULT};

/**
 * Classe Venda
 */
class Venda {
private:
	std::map<Produto, std::vector<float>> produtosVendidos; //Map cujas keys são objetos do tipo Produto e o valor é um vetor com quantidade, iva e comparticipação
	Data data; //Data na qual foi realizada a venda
	Hora hora; //Hora à qual foi realizada a venda
	double totalVenda; //Valor total da venda
public:
	/**
	 * Construtor da classe Venda
	 */
	Venda();
	/**
	 * Método que permite obter o total da venda
	 * @return totalVenda (atributo da classe)
	 */
	double getTotalVenda() const;
	/**
	 * Método que permite obter o número de produtos vendidos
	 * @return Tamanho de porudtosVenidos (atributo da classe)
	 */
	unsigned int getNumProdutos() const;
	/**
	 * Método que permite obter a data da venda
	 * @return Objeto do tipo Data
	 */
	Data getData() const;
	/**
	 * Método que permite obter a hora da venda
	 * @return Objeto do tipo Hora
	 */
	Hora getHora() const;
	/**
	 * Método que permite obter o preço de um produto
	 * @param nomeProd Nome do produto que irá ser procurado
	 * @return Preço do produto especificado como argumento. Retorna -1 se não existir
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * Método que permite adicionar um produto à venda
	 * @param prod Apontador para objeto da classe Produto
	 * @param quant, iva, comparticipacao Valores do tipo float que serão colocados do vetor do map produtosVendidos
	 */
	void addProduto(Produto* prod, float quant, float iva, float comparticipacao);
	/**
	 * Operador menor: compara dois objetos do tipo Venda com regras pré-definidas
	 * @param v1 Objeto do tipo Venda
	 * @return Retorna true se a venda for menor que v1. Caso contrário, retorna false
	 */
	bool operator< (const Venda &v1) const;
	/**
	 * Método que permite imprimir no ecrã uma fatura
	 */
	void imprimeFatura() const;
	/**
	 * Método semelhante ao operador menor, no qual o utilizador escolhe a forma de comparação
	 * @param v1 Venda que irá ser comparada
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação das duas vendas
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
	 * @return Retorn true se a venda for menor que v1. Caso contrário, retorn false
	 */
	bool menorQue(const Venda &v1, enum tipoSort tipo, bool crescente) const;
};

#endif
