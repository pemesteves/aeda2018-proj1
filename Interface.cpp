#include "CadeiaFarmacias.h"
#include "Data.h"
#include "Farmacia.h"
#include "Pessoa.h"
#include "Produto.h"
#include "Receita.h"
#include "util.h"
#include "Venda.h"

#include <iostream>
#include <fstream>
#include <string>

static CadeiaFarmacias cadeiaF;

void menu();

//TODO //- PASSAR PARA CADEIAFARMACIAS.H OU FARMACIAS.H
std::vector<Farmacia*>::iterator findFarmacia(std::string nomeFarmacia, std::vector<Farmacia*> farmacias ){
	std::vector<Farmacia*>::iterator it;

	for(it=farmacias.begin() ; it != farmacias.end();it++){
		if((*it)->getNome() == nomeFarmacia)
			return it;
	}
	throw FarmaciaInexistente(nomeFarmacia);
}

void menuFuncionarios(){
	int opcao;

	std::cout << "FUNCIONARIOS" << std::endl;

	std::cout << "1. Definir/modificar Gerente." << std::endl;
	std::cout << "2. Definir/modificar Diretor Técnico." << std::endl;
	std::cout << "3. Adicionar funcionário." << std::endl;
	std::cout << "4. Remover funcionário." << std::endl;
	std::cout << "5. Ordenar funcionários." << std::endl << std::endl;

	std::cout << "0. Voltar atrás." << std::endl;

	std::cout << "Opção: "; std::cin >> opcao; std::cout << std::endl;

	switch(opcao){
	case 1:
	{
		std::vector<Farmacia *> farmacias = cadeiaF.getFarmacias();
		std::string nomeFarmacia, nomeGerente, moradaGerente;
		double contribuinte, salario;
		std::vector<Farmacia *>::iterator it;
		bool valido = false;

		while(!valido){
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			std::cout << "Farmácia: "; std::cin >> nomeFarmacia;

			try{
				it = findFarmacia(nomeFarmacia, farmacias);
				valido = true;
			}catch (FarmaciaInexistente& nomeFarmacia){
				std::cerr << "Farmácia inexistente!" << std::endl;
				valido = false;
			}
		}

		std::cout << "Nome do Gerente: " ; std::cin >> nomeGerente;
		std::cout << "Morada do Gerente: "; std::cin >> moradaGerente;
		std::cout << "Nº de contribuinte: "; std::cin >> contribuinte;
		std::cout << "Salario: "; std::cin >> salario;

		Funcionario gerente(nomeGerente, moradaGerente, contribuinte, salario);

		(*it)->setGerente(&gerente);
		cadeiaF.addFuncionario(&gerente);
		break;
	}

	case 2:
	{
		std::vector<Farmacia *> farmacias = cadeiaF.getFarmacias();
		std::string nomeFarmacia, nomeDir, moradaDir;
		double contribuinte, salario;
		std::vector<Farmacia *>::iterator it;
		bool valido = false;

		while(!valido){
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			std::cout << "Farmácia: "; std::cin >> nomeFarmacia;
			valido = true;

			try{
				it = findFarmacia(nomeFarmacia, farmacias);
			} catch (FarmaciaInexistente& nomeFarmacia){
				std::cerr << "Farmácia inexistente!" << std::endl;
				valido = false;
			}
		}

		std::cout << "Nome do Diretor: " ; std::cin >> nomeDir;
		std::cout << "Morada do Diretor: "; std::cin >> moradaDir;
		std::cout << "Nº de contribuinte: "; std::cin >> contribuinte;
		std::cout << "Salario: "; std::cin >> salario;

		Funcionario diretor(nomeDir, moradaDir, contribuinte, salario);

		(*it)->setDiretorTecnico(&diretor);
		cadeiaF.addFuncionario(&diretor);
		break;
	}

	case 3:
	{
		std::string nomeFarmacia, nome, morada;
		double contribuinte, salario;


		std::cout << "Nome do Funcionario: " ; std::cin >> nome;
		std::cout << "Morada do Gerente: "; std::cin >> morada;
		std::cout << "Nº de contribuinte: "; std::cin >> contribuinte;
		std::cout << "Salario: "; std::cin >> salario;

		Funcionario funcionario(nome, morada, contribuinte, salario);

		cadeiaF.addFuncionario(&funcionario);
		break;
	}

	case 4:
	{
		std::string nomeFunc;
		std::vector<Funcionario*> funcionarios = cadeiaF.getFuncionarios();
		std::vector<Funcionario*>::iterator it;
		bool valido = false;;

		while(!valido){
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			std::cout << "Nome do funcionário a remover: " ;
			std::cin >> nomeFunc;
			bool encontrou = false;

			try{
				for(it=funcionarios.begin() ; it != funcionarios.end();it++){
					if((*it)->getNome() == nomeFunc){
						encontrou = true;
						break;
					}
				}
				if (!encontrou) throw FuncionarioInexistente(nomeFunc);
				valido = true;
			} catch (FuncionarioInexistente& nomeFunc){
				std::cerr << "Funcionário inexistente!" << std::endl;
				valido = false;
			}
		}

		cadeiaF.removeFuncionario(nomeFunc);
		break;
	}

	case 5:
	{
		std::string fator;
		std::string ordem;
		bool valido = false;
		tipoSort sort;

		std::cout << "Ordenar com base em que fator?" << std::endl;
		std::cout << "(Nome / NumProdutos / NumCompras / Default)" << std::endl;
		std::cout << "Fator: "; std::cin >> fator;

		while(!valido){
			if (fator == "Nome"){
				sort = NOME;
				valido=true;
			}
			else if (fator == "NumProdutos"){
				sort = NUM_PROD;
				valido= true;
			}
			else if (fator == "NumCompras"){
				sort = NUM_VENDA;
				valido = true;
			}
			else if (fator == "Default"){
				sort=DEFAULT;
				valido = true;
			}
			else{
				std::cin.clear();
				std::cin.ignore(100000, '\n');
				std::cerr << "Insira Nome, NumProdutos, NumCompras ou Default: ";
				std::cin >> fator;
			}
		}

		std::cout << "Ordenar por que ordem?(Crescente / Decrescente) " << std::endl;
		std::cout << "Ordem: "; std::cin >> ordem;

		valido = false;

		while(!valido){
			if(ordem=="Crescente"){
				cadeiaF.sortFarmacias(sort,1);
				valido = true;
			}
			else if(ordem == "Decrescente"){
				cadeiaF.sortFarmacias(sort,0);
				valido = true;
			}
			else{
				std::cin.clear();
				std::cin.ignore(100000, '\n');
				std::cerr << "Insira Crescente ou Decrescente: ";
				std::cin >> ordem;
			}
		}
		break;
	}

	case 0:
		menu();
		break;

	default:
		std::cerr <<"Opcao inexistente!" << std::endl;
		break;
	}
}

