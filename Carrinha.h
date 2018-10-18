#ifndef CARRINHA_H
#define CARRINHA_H

class Carrinha {

private:
	string matricula;
	string marca;
	int capacidade;
	bool disponibilidade;

public:
	string getMatricula();

	string getMarca();

	int getCapacidade();

	Carrinha(string matricula, string marca, string capacidade);

	bool getDisponibilidade();
};

#endif
