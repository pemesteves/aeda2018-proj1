#ifndef VENDA_H
#define VENDA_H

#include "Data.h"
#include "Produto.h"

#include <vector>
#include <string>
#include <map>

class Venda {
private:
	std::map<Produto*, std::vector<float>> produtosVendidos;
	Data data;
	Hora hora;
	double totalVenda;

public:
	Venda();
	double getTotalVenda() const;
	unsigned int getNumProdutos() const;
	Data getData() const;
	Hora getHora() const;
	float getPrecoProduto(std::string nomeProd) const;
	void addProduto(Produto* prod, float quant, float iva, float comparticipacao);

};
/*
class Pessoa;
class Funcionario;
*/
#endif
