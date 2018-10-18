#ifndef HORA_H
#define HORA_H

class Hora {

private:
	unsigned short hora;
	unsigned short minutos;
	unsigned short segundos;

public:
	unsigned short getHora();

	unsigned short getMinutos();

	unsigned short getSegundos();

	Hora();

	bool operator>(Hora hora);

	bool operator==(Hora hora);

	bool operator>(Hora hora);

	bool operator==(Hora hora);

	bool operator>(Hora hora);

	bool operator==(Hora hora);
};

#endif
