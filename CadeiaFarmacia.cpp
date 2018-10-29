#include "CadeiaFarmacias.h"

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

std::vector<Farmacia *> CadeiaFarmacias::getFarmacias() const {
	return farmacias;
}

std::vector <Cliente*>  CadeiaFarmacias::getClientes() const {
	return clientes;
}

std::vector <Funcionario*> CadeiaFarmacias::getFuncionarios() const {
	return funcionarios;
}

void CadeiaFarmacias::addFarmacia(Farmacia* farmacia) {
	farmacias.push_back(farmacia);
}

void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente);
}

void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}