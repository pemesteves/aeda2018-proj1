/*
 * menu.cpp
 *
 *  Created on: 24/11/2018
 *      Author: Pedro
 */


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

using namespace std;

CadeiaFarmacias cadeia;

void menuCriarCadeia(){
	cout << "CADEIA DE FARMACIAS" << endl << endl;
	cout << "1. Criar nova cadeia. " << endl;
	cout << "2. Importar cadeia. " << endl;
	cout << "3. Sair. " << endl;
}

void menuGerirCadeia(){
	cout << "1. Adicionar Farmacia." << endl;
	cout << "2. Ordenar farmacias." << endl;
	cout << "3. Remover Farmacia." << endl;
	cout << "4. Ver farmacias." << endl;
	cout << "5. Adicionar Cliente." << endl;
	cout << "6. Ordenar clientes." << endl;
	cout << "7. Remover Cliente." << endl;
	cout << "8. Ver clientes." << endl;
	cout << "9. Adicionar Funcionario." << endl;
	cout << "10. Ordenar funcionarios." << endl;
	cout << "11. Remover Funcionario." << endl;
	cout << "12. Ver funcionarios." << endl;
	cout << "13. Ver dados da cadeia." << endl;
	cout << "14. Gerir Farmacia." << endl;
	cout << "15. Gerir Funcionario." << endl;
	cout << "16. Gerir Cliente." << endl;
	cout << "17. Sair." << endl;
}

void menuFarmacia(){
	cout << "1. Ver dados da Farmacia." << endl;
	cout << "2. Mudar gerente." << endl;
	cout << "3. Mudar diretor tecnico." << endl;
	cout << "4. Consultar stock." << endl;
	cout << "5. Adicionar Produto." << endl;
	cout << "6. Remover Produto." << endl;
	cout << "7. Ver historial de vendas." << endl;
	cout << "8. Ver vendas entre duas datas." << endl;
	cout << "9. Realizar Venda." << endl;
	cout << "10. Ordenar Vendas." << endl;
	cout << "11. Voltar atras." << endl;
}

void menuFuncionarios(){

}

