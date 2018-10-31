#include "Venda.h"

using namespace std;

Venda::Venda(){
	Data d; data = d;
	Hora h; hora = h;
	totalVenda = 0;
}

double Venda::getTotalVenda() const{
	return totalVenda;
}

unsigned int Venda::getNumProdutos() const{
	return produtosVendidos.size();
}

Data Venda::getData() const{
	return data;
}

Hora Venda::getHora() const{
	return hora;
}

float Venda::getPrecoProduto(string nomeProd) const{
	map<Produto *, vector<float>>::const_iterator it = produtosVendidos.begin();
	for (; it != produtosVendidos.end(); it++){
		if ((*it).first->getNome() == nomeProd)
			return (*it).first->getPreco();
	}
	return -1; //Se não houver um produto com o nome = nomeProd, retorna -1
}

void Venda::addProduto(Produto* prod, float quant, float iva, float comparticipacao){
	map<Produto *, vector<float>>::iterator it;
	if ((it = produtosVendidos.find(prod)) != produtosVendidos.end()){
		(*it).second[0] += quant;
	}
	else{
		vector<float> v = {quant, iva, comparticipacao};
		pair<Produto*, vector<float>> p;
		p = make_pair(prod, v);
		produtosVendidos.insert(p);
	}
}

bool Venda::operator< (const Venda &v1){
	if (data < v1.getData())
		return true;
	if (data== v1.getData() && hora < v1.getHora())
		return true;
	return false;
}


