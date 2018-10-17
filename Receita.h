#ifndef RECEITA_H
#define RECEITA_H

class Receita {

private:
	double Numero;

	string Medico;
	vector<Produto*> Produtos;
	double PrecoMax;

public:
	double getNumero();

	void setNumero(double Numero);

	vector<Cliente*> getCliente();

	void setCliente(vector<Cliente*> Cliente);

	string getMedico();

	void setMedico(string Medico);

	vector<Produto*> getProdutos();

	void setProdutos(vector<Produto*> Produtos);

	double getPrecoMax();
};

#endif