int main(){
	unsigned int option;

	menuCriarCadeia();
	cin >> option;
	string nome;
	switch(option){
	case 1:
		cout << "Nome: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin,nome);
		cadeia.setNome(nome);
		break;
	case 2:
	{
		ifstream ficheiro;
		cout << "Nome da cadeia: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nome);
		ficheiro.open(nome + ".txt");

		while (!ficheiro.is_open())
		{
			cerr << "Ficheiro " << nome << ".txt nao encontrado!" << endl;
			cout << "Quer tentar outra vez ou sair? (S = sair)" << endl;
			char sair;
			cin >> sair;
			if(toupper(sair) == 'S'){
				goto sairDoPrograma;
			}
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			ficheiro.open(nome + ".txt");
		}
		cadeia.setNome(nome);
		import(ficheiro, cadeia);
		break;
	}
	case 3:
		goto sairDoPrograma;
		break;
	default:
		cout << "Opcao Invalida" << endl;
	}

	do{
		menuGerirCadeia();
		cin >> option;
		switch(option){
		case 1:{
			cout << "Nome da Farmacia: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			string morada;
			cout << "Morada da Farmacia: ";
			getline(cin, morada);
			Farmacia* f = new Farmacia(nome, morada);
			cadeia.addFarmacia(f);
			break;
		}
		case 2:{
			cout << "Como pretende ordenar as farmacias? " << endl;
			cout << "	1-Por nome;" << endl;
			cout << "	2-Por numero de produtos;" << endl;
			cout << "	3-Por numero de vendas;" << endl;
			cin >> option;
			if(option >= 1 && option <= 3)
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
			char crescente;
			do{
				cin >> crescente;
			}while(tolower(crescente) != 'c' && tolower(crescente) != 'd');

			switch(option){
			case 1:
				if(crescente == 'c')
					cadeia.sortFarmacias(NOME,true);
				else
					cadeia.sortFarmacias(NOME,false);
				break;
			case 2:
				if(crescente == 'c')
					cadeia.sortFarmacias(NUM_PROD,true);
				else
					cadeia.sortFarmacias(NUM_PROD,false);
				break;
			case 3:
				if(crescente == 'c')
					cadeia.sortFarmacias(NUM_VENDA,true);
				else
					cadeia.sortFarmacias(NUM_VENDA,false);
				break;
			default:
				cadeia.sortFarmacias(DEFAULT, true);
				break;
			}

			break;
		}
		case 3:{
			cout << "Nome da Farmacia a eliminar: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			try{
				Farmacia *f;
				f = cadeia.removeFarmacia(nome);
				cout << "Farmacia " << f->getNome() << " eliminada" << endl;
			}catch(FarmaciaInexistente &e){
				cerr << "Farmacia " << e.getNome() << " inexistente" << endl;
			}
			break;
		}
		case 4:{
			vector<Farmacia *>::const_iterator it = cadeia.getFarmacias().begin();
			for(; it != cadeia.getFarmacias().end(); it++){
				(*it)->imprimeDados();
				cout << endl;
			}
			break;
		}
		case 5:{
			cout << "Nome do Cliente: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			string morada;
			cout << "Morada do Cliente: ";
			getline(cin, morada);
			double contribuinte;
			cin >> contribuinte;
			Cliente *c = new Cliente(nome, morada, contribuinte);
			cadeia.addCliente(c);
			break;
		}
		case 6:{
			cout << "Como pretende ordenar os clientes? " << endl;
			cout << "	1-Por nome;" << endl;
			cout << "	2-Por numero de contribuinte;" << endl;
			cout << "	3-Por numero de compras;" << endl;
			cin >> option;
			if(option >= 1 && option <= 3)
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
			char crescente;
			do{
				cin >> crescente;
			}while(tolower(crescente) != 'c' && tolower(crescente) != 'd');

			switch(option){
			case 1:
				if(crescente == 'c')
					cadeia.sortFarmacias(NOME,true);
				else
					cadeia.sortFarmacias(NOME,false);
				break;
			case 2:
				if(crescente == 'c')
					cadeia.sortFarmacias(CONTRIBUINTE,true);
				else
					cadeia.sortFarmacias(CONTRIBUINTE,false);
				break;
			case 3:
				if(crescente == 'c')
					cadeia.sortFarmacias(NUM_VENDA,true);
				else
					cadeia.sortFarmacias(NUM_VENDA,false);
				break;
			default:
				cadeia.sortFarmacias(DEFAULT, true);
				break;
			}
			break;
		}
		case 7:{
			cout << "Nome do Cliente a eliminar: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			try{
				Cliente *c;
				c = cadeia.removeCliente(nome);
				cout << "Cliente " << c->getNome() << " eliminado" << endl;
			}catch(ClienteInexistente &e){
				cerr << "Cliente " << e.getNome() << " inexistente" << endl;
			}
			break;
		}
		case 8:{
			vector<Cliente *>::iterator it = cadeia.getClientes().begin();
			for(; it != cadeia.getClientes().end(); it++){
				(*it)->showInfo();
				cout << endl;
			}
			break;
		}
		case 9:{
			cout << "Nome do Funcionario: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			string morada;
			cout << "Morada do Funcionario: ";
			getline(cin, morada);
			double contribuinte;
			cin >> contribuinte;
			Funcionario *f = new Funcionario(nome, morada, contribuinte);
			cadeia.addFuncionario(f);
			break;
		}
		case 10:{
			cout << "Como pretende ordenar os funcionarios? " << endl;
			cout << "	1-Por nome;" << endl;
			cout << "	2-Por contribuinte;" << endl;
			cout << "	3-Por salario;" << endl;
			cin >> option;
			if(option >= 1 && option <= 3)
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
			char crescente;
			do{
				cin >> crescente;
			}while(tolower(crescente) != 'c' && tolower(crescente) != 'd');

			switch(option){
			case 1:
				if(crescente == 'c')
					cadeia.sortFarmacias(NOME,true);
				else
					cadeia.sortFarmacias(NOME,false);
				break;
			case 2:
				if(crescente == 'c')
					cadeia.sortFarmacias(CONTRIBUINTE,true);
				else
					cadeia.sortFarmacias(CONTRIBUINTE,false);
				break;
			case 3:
				if(crescente == 'c')
					cadeia.sortFarmacias(SALARIO,true);
				else
					cadeia.sortFarmacias(SALARIO,false);
				break;
			default:
				cadeia.sortFarmacias(DEFAULT, true);
				break;
			}

			break;
		}
		case 11:{
			cout << "Nome do Funcionario a eliminar: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			try{
				Funcionario *f;
				f = cadeia.removeFuncionario(nome);
				cout << "Funcionario " << f->getNome() << " eliminado" << endl;
			}catch(FuncionarioInexistente &e){
				cerr << "Funcionario " << e.getNome() << " inexistente" << endl;
			}
			break;
		}
		case 12:{
			vector<Funcionario *>::iterator it = cadeia.getFuncionarios().begin();
			for(; it != cadeia.getFuncionarios().end(); it++){
				(*it)->showInfo();
				cout << endl;
			}
			break;
		}
		case 13:{
			cout << "Cadeia de Farmacias " << cadeia.getNome() << endl;
			cout << "	Numero de Farmacias: " << cadeia.getNumFarmacias() << endl;
			cout << "	Numero de Funcionarios: " << cadeia.getNumFuncionarios() << endl;
			cout << "	Numero de Clientes: " << cadeia.getNumClientes() << endl << endl;
			break;
		}
		case 14:{
			cout << "Nome da Farmacia: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			vector<Farmacia *> v = cadeia.getFarmacias();
			vector<Farmacia *>::iterator it;
			for(it = v.begin(); it != v.end(); it){
				if((*it)->getNome() == nome)
					break;
			}

			if(it == v.end()){
				cout << "Farmacia " << nome << " inexistente" << endl;
				break;
			}

			menuFarmacia();

			break;
		}
		case 15:
			break;
		case 16:
			break;
		case 17:
			goto sairDoPrograma;
			break;
		}
	}while(true);



	sairDoPrograma:
	return 0;
}



