/**
 * Header File que contem as classes Produto, Medicamento, PassivelReceita e ProdutoInexistente
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef PESSOA_H
#define PESSOA_H

#include "Venda.h"
#include "Farmacia.h"

#include <string>
#include <vector>

class Farmacia;
/**
 * Classe Pessoa
 */
class Pessoa {
protected:
	std::string nome; //Nome da Pessoa
	std::string morada; //Morada da Pessoa
	double noContribuinte; //Número de Contribuinte da Pessoa
public:
	/**
	 * Construtor da classe Pessoa
	 * @param nome Nome da Pessoa
	 * @param morada Morada da Pessoa
	 * @param cont Número de contribuinte da Pessoa
	 */
	Pessoa(std::string nome, std::string morada, double cont);
	/**
	 * Destrutor da classe Pessoa
	 */
	virtual ~Pessoa() {}
	/**
	 * Método que permite obter o nome da pessoa
	 * @return Nome da Pessoa
	 */
	std::string getNome() const;
	/**
	 * Método que permite obter a morada da Pessoa
	 * @return Morada da Pessoa
	 */
	std::string getMorada() const;
	/**
	 * Método que permite obter o número de contribuinte da pessoa
	 * @return Número de contribuinte
	 */
	double getNoContribuinte() const;
	/**
	 * Método puramente virtual que, nas classes derivadas, imprime no ecrã os atributos da classe
	 */
	virtual void showInfo() const = 0;
};

/**
 * Classe Funcionario
 */
class Funcionario : public Pessoa {
private:
	double salario; //Salario do Funcionario
	Farmacia* farmaciaTrabalho; //Apontador para a Farmacia onde o Funcionario trabalha
	std::string cargo; //Cargo na Farmacia (funcionario, gerente,...)
public:
	/**
	 * Construtor da classe Funcionario
	 * @param nome Nome do Funcionario/Pessoa
	 * @param morada Morada do Funcionario/Pessoa
	 * @param cont Número de Contribuinte do Funcionario/Pessoa
	 * @param sal Salário do Funcionario: caso não seja atribuído, será 500
	 */
	Funcionario(std::string nome, std::string morada, double cont, double sal = 500);
	/**
	 * Destrutor da classe Pessoa
	 */
	~Funcionario() {}
	/**
	 * Método para alterar a Farmacia onde o Funcionario trabalha
	 * @param f Apontador para Farmacia onde o Funcionario trabalha
	 */
	void setFarmacia(Farmacia* f);
	/**
	 * Método que permite obter a Farmacia onde o Funcionario trabalha
	 * @return Apontador para Farmacia
	 */
	Farmacia* getFarmacia() const {return farmaciaTrabalho;}
	/**
	 * Método que permite obter o salário do Funcionario
	 * @return Salário do Funcionario
	 */
	double getSalario() const;
	/**
	 * Método que permite obter o cargo do Funcionario
	 * @return Cargo do Funcionario na Farmacia onde trabalha
	 */
	std::string getCargo() const;
	/**
	 * Método que permite alterar o salário do Funcionario
	 * @param salario Salário do Funcionario a alterar
	 */
	void changeSalario(double salario);
	/**
	 * Método que imprime no ecrã os atributos de um Funcionario
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois funcionários com regras pré-definidas
	 * @param f1 Funcionário que irá ser comparado
	 * @return Retorna true se o funcionário for menor que f1. Caso contrário, retorna false
	 */
	bool operator< (const Funcionario &f1) const;
	/**
	 * Método semelhante ao operador menor, no qual o utilizador escolhe a forma de comparação
	 * @param f1 Funcionário que irá ser comparado
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação dos dois funcionários
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o funcionário for menor que f1. Caso contrário, retorna false
	 */
	bool menorQue(const Funcionario &f1, enum tipoSort tipo, bool crescente) const;
};

/**
 * Classe Cliente
 */
class Cliente : public Pessoa {
private:
	std::vector<Venda*> historialCompras; //Historial de Compras do Cliente
public:
	/**
	 * Construtor da classe Cliente
	 * @param nome Nome do Cliente/Pessoa
	 * @param morada Morada do Cliente/Pessoa
	 * @param contribuinte Número de Contribuinte do Cliente/Pessoa
	 */
	Cliente(std::string nome, std::string morada, double contribuinte);
	/**
	 * Destrutor da classe Cliente
	 */
	~Cliente() {}
	/**
	 * Método para obter o historial de compras do Cliente
	 * @return Vetor de apontadores para objetos da classe Venda
	 */
	std::vector<Venda*> getHistorialCompras() const;
	/**
	 * Método para obter o número de compras realizadas pelo Cliente
	 * @return Tamanho do vetor historialCompras
	 */
	unsigned int getNumCompras() const;
	/**
	 * Método para adicionar uma compra ao historial
	 * @param compra Apontador para objeto da classe Venda
	 */
	void addCompra(Venda* compra);
	/**
	 * Método que imprime no ecrã os atributos de um Funcionario
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois clientes com regras pré-definidas
	 * @param c1 Cliente que irá ser comparado
	 * @return Retorna true se o cliente for menor que c1. Caso contrário, retorna false
	 */
	bool operator< (const Cliente &c1) const;
	/**
	 * Método semelhante ao operador menor, no qual o utilizador escolhe a forma de comparação
	 * @param c1 Cliente que irá ser comparado
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de comparação dos dois clientes
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu critério de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o cliente for menor que c1. Caso contrário, retorna false
	 */
	bool menorQue(const Cliente &c1, enum tipoSort tipo, bool crescente) const;
};

/**
 * Classe ClienteInexistente
 */
class ClienteInexistente{
	std::string nome; //Nome do Cliente
public:
	/**
	 * Construtor da classe -> classe utilizada em exceções
	 * @param nomeC Nome utilizado para a procura do cliente que não existe
	 */
	ClienteInexistente(std::string nomeC){nome = nomeC;}
	/**
	 * Método que permite obter o nome utilizado na procura do cliente
	 * @return Retorna o nome do cliente inexistente
	 */
	std::string getNome() const {return nome;}
};

/**
 * Classe FuncionarioInexistente
 */
class FuncionarioInexistente{
	std::string nome; //Nome do Funcionario
public:
	/**
	 * Construtor da classe -> classe utilizada em exceções
	 * @param nomeF Nome utilizado para a procura do funcionário que não existe
	 */
	FuncionarioInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * Método que permite obter o nome utilizado na procura do funcionário
	 * @return Retorna o nome do funcionário inexistente
	 */
	std::string getNome() const {return nome;}
};

#endif
