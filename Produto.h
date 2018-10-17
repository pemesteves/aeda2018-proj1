#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {

private:
	double Codigo;
	string Nome;
	int Preco;
	string Descricao;

public:
	double getCodigo();

	string getNome();

	int getPreco();

	void changePreco(int Preco);

	string getDescricao();

	Produto(double cod, string nome, int preco, string descricao);
};

#endif
