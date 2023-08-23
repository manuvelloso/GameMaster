#pragma once

#include <stdlib.h>
#include "cListaT.h"
#include "cPais.h"
#include "windows.h"

class cMundo
{
private:
	cListaT<cPais>* ListaPaises; //lista de paises que constituyen al mundo
	string Nombre;

#pragma region METODOS DE ARCHIVOS
	/**
	* LeerArchivo 
	* abre el .txt correspondiente al mundo elegido en el main. Lee linea por linea,
	* separando los nombres (separados por '-') y crea la lista de strings que tiene los nombres de los paises limitrofes
	* @param filename
	*/
	void LeerArchivo(const char* Filename);

	void SetNombreMundo(string str);

#pragma endregion
	
public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cMundo
	* constructor de la clase cMundo
	*/
	cMundo();
	/**
	* cMundo
	* constructor de la clase cMundo
	*/
	~cMundo();
#pragma endregion

#pragma region SET UP
	/**
	* PaisesLimitrofes 
	* Crear array de strings con nombres de paises limitrofes PARA 1 SOLO PAIS
	* @param string, nombre 
	*/
	void PaisesLimitrofes(string& Limitrofes, string NombrePais);
	/**
	* BuscarNombrePais
	* Por medio de funciones de la class string, se buscar el nombre del pais
	* @param string, caracter, posicion
	*/
	string BuscarNombrePais(string str, char separator, int* pos);
	/**
	* SetUp
	* inicializa al mundo
	* @param filename
	*/
	void SetUp(const char* Filename);

#pragma endregion

#pragma region GETTERS & SETTERS

	cListaT<cPais>* GetLista();
	void setNombre(string nombre);

#pragma region IMPRIMIR

	void Imprimir() const;
	

#pragma endregion


#pragma endregion
};

