#include "Pessoa.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Pessoa
Pessoa::Pessoa(string nome, string morada, double cont) {
	this->nome = nome;
	this->morada = morada;
	this->noContribuinte = cont;
}

string Pessoa::getNome() const {
	return nome;
}

string Pessoa::getMorada() const {
	return morada;
}

double Pessoa::getNoContribuinte() const {
	return noContribuinte;
}
/*
class Funcionario : public Pessoa {
private:
	double salario;
	Farmacia* farmaciaTrabalho;
	std::string cargo;
	bool cartaConducao;

public:
	Funcionario(std::string nome, std::string morada, double cont, double sal = 500, bool carta = false);
	double getSalario() const;
	std::string getCargo() const;
	void changeSalario(double salario);
	bool getCartaConducao();
	void showInfo() const;
};*/
//Funcionario
Funcionario::Funcionario(string nome, string morada, double cont, double sal = 500, bool carta = false): Pessoa(nome, morada, cont){
	salario = sal;
	cargo = "Funcionario";
	cartaConducao = false;
	farmaciaTrabalho = NULL;
}

double Funcionario::getSalario() const{
	return salario;
}

string Funcionario::getCargo() const{
	return cargo;
}

bool Funcionario::getCartaConducao() const{
	return cartaConducao;
}

void Funcionario::changeSalario(double salario){
	this->salario = salario;
}

void Funcionario::setFarmacia(Farmacia* f){
	this->farmaciaTrabalho = f;
}

void Funcionario::showInfo() const{
	cout << "Funcionario" << endl << setw(10);
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
	cout << "Contribuinte: " << noContribuinte << endl;
	cout << "Salario: " << salario << endl;
	if (farmaciaTrabalho != NULL)
		cout << cargo << "na farmacia " << farmaciaTrabalho->getNome() << endl;

}



