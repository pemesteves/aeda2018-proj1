#ifndef VENDA_H
#define VENDA_H

class Venda {

private:
	map<Produto*, vector<float>> ProdutosVendidos;
	string Data;
	string Hora;
	double TotalVenda;

public:
	TotalVenda getTotalVenda();

	Venda(string hora, string data);

	void addProduto(Produto* prod, float quant, float iva, float comparticipacao);
};

#endif
