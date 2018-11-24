#include "CadeiaFarmacias.h"

using namespace std;

template <> enum tipoSort sorting<Farmacia>::tipo = DEFAULT;
template <> bool sorting<Farmacia>::crescente = false;
template <> enum tipoSort sorting<Funcionario>::tipo = DEFAULT;
template <> bool sorting<Funcionario>::crescente = false;
template <> enum tipoSort sorting<Cliente>::tipo = DEFAULT;
template <> bool sorting<Cliente>::crescente = false;

CadeiaFarmacias::CadeiaFarmacias() {
	this->nome = ""; //Inicializacao de um nome vazio
	farmacias.resize(0); //Vetor de farmacias vazio
	clientes.resize(0); //Vetor de clientes vazio
	funcionarios.resize(0); //Vetor de funcionarios vazio
}

CadeiaFarmacias::CadeiaFarmacias(std::string nome) {
	this->nome=nome; //Inicializacao de uma cadeia com nome
	farmacias.resize(0); //Vetor de farmacias vazio
	clientes.resize(0); //Vetor de clientes vazio
	funcionarios.resize(0); //Vetor de funcionarios vazio
}

void CadeiaFarmacias::setNome(string nome){
	this->nome = nome;
}

string CadeiaFarmacias::getNome() const{
	return nome;
}

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
	for (; it != farmacias.end(); it++){ //Percorrer o vetor farmacias
		if ((*it)->getNome() == nomeF){
			farmacias.erase(it); //Eliminar o elemento pretendido
			vector<Funcionario*>::iterator itFunc = funcionarios.begin();
			for(; itFunc != funcionarios.end(); itFunc++){ //Percorrer o vetor funcionarios
				Farmacia* f = (*itFunc)->getFarmacia();
				if (nomeF == f->getNome()) //Se a Farmacia a eliminar e igual a Farmacia onde trabalha o Funcionario, esta e apagada
					(*itFunc)->setFarmacia(NULL);
			}
			return *it;
		}
	}
	throw FarmaciaInexistente(nomeF); //Lancamento de uma excecao caso a Farmacia nao exista
}

void CadeiaFarmacias::sortFarmacias(enum tipoSort tipo, bool crescente){
	sorting<Farmacia> s;
	sorting<Farmacia>::tipo = tipo;
	sorting<Farmacia>::crescente = crescente;
	s.sort_p(farmacias);
}

void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente); //Adicionar um apontador para cliente ao vetor
}

Cliente* CadeiaFarmacias::removeCliente(const std::string &nomeC){
	vector<Cliente*>::iterator it = clientes.begin();
	for(; it != clientes.end(); it++){ //Percorrer o vetor clientes
		if ((*it)->getNome() == nomeC){
			clientes.erase(it);
			return *it;
		}
	}
	throw ClienteInexistente(nomeC); //Lançamento de uma excecao caso o cliente nao exista
}

void CadeiaFarmacias::sortClientes(enum tipoSort tipo, bool crescente){
	sorting<Cliente> s;
	sorting<Cliente>::tipo = tipo;
	sorting<Cliente>::crescente = crescente;
	s.sort_p(clientes);
}

void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}

Funcionario* CadeiaFarmacias::removeFuncionario(const std::string &nomeF){
	vector<Funcionario*>::iterator it = funcionarios.begin();
	for(; it != funcionarios.end(); it++){//Percorrer o vetor de funcionarios
		if ((*it)->getNome() == nomeF){
			funcionarios.erase(it);
			return *it;
		}
	}
	throw FuncionarioInexistente(nomeF); //Lancamento de uma excecao caso o funcionario nao exista
}

void CadeiaFarmacias::sortFuncionarios(enum tipoSort tipo, bool crescente){
	sorting<Funcionario> s;
	sorting<Funcionario>::tipo = tipo;
	sorting<Funcionario>::crescente = crescente;
	s.sort_p(funcionarios);
}

std::ostream& operator<<(std::ostream &output, const CadeiaFarmacias &cF){
	output << cF.farmacias.size() << endl;
	for(size_t i = 0; i < cF.farmacias.size(); i++){
		output << cF.farmacias[i] << endl;
	}
	output << cF.clientes.size() << endl;
	for(size_t i = 0; i < cF.clientes.size(); i++){
		output << cF.clientes[i] << endl;
	}
	output << cF.funcionarios.size() << endl;
	for(size_t i = 0; i < cF.funcionarios.size(); i++){
		output << cF.funcionarios[i] << endl;
	}
	return output;
}

