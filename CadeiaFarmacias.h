#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

class CadeiaFarmacias {

private:
	vector<Farmacia*> Farmacias;
	vector<Cliente*> Clientes;
	vector<Funcionario*> Funcionarios;

public:
	void Cadeia_Farmacias();

	CadeiaFarmacias();
};

#endif
