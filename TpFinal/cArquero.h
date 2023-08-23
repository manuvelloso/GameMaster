///////////////////////////////////////////////////////////
//  cArquero.h
//  Implementation of the Class cArquero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_)
#define EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_

#include "cGuerrero.h"

class cArquero : public cGuerrero
{
	
public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cArquero 
	* constructor de la clase cArquero
	*/
	cArquero();
	/**
	* ~cArquero
	* destructor de la clase cArquero
	*/
	~cArquero();
#pragma endregion

	/**
	* AtaqueAleatorio 
	* decide si atacar por segunda vez
	* @return bool
	*/
	bool AtaqueAleatorio();
	unsigned int AtaquePorSegunda(cGuerrero* Atacado);
	unsigned int Ataque(cGuerrero* Atacado);

};
//ostream& operator<<(ostream& out, cArquero* obj)
//{
//	out << "ARQUERO ";
//	return out;
//}
#endif // !defined(EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_)
