/**
 * Header File que contém a classe CadeiaFarmacias.
 *
 * @author Márcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

#include "Farmacia.h"
#include <vector>

/**
 * Classe CadeiaFarmacias
 */
class CadeiaFarmacias {
private:
	std::vector<Farmacia *> farmacias; //Vetor de apontadores para objetos do tipo Farmacia
	std::vector <Cliente*> clientes; //Vetor de apontadores para objetos do tipo Cliente
	std::vector <Funcionario*> funcionarios; //Vetor de apontadores para objetos do tipo Funcionario
public:
	/**
	 *  Construtor da classe
	 * 	Inicializa um objeto da classe colocando todos os vetores vazios
	 */
	CadeiaFarmacias();
	/**
	 * Método que retorna o número de farmácias
	 * @return Tamanho do vetor de farmácias(unsigned int)
	 */
	unsigned int getNumFarmacias() const;
	/**
	 * Método que retorna o número de clientes
	 * @return Tamanho do vetor de clientes(unsigned int)
	 */
	unsigned int getNumClientes() const;
	/**
	 * Método que retorna o número de funcionários
	 * @return Tamanho do vetor de funcionários(unsigned int)
	 */
	unsigned int getNumFuncionarios() const;
	/**
	 * Método que retorna um vetor de farmácias
	 * @return Vetor farmacias (atributo da classe)
	 */
	std::vector<Farmacia *> getFarmacias() const;
	/**
	 * Método que retorna um vetor de clientes
	 * @return Vetor clientes (atributo da classe)
	 */
	std::vector <Cliente*> getClientes() const;
	/**
	 * Método que retorna um vetor de funcionários
	 * @return Vetor funcionarios (atributo da classe)
	 */
	std::vector <Funcionario*> getFuncionarios() const;
	/**
	 * Método que permite adicionar um apontador para Farmácia ao respetivo vetor
	 * @param farmacia Apontador para objeto do tipo Farmacia que será adicionado ao vetor farmacias
	 */
	void addFarmacia(Farmacia* farmacia);
	/**
	 * Método que permite eliminar a Farmacia nomeF do respetivo vetor. Também remove o apontador Farmacia de todos os funcionarios caso seja o mesmo
	 * @param nomeF Nome da farmácia que será removida do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo FarmaciaInexistente
	 */
	Farmacia* removeFarmacia(const std::string &nomeF);
	/**
	 * Método que permite ordenar as farmácias
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
	 */
	void sortFarmacias(enum tipoSort tipo, bool crescente);
	/**
	 * Método que permite adicionar um apontador para Cliente ao respetivo vetor
	 * @param cliente Apontador para objeto do tipo Cliente que será adicionado ao vetor clientes
	 */
	void addCliente(Cliente* cliente);
	/**
	 * Método que permite eliminar o Cliente nomeC do respetivo vetor
	 * @param nomeC Nome do cliente que será removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo ClienteInexistente
	 */
	Cliente* removeCliente(const std::string &nomeC);
	/**
	 * Método que permite ordenar os clientes
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
	 */
	void sortClientes(enum tipoSort tipo, bool crescente);
	/**
	 * Método que permite adicionar um apontador para Funcionario ao respetivo vetor
	 * @param funcionario Apontador para objeto do tipo Funcionario que será adicionado ao vetor funcionarios
	 */
	void addFuncionario(Funcionario* funcionario);
	/**
	 * Método que permite eliminar o Funcionario nomeF do respetivo vetor
	 * @param nomeF Nome do funcionario que será removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo FuncionarioInexistente
	 */
	Funcionario* removeFuncionario(const std::string &nomeF);
	/**
	 * Método que permite ordenar os funcionários
	 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
	 */
	void sortFuncionarios(enum tipoSort tipo, bool crescente);
};

#endif
