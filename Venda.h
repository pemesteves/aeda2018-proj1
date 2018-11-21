<<<<<<< HEAD
/**
 * Header File que contem a classe Venda
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef VENDA_H
#define VENDA_H

#include "util.h"

#include "Data.h"
#include "Produto.h"
#include "Receita.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>

/**
 * Classe Venda
 */
class Venda {
private:
	std::map<Produto, std::vector<float>> produtosVendidos; //Map cujas keys são objetos do tipo Produto e o valor é um vetor com quantidade, iva e comparticipação
	Data data; //Data na qual foi realizada a venda
	Hora hora; //Hora à qual foi realizada a venda
	double totalVenda; //Valor total da venda
	bool temReceita; //Indica se a venda tem uma receita associada (true quando tem)
	Receita* receitaVenda; //Caso a venda tenha uma receita associada, receitaVenda guarda um apontador para essa receita
	Cliente* clienteVenda; //Cliente ao qual está associada a venda

public:
	/**
	 * Construtor da classe Venda
	 */
	Venda();
	/**
	 * Construtor da classe Venda
	 * @param receitaVenda Apontador para a receita associada à venda
	 * @param clienteVenda Apontador para o cliente associado à venda
	 */
	Venda(Receita* receitaVenda, Cliente* clienteVenda);
	/**
	 * Construtor da classe Venda
	 * @param dia, mes, ano, horas, min, segundos Dados correspondentes à data e hora da venda
	 */
	Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short min, unsigned short segundos);
	/**
	 * Método que permite obter o valor total da venda
	 * @return totalVenda (atributo da classe)
	 */
	double getTotalVenda() const;
	/**
	 * Método que permite obter o map com os produtos vendidos
	 * @return produtosVendidos (atributo da classe)
	 */
	std::map<Produto, std::vector<float>> getProdutosVendidos() const;
	/**
	 * Método que permite atribuir uma receita à venda
	 * Só é possível atribuir uma receita à venda se esta não tiver ainda nenhuma receita associada
	 * @param receitaVenda Apontador para a receita a associar
	 * @return True se foi possível atribuir a receita e false se não tiver sido possível
	 */
	bool setReceita(Receita* receitaVenda);
	/**
	 * Método que permite atribuir um cliente à venda
	 * Só é possível atribuir um cliente à venda se esta não tiver ainda nenhum cliente associado
	 * @param clienteVenda Apontador para o cliente a associar
	 * @return True se foi possível atribuir o cliente e false se não tiver sido possível
	 */
	void setCliente(Cliente* clienteVenda);
	/**
	 * Método que permite obter o número de produtos vendidos
	 * @return Tamanho de produtosVendidos (atributo da classe)
	 */
	unsigned int getNumProdutos() const;
	/**
	 * Método que permite obter o cliente da venda
	 * @return Cliente associado à venda, se ainda não houver nenhum cliente associado retorna NULL
	 */
	Cliente* getCliente();
	/**
	 * Método que permite obter a receita da venda
	 * @return Receita associada à venda, se não houver nenhuma receita associada retorna NULL
	 */
	Receita* getReceita();
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
