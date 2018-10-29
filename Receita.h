#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>

class Receita {
private:
	double numero;
	std::string medico;
	std::vector<Produto*> produtos;
	double precoMax;
	Cliente* cliente;

public:
	Receita(double numero, std::string medico, Cliente* cliente, double preco);
	double getNumero() const;
	std::vector<Cliente*> getCliente() const;
	std::string getMedico() const;
	std::vector<Produto*> getProdutos() const;
	double getPrecoMax() const;
	void setNumero(double numero);
	void setCliente(std::vector<Cliente*> cliente);
	void setMedico(std::string medico);
	void setProdutos(std::vector<Produto*> produtos);
};

#endif
