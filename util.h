#ifndef UTIL_H
#define UTIL_H

/**
 * Declaração de uma enumeração: tipoSort
 * É utilizada para todas as operações de sort
 * Valores: NOME = ordenação por nome; CONTIBUINTE = ordenação por contribuinte; NUM_PROD = ordenação por número de produtos;
 * 			NUM_VENDA = ordenação por número de vendas/compras; SALARIO = ordenação por salário; DATA = ordenação por data;
 * 			HORA = ordenação por hora; DEFAULT = ordenação por um critério pré-definido
 */
enum tipoSort {NOME, CONTRIBUINTE, NUM_PROD, NUM_VENDA, SALARIO, DATA, HORA, DEFAULT};

/**
 * Declaração de uma enumeração: dadosProd
 * É utilizada para facilitar o acesso a dados de um produto numa venda
 * Valores: QUANTIDADE = unidades do produto vendidas; IVA = percentagem de IVA do produto; COMPARTICIPACAO = percentagem de comparticipacao do produto
 */
enum dadosProd {QUANTIDADE, IVA, COMPARTICIPACAO};

class Receita;
class Pessoa;
class Cliente;
class Funcionario;
class Venda;

#endif