void import(fstream &f, CadeiaFarmacias &cF){
	string line;
	getline(f, line);
	size_t numVars = stoi(line);
	vector<double> gerentes;
	vector<double> diretoresTecnicos;
	vector<double> clientesReceitas;
	vector<double> clientes;

	string nome, morada;
	double contribuinte;
	while(numVars > 0){
		getline(f, nome);
		getline(f, morada);
		Farmacia *farm = new Farmacia(nome, morada);
		getline(f, nome);
		if(nome == "NULL"){
			gerentes.push_back(0);
			farm->setGerente(NULL);
		}
		else{
			contribuinte = stod(nome);
			gerentes.push_back(contribuinte);
		}

		getline(f, nome);
		if(nome == "NULL"){
			diretoresTecnicos.push_back(0);
			farm->setDiretorTecnico(NULL);
		}
		else{
			contribuinte = stod(nome);
			diretoresTecnicos.push_back(contribuinte);
		}

		getline(f, line);
		size_t numProd = stoi(line);

		double codigo;
		float desconto, preco;
		bool pasReceita, vendaSemReceita;
		int quantidade;
		while(numProd > 0){
			getline(f, line);
			quantidade = stoi(line); //quantidade do produto: segundo campo do map
			getline(f, line);
			codigo = stod(line);
			getline(f, nome);
			getline(f, line);
			preco = stof(line);
			getline(f, morada); //morada tera a descricao
			getline(f, line);
			pasReceita = (bool)stoi(line);
			getline(f, line);
			vendaSemReceita = (bool)stoi(line);
			getline(f, line);
			desconto = stof(line);
			Produto *p = new Produto(codigo, nome, preco, morada, pasReceita, desconto, vendaSemReceita);
			farm->addProdutoVender(p);
			farm->setQuantidade(nome, quantidade);
			numProd--;
		}

		getline(f, line);
		numProd = stoi(line); //numProd tera o numero de vendas
		int dia, mes, ano, hora, minutos, segundos;
		while(numProd > 0){
			getline(f, line); //line tera: codigo data hora
			codigo = stod(line.substr(0, line.find(" ")));
			line = line.substr(line.find(" ") + 1); //line tera: hora data
			dia = stoi(line.substr(0, line.find("/")));
			line = line.substr(line.find("/") + 1); //line tera: mes/ano hora:minutos:segundos
			mes = stoi(line.substr(0, line.find("/")));
			line = line.substr(line.find("/") + 1); //line tera: ano hora:minutos:segundos
			ano = stoi(line.substr(0, line.find(" ")));
			line = line.substr(line.find(" ") + 1); //line tera: hora:minutos:segundos
			hora = stoi(line.substr(0, line.find(":")));
			line = line.substr(line.find(":") + 1); //line tera: minutos:segundos
			minutos = stoi(line.substr(0, line.find(":")));
			line = line.substr(line.find(":") + 1); //line tera: segundos
			segundos = stoi(line);

			getline(f, line);
			clientes.push_back(stod(line));
			Venda *v = new Venda(dia, mes, ano, hora, minutos, segundos, codigo);

			getline(f, line);
			if(line == "NULL"){
				v->setReceita(NULL);
				clientesReceitas.push_back(0);
			}
			else{
				double numeroRec = stod(line);
				getline(f, morada); //morada tera o nome do medico
				getline(f, line);
				clientesReceitas.push_back(stod(line));
				Receita *r = new Receita(numeroRec, morada, NULL); //default para Cliente* é NULL-> sera alterado depois
				getline(f, line);
				size_t numProdutos = stoi(line);
				Produto *produto = NULL;
				while(numProdutos > 0){
					getline(f, line);
					codigo = stod(line); //codigo tera o codigo do Produto
					getline(f, line);
					numeroRec = stod(line); //numeroRec tera a quantidade do Produto
					*produto = farm->getProduto(codigo);
					r->addProduto(produto, numeroRec);
					numProdutos--;
				}
				v->setReceita(r);
			}

			size_t num;
			getline(f, line);
			getline(f, line);
			num = stoi(line); //total da venda

			while(num > 0){
				getline(f, line);
				codigo = stod(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				preco = stof(line.substr(0, line.find(" "))); //preco guarda a quantidade do produto
				line = line.substr(line.find(" ") + 1);
				desconto = stof(line.substr(0, line.find(" "))); //desconto guarda o valor do iva
				Produto *p = NULL;
				*p = farm->getProduto(codigo);
				v->addProduto(p, preco, desconto);
				num--;
			}
			farm->addVenda(v);
			numProd--;
		}

		cF.farmacias.push_back(farm);
		numVars--;
	}

	numVars = 0;
	getline(f, line);
	numVars = stoi(line);
	while(numVars > 0){ //Importar Clientes
		getline(f, nome);
		getline(f, line);
		contribuinte = stod(line);
		getline(f, morada);
		Cliente *c = new Cliente(nome, morada, contribuinte);
		size_t numCompras = 0;
		getline(f, line);
		numCompras = stoi(line);
		while(numCompras > 0){
			getline(f, line);
			contribuinte = stod(line); //contribuinte terá o código da Venda
			Venda *v = NULL;
			for(vector<Farmacia *>::iterator it = cF.farmacias.begin(); it != cF.farmacias.end(); it++){
				v = (*it)->getVenda(contribuinte);
				if(v != NULL)
					break;
			}
			c->addCompra(v);
			numCompras--;
		}

		cF.addCliente(c);
		numVars--;
	}

	numVars = 0;
	getline(f, line);
	numVars = stoi(line);
	string cargo;
	while(numVars > 0){ //Importar Funcionários
		getline(f, nome);
		getline(f, line);
		contribuinte = stod(line);
		getline(f, morada);
		Funcionario *func = new Funcionario(nome, morada, contribuinte);
		getline(f, line);
		nome = line.substr(0, line.find("-")); //nome conterá o cargo do Funcionário
		func->setCargo(nome);
		line = line.substr(line.find("-") + 1);
		contribuinte = stod(line); //contribuinte conterá o salário do Funcionário
		func->changeSalario(contribuinte);
		getline(f, nome); //nome conterá o nome da Farmácia onde trabalha o Funcionário
		Farmacia *farm = NULL;
		for(vector<Farmacia*>::iterator it = cF.farmacias.begin(); it != cF.farmacias.end(); it++){
			if ((*it)->getNome() == nome){
				farm = (*it);
				break;
			}
		}
		func->setFarmacia(farm);
		cF.addFuncionario(func);
		numVars--;
	}

	for(size_t i = 0; i < cF.farmacias.size(); i++){
		if(gerentes[i] != 0){
			for(vector<Funcionario *>::iterator it = cF.funcionarios.begin(); it != cF.funcionarios.end(); it++){
				if((*it)->getNoContribuinte() == gerentes[i]){
					cF.farmacias[i]->setGerente(*it);
					break;
				}
			}
		}

		if(diretoresTecnicos[i] != 0){
			for(vector<Funcionario *>::iterator it = cF.funcionarios.begin(); it != cF.funcionarios.end(); it++){
				if((*it)->getNoContribuinte() == diretoresTecnicos[i]){
					cF.farmacias[i]->setDiretorTecnico(*it);
					break;
				}
			}
		}
		vector<Venda *> v = cF.farmacias[i]->getVendas();
		for(size_t j = 0; j < v.size(); j++){
			if(clientesReceitas[j] != 0){
				for(vector<Cliente *>::iterator it = cF.clientes.begin(); it != cF.clientes.end(); it++){
					if((*it)->getNoContribuinte() == clientesReceitas[j]){
						v[j]->setCliente(*it);
						break;
					}
				}
			}

			if(clientes[j] != 0){
				for(vector<Cliente *>::iterator it = cF.clientes.begin(); it != cF.clientes.end(); it++){
					if((*it)->getNoContribuinte() == clientes[j]){
						Receita *r;
						r = v[j]->getReceita();
						r->setCliente(*it);
						v[j]->setReceita(r);
						break;
					}
				}
			}

		}
		cF.farmacias[i]->setVendas(v);
	}
}


