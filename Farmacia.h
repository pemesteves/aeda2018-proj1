/**
 * Header File que contem a classe Farmacia e a classe FarmaciaInexistente
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "util.h"
#include "Pessoa.h"
#include "Venda.h"
#include "Data.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

/**
 * Classe Farmacia
 */
class Farmacia {
private:
	std::string nome; //Nome da Farmacia
	std::string morada; //Morada da Farmacia
	Funcionario* gerente; //Apontador para o gerente da Farmacia(tipo Funcionario)
	Funcionario* diretorTecnico; //Apontador para o diretor tecnico da Farmacia(tipo Funcionario)
	std::map<Produto, int> produtosVender; //Map cujas keys sao objetos do tipo Produto e os valores sao as quantidades desse produto. Serve para representar os produtos a vender
	std::vector<Venda*> vendas; //Vetor de apontador para objetos do tipo Venda
public:
	/**
	 * Construtor da Classe Farmacia
	 * @param nome Nome da farmacia
	 * @param morada Morada da farmacia
	 */
	Farmacia(std::string nome, std::string morada);
	/**
	 * Metodo que permite obter o nome da farmacia
	 * @return Nome da farmacia(atributo da classe)
	 */
	std::string getNome() const;
	/**
	 * Metodo que permite obter a morada da farmacia
	 * @return Morada da farmacia(atributo da classe)
	 */
	std::string getMorada() const;
	/**
	 * Metodo que permite obter o gerente da farmacia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getGerente() const;
	/**
	 * Metodo que permite obter o diretor tecnico da farmacia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getDiretorTecnico() const;
	/**
	 * Metodo que permite obter todas as vendas realizadas na farmacia
	 * @return Vetor de apontador para objetos da classe Venda(atributo da classse)
	 */
	std::vector<Venda*> getVendas() const;
	/**
	 * Metodo que permite obter uma dada Venda
	 * @param codigo Codigo da Venda a procurar
	 * @return Apontador para objeto da classe Venda com o codigo especificado
	 */
	Venda* getVenda(unsigned long codigo) const;
	/**
	 * Metodo que permite obter os produtos disponiveis para venda mais a sua quantidade
	 * @return Atributo da classe -> produtosVender
	 */
	std::map<Produto, int> getProdutosVender() const;
	/**
	 * Metodo para obter o Produto com um certo codigo
	 * @param codigo Codigo do Produto a procurar
	 * @return Produto que contem o codigo especificado no argumento
	 */
	Produto getProduto(unsigned long codigo);
	/**
	 * Metodo que permite obter o numero de produtos disponiveis para venda
	 * @return Tamanho do map produtosVender
	 */
	unsigned int getNumProdutos() const;
	/**
	 * Metodo que permite obter o numero de vendas realizadas na farmacia
	 * @return Tamanho do vetor vendas
	 */
	unsigned int getNumVendas() const;
	/**
	 * Metodo que permite obter o numero de vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contam o numero de vendas
	 * @return Numero de vendas realizadas no intervalo especificado
	 */
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	/**
	 * Metodo que permite obter as vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contabilizam as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no intervalo especificado
	 */
	std::vector<Venda*> getVendasTempo(Data d1, Data d2) const;
	/**
	 * Metodo que permite obter o numero de vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return Numero de vendas realizadas no dia especificado
	 */
	unsigned int getNumVendasDia(Data d) const;
	/**
	 * Metodo que permite obter as vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no dia especificado
	 */
	std::vector<Venda*> getVendasDia(Data d) const;
	/**
	 * Metodo que permite obter o preco de um determinado produto
	 * @param nomeProd Nome do produto do qual se quer saber o preco
	 * @return Preco do produto passado como argumento. Se nao existir, retorna-se -1
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * Metodo que permite obter o numero de unidades disponiveis de um determinado produto
	 * @param nomeProd Nome do produto do qual se quer saber a quantidade
	 * @return Quantidade do produto passado como argumento. Se nao existir, retorna-se -1
	 */
	int getQuantProduto(std::string nomeProd) const;
	/**
	 * Metodo que permite alterar o gerente da farmacia
	 * @param gerente Apontador para Funcionario que sera colocado no atributo gerente
	 */
	void setGerente(Funcionario* gerente);	
	/**
	 * Metodo que permite alterar o diretor tecnico da farmacia
	 * @param diretor Apontador para Funcionario que sera colocado no atributo diretorTecnico
	 */
	void setDiretorTecnico(Funcionario* diretor);
	/**
	 * Metodo que altera o vetor de vendas pelo vetor passado por parametro
	 * @param v Vetor a alterar
	 */
	void setVendas(std::vector<Venda*> v);
	/**
	 * Metodo que permite adicionar varios produtos ao map produtosVender
	 * @param produtosVender_new Vetor de apontadores para objetos da classe Produto
	 */
	void addProdutosVender(std::vector<Produto*> produtosVender_new);
	/**
	 * Metodo que permite adicionar um produto ao map produtosVender
	 * @param produtoVender Apontador para objeto da classe Porduto
	 * @return Booleano que indica se a operacao foi efetuada com sucesso
	 */
	bool addProdutoVender(Produto* produtoVender);
	/**
	 * Metodo que permite remover um produto do map produtosVender
	 * @param nomeP Nome do produto a remover
	 * @return Retorna um apontador para o objeto removido ou, se este nao existir, lanca uma excecao do tipo ProdutoInexistente
	 */
	const Produto* removeProduto(std::string nomeP);
	/**
	 * Metodo que permite realizar uma venda
	 * A venda e possível apenas se os produtos da mesma existirem na farmacia nas quantidades necessarias
	 * @param venda Apontador para objeto da classe Venda
	 * @return Retorna true caso
	 */
	bool addVenda(Venda* venda);
	/**
	 * Metodo que permite ordenar as vendas
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de ordenacao do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenacao por ordem crescente ou decrescente
	 */
	void sortVendas(enum tipoSort tipo, bool crescente);
	/**
	 * Metodo que permite saber se um determinado produto existe para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @return Se existir, retorna-se true. Caso contrario, retorna-se false
	 */
	bool existeProduto(std::string nomeProduto) const;
	/**
	 * Metodo que permite saber se existe um determinado número de unidades de um produto para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @param quant Numero de unidades do produto
	 * @return Se existir, retorna-se true. Caso contrario, retorna-se false
	 */
	bool existeProdutoQuant(std::string nomeProduto, int quant) const;
	/**
	 * Metodo que permite alterar a quantidade de um determinado produto
	 * @param nomeProd Nome do produto cuja quantidade sera alterada
	 * @param quant Quantidade a alterar
	 * @return Retorna true se a operacao foi realizada com sucesso. Caso contrario, retorna false
	 */
	bool setQuantidade(std::string nomeProd, int quant);
	/**
	 * Operador menor: Compara duas farmacias com regras pre-definidas
	 * @param f1 Farmacia que ira ser comparada
	 * @return Retorna true se a farmacia for menor a f1. Caso contrario, retorna false
	 */
	bool operator< (const Farmacia &f1) const;
	/**
	 * Metodo semelhante ao operador menor, no qual o utilizador escolhe a forma de comparacao
	 * @param f1 Farmacia que ira ser comparada
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao das duas farmacias
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se a farmacia for menor que f1. Caso contrario, retorna false
	 */
	bool menorQue(const Farmacia &f1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Metodo que permite imprimir no ecra uma fatura
	 * @param v Apontador para objeto do tipo Venda que contem a venda da qual sera impressa a fatura
	 */
	void imprimeFatura(Venda* v) const;
	/*
	 * Metodo que imprime no ecra os dados da farmacia (nome, morada, gerente, diretor tecnico)
	 */
	void imprimeDados() const;
	/**
	 * Overload do operador << para exportar a farmacia
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param f Farmacia que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Farmacia &f);
};

/**
 * Classe FarmaciaInexistente
 */
class FarmaciaInexistente{
	std::string nome; //Nome da Farmacia
public:
	/**
	 * Construtor da classe -> classe utilizada em excecões
	 * @param nomeF Nome utilizado para a procura da farmacia que nao existe
	 */
	FarmaciaInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * Metodo que permite obter o nome utilizado na procura da farmacia
	 * @return Retorna o nome da farmacia inexistente
	 */
	std::string getNome() const{return nome;}
};


#endif 
