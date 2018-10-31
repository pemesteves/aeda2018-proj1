#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
private:
	double codigo;
	std::string nome;
	float preco;
	std::string descricao;
public:
	Produto(double cod, std::string nome, float preco, std::string descricao);
	double getCodigo() const;
	std::string getNome() const;
	float getPreco() const;
	std::string getDescricao() const;
	void changePreco(float preco);
};


class Medicamento : public Produto {
private:
	bool vendaSemReceita;

public:
	Medicamento(bool receita, double cod, std::string nome, int preco, std::string desc);
	bool getVendaSemReceita() const;
	void setVendaSemReceita(bool vendaSemReceita);

};

class PassivelReceita : public Medicamento {
private:
	float taxaDesconto;

public:
	PassivelReceita(int desconto, double cod, std::string nome, int preco, std::string desc, bool semRec = false);
	float getTaxaDesconto() const;
	void setTaxaDesconto(float taxaDesconto);
};

class ProdutoInexistente {
	std::string nome;
public:
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	std::string getNome() const { return nome; }
};


#endif
