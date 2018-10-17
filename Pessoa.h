#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {

private:
	string Nome;
	string Morada;
	double NoContribuinte;

public:
	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	Pessoa(string nome, string morada, double cont);
};

#endif
