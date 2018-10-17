#ifndef PASSIVELRECEITA_H
#define PASSIVELRECEITA_H

class PassivelReceita : Medicamento {

public:
	int TaxaDesconto;

	int getTaxaDesconto();

	void setTaxaDesconto(int TaxaDesconto);

	PassivelReceita(int desconto, bool semReceita);

	PassivelReceita(int desconto, double cod, string nome, int preco, string descsc);
};

#endif
