#ifndef PESSOA_H
#define PESSOA_H

#include "Vendas.h"
#include "Farmacia.h"

#include <string>
#include <vector>

class Pessoa {
private:
	std::string nome;
	std::string morada;
	double noContribuinte;

public:
	Pessoa(std::string nome, std::string morada, double cont);
	std::string getNome() const;
	std::string getMorada() const;
	double getNoContribuinte() const;

};

class Funcionario : public Pessoa {
private:
	double salario;
	Farmacia* farmaciaTrabalho;
	std::string cargo;
	//bool cartaConducao;

public:
	Funcionario(std::string nome, std::string morada, double noContribuinte);
	double getSalario() const;
	std::string getCargo() const;
	void setNoContribuinte(double noContribuinte);
	//bool getCartaConducao();

};

class Cliente : public Pessoa {
private:
	std::vector<Venda*> historialCompras;
public:
	Cliente(std::string nome, std::string morada, double contribuinte);
	std::vector<Venda*> getHistorialCompras() const;
	unsigned int getNumCompras() const;
	void addCompra(Venda* compra);
};

#endif
