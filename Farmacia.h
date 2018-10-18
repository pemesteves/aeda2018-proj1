#ifndef FARMACIA_H
#define FARMACIA_H

class Farmacia {

private:
	string nome;
	string morada;

	vector<Produto*> produtosVender;
	vector<Venda*> vendas;
	bool entregaDomicilios;
	vector<Carrinha*> carrinhas;
	Funcionario* gerente;

public:
	string getNome();

	string getMorada();

	Funcionario* getGerente();

	vector<Produto*> getProdutosVender();

	void addProdutosVender(vector<Produto*> produtosVender);

	vector<Venda*> getVendas();

	void addVenda(Venda* venda);

	bool getDomicilios();

	Farmacia(string nome, string morada, bool entregaDomicilios);

	bool existeProduto(string nomeProduto);

	bool carrinhasDisponiveis();

	void setGerente(Funcionario* gerente);

	Carrinha* getCarrinha(bool disponibilidade);

	void addCarrinha(Carrinha* carrinha);

	unsigned int numCarrinhas();

	unsigned int numProdutos();

	unsigned int numVendas();

	unsigned int numVendasTempo(Data d1, Data d2);

	unsigned int numVendasDia(Data d);

	int precoProduto(string nomeProd);

	void setGerente(Funcionario* gerente);

	void addCarrinha(Carrinha* carrinha);

	void setGerente(Funcionario* gerente);

	void addCarrinha(Carrinha* carrinha);
};

#endif
