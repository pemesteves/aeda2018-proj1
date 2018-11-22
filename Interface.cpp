#include "CadeiaFarmacias.h"
#include "Data.h"
#include "Farmacia.h"
#include "Pessoa.h"
#include "Produto.h"
#include "Receita.h"
#include "util.h"
#include "Venda.h"

#include <iostream>

void menuCadeia(){
	std::cout << "CADEIA DE FARMÁCIAS" << std::endl;
	std::cout << "1. Criar cadeia de farmácias." << std::endl;
	std::cout << "2. Alterar o nome da cadeia de farmácias." << std::endl << std::endl;

	std::cout << "3. Adicionar farmácia." << std::endl;
	std::cout << "4. Remover farmácia." << std::endl;
	std::cout << "5. Ordenar farmácia." << std::endl << std::endl;

	std::cout << "6. Adicionar novo cliente." << std::endl;
	std::cout << "7. Remover cliente." << std::endl;
	std::cout << "8. Ordenar clientes." << std::endl << std::endl;

	std::cout << "9. Adicionar funcionário." << std::endl;
	std::cout << "10. Remover funcionário." << std::endl;
	std::cout << "11. Ordenar funcionários." << std::endl << std::endl;

}

void menuS(int opcao){
	switch(opcao){
	case 1: menuCadeia();
	case 2: menuFarmacia();
	case 3: menuClientes();
	case 4: menuReceita();
	case 5: menuVendas();
	}
}
void menu(){

	int opcao;
	std::cout << "		FARMÁCIA DO PEDRITO" << std::endl << std::endl;

	std::cout << "O que pretende fazer?" << std::endl;
	std::cout << "1. Gerir cadeia de farmácias" << std::endl;
	std::cout << "2. Gerir uma farmácia." << std::endl;
	std::cout << "3. Gerir clientes." << std::endl;
	std::cout << "3. Inserir receita." << std::endl;
	std::cout << "5. Gerir vendas." << std:: endl << std::endl;

	std::cin >> opcao; std::cout << std::endl;
	menuS(opcao);

}




void menuFarmacia(){
	std::cout << "FARMÁCIA" << std::endl;
	std::cout << "1. Definir/modificar Gerente." << std::endl;
	std::cout << "2. Definir/modificar Diretor Técnico." << std::endl << std::endl;

	std::cout << "3. Adicionar 1 produto para venda." << std::endl;
	std::cout << "4. Adicionar vários produtos para venda." << std::endl;
	std::cout << "5. Alterar quantidade disponível de um produto" << std::endl;
	std::cout << "6. Remover produto."<< std::endl << std::endl;

	std::cout << "7. Adicionar venda." << std::endl;
	std::cout << "8. Ordenar vendas." << std::endl;
	std::cout << "9. Ordenar clientes." << std::endl << std::endl;

	std::cout << "10. Imprimir fatura" << std::endl;


}

int main(){
	menu();

	return 0;
}
