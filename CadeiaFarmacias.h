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
	CadeiaFarmacias(); //Construtor da classe
	unsigned int getNumFarmacias() const; //Método que retorna o número de farmácias
	unsigned int getNumClientes() const; //Método que retorna o número de clientes
	unsigned int getNumFuncionarios() const; //Método que retorna o número de funcionários
	std::vector<Farmacia *> getFarmacias() const; //Método que retorna um vetor de farmácias
	std::vector <Cliente*> getClientes() const; //Método que retorna um vetor de clientes
	std::vector <Funcionario*> getFuncionarios() const; //Método que retorna um vetor de funcionários
	void addFarmacia(Farmacia* farmacia); //Método que permite adicionar um apontador para Farmácia ao respetivo vetor
	Farmacia* removeFarmacia(const std::string &nomeF); //Método que permite eliminar a Farmácia nomeF do respetivo vetor
	void sortFarmacias(enum tipoSort tipo, bool crescente); //Método que permite ordenar as farmácias
	void addCliente(Cliente* cliente); //Método que permite adicionar um apontador para Cliente ao respetivo vetor
	Cliente* removeCliente(const std::string &nomeC); //Método que permite eliminar o Cliente nomeC do respetivo vetor
	void sortClientes(enum tipoSort tipo, bool crescente); //Método que permite ordenar os clientes
	void addFuncionario(Funcionario* funcionario); //Método que permite adicionar um apontador para Funcionario ao respetivo vetor
	Funcionario* removeFuncionario(const std::string &nomeF); //Método que permite eliminar o Funcionario nomeF do respetivo vetor
	void sortFuncionarios(enum tipoSort tipo, bool crescente); //Método que permite ordenar os funcionários
};

#endif