void menuFarmacia(){

	int opcao;

	std::cout << "FARMÁCIA" << std::endl;

	std::cout << "O que pretende fazer?" << std::endl;
	std::cout << "1. Adicionar farmácia." << std::endl;
	std::cout << "2. Remover farmácia." << std::endl;
	std::cout << "3. Ordenar farmácias." << std::endl << std::endl;

	std::cout << "4. Mostrar farmácias existentes." << std::endl;
	std::cout << "5. Mostrar dados de uma farmácia." << std::endl << std::endl;

	std::cout << "0. Voltar atrás." << std::endl;


	std::cout << "Opção: "; std::cin >> opcao; std::cout << std::endl;

	switch (opcao){
	case 1:
	{
		std::string nomeFarmacia;
		std::string moradaFarmacia;
		std::cout << "Que nome pretende dar à farmácia? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, nomeFarmacia);
		std::cout << "Qual é a morada da farmácia? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, moradaFarmacia);
		Farmacia* farmacia = new Farmacia(nomeFarmacia, moradaFarmacia);
		cadeiaF.addFarmacia(farmacia);
		break;
	}
	case 2:
	{
		std::string nomeFarmacia;
		std::cout << "Qual o nome da farmácia que pretende remover? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, nomeFarmacia);
		std::cout << std::endl;

		if(cadeiaF.getFarmacias().empty())
			std::cerr << "A cadeia de farmácias não tem nenhuma farmácia!" <<std::endl;

		else{
			try {
				cadeiaF.removeFarmacia(nomeFarmacia);
			} catch(FarmaciaInexistente& (nomeFarmacia)){
				std::cerr << "Farmácia inexistente! \n" <<std::endl;

			}
		}
		break;
	}
	case 3: //NÃO FUNCIONA
	{
		std::string fator;
		std::string ordem;
		bool valido = false;
		tipoSort sort;

		std::cout << "Ordenar com base em que fator?" << std::endl;
		std::cout << "(Nome / NumProdutos / NumCompras / Default)" << std::endl;
		std::cout << "Fator: "; std::cin >> fator;

		while(!valido){
			if (fator == "Nome"){
				sort = NOME;
				valido=true;
			}
			else if (fator == "NumProdutos"){
				sort = NUM_PROD;
				valido= true;
			}
			else if (fator == "NumCompras"){
				sort = NUM_VENDA;
				valido = true;
			}
			else if (fator == "Default"){
				sort=DEFAULT;
				valido = true;
			}
			else{
				std::cin.clear();
				std::cin.ignore(100000, '\n');
				std::cerr << "Insira Nome, NumProdutos, NumCompras ou Default: ";
				std::cin >> fator;
			}
		}

		std::cout << "Ordenar por que ordem?(Crescente / Decrescente) " << std::endl;
		std::cout << "Ordem: "; std::cin >> ordem;

		valido = false;

		while(!valido){
			if(ordem=="Crescente"){
				cadeiaF.sortFarmacias(sort,1);
				valido = true;
			}
			else if(ordem == "Decrescente"){
				cadeiaF.sortFarmacias(sort,0);
				valido = true;
			}
			else{
				std::cin.clear();
				std::cin.ignore(100000, '\n');
				std::cerr << "Insira Crescente ou Decrescente: ";
				std::cin >> ordem;
			}
		}
		break;
	}




	case 4:
	case 5:

	case 0:
		menu();
		break;
	default:
		std::cerr <<"Opcao inexistente!" << std::endl;
		break;
	}
	std::cout << std::string(3, '\n');
	menuFarmacia();
}

