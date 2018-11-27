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
	cout << endl << endl;
	cout << "GERIR CADEIA DE FARMACIAS" << endl;
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
	cout << endl << endl;
	cout << "GERIR FARMACIA" << endl;
	cout << "1. Ver dados da Farmacia." << endl;
	cout << "2. Mudar gerente." << endl;
	cout << "3. Mudar diretor tecnico." << endl;
	cout << "4. Consultar stock." << endl;
	cout << "5. Adicionar ou alterar quantidade de Produto." << endl;
	cout << "6. Remover Produto." << endl;
	cout << "7. Ver historial de vendas." << endl;
	cout << "8. Ver vendas entre duas datas." << endl;
	cout << "9. Realizar Venda." << endl;
	cout << "10. Ordenar Vendas." << endl;
	cout << "11. Voltar atras." << endl;
}

void menuFuncionario(){
	cout << endl << endl;
	cout << "GERIR FUNCIONARIO" << endl;
	cout << "1. Ver dados do Funcionario." << endl;
	cout << "2. Alterar farmacia em que trabalha." << endl;
	cout << "3. Alterar cargo." << endl;
	cout << "4. Alterar salario." << endl;
	cout << "5. Alterar morada." << endl;
	cout << "6. Voltar atras." << endl;
}

void menuCliente() {
	cout << endl << endl;
	cout << "GERIR CLIENTE" << endl;
	cout << "1. Ver dados do Cliente." << endl;
	cout << "2. Ver historial de compras." << endl;
	cout << "3. Alterar morada." << endl;
	cout << "4. Voltar atras." << endl;
}

