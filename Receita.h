#ifndef RECEITA_H
#define RECEITA_H

class Receita {

private:
	double numero;

	string medico;
	vector<Produto*> produtos;
	double precoMax;
	Cliente* cliente;

public:
	double getNumero();

	void setNumero(double numero);

	vector<Cliente*> getCliente();

	void setCliente(vector<Cliente*> cliente);

	string getMedico();

	void setMedico(string medico);

	vector<Produto*> getProdutos();

	void setProdutos(vector<Produto*> produtos);

	double getPrecoMax();

	Receita(double numero, string medico, Cliente* cliente, double preco);

	Receita(double numero, string medico, Cliente* cliente, double preco);

	Receita(double numero, string medico, Cliente* cliente, double preco);
};

#endif
