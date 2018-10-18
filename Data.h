#ifndef DATA_H
#define DATA_H

class Data {


public:
	Data();

	unsigned short getDia();

	unsigned short getMes();

	int getAno();

	bool operator>(Data data);

	bool operator==(Data data);

	bool operator>(Data data);

	bool operator==(Data data);

	bool operator>(Data data);

	bool operator==(Data data);

private:
	unsigned short dia;
	unsigned short mes;
	int ano;
};

#endif
