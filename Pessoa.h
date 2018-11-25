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
	unsigned long noContribuinte; //Numero de Contribuinte da Pessoa
public:
	/**
	 * Construtor da classe Pessoa
	 * @param nome Nome da Pessoa
	 * @param morada Morada da Pessoa
	 * @param cont Numero de contribuinte da Pessoa
	 */
	Pessoa(std::string nome, std::string morada, unsigned long cont);
	/**
	 * Destrutor da classe Pessoa
	 */
	virtual ~Pessoa() {}
	/**
	 * Metodo que permite obter o nome da pessoa
	 * @return Nome da Pessoa
	 */
	std::string getNome() const;
	/**
	 * Metodo que permite obter a morada da Pessoa
	 * @return Morada da Pessoa
	 */
	std::string getMorada() const;
	/**
	 * Metodo que permite obter o numero de contribuinte da pessoa
	 * @return Número de contribuinte
	 */
	unsigned long getNoContribuinte() const;
	/**
	 * Metodo que permite alterar o nome da pessoa
	 * @param nome Novo nome da Pessoa
	 */
	void setNome(std::string nome);
	/**
	 * Metodo que permite alterar a morada da pessoa
	 * @param morada Nova morada da Pessoa
	 */
	void setMorada(std::string morada);
	/**
	 * Metodo que permite alterar o numero de contribuinte da pessoa
	 * @param no Novo numero de contribuinte da Pessoa
	 */
	void setNoContribuinte(unsigned long no);
	/**
	 * Metodo puramente virtual que, nas classes derivadas, imprime no ecra os atributos da classe
	 */
	virtual void showInfo() const = 0;
	/**
	 * Overload do operador para exportar a Pessoa
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param p Pessoa que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Pessoa &p);
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
	 * @param cont Numero de Contribuinte do Funcionario/Pessoa
	 * @param sal Salario do Funcionario: caso nao seja atribuido, sera 500
	 */
	Funcionario(std::string nome, std::string morada, unsigned long cont, double sal = 500);
	/**
	 * Destrutor da classe Funcionario
	 */
	~Funcionario() {}
	/**
	 * Metodo para alterar a Farmacia onde o Funcionario trabalha
	 * @param f Apontador para Farmacia onde o Funcionario trabalha
	 */
	void setFarmacia(Farmacia* f);
	/**
	 * Metodo que permite obter a Farmacia onde o Funcionario trabalha
	 * @return Apontador para Farmacia
	 */
	Farmacia* getFarmacia() const {return farmaciaTrabalho;}
	/**
	 * Metodo que permite obter o salario do Funcionario
	 * @return Salario do Funcionario
	 */
	double getSalario() const;
	/**
	 * Metodo que permite obter o cargo do Funcionario
	 * @return Cargo do Funcionario na Farmacia onde trabalha
	 */
	std::string getCargo() const;
	/**
	 * Metodo que permite alterar o salario do Funcionario
	 * @param salario Salario do Funcionario a alterar
	 */
	void changeSalario(double salario);
	/**
	 * Metodo que permite alterar o cargo do Funcionario
	 * @param cargo Novo cargo do Funcionario
	 */
	void setCargo(std::string cargo);
	/**
	 * Metodo que imprime no ecra os atributos de um Funcionario
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois funcionarios com regras pre-definidas
	 * @param f1 Funcionario que ira ser comparado
	 * @return Retorna true se o funcionario for menor que f1. Caso contrario, retorna false
	 */
	bool operator< (const Funcionario &f1) const;
	/**
	 * Metodo semelhante ao operador menor, no qual o utilizador escolhe a forma de comparacao
	 * @param f1 Funcionario que ira ser comparado
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao dos dois funcionarios
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o funcionario for menor que f1. Caso contrario, retorna false
	 */
	bool menorQue(const Funcionario &f1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Overload do operador para exportar o Funcionario
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param f Funcionario que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Funcionario &f);
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
	 * @param contribuinte Numero de Contribuinte do Cliente/Pessoa
	 */
	Cliente(std::string nome, std::string morada, unsigned long contribuinte);
	/**
	 * Destrutor da classe Cliente
	 */
	~Cliente() {}
	/**
	 * Metodo para obter o historial de compras do Cliente
	 * @return Vetor de apontadores para objetos da classe Venda
	 */
	std::vector<Venda*> getHistorialCompras() const;
	/**
	 * Metodo para obter o numero de compras realizadas pelo Cliente
	 * @return Tamanho do vetor historialCompras
	 */
	unsigned int getNumCompras() const;
	/**
	 * Metodo para adicionar uma compra ao historial
	 * @param compra Apontador para objeto da classe Venda
	 */
	void addCompra(Venda* compra);
	/**
	 * Metodo que imprime no ecra os atributos de um Cliente
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois clientes com regras pre-definidas
	 * @param c1 Cliente que ira ser comparado
	 * @return Retorna true se o cliente for menor que c1. Caso contrario, retorna false
	 */
	bool operator< (const Cliente &c1) const;
	/**
	 * Metodo semelhante ao operador menor, no qual o utilizador escolhe a forma de comparacao
	 * @param c1 Cliente que ira ser comparado
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de comparacao dos dois clientes
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu criterio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o cliente for menor que c1. Caso contrario, retorna false
	 */
	bool menorQue(const Cliente &c1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Overload do operador para exportar o Cliente
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param c Cliente que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Cliente &c);
};

/**
 * Classe ClienteInexistente
 */
class ClienteInexistente{
	std::string nome; //Nome do Cliente
public:
	/**
	 * Construtor da classe -> classe utilizada em excecões
	 * @param nomeC Nome utilizado para a procura do cliente que nao existe
	 */
	ClienteInexistente(std::string nomeC){nome = nomeC;}
	/**
	 * Metodo que permite obter o nome utilizado na procura do cliente
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
	 * Construtor da classe -> classe utilizada em excecões
	 * @param nomeF Nome utilizado para a procura do funcionario que nao existe
	 */
	FuncionarioInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * Metodo que permite obter o nome utilizado na procura do funcionario
	 * @return Retorna o nome do funcionario inexistente
	 */
	std::string getNome() const {return nome;}
};

#endif
