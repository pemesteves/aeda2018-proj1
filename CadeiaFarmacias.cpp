#include "CadeiaFarmacias.h"

using namespace std;

/**
 *  Construtor da classe
 * 	Inicializa um objeto da classe colocando todos os vetores vazios
 */
CadeiaFarmacias::CadeiaFarmacias() {
	farmacias.resize(0);
	clientes.resize(0);
	funcionarios.resize(0);
}

/**
 * Método que retorna o número de farmácias
 * @return Tamanho do vetor de farmácias(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumFarmacias() const {
	return farmacias.size();
}

/**
 * Método que retorna o número de clientes
 * @return Tamanho do vetor de clientes(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumClientes() const {
	return clientes.size();
}

/**
 * Método que retorna o número de funcionários
 * @return Tamanho do vetor de funcionários(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumFuncionarios() const {
	return funcionarios.size();
}

/**
 * Método que retorna um vetor de farmácias
 * @return Vetor farmacias (atributo da classe)
 */
vector<Farmacia *> CadeiaFarmacias::getFarmacias() const {
	return farmacias;
}

/**
 * Método que retorna um vetor de clientes
 * @return Vetor clientes (atributo da classe)
 */
vector <Cliente*>  CadeiaFarmacias::getClientes() const {
	return clientes;
}

/**
 * Método que retorna um vetor de funcionários
 * @return Vetor funcionarios (atributo da classe)
 */
vector <Funcionario*> CadeiaFarmacias::getFuncionarios() const {
	return funcionarios;
}

/**
 * Método que permite adicionar um apontador para Farmácia ao respetivo vetor
 * @param farmacia Apontador para objeto do tipo Farmacia que será adicionado ao vetor farmacias
 */
void CadeiaFarmacias::addFarmacia(Farmacia* farmacia) {
	farmacias.push_back(farmacia);
}

/**
 * Método que permite eliminar a Farmacia nomeF do respetivo vetor. Também remove o apontador Farmacia de todos os funcionarios caso seja o mesmo
 * @param nomeF Nome da farmácia que será removida do vetor
 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo FarmaciaInexistente
 */
Farmacia* CadeiaFarmacias::removeFarmacia(const string &nomeF){
	vector<Farmacia*>::iterator it = farmacias.begin();
	for (; it != farmacias.end(); it++){ //Percorrer o vetor farmacias
		if ((*it)->getNome() == nomeF){
			farmacias.erase(it); //Eliminar o elemento pretendido
			vector<Funcionario*>::iterator itFunc = funcionarios.begin();
			for(; itFunc != funcionarios.end(); itFunc++){ //Percorrer o vetor funcionarios
				Farmacia* f = (*itFunc)->getFarmacia();
				if (nomeF == f->getNome()) //Se a Farmacia a eliminar é igual à Farmacia onde trabalha o Funcionario, esta é apagada
					(*itFunc)->setFarmacia(NULL);
			}
			return *it;
		}
	}
	throw FarmaciaInexistente(nomeF); //Lançamento de uma exceção caso a Farmacia não exista
}

/**
 * Método que permite ordenar as farmácias
 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortFarmacias(enum tipoSort tipo, bool crescente){
	//sort(farmacias.begin(), farmacias.end(), funcSort<Farmacia>);
	quickSort(farmacias, 0, farmacias.size()-1, tipo, crescente);
}

/**
 * Método que permite adicionar um apontador para Cliente ao respetivo vetor
 * @param cliente Apontador para objeto do tipo Cliente que será adicionado ao vetor clientes
 */
void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente);
}

/**
 * Método que permite eliminar o Cliente nomeC do respetivo vetor
 * @param nomeC Nome do cliente que será removido do vetor
 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo ClienteInexistente
 */
Cliente* CadeiaFarmacias::removeCliente(const std::string &nomeC){
	vector<Cliente*>::iterator it = clientes.begin();
	for(; it != clientes.end(); it++){ //Percorrer o vetor clientes
		if ((*it)->getNome() == nomeC){
			clientes.erase(it);
			return *it;
		}
	}
	throw ClienteInexistente(nomeC); //Lançamento de uma exceção caso o cliente não exista
}

/**
 * Método que permite ordenar os clientes
 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortClientes(enum tipoSort tipo, bool crescente){
	//sort(clientes.begin(), clientes.end(), funcSort<Cliente>);
	quickSort(clientes, 0, clientes.size()-1, tipo, crescente);
}

/**
 * Método que permite adicionar um apontador para Funcionario ao respetivo vetor
 * @param funcionario Apontador para objeto do tipo Funcionario que será adicionado ao vetor funcionarios
 */
void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}

/**
 * Método que permite eliminar o Funcionario nomeF do respetivo vetor
 * @param nomeF Nome do funcionario que será removido do vetor
 * @return Retorna um apontador para o objeto removido ou, se este não existir, lança uma exceção do tipo FuncionarioInexistente
 */
Funcionario* CadeiaFarmacias::removeFuncionario(const std::string &nomeF){
	vector<Funcionario*>::iterator it = funcionarios.begin();
	for(; it != funcionarios.end(); it++){//Percorrer o vetor de funcionarios
		if ((*it)->getNome() == nomeF){
			funcionarios.erase(it);
			return *it;
		}
	}
	throw FuncionarioInexistente(nomeF); //Lançamento de uma exceção caso o funcionario não exista
}

/**
 * Método que permite ordenar os funcionários
 * @param tipo Enumeração do tipo tipoSort que permite ao utilizador escolher o modo de ordenação do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordenação por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortFuncionarios(enum tipoSort tipo, bool crescente){
	//sort(funcionarios.begin(), funcionarios.end(), funcSort<Funcionario>);
	quickSort(funcionarios, 0, funcionarios.size()-1, tipo, crescente);
}



