#ifndef DATA_H
#define DATA_H

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
	 * Data será a mesma do sistema
	 */
	Data();
	/**
	 * Método que permite obter o dia
	 * @return Dia do mês
	 */
	unsigned short getDia() const;
	/**
	 * Método que permite obter o mes
	 * @return Mês do ano (em número)
	 */
	unsigned short getMes() const;
	/**
	 * Método que permite obter o ano
	 * @return Ano
	 */
	int getAno() const;
	/**
	 * Operador menor que verifica se uma data é menor que outra
	 * @param data Data a ser comparada
	 * @return Retorna true se for menor que a data do parâmetro. Caso contrário, retorna false
	 */
	bool operator< (const Data &data) const;
	/**
	 * Método que verifica se duas datas são iguais
	 * @param data Data a ser comparada
	 * @return Retorna true se as datas forem iguais. Caso contrário, retorna false
	 */
	bool operator==(const Data &data) const;

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
	 * Hora será a mesma do sistema
	 */
	Hora();
	/**
	 * Método que permite obter a hora do dia
	 * @return Hora do dia
	 */
	unsigned short getHora() const;
	/**
	 * Método que permite obter os minutos
	 * @return Minutos
	 */
	unsigned short getMinutos() const;
	/**
	 * Método que permite obter os segundos
	 * @return Segundos
	 */
	unsigned short getSegundos() const;
	/**
	 * Operador menor que verifica se uma hora é menor que outra
	 * @param h Hora a ser comparada
	 * @return Retorna true se for menor que a hora do parâmetro. Caso contrário, retorna false
	 */
	bool operator< (const Hora &h) const;
	/**
	 * Método que verifica se duas datas são iguais
	 * @param h Hora a ser comparada
	 * @return Retorna true se as horas forem iguais. Caso contrário, retorna false
	 */
	bool operator ==(const Hora &h) const;
};

#endif
