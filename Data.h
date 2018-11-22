/**
 * Header File que contem as classes Data e Hora
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef DATA_H
#define DATA_H

#include <ctime>
#include <iostream>
/**
 * Classe Data
 */
class Data {
private:
	unsigned short dia; //Dia do mês
	unsigned short mes; //Mês do ano
	int ano; //Ano

public:
	/**
	 * Construtor da Classe Data
	 * Data sera a mesma do sistema
	 */
	Data();
	/**
	 * Construtor da Classe Data
	 * @param dia Dia da data
	 * @param mes Mês da data
	 * @param ano Ano da data
	 */
	Data(unsigned short dia, unsigned short mes, int ano);
	/**
	 * Metodo que permite obter o dia
	 * @return Dia do mês
	 */
	unsigned short getDia() const;
	/**
	 * Metodo que permite obter o mes
	 * @return Mês do ano (em número)
	 */
	unsigned short getMes() const;
	/**
	 * Metodo que permite obter o ano
	 * @return Ano
	 */
	int getAno() const;
	/**
	 * Operador menor que verifica se uma data e menor que outra
	 * @param data Data a ser comparada
	 * @return Retorna true se for menor que a data do parametro. Caso contrario, retorna false
	 */
	bool operator< (const Data &data) const;
	/**
	 * Metodo que verifica se duas datas sao iguais
	 * @param data Data a ser comparada
	 * @return Retorna true se as datas forem iguais. Caso contrario, retorna false
	 */
	bool operator==(const Data &data) const;
	/**
	 * Overload de operador << para exportar a data
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param d1 Data que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Data &d1);

};

/**
 * Classe Hora
 */
class Hora {
private:
	unsigned short hora; //Hora do dia
	unsigned short minutos; //Minutos
	unsigned short segundos; //Segundos

public:
	/**
	 * Construtor da Classe Hora
	 * Hora sera a mesma do sistema
	 */
	Hora();
	/**
	 * Construtor da Classe Hora
	 * @param h Horas da hora
	 * @param m Minutos da hora
	 * @param s Segundos da hora
	 */
	Hora(unsigned short h, unsigned short m, unsigned short s);
	/**
	 * Metodo que permite obter as horas (número da hora)
	 * @return Hora do dia
	 */
	unsigned short getHora() const;
	/**
	 * Metodo que permite obter os minutos
	 * @return Minutos
	 */
	unsigned short getMinutos() const;
	/**
	 * Metodo que permite obter os segundos
	 * @return Segundos
	 */
	unsigned short getSegundos() const;
	/**
	 * Operador menor que verifica se uma hora e menor que outra
	 * @param h Hora a ser comparada
	 * @return Retorna true se for menor que a hora do parametro. Caso contrario, retorna false
	 */
	bool operator< (const Hora &h) const;
	/**
	 * Metodo que verifica se duas datas sao iguais
	 * @param h Hora a ser comparada
	 * @return Retorna true se as horas forem iguais. Caso contrario, retorna false
	 */
	bool operator ==(const Hora &h) const;
	/**
	 * Overload de operador << para exportar a data
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param d1 Data que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Hora &h1);
};

#endif
