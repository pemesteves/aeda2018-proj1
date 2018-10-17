#ifndef FARMACIA_H
#define FARMACIA_H

class Farmacia {

private:
	string Nome;
	string Morada;

	vector<Produto*> ProdutosVender;
	vector<Venda*> Vendas;
	bool EntregaDomicilios;
	vector<Carrinha*> Carrinhas;

public:
	Nome getNome();

	Morada getMorada();

	Gerente getGerente();

	ProdutosVender getProdutosVender();

	void addProdutosVender(vector<Produto*> ProdutosVender);

	Vendas getVendas();

	void addVenda(vector<Venda*> Venda);

	EntregaDomicilios getDomicilios();

	Farmacia(string Nome, string Morada, bool EntregaDomicilios);

	bool existeProduto(string NomeProduto);

	bool carrinhasDisponiveis();
};

#endif
