#include "Pessoa.h"
#include <iostream>
#include <iomanip>
#include <cctype>

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

void Pessoa::setNome(string nome){
	this->nome = nome;
}

void Pessoa::setMorada(string morada){
	this->morada = morada;
}

void Pessoa::setNoContribuinte(double no){
	noContribuinte = no;
}

std::ostream& operator<<(std::ostream &output, const Pessoa &p){
	output << p.nome << endl;
	output << p.noContribuinte << endl;
	output << p.morada << endl;
	return output;
}

//Funcionario
Funcionario::Funcionario(string nome, string morada, double cont, double sal): Pessoa(nome, morada, cont){
	this->salario = sal;
	this->cargo = "Funcionario";
	this->farmaciaTrabalho = NULL;
}

double Funcionario::getSalario() const{
	return salario;
}

string Funcionario::getCargo() const{
	return cargo;
}

void Funcionario::changeSalario(double salario){
	this->salario = salario;
}

void Funcionario::setFarmacia(Farmacia* f){
	string cargo1 = toupperstring(cargo);
	if (cargo1 == "GERENTE"){
		farmaciaTrabalho->setGerente(NULL);
		f->setGerente(this);
	}
	else if (cargo1 == "DIRETOR TECNICO" || cargo1 == "DIRETOR TÉCNICO"){
		farmaciaTrabalho->setDiretorTecnico(NULL);
		f->setDiretorTecnico(this);
	}
	this->farmaciaTrabalho = f;
}

void Funcionario::setCargo(string cargo){
	string cargo1 = toupperstring(cargo);
	if (cargo1 == "GERENTE"){
		if(farmaciaTrabalho->getGerente()->getNoContribuinte()==this->noContribuinte){
			this->cargo = cargo1;
			return;
		}
		else{
			farmaciaTrabalho->setGerente(this);
			return;
		}
	}
	else if (cargo1 == "DIRETOR TECNICO" || cargo1 == "DIRETOR TÉCNICO"){
		if(farmaciaTrabalho->getDiretorTecnico()->getNoContribuinte()==this->noContribuinte){
			this->cargo = cargo1;
			return;
		}
		else{
			farmaciaTrabalho->setDiretorTecnico(this);
			return;
		}
	}
	this->cargo = cargo1;
}

void Funcionario::showInfo() const{
	cout << "Funcionario" << endl << setw(10);
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
	cout << "Contribuinte: " << to_string(noContribuinte).substr(0, to_string(noContribuinte).find('.')) << endl;
	cout << "Salario: " << salario << endl;
	if (farmaciaTrabalho != NULL)
		cout << cargo << " na farmacia " << farmaciaTrabalho->getNome() << endl;
}

bool Funcionario::operator< (const Funcionario &f1) const{
	if(nome < f1.getNome())
		return true;
	if (nome == f1.getNome() && salario > f1.getSalario())
		return true;
	if (nome == f1.getNome() && salario == f1.getSalario() && noContribuinte < f1.getNoContribuinte())
		return true;
	return false;
}

std::ostream& operator<<(std::ostream &output, const Funcionario &f){
	output << static_cast<const Pessoa&>(f);
	output << f.cargo  << " - " << f.salario << endl;
	output << f.farmaciaTrabalho->getNome();
	return output;
}

//Cliente
Cliente::Cliente(string nome, string morada, double contribuinte): Pessoa(nome, morada, contribuinte) {
	historialCompras.clear();
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

bool Cliente::operator< (const Cliente &c1) const{
	if (nome < c1.getNome())
		return true;
	if (nome == c1.getNome() && historialCompras.size() > c1.getHistorialCompras().size())
		return true;
	if (nome == c1.getNome() && historialCompras.size() == c1.getHistorialCompras().size() && noContribuinte < c1.getNoContribuinte())
		return true;
	return false;
}

bool Funcionario::menorQue(const Funcionario &f1, enum tipoSort tipo, bool crescente) const{
	switch(tipo){
	case NOME:
		if (crescente)
			return nome < f1.getNome();
		else
			return nome > f1.getNome();
		break;
	case CONTRIBUINTE:
		if (crescente)
			return noContribuinte < f1.getNoContribuinte();
		else
			return noContribuinte > f1.getNoContribuinte();
		break;
	case SALARIO:
		if (crescente)
			return salario < f1.getSalario();
		else
			return salario > f1.getSalario();
		break;
	default:
		return (*this) < f1;
		break;
	}
}

bool Cliente::menorQue(const Cliente &c1, enum tipoSort tipo, bool crescente) const{
	switch(tipo){
	case NOME:
		if (crescente)
			return nome < c1.getNome();
		else
			return nome > c1.getNome();
		break;
	case CONTRIBUINTE:
		if (crescente)
			return noContribuinte < c1.getNoContribuinte();
		else
			return noContribuinte > c1.getNoContribuinte();
		break;
	case NUM_VENDA:
		if (crescente)
			return historialCompras.size() < c1.getNumCompras();
		else
			return historialCompras.size() > c1.getNumCompras();
		break;
	default:
		return (*this) < c1;
		break;
	}
}

std::ostream& operator<<(std::ostream &output, const Cliente &c){
	output << static_cast<const Pessoa&>(c);
	for (size_t i = 0; i < c.historialCompras.size(); i++){
		output << c.historialCompras[i]->getCodigo() << endl;
	}
	return output;
}


