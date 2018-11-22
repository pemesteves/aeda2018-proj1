/**
 * Header File que contem enumeracoes e metodos sort importantes para o projeto
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef UTIL_H
#define UTIL_H

#include <vector>

/**
 * Declaracao de uma enumeracao: tipoSort
 * e utilizada para todas as operacões de sort
 * Valores: NOME = ordenacao por nome; CONTIBUINTE = ordenacao por contribuinte; NUM_PROD = ordenacao por número de produtos;
 * 			NUM_VENDA = ordenacao por número de vendas/compras; SALARIO = ordenacao por salario; DATA = ordenacao por data;
 * 			HORA = ordenacao por hora; DEFAULT = ordenacao por um criterio pre-definido
 */
enum tipoSort {NOME, CONTRIBUINTE, NUM_PROD, NUM_VENDA, SALARIO, DATA, HORA, DEFAULT};

/**
 * Declaracao de uma enumeracao: dadosProd
 * e utilizada para facilitar o acesso a dados de um produto numa venda
 * Valores: QUANTIDADE = unidades do produto vendidas; IVA = percentagem de IVA do produto; COMPARTICIPACAO = percentagem de comparticipacao do produto; PRECO_PAGO = preco pago pelo produto, tendo em conta o IVA e a comparticipacao
 */
enum dadosProd {QUANTIDADE, IVA, COMPARTICIPACAO, PRECO_PAGO};

/**
 * Metodo usado no algoritmo quickSort
 * @param v Vetor a ordenar
 * @param left, rigth Índices inicial e final do vetor
 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
 * @return Retorna o valor medio do vetor (?)
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
 * Algoritmo de Ordenacao
 * @param v Vetor a ordenar
 * @param left, rigth Índices inicial e final do vetor
 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
 */
template <class Comparable>
void quickSort(std::vector<Comparable* > &v, int left, int right, enum tipoSort tipo, bool crescente)
{

	Comparable x = median3(v,left,right, tipo, crescente); // x e o pivot
	int i = left; int j = right-1; // passo de particao
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
}

class Receita;
class Pessoa;
class Cliente;
class Funcionario;
class Venda;

#endif
