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
	Funcionario(std::string nome, std::string morada, double cont, double sal = 500, bool carta = false);
	void setFarmacia(Farmacia* f);
	double getSalario() const;
	std::string getCargo() const;
	void changeSalario(double salario);
	bool getCartaConducao() const;
	void showInfo() const;
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
};

#endif
