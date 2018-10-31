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

//Cliente
Cliente::Cliente(string nome, string morada, double contribuinte): Pessoa(nome, morada, contribuinte) {
}

vector<Venda*> Cliente::getHistorialCompras() const {
	return historialCompras;
}

unsigned int Cliente::getNumCompras() const {
	return historialCompras.size();
}

void Cliente::addCompra(Venda* compra) {
	historialCompras.push_back(compra);
}

void Cliente::showInfo() const {
	cout << "Cliente" << endl << setw(10);
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
	cout << "Contribuinte: " << noContribuinte << endl;
}

bool Cliente::operator< (const Cliente &c1){
	if (nome < c1.getNome())
		return true;
	if (nome == c1.getNome() && historialCompras.size() > c1.getHistorialCompras().size())
		return true;
	if (nome == c1.getNome() && historialCompras.size() == c1.getHistorialCompras().size() && noContribuinte < c1.getNoContribuinte())
		return true;
	return false;
}



