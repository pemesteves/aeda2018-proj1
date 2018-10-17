#ifndef CARRINHA_H
#define CARRINHA_H

class Carrinha {

private:
	string Matricula;
	string Marca;
	int Capacidade;
	bool Disponibilidade;

public:
	string getMatricula();

	string getMarca();

	int getCapacidade();

	Carrinha(string matricula, string marca, string capacidade);

	Disponibilidade getDisponibilidade();
};

#endif