void merda(){
	std::cout << "CADEIA DE FARMÁCIAS" << std::endl;

	std::cout << "5. Adicionar novo cliente." << std::endl;
	std::cout << "6. Remover cliente." << std::endl;
	std::cout << "7. Ordenar clientes." << std::endl << std::endl;


	std::cout << "3. Adicionar 1 produto para venda." << std::endl;
	std::cout << "4. Adicionar vários produtos para venda." << std::endl;
	std::cout << "5. Alterar quantidade disponível de um produto" << std::endl;
	std::cout << "6. Remover produto."<< std::endl << std::endl;

	std::cout << "7. Adicionar venda." << std::endl;
	std::cout << "8. Ordenar vendas." << std::endl;

	std::cout << "10. Imprimir fatura" << std::endl;

}

void menu(){

	int opcao;
	std::cout << "CADEIA DE FARMÁCIAS (" << cadeiaF.getNome() << ") - AEDA 2018" << std::endl << std::endl;

	std::cout << "O que pretende fazer?" << std::endl;
	std::cout << "1. Alterar o nome da cadeia de farmácias" << std::endl;
	std::cout << "2. Gerir uma farmácia." << std::endl;
	std::cout << "3. Gerir funcionários." << std::endl;
	std::cout << "4. Gerir clientes." << std::endl;
	std::cout << "5. Inserir receita." << std::endl;
	std::cout << "6. Gerir vendas." << std::endl;
	std::cout << "7. Mostrar dados da cadeia de farmácias" << std::endl;
	std::cout << "8. Importar novo ficheiro." << std:: endl;
	//std::cout << 8. "Gravar e sair. << std::endl;


	std::cout << "Opção: "; std::cin >> opcao; std::cout << std::endl;


	switch(opcao){
	case 1:
	{
		std::string nomeCadeia;
		std::cout << "Que nome pretende dar à cadeia de farmácias? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		std::cout << std::string(3, '\n');
		break;
	}

	case 2:
		std::cout << std::string(3, '\n');
		menuFarmacia();
		break;

	case 3:
		std::cout << std::string(3, '\n');
		menuFuncionarios();
		break;

		//TODO
		//case 4: menuReceita();
		//case 5: menuVendas();
		//case 6:
		//case 7:
		//case 8:
	default:
		std::cerr << "Opcao inexistente!" << std::endl;
		break;

	}
	menu();
}


void menuInicial(){
	int opcao;
	std::string nomeCadeia;
	std::fstream ficheiro;

	std::cout << "CADEIA DE FARMÁCIAS - AEDA 2018" << std::endl << std::endl;
	std::cout << "O que pretende fazer?" << std::endl;
	std::cout << "1. Importar ficheiro." << std::endl;
	std::cout << "2. Criar cadeia de farmácias." << std::endl << std::endl;

	std::cout << "Opção: "; std::cin >> opcao; std::cout << std::endl;

	switch(opcao){
	case 1:
	{
		std::cout << "Qual o nome da cadeia de farmácias que quer importar? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		nomeCadeia += ".txt";
		ficheiro.open(nomeCadeia);
		while (!ficheiro.is_open())
		{
			std::cerr << "Ficheiro " << nomeCadeia << " não encontrado!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::getline(std::cin, nomeCadeia);
			cadeiaF.setNome(nomeCadeia);
			nomeCadeia += ".txt";
			ficheiro.open(nomeCadeia);
		}
		import(ficheiro,cadeiaF);
		std::cout << std::string(3, '\n');
		break;
	}
	case 2:
		std::cout << "Qual o nome da cadeia de farmácias? ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		std::cout << std::string(3, '\n');
		break;

	default:
		std::cout << std::string(3, '\n');
		std::cerr << "Opcao inexistente!" << std::endl;
		std::cout << std::string(3, '\n');
		menuInicial();
	}
	menu();
}


int main(){
	menuInicial();
	return 0;
}
