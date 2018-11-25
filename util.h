/**
 * Header File que contem enumeracoes e metodos sort importantes para o projeto
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>

/**
 * Declaracao de uma enumeracao: tipoSort
 * e utilizada para todas as operacoes de sort
 * Valores: NOME = ordenacao por nome; CONTIBUINTE = ordenacao por contribuinte; NUM_PROD = ordenacao por numero de produtos;
 * 			NUM_VENDA = ordenacao por numero de vendas/compras; SALARIO = ordenacao por salario; DATA = ordenacao por data;
 * 			HORA = ordenacao por hora; DEFAULT = ordenacao por um criterio pre-definido
 */
enum tipoSort {NOME, CONTRIBUINTE, NUM_PROD, NUM_VENDA, SALARIO, DATA, HORA, DEFAULT};

/**
 * Declaracao de uma enumeracao: dadosProd
 * e utilizada para facilitar o acesso a dados de um produto numa venda
 * Valores: QUANTIDADE = unidades do produto vendidas; IVA = percentagem de IVA do produto; COMPARTICIPACAO = percentagem de comparticipacao do produto; PRECO_PAGO = preco pago pelo produto, tendo em conta o IVA e a comparticipacao
 */
enum dadosProd {QUANTIDADE, IVA, COMPARTICIPACAO, PRECO_PAGO};

/*
 * Metodo que retorna uma string com todas as letras maiusculas, usado para comparacoes de strings case-insensitive
 * @param str String cujas letras se vai converter para uppercase
 * @return string com todas as letras maiusculas
 */
inline std::string toupperstring(std::string str){
	std::string s = str;
	for (size_t i = 0; i<s.length(); i++){
		s.at(i)=toupper(s.at(i));
	}
	return s;
}

template <typename T>
class sorting{
public:
	static enum tipoSort tipo;
	static bool crescente;
	static bool compare_p(const T* a, const T* b){
		return a->menorQue(*b, tipo, crescente);
	}
	void sort_p(std::vector<T*> &v){
		sort(v.begin(), v.end(), compare_p);
	}
};


class Receita;
class Pessoa;
class Cliente;
class Funcionario;
class Venda;

#endif