int main(){
	unsigned int option;

	menuCriarCadeia();
	do{
		cin >> option;
		if(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcao Invalida. Tente outra vez: ";
		}
	}while(cin.fail());
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
		string nome_fich = nome + ".txt";
		ficheiro.open(nome_fich);
		while (!ficheiro.is_open())
		{
			cerr << "Ficheiro " << nome << ".txt nao encontrado!" << endl;
			cout << "Quer tentar outra vez ou sair? (S = sair)" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			if (toupperstring(nome) == "S")
				goto sairDoPrograma;
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
		menu_cadeia:

		menuGerirCadeia();
		do{
			cin >> option;
			if(cin.fail()){
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Opcao Invalida. Tente outra vez: ";
			}
		}while(cin.fail());
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
			do{
				cin >> option;
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcao Invalida. Tente outra vez: ";
				}
			}while(cin.fail());
			char crescente;
			if (option >= 1 && option <= 3) {
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
				do {
					cin >> crescente;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				} while ((tolower(crescente) != 'c' && tolower(crescente) != 'd') || cin.fail());
			}

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
			vector<Farmacia *> v = cadeia.getFarmacias();
			for(unsigned int i =0; i<v.size(); i++){
				v.at(i)->imprimeDados();
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
			cout << "Contribuinte do Cliente: ";
			unsigned long contribuinte;
			do{
				cin >> contribuinte;
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcao Invalida. Tente outra vez: ";
				}
			}while(cin.fail());
			Cliente *c = new Cliente(nome, morada, contribuinte);
			cadeia.addCliente(c);
			break;
		}
		case 6:{
			cout << "Como pretende ordenar os clientes? " << endl;
			cout << "	1-Por nome;" << endl;
			cout << "	2-Por numero de contribuinte;" << endl;
			cout << "	3-Por numero de compras;" << endl;
			do{
				cin >> option;
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcao Invalida. Tente outra vez: ";
				}
			}while(cin.fail());
			char crescente;
			if (option >= 1 && option <= 3) {
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
				do {
					cin >> crescente;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				} while ((tolower(crescente) != 'c' && tolower(crescente) != 'd') || cin.fail());
			}

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
			vector<Cliente *>clientes1 = cadeia.getClientes();
			for(unsigned int i = 0; i < clientes1.size(); i++){
				(clientes1.at(i))->showInfo();
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
			cout << "Numero de contribuinte do Funcionario: ";
			unsigned long contribuinte;
			do{
				cin >> contribuinte;
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcao Invalida. Tente outra vez: ";
				}
			}while(cin.fail());
			Funcionario *f = new Funcionario(nome, morada, contribuinte);
			cadeia.addFuncionario(f);
			break;
		}
		case 10:{
			cout << "Como pretende ordenar os funcionarios? " << endl;
			cout << "	1-Por nome;" << endl;
			cout << "	2-Por contribuinte;" << endl;
			cout << "	3-Por salario;" << endl;
			do{
				cin >> option;
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcao Invalida. Tente outra vez: ";
				}
			}while(cin.fail());
			char crescente;
			if (option >= 1 && option <= 3) {
				cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
				do {
					cin >> crescente;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				} while ((tolower(crescente) != 'c' && tolower(crescente) != 'd') || cin.fail());
			}

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
			vector<Funcionario *> v = cadeia.getFuncionarios();
			for(size_t i = 0; i < cadeia.getFuncionarios().size(); i++){
				v.at(i)->showInfo();
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
			cout << endl << "Nome da Farmacia: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			vector<Farmacia *> v = cadeia.getFarmacias();
			vector<Farmacia *>::iterator frm;
			for(frm = v.begin(); frm != v.end(); frm++){
				if((*frm)->getNome() == nome)
					break;
			}

			if(frm == v.end()){
				cout << "Farmacia " << nome << " inexistente" << endl;
				break;
			}
			do {
				menu_farmacia:

				menuFarmacia();
				do{
					cin >> option;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				}while(cin.fail());
				switch (option) {
				case 1: {
					(*frm)->imprimeDados();
					cout << endl;
					break;
				}
				case 2: {
					string num;
					string frm_nome = (*frm)->getNome();
					cout << "Numero de contribuinte do novo gerente: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, num);
					vector<Funcionario*>::iterator f;
					for (f = cadeia.getFuncionarios().begin(); f != cadeia.getFuncionarios().end(); f++) {
						if ((*f)->getNoContribuinte() == stoul(num)) {
							if ((*f)->getFarmacia()->getNome() == frm_nome) {
								(*frm)->setGerente(*f);
								string func_nome = (*f)->getNome();
								cout << "Novo gerente: " << func_nome;
								cout << endl;
							}
							else{
								cout << "Funcionario nao trabalha na farmacia " << frm_nome;
								cout<< endl;
							}
							break;
						}
					}
					if (f == cadeia.getFuncionarios().end()) {
						cout << "Funcionario nao encontrado" << endl;
					}
					break;
				}
				case 3: {
					string num;
					string frm_nome = (*frm)->getNome();
					cout << "Numero de contribuinte do novo diretor tecnico: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, num);
					vector<Funcionario*> func = cadeia.getFuncionarios();
					vector<Funcionario*>::iterator f;
					for (f = func.begin(); f != func.end(); f++) {
						if ((*f)->getNoContribuinte() == stoul(num)) {
							if ((*f)->getFarmacia()->getNome() == frm_nome) {
								(*frm)->setDiretorTecnico(*f);
								string func_nome = (*f)->getNome();
								cout << "Novo diretor tecnico: " << func_nome << endl;
							}
							else
								cout << "Funcionario nao trabalha na farmacia " << frm_nome << endl;
						}
						if (f == func.end()) {
							cout << "Funcionario nao encontrado" << endl;
						}
					}
					break;
				}
				case 4: {
					map<Produto, int> p = (*frm)->getProdutosVender();
					map<Produto, int>::const_iterator prods;
					for (prods = p.begin(); prods != p.end(); prods++) {
						cout << prods->first.getCodigo() << "  ";
						cout << prods->first.getNome() << "   ";
						cout << prods->second << " unidades";
						cout << endl;
					}
					cout << endl;
					break;
				}
				case 5: {
					string nome;
					cout << "Nome do produto: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, nome);
					nome = toupperstring(nome);
					bool existe = (*frm)->existeProduto(nome);
					if (!existe) {
						unsigned long cod;
						float preco;
						string desc;
						char pass;
						Produto* p = NULL;
						cout << "Codigo do produto: ";
						do{
							cin >> cod;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						cout << endl << "Preco do produto: ";
						do{
							cin >> preco;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						cout << endl << "Descricao do produto: ";
						cin.clear();
						cin.ignore(10000, '\n');
						getline(cin, desc);
						cout << endl << "Produto passivel de receita? (S / N) ";
						do{
							cin >> pass;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						if (toupper(pass) == 'S') {
							float comp;
							char sR;
							bool semR;
							cout << endl << "Comparticipacao (em percentagem): ";
							do{
								cin >> comp;
								if(cin.fail()){
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "Opcao Invalida. Tente outra vez: ";
								}
							}while(cin.fail());
							comp = comp / 100;
							cout << endl << "Produto pode ser vendido sem receita? (S / N) ";
							do{
								cin >> sR;
								if(cin.fail()){
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "Opcao Invalida. Tente outra vez: ";
								}
							}while(cin.fail());
							semR = (toupper(sR) == 'S');
							p = new Produto(cod, nome, preco, desc, true, comp, semR);
							(*frm)->addProdutoVender(p);
						}
						else {
							p = new Produto(cod, nome, preco, desc, false, 0, false);
							(*frm)->addProdutoVender(p);
						}
					}
					int quant;
					cout << endl << "Quantidade do produto: ";
					do{
						cin >> quant;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					(*frm)->setQuantidade(nome, quant);
					cout << endl << "Quantidade alterada." << endl;
					break;
				}
				case 6: {
					string nome;
					cout << "Nome do produto: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, nome);
					nome = toupperstring(nome);
					try {
						(*frm)->removeProduto(nome);
						cout << "Produto " << nome << " eliminado" << endl;
					}
					catch (ProdutoInexistente &e) {
						cerr << "Produto " << nome << " inexistente" << endl;
					}
					break;
				}
				case 7: {
					vector<Venda*> v = (*frm)->getVendas();
					for (unsigned int i = 0; i < v.size(); i++) {
						cout << "Venda " << v.at(i)->getCodigo() << endl;
						v.at(i)->imprimeFatura();
						cout << endl << endl;
					}
					break;
				}
				case 8: {
					int ano;
					unsigned short mes;
					unsigned short dia;
					cout << "Data inferior:" << endl;
					cout << "Dia: " << endl;
					do{
						cin >> dia;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					while (dia<1 || dia>31){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Dia invalido. Insira um valor valido: ";
						do{
							cin >> dia;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n'):
										cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
					}
					cout << "Mes: " << endl;
					do{
						cin >> mes;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					while (mes<1 || mes>12){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Mes invalido. Insira um valor valido: ";
						do{
							cin >> mes;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
					}
					cout << "Ano: " << endl;
					do{
						cin >> ano;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					while (ano<1 || ano>12){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Ano invalido. Insira um valor valido: ";
						do{
							cin >> ano;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
					}
					Data d1(dia, mes, ano);
					cout << "Data superior:" << endl;
					cout << "Dia: " << endl;
					do{
						cin >> dia;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					while (dia<1 || dia>31){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Dia invalido. Insira um valor valido: ";
						do{
							cin >> dia;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
					}
					cout << "Mes: " << endl;
					do{
						cin >> mes;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());


					while (mes<1 || mes>12){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Mes invalido. Insira um valor valido: ";
						do{
							cin >> mes;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());

					}
					cout << "Ano: " << endl;
					do{
						cin >> ano;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					while (ano<1 || ano>12){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Ano invalido. Insira um valor valido: ";
						do{
							cin >> ano;

							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
					}
					Data d2(dia, mes, ano);
					vector<Venda*> v = (*frm)->getVendasTempo(d1,d2);
					for (unsigned int i = 0; i < v.size(); i++) {
						cout << "Venda " << v.at(i)->getCodigo() << endl;
						v.at(i)->imprimeFatura();
						cout << endl << endl;
					}
					break;
				}
				case 9:{
					Venda *v1 = new Venda();
					unsigned long no_con;
					cout << "VENDA" << v1->getCodigo() << endl;
					cout << "Numero de contribuinte do cliente: ";
					do{
						cin >> no_con;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					vector<Cliente *> v = cadeia.getClientes();
					int existe_cliente = -1;
					for(unsigned int i =0; i<v.size(); i++){
						if(v.at(i)->getNoContribuinte() == no_con){
							existe_cliente = i;
							break;
						}
					}
					if(existe_cliente==-1){
						cout << "Cliente nao existe na cadeia" << endl << endl;
						goto menu_farmacia;
					}
					v1->setCliente(v.at(existe_cliente));
					cout << endl << "Tem receita?(S/N) ";
					char op;
					do{
						cin >> op;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());

					if (toupper(op)=='S'){
						cout << endl << "ADICIONAR RECEITA";
						cout << endl << "Numero da receita: ";
						unsigned long numero_r;
						do{
							cin >> numero_r;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());

						cout << "Numero de contribuinte do utente: ";
						unsigned long numero_c;
						do{
							cin >> numero_c;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						existe_cliente = -1;
						for(unsigned int i =0; i<v.size(); i++){
							if(v.at(i)->getNoContribuinte() == no_con){
								existe_cliente = i;
								break;
							}
						}
						if(existe_cliente == -1){
							cout << "Cliente nao existe na cadeia" << endl << endl;
							goto menu_farmacia;
						}
						string nome_medico;
						cout << "Nome do medico: ";
						cin.clear();
						cin.ignore(10000, '\n');
						getline(cin, nome_medico);
						Receita *r1 = new Receita(numero_r, nome_medico, v.at(existe_cliente));
						Produto *p1;
						string nome_prod = "";
						unsigned long quant;
						cout << "Adicionar medicamentos a receita (para parar escreva SAIR no nome do produto):" << endl;
						while(true){
							cout << "Nome do Produto: ";
							do{
								cin >> nome_prod;
								if(cin.fail()){
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "Opcao Invalida. Tente outra vez: ";
								}
							}while(cin.fail());
							nome_prod = toupperstring(nome_prod);
							if(nome_prod =="SAIR")
								break;
							p1 = new Produto(0, nome_prod, 0, " ", true, 0, true);
							cout << endl << "Quantidade: ";
							do{
								cin >> quant;
								if(cin.fail()){
									cin.clear();
									cin.ignore(10000, '\n');
									cout << "Opcao Invalida. Tente outra vez: ";
								}
							}while(cin.fail());
							r1->addProduto(p1, quant);
						}
						cout << endl << "Fim da receita"<< endl;
						v1->setReceita(r1);
					}
					cout << "Adicionar produtos a venda (para parar escreva SAIR no nome do produto): "<< endl;
					while(true){
						string nome_prod;
						float quant;
						float iva;
						cout << "Nome do Produto: ";
						do{
							cin >> nome_prod;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						nome_prod = toupperstring(nome_prod);
						if(nome_prod=="SAIR")
							break;
						bool existe_prod = (*frm)->existeProduto(nome_prod);
						if (!existe_prod){
							cout << endl << "Produto nao existe na farmacia" << endl;
							continue;
						}
						map<Produto, int>::const_iterator prod;
						map<Produto, int> stock = (*frm)->getProdutosVender();
						for (prod = stock.begin(); prod != stock.end(); prod++){
							if (prod->first.getNome() == nome_prod)
								break;
						}
						Produto p1 = prod->first;
						cout << endl << "Quantidade: ";
						do{
							cin >> quant;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						cout << endl << "IVA (em percentagem): ";
						do{
							cin >> iva;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						}while(cin.fail());
						iva = iva/100;
						if(v1->addProduto(&p1, quant, iva)){
							cout << "Nao foi possivel adicionar o produto. Necessita de receita medica" << endl;
						}
					}
					bool venda_sucesso = (*frm)->addVenda(v1);
					if (venda_sucesso){
						cout << endl << "Venda realizada com sucesso. Fatura: " << endl;
						(*frm)->imprimeFatura(v1);
					}
					else{
						cout << endl << "Nao foi possivel realizar a venda. Nao existe stock suficiente." << endl;
					}
					break;
				}
				case 10: {
					cout << "Como pretende ordenar as vendas? " << endl;
					cout << "	1-Por numero de produtos vendidos;" << endl;
					cout << "	2-Por data;" << endl;
					cout << "	3-Por hora;" << endl;
					cout << "   4-Por valor total." << endl;
					do{
						cin >> option;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					char crescente;
					if (option >= 1 && option <= 3) {
						cout << "Pretende fazer esta ordenacao por ordem crescente(c) ou decrescente(d)? ";
						do {
							cin >> crescente;
							if(cin.fail()){
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Opcao Invalida. Tente outra vez: ";
							}
						} while ((tolower(crescente) != 'c' && tolower(crescente) != 'd') || cin.fail());
					}

					switch(option){
					case 1:
						if(crescente == 'c')
							(*frm)->sortVendas(NUM_PROD,true);
						else
							(*frm)->sortVendas(NUM_PROD,false);
						break;
					case 2:
						if(crescente == 'c')
							(*frm)->sortVendas(DATA,true);
						else
							(*frm)->sortVendas(DATA,false);
						break;
					case 3:
						if(crescente == 'c')
							(*frm)->sortVendas(HORA,true);
						else
							(*frm)->sortVendas(HORA,false);
						break;
					default:
						(*frm)->sortVendas(DEFAULT,true);
						break;
					}
					break;
				}
				case 11:
					goto menu_cadeia;
					break;
				}
			} while (true);
			break;
		}
		case 15: {
			cout << endl << "Nome do Funcionario: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			vector<Funcionario *> v = cadeia.getFuncionarios();
			vector<Funcionario *>::iterator func;
			for (func = v.begin(); func != v.end(); func++) {
				if ((*func)->getNome() == nome)
					break;
			}

			if (func == v.end()) {
				cout << "Funcionario " << nome << " inexistente" << endl;
				break;
			}

			do {

				menuFuncionario();
				do{
					cin >> option;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				}while(cin.fail());
				switch (option) {
				case 1:{
					(*func)->showInfo();
					cout << endl;
					break;
				}
				case 2:{
					string nome_farmacia_nova;
					cout << "Nome da farmacia onde vai trabalhar: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, nome_farmacia_nova);
					vector<Farmacia*> farmacias = cadeia.getFarmacias();
					vector<Farmacia*>::iterator frm;
					for(frm = farmacias.begin(); frm!=farmacias.end(); frm++){
						if(toupperstring((*frm)->getNome())==toupperstring(nome_farmacia_nova)){
							(*func)->setFarmacia((*frm));
							string nome_funcionario = (*func)->getNome();
							cout << nome_funcionario << " trabalha agora na farmacia " << nome_farmacia_nova << endl;
							break;
						}
					}
					if (frm == farmacias.end()){
						cout << "Farmacia nao encontrada" << endl;
					}
					break;
				}
				case 3:{
					string novo_cargo;
					cout << "Novo Cargo: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, novo_cargo);
					(*func)->setCargo(novo_cargo);
					break;
				}
				case 4:{
					double novo_salario;
					cout << "Novo salario: ";
					do{
						cin >> novo_salario;
						if(cin.fail()){
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Opcao Invalida. Tente outra vez: ";
						}
					}while(cin.fail());
					(*func)->changeSalario(novo_salario);
					break;
				}
				case 5:{
					string nova_morada;
					cout << "Nova morada: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, nova_morada);
					(*func)->setMorada(nova_morada);
					break;
				}
				case 6: {
					goto menu_cadeia;
					break;
				}
				}

			} while (true);

			break;
		}
		case 16: {
			cout << endl << "Nome do Cliente: ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nome);
			vector<Cliente *> v = cadeia.getClientes();
			vector<Cliente *>::iterator cl;
			for (cl = v.begin(); cl != v.end(); cl++) {
				if ((*cl)->getNome() == nome)
					break;
			}

			if (cl == v.end()) {
				cout << "Cliente " << nome << " inexistente" << endl;
				break;
			}
			do {

				menuCliente();
				do{
					cin >> option;
					if(cin.fail()){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Opcao Invalida. Tente outra vez: ";
					}
				}while(cin.fail());
				switch (option) {
				case 1: {
					(*cl)->showInfo();
					cout << endl;
					break;
				}
				case 2: {
					vector<Venda*> v = (*cl)->getHistorialCompras();
					for (unsigned int i = 0; i < v.size(); i++) {
						cout << "Venda " << v.at(i)->getCodigo() << endl;
						v.at(i)->imprimeFatura();
						cout << endl << endl;
					}
					break;
				}
				case 3: {
					string nova_morada;
					cout << "Nova morada: ";
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, nova_morada);
					(*cl)->setMorada(nova_morada);
					break;
				}
				case 4: {
					goto menu_cadeia;
					break;
				}
				}
			} while (true);
			break;
		}
		case 17:{
			string op;
			cout << endl << "Deseja guardar as alteracoes? (S / N)";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, op);
			if (toupperstring(op)=="S"){
				string nome_fich = cadeia.getNome();
				nome_fich += ".txt";
				ofstream exportfile;
				exportfile.open(nome_fich);
				cout << endl << "A guardar alteraçoes..." << endl;
				exportfile << cadeia;
				cout << "Cadeia guardada com sucesso" << endl;
			}
			goto sairDoPrograma;
			break;
		}
		}
	}while(true);



	sairDoPrograma:
	return 0;
}



