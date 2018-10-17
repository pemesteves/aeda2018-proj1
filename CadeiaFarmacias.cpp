#include "CadeiaFarmacias.h"

CadeiaFarmacias::CadeiaFarmacias() {

}

void CadeiaFarmacias::addFarmacia(Farmacia *farmacia){
	Farmacias.push_back(farmacia);
}

void CadeiaFarmacias::addCliente(Cliente *cliente){
	Clientes.push_back(cliente);
}

void CadeiaFarmacias::addFuncionario(Funcionario *funcionario){
	Funcionarios.push_back(funcionario);
}
