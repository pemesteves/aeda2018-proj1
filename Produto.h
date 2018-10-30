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
	void changePreco(float Preco);
};


class Medicamento : public Produto {
private:
	bool vendaSemReceita;

public:
	Medicamento(bool receita, double cod, std::string nome, int preco, std::string desc);
	bool getVendaSemReceita() const;
	void setVendaSemReceita(bool VendaSemReceita);

};

class PassivelReceita : public Medicamento {
private:
	float taxaDesconto;
	bool semReceita;

public:
	PassivelReceita(int desconto, bool semReceita);
	PassivelReceita(int desconto, double cod, std::string nome, int preco, std::string desc);
	float getTaxaDesconto() const;
	void setTaxaDesconto(float TaxaDesconto);
};



#endif
