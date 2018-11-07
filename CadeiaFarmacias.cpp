#include "CadeiaFarmacias.h"

using namespace std;

CadeiaFarmacias::CadeiaFarmacias() {}

unsigned int CadeiaFarmacias::getNumFarmacias() const {
	return farmacias.size();
}

unsigned int CadeiaFarmacias::getNumClientes() const {
	return clientes.size();
}

unsigned int CadeiaFarmacias::getNumFuncionarios() const {
	return funcionarios.size();
}

vector<Farmacia *> CadeiaFarmacias::getFarmacias() const {
	return farmacias;
}

vector <Cliente*>  CadeiaFarmacias::getClientes() const {
	return clientes;
}

vector <Funcionario*> CadeiaFarmacias::getFuncionarios() const {
	return funcionarios;
}

void CadeiaFarmacias::addFarmacia(Farmacia* farmacia) {
	farmacias.push_back(farmacia);
}

Farmacia* CadeiaFarmacias::removeFarmacia(const string &nomeF){
	vector<Farmacia*>::iterator it = farmacias.begin();
	for (; it != farmacias.end(); it++){
		if ((*it)->getNome() == nomeF){
			farmacias.erase(it);
			vector<Funcionario*>::iterator itFunc = funcionarios.begin();
			for(; itFunc != funcionarios.end(); itFunc++){
				Farmacia* f = (*itFunc)->getFarmacia();
				if (nomeF == f->getNome())
					(*itFunc)->setFarmacia(NULL);
			}
			return *it;
		}
	}
	throw FarmaciaInexistente(nomeF);
}

void CadeiaFarmacias::sortFarmacias(){
	sort(farmacias.begin(), farmacias.end(), funcSort<Farmacia>);
}

void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente);
}

Cliente* CadeiaFarmacias::removeCliente(const std::string &nomeC){
	vector<Cliente*>::iterator it = clientes.begin();
	for(; it != clientes.end(); it++){
		if ((*it)->getNome() == nomeC){
			clientes.erase(it);
			return *it;
		}
	}
	throw ClienteInexistente(nomeC);
}

void CadeiaFarmacias::sortClientes(){
	sort(clientes.begin(), clientes.end(), funcSort<Cliente>);
}

void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}

Funcionario* CadeiaFarmacias::removeFuncionario(const std::string &nomeF){
	vector<Funcionario*>::iterator it = funcionarios.begin();
	for(; it != funcionarios.end(); it++){
		if ((*it)->getNome() == nomeF){
			funcionarios.erase(it);
			return *it;
		}
	}
	throw FuncionarioInexistente(nomeF);
}

void CadeiaFarmacias::sortFuncionarios(){
	sort(funcionarios.begin(), funcionarios.end(), funcSort<Funcionario>);
}



