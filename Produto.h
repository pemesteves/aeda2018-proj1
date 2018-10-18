#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {

private:
	double codigo;
	string nome;
	float preco;
	string descricao;

public:
	double getCodigo();

	string getNome();

	float getPreco();

	void changePreco(float Preco);

	string getDescricao();

	Produto(double cod, string nome, float preco, string descricao);
};

#endif
