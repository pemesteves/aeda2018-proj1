#ifndef FARMACIA_H
#define FARMACIA_H

#include "Pessoa.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Pessoa;
class Funcionario;

class Farmacia {
private:
	std::string nome;
	std::string morada;
	Funcionario* gerente;
	Funcionario* diretorTecnico;
	std::map<Produto, int> produtosVender;
	std::vector<Venda*> vendas;
public:
	Farmacia(std::string nome, std::string morada);
	std::string getNome() const;
	std::string getMorada() const;
	Funcionario* getGerente() const;
	Funcionario* getDiretorTecnico() const;
	std::vector<Venda*> getVendas() const;
	std::map<Produto, int> getProdutosVender() const;
	unsigned int getNumProdutos() const;
	unsigned int getNumVendas() const;
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	std::vector<Venda*> getVendasTempo(Data d1, Data d2) const;
	unsigned int getNumVendasDia(Data d) const;
	std::vector<Venda*> getVendasDia(Data d) const;
	float getPrecoProduto(std::string nomeProd) const;
	void setGerente(Funcionario* gerente);	
	void setDiretorTecnico(Funcionario* diretor){diretorTecnico = diretor;}
	void addProdutosVender(std::vector<Produto*> produtosVender_new);
	bool addProdutoVender(Produto* produtoVender);
	Produto removeProduto(std::string nomeP);
	void addVenda(Venda* venda);
	void sortVendas(enum tipoSort tipo, bool crescente);
	bool existeProduto(std::string nomeProduto) const;
	bool setQuantidade(std::string nomeProd, int quant);
	bool operator< (const Farmacia &f1) const;
	bool menorQue(const Farmacia &f1, enum tipoSort tipo, bool crescente) const;
	void imprimeFatura(Venda* v) const; //Não sei se isto faz muito sentido aqui
};

class FarmaciaInexistente{
	std::string nome;
public:
	FarmaciaInexistente(std::string nomeF){nome = nomeF;}
	std::string getNome() const{return nome;}
};
/*
template<class T>
bool funcSort(T* a, T* b){
	return (*a)<(*b);
}*/

template <class Comparable>
const Comparable &median3(std::vector<Comparable*> &v, int left,
		int right, enum tipoSort tipo, bool crescente)
{
	int center = (left+right) /2;
	if (v[center]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[center]);
	if (v[right]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[right]);
	if (v[right]->menorQue(*v[center], tipo, crescente))
		std::swap(v[center], v[right]);
	//coloca pivot na posicao right-1
	std::swap(v[center], v[right-1]);
	return *v[right-1];
}


template <class Comparable>
void quickSort(std::vector<Comparable* > &v, int left, int right, enum tipoSort tipo, bool crescente)
{
	/*if (right-left <= 10)// se vetor pequeno
		insertionSort(v,left,right);
	else {*/
	Comparable x = median3(v,left,right, tipo, crescente); // x é o pivot
	int i = left; int j = right-1; // passo de partição
	for(; ; ) {
		while (v[++i]->menorQue(x, tipo, crescente)) ;
		while (x.menorQue(*v[--j], tipo, crescente)) ;
		if (i < j)
			std::swap(v[i], v[j]);
		else
			break;
	}
	std::swap(v[i], v[right-1]);//repoe pivot
	quickSort(v, left, i-1, tipo, crescente);
	quickSort(v, i+1, right, tipo, crescente);
	//}
}


#endif 
