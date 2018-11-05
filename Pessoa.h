#ifndef PESSOA_H
#define PESSOA_H

#include "Venda.h"
#include "Farmacia.h"

#include <string>
#include <vector>

class Farmacia;

class Pessoa {
protected:
	std::string nome;
	std::string morada;
	double noContribuinte;
public:
	Pessoa(std::string nome, std::string morada, double cont);
	std::string getNome() const;
	std::string getMorada() const;
	double getNoContribuinte() const;
	virtual void showInfo() const = 0;
};

class Funcionario : public Pessoa {
private:
	double salario;
	Farmacia* farmaciaTrabalho;
	std::string cargo;
	bool cartaConducao;

public:
	Funcionario(std::string nome, std::string morada, double cont, double sal, bool carta);
	void setFarmacia(Farmacia* f);
	Farmacia* getFarmacia() const {return farmaciaTrabalho;}
	double getSalario() const;
	std::string getCargo() const;
	void changeSalario(double salario);
	bool getCartaConducao() const;
	void showInfo() const;
	bool operator< (const Funcionario &f1) const;
};

class Cliente : public Pessoa {
private:
	std::vector<Venda*> historialCompras;
public:
	Cliente(std::string nome, std::string morada, double contribuinte);
	std::vector<Venda*> getHistorialCompras() const;
	unsigned int getNumCompras() const;
	void addCompra(Venda* compra);
	void showInfo() const;
	bool operator< (const Cliente &c1) const;
};

class ClienteInexistente{
	std::string nome;
public:
	ClienteInexistente(std::string nomeC){nome = nomeC;}
	std::string getNome() const {return nome;}
};

class FuncionarioInexistente{
	std::string nome;
public:
	FuncionarioInexistente(std::string nomeF){nome = nomeF;}
	std::string getNome() const {return nome;}
};

#endif
