#ifndef VENDA_H
#define VENDA_H

class Venda {

private:
	map<Produto*, vector<float>> produtosVendidos;
	Data data;
	Hora hora;
	double totalVenda;

public:
	double getTotalVenda();

	Venda(string hora, string data);

	void addProduto(Produto* prod, float quant, float iva, float comparticipacao);

	unsigned int numProdutos();

	Data getData();

	Hora getHora();

	int precoProduto(string nomeProd);
};

#endif
