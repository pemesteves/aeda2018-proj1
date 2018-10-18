#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario : Pessoa {

private:
	double salario;
	Farmacia* farmaciaTrabalho;
	string cargo;
	bool cartaConducao;

public:
	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	void setNoContribuinte(double noContribuinte);

	double getSalario();

	void setSalario(double salario);

	Farmacia* getFarmaciaTrabalho();

	void setFarmaciaTrabalho(Farmacia* farmaciaTrabalho);

	string getCargo();

	void setCargo(string cargo);

	bool getCartaConducao();

	void setCartaConducao(bool cartaConducao);

	Funcionario(string nome, string morada, double noContribuinte);

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();
};

#endif
