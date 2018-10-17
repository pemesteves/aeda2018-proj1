#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {

private:
	string Nome;
	string Morada;
	double NoContribuinte;

public:
	virtual string getNome();

	virtual string getMorada();

	virtual double getNoContribuinte();

	Pessoa(string nome, string morada, double cont);
};

#endif
