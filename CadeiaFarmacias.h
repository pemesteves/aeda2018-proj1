/**
 * Header File que contem a classe CadeiaFarmacias.
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

#include "Farmacia.h"
#include <vector>
#include <iostream>
#include <fstream>

/**
 * Classe CadeiaFarmacias
 */
class CadeiaFarmacias {
private:
	std::string nome; //Nome da cadeia de farmacias
	std::vector<Farmacia*> farmacias; //Vetor de apontadores para objetos do tipo Farmacia
	std::vector <Cliente*> clientes; //Vetor de apontadores para objetos do tipo Cliente
	std::vector <Funcionario*> funcionarios; //Vetor de apontadores para objetos do tipo Funcionario
public:
	/**
	 *  Construtor da classe
	 * 	Inicializa um objeto da classe colocando todos os vetores vazios
	 */
	CadeiaFarmacias();
	/**
	 *  Construtor da classe
	 * 	Inicializa um objeto da classe colocando todos os vetores vazios e atribuindo um nome
	 * 	@param nome Nome da cadeia de farmacias
	 */
	CadeiaFarmacias(std::string nome);
	/**
	 * Metodo para alterar o nome de uma cadeia de farmacias
	 * @param nome Novo nome da cadeia
	 */
	void setNome(std::string nome);
	/**
	 * Metodo que retorna o numero de farmacias
	 * @return Tamanho do vetor de farmacias(unsigned int)
	 */
	unsigned int getNumFarmacias() const;
	/**
	 * Metodo que retorna o numero de clientes
	 * @return Tamanho do vetor de clientes(unsigned int)
	 */
	unsigned int getNumClientes() const;
	/**
	 * Metodo que retorna o numero de funcionarios
	 * @return Tamanho do vetor de funcionarios(unsigned int)
	 */
	unsigned int getNumFuncionarios() const;
	/**
	 * Metodo que retorna o nome da cadeia de farmacias
	 * @return Nome da Cadeia (atributo da classe)
	 */
	std::string getNome() const;
	/**
	 * Metodo que retorna um vetor de farmacias
	 * @return Vetor farmacias (atributo da classe)
	 */
	std::vector<Farmacia *> getFarmacias() const;
	/**
	 * Metodo que retorna um vetor de clientes
	 * @return Vetor clientes (atributo da classe)
	 */
	std::vector <Cliente*> getClientes() const;
	/**
	 * Metodo que retorna um vetor de funcionarios
	 * @return Vetor funcionarios (atributo da classe)
	 */
	std::vector <Funcionario*> getFuncionarios() const;
	/**
	 * Metodo que permite adicionar um apontador para Farmacia ao respetivo vetor
	 * @param farmacia Apontador para objeto do tipo Farmacia que sera adicionado ao vetor farmacias
	 */
	void addFarmacia(Farmacia* farmacia);
	/**
	 * Metodo que permite eliminar a Farmacia nomeF do respetivo vetor. Tambem remove o apontador Farmacia de todos os funcionarios caso seja o mesmo
	 * @param nomeF Nome da farmacia que sera removida do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este nao existir, lanca uma excecao do tipo FarmaciaInexistente
	 */
	Farmacia* removeFarmacia(const std::string &nomeF);
	/**
	 * Metodo que permite ordenar as farmacias
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de ordenacao do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenacao por ordem crescente ou decrescente
	 */
	void sortFarmacias(enum tipoSort tipo, bool crescente);
	/**
	 * Metodo que permite adicionar um apontador para Cliente ao respetivo vetor
	 * @param cliente Apontador para objeto do tipo Cliente que sera adicionado ao vetor clientes
	 */
	void addCliente(Cliente* cliente);
	/**
	 * Metodo que permite eliminar o Cliente nomeC do respetivo vetor
	 * @param nomeC Nome do cliente que sera removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este nao existir, lanca uma excecao do tipo ClienteInexistente
	 */
	Cliente* removeCliente(const std::string &nomeC);
	/**
	 * Metodo que permite ordenar os clientes
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de ordenacao do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenacao por ordem crescente ou decrescente
	 */
	void sortClientes(enum tipoSort tipo, bool crescente);
	/**
	 * Metodo que permite adicionar um apontador para Funcionario ao respetivo vetor
	 * @param funcionario Apontador para objeto do tipo Funcionario que sera adicionado ao vetor funcionarios
	 */
	void addFuncionario(Funcionario* funcionario);
	/**
	 * Metodo que permite eliminar o Funcionario nomeF do respetivo vetor
	 * @param nomeF Nome do funcionario que sera removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este nao existir, lanca uma excecao do tipo FuncionarioInexistente
	 */
	Funcionario* removeFuncionario(const std::string &nomeF);
	/**
	 * Metodo que permite ordenar os funcionarios
	 * @param tipo Enumeracao do tipo tipoSort que permite ao utilizador escolher o modo de ordenacao do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenacao por ordem crescente ou decrescente
	 */
	void sortFuncionarios(enum tipoSort tipo, bool crescente);
	/**
	 * Overload do operador exportar a cadeia de farmacias
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param cF Cadeia de Farmacias que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const CadeiaFarmacias &cF);
	/**
	 * Metodo para importar a cadeia de farmacias
	 * @param f Ficheiro de onde se vai importar
	 * @param cF Cadeia de Farmacias que se quer exportar
	 */
	friend void import(std::ifstream &f, CadeiaFarmacias &cF);
};

#endif
