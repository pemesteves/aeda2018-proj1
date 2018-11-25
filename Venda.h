
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
	unsigned long codigo; //Codigo da venda
	static unsigned long codigo_sequencial; //Variavel usada para que os codigos das vendas sejam sequenciais (primeira venda tem codigo 0)
	std::map<Produto, std::vector<float>> produtosVendidos; //Map cujas keys sao objetos do tipo Produto e o valor e um vetor com quantidade, iva e comparticipacao
	Data data; //Data na qual foi realizada a venda
	Hora hora; //Hora a qual foi realizada a venda
	double totalVenda; //Valor total da venda
	bool temReceita; //Indica se a venda tem uma receita associada (true quando tem)
	Receita* receitaVenda; //Caso a venda tenha uma receita associada, receitaVenda guarda um apontador para essa receita
	Cliente* clienteVenda; //Cliente ao qual esta associada a venda

public:
	/**
	 * Construtor da classe Venda
	 */
	Venda();
	/**
	 * Construtor da classe Venda
	 * @param receitaVenda Apontador para a receita associada a venda
	 * @param clienteVenda Apontador para o cliente associado a venda
	 */
	Venda(Receita* receitaVenda, Cliente* clienteVenda);
	/**
	 * Construtor da classe Venda
	 * @param dia, mes, ano, horas, min, segundos, codigo Dados correspondentes a data, hora e codigo da venda
	 */
	Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short min, unsigned short segundos, unsigned long codigo);
	/**
	 * Metodo que permite obter o valor total da venda
	 * @return totalVenda (atributo da classe)
	 */
	double getTotalVenda() const;
	/**
	 * Metodo que permite obter o map com os produtos vendidos
	 * @return produtosVendidos (atributo da classe)
	 */
	std::map<Produto, std::vector<float>> getProdutosVendidos() const;
	/**
	 * Metodo que permite atribuir uma receita a venda
	 * Só e possível atribuir uma receita a venda se esta nao tiver ainda nenhuma receita associada
	 * @param receitaVenda Apontador para a receita a associar
	 * @return True se foi possivel atribuir a receita e false se nao tiver sido possivel
	 */
	bool setReceita(Receita* receitaVenda);
	/**
	 * Metodo que permite atribuir um cliente a venda
	 * So e possivel atribuir um cliente a venda se esta nao tiver ainda nenhum cliente associado
	 * @param clienteVenda Apontador para o cliente a associar
	 * @return True se foi possivel atribuir o cliente e false se nao tiver sido possivel
	 */
	void setCliente(Cliente* clienteVenda);
	/**
	 * Metodo que permite obter o numero de produtos vendidos
	 * @return Tamanho de produtosVendidos (atributo da classe)
	 */
	unsigned int getNumProdutos() const;
	/**
	 * Metodo que permite obter o cliente da venda
	 * @return Cliente associado a venda, se ainda nao houver nenhum cliente associado retorna NULL
	 */
	Cliente* getCliente();
	/**
	 * Metodo que permite obter a receita da venda
	 * @return Receita associada a venda, se nao houver nenhuma receita associada retorna NULL
	 */
	Receita* getReceita();
	/**
	 * Metodo que permite obter a data da venda
	 * @return Objeto do tipo Data
	 */
	Data getData() const;
	/**
	 * Metodo que permite obter a hora da venda
	 * @return Objeto do tipo Hora
	 */
	Hora getHora() const;
	/**
	 * Metodo que permite obter o codigo da venda
	 * @return codigo da venda
	 */
	unsigned long getCodigo() const;
	/**
	 * Metodo que permite obter o preco de um produto
	 * @param nomeProd Nome do produto que ira ser procurado
	 * @return Preco do produto especificado como argumento. Retorna -1 se nao existir
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * Metodo que permite adicionar um produto a venda
	 * @param prod Apontador para objeto da classe Produto
	 * @param quant, iva Valores do tipo float que serao colocados do vetor do map produtosVendidos
	 * @return True se foi possivel adicionar o produto, false se nao foi (se necessitar de ser vendido com receita e nao estiver contido na receita associada a venda)
	 */
	bool addProduto(Produto* prod, float quant, float iva);
	/**
	 * Operador menor: compara dois objetos do tipo Venda com regras pre-definidas
	 * @param v1 Objeto do tipo Venda
	 * @return Retorna true se a venda for menor que v1. Caso contrario, retorna false
	 */
	bool operator< (const Venda &v1) const;
	/**
	 * Metodo que permite imprimir no ecra uma fatura
	 */
	void imprimeFatura() const;
	/**
	 * Metodo semelhante ao operador menor, no qual o utilizador escolhe a forma de comparacao
	 * @param v1 Venda que ira ser comparada
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao das duas vendas
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
	 * @return Retorn true se a venda for menor que v1. Caso contrario, retorna false
	 */
	bool menorQue(const Venda &v1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Overload de operador << para exportar a venda
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param v1 Venda que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Venda &v1);
};

#endif
