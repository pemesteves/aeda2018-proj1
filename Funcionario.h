#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario : Pessoa {

private:
	double Salario;
	Farmacia* FarmaciaTrabalho;
	string Cargo;
	bool CartaConducao;

public:
	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	void setNoContribuinte(double NoContribuinte);

	double getSalario();

	void setSalario(double Salario);

	Farmacia* getFarmaciaTrabalho();

	void setFarmaciaTrabalho(Farmacia* FarmaciaTrabalho);

	string getCargo();

	void setCargo(string Cargo);

	bool getCartaConducao();

	void setCartaConducao(bool CartaConducao);

	Funcionario(string Nome, string Morada, double NoContribuinte);
};

#endif
