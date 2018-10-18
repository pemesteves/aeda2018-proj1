#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {

private:
	string nome;
	string morada;
	double noContribuinte;

public:
	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	Pessoa(string nome, string morada, double cont);

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
