/**
 * Header File que contém a classe Farmacia, a classe FarmaciaInexistente e um algoritmo para ordenar os vetores de todo o projeto.
 *
 * @author Márcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "Pessoa.h"
#include "Venda.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Pessoa;
class Funcionario;
class Venda;

/**
 * Classe Farmacia
 */
class Farmacia {
private:
	std::string nome; //Nome da Farmacia
	std::string morada; //Morada da Farmacia
	Funcionario* gerente; //Apontador para o gerente da Farmacia(tipo Funcionario)
	Funcionario* diretorTecnico; //Apontador para o diretor técnico da Farmacia(tipo Funcionario)
	std::map<Produto, int> produtosVender; //Map cujas keys são objetos do tipo Produto e os valores são as quantidades desse produto. Serve para representar os produtos à venda
	std::vector<Venda*> vendas; //Vetor de apontador para objetos do tipo Venda
public:
	/**
	 * Construtor da Classe Farmacia
	 * @param nome Nome da farmácia
	 * @param morada Morada da farmácia
	 */
	Farmacia(std::string nome, std::string morada);
	/**
	 * Método que permite obter o nome da farmácia
	 * @return Nome da farmácia(atributo da classe)
	 */
	std::string getNome() const;
	/**
	 * Método que permite obter a morada da farmácia
	 * @return Morada da farmácia(atributo da classe)
	 */
	std::string getMorada() const;
	/**
	 * Método que permite obter o gerente da farmácia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getGerente() const;
	/**
	 * Método que permite obter o diretor técnico da farmácia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getDiretorTecnico() const;
	/**
	 * Método que permite obter todas as vendas realizadas na farmácia
	 * @return Vetor de apontador para objetos da classe Venda(atributo da classse)
	 */
	std::vector<Venda*> getVendas() const;
	/**
	 * Método que permite obter os produtos disponíveis para venda mais a sua quantidade
	 * @return Atributo da classe -> produtosVender
	 */
	std::map<Produto, int> getProdutosVender() const;
	/**
	 * Método que permite obter o número de produtos disponíveis para venda
	 * @return Tamanho do map produtosVender
	 */
	unsigned int getNumProdutos() const;
	/**
	 * Método que permite obter o número de vendas realizadas na farmácia
	 * @return Tamanho do vetor vendas
	 */
	unsigned int getNumVendas() const;
	/**
	 * Método que permite obter o número de vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contam o número de vendas
	 * @return Número de vendas realizadas no intervalo especificado
	 */
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	/**
	 * Método que permite obter as vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contabilizam as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no intervalo especificado
	 */
	std::vector<Venda*> getVendasTempo(Data d1, Data d2) const;
	/**
	 * Método que permite obter o número de vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return Número de vendas realizadas no dia especificado
	 */
	unsigned int getNumVendasDia(Data d) const;
	/**
	 * Método que permite obter as vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no dia especificado
	 */
	std::vector<Venda*> getVendasDia(Data d) const;
	/**
	 * Método que permite obter o preço de um determinado produto
	 * @param nomeProd Nome do produto do qual se quer saber o preço
	 * @return Preço do produto passado como argumento. Se não existir, retorna-se -1
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * Método que permite alterar o gerente da farmácia
	 * @param gerente Apontador para Funcionario que será colocado no atributo gerente
	 */
	void setGerente(Funcionario* gerente);	
	/**
	 * Método que permite alterar o diretor técnico da farmácia
	 * @param diretor Apontador para Funcionario que será colocado no atributo diretorTecnico
	 */
	void setDiretorTecnico(Funcionario* diretor){diretorTecnico = diretor;}
	/**
	 * Método que permite adicionar vários produtos ao map produtosVender
	 * @param produtosVender_new Vetor de apontadores para objetos da classe Produto
	 */
	void addProdutosVender(std::vector<Produto*> produtosVender_new);
	/**
	 * Método que permite adicionar um produto ao map produtosVender
	 * @param produtoVender Apontador para objeto da classe Porduto
	 * @return Booleano que indica se a operação foi efetuada com sucesso se for 0
	 */
	bool addProdutoVender(Produto* produtoVender);
	/**
	 * Método que permite remover um produto do map produtosVender
	 * @param nomeP Nome do produto a remover
	 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nomeP);
	/**
	 * Método que permite realizar uma venda
	 * @param venda Apontador para objeto da classe Venda
	 */
	void addVenda(Venda* venda);
	/**
	 * Método que permite ordenar as vendas
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
	 */
	void sortVendas(enum tipoSort tipo, bool crescente);
	/**
	 * Método que permite saber se um determinado produto existe para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @return Se existir, retorna-se true. Caso contrário, retorna-se false
	 */
	bool existeProduto(std::string nomeProduto) const;
	/**
	 * Método que permite saber se existe um determinado número de unidades de um produto para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @param quant Número de unidades do produto
	 * @return Se existir, retorna-se true. Caso contrário, retorna-se false
	 */
	bool existeProdutoQuant(std::string nomeProduto, int quant) const;
	/**
	 * Método que permite alterar a quantidade de um determinado produto
	 * @param nomeProd Nome do produto cuja quantidade será alterada
	 * @param quant Quantidade a alterar
	 * @return Retorna true se a operação foi realizada com sucesso. Caso contrário, retorna false
	 */
	bool setQuantidade(std::string nomeProd, int quant);
	/**
	 * Operador menor: Compara duas farmácias com regras pré-definidas
	 * @param f1 Farmácia que irá ser comparada
	 * @return Retorna true se a farmácia for menor a f1. Caso contrário, retorna false
	 */
	bool operator< (const Farmacia &f1) const;
	/**
	 * Método semelhante ao operador menor, no qual o utilizador escolhe a forma de comparação
	 * @param f1 Farmácia que irá ser comparada
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação das duas farmácias
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se a farmácia for menor que f1. Caso contrário, retorna false
	 */
	bool menorQue(const Farmacia &f1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Método que permite imprimir no ecrã uma fatura
	 * @param v Apontador para objeto do tipo Venda que contém a venda da qual será impressa a fatura
	 */
	void imprimeFatura(Venda* v) const; //Não sei se isto faz muito sentido aqui
};

/**
 * Classe FarmaciaInexistente
 */
class FarmaciaInexistente{
	std::string nome; //Nome da Farmácia
public:
	/**
	 * Construtor da classe -> classe utilizada em exceções
	 * @param nomeF Nome utilizado para a procura da farmácia que não existe
	 */
	FarmaciaInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * Método que permite obter o nome utilizado na procura da farmácia
	 * @return Retorna o nome da farmácia inexistente
	 */
	std::string getNome() const{return nome;}
};

/*
template<class T>
bool funcSort(T* a, T* b){
	return (*a)<(*b);
}*/


/**
 * Método usado no algoritmo quickSort
 * @param v Vetor a ordenar
 * @param left, rigth Índices inicial e final do vetor
 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
 * @return Retorna o valor médio do vetor (?)
 */
template <class Comparable>
const Comparable &median3(std::vector<Comparable*> &v, int left,
		int right, enum tipoSort tipo, bool crescente)
{
	int center = (left+right) /2;
	if (v[center]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[center]);
	if (v[right]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[right]);
	if (v[right]->menorQue(*v[center], tipo, crescente))
		std::swap(v[center], v[right]);//coloca pivot na posicao right-1
	std::swap(v[center], v[right-1]);
	return *v[right-1];
}

/**
 * Algoritmo de Ordenação
 * @param v Vetor a ordenar
 * @param left, rigth Índices inicial e final do vetor
 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
 */
template <class Comparable>
void quickSort(std::vector<Comparable* > &v, int left, int right, enum tipoSort tipo, bool crescente)
{
	/*if (right-left <= 10)// se vetor pequeno
		insertionSort(v,left,right);
	else {*/
	Comparable x = median3(v,left,right, tipo, crescente); // x é o pivot
	int i = left; int j = right-1; // passo de partição
	for(; ; ) {
		while (v[++i]->menorQue(x, tipo, crescente)) ;
		while (x.menorQue(*v[--j], tipo, crescente)) ;
		if (i < j)
			std::swap(v[i], v[j]);
		else
			break;
	}
	std::swap(v[i], v[right-1]);//repoe pivot
	quickSort(v, left, i-1, tipo, crescente);
	quickSort(v, i+1, right, tipo, crescente);
	//}
}


#endif 
