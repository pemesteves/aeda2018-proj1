#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class Medicamento : Produto {

public:
	bool vendaSemReceita;

	bool getVendaSemReceita();

	void setVendaSemReceita(bool VendaSemReceita);

	Medicamento(bool receita, double cod, string nome, int preco, string desc);
};

#endif
