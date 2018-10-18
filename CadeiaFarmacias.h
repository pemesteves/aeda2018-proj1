#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

class CadeiaFarmacias {

private:
	vector<Farmacia*> farmacias;
	vector<Cliente*> clientes;
	vector<Funcionario*> funcionarios;

public:
	void Cadeia_Farmacias();

	CadeiaFarmacias();

	void addFarmacia(Farmacia* farmacia);

	void addCliente(Cliente* cliente);

	void addFuncionario(Funcionario* funcionario);

	unsigned int numFarmacias();

	unsigned int numClientes();

	unsigned int numFuncionarios();
};

#endif
