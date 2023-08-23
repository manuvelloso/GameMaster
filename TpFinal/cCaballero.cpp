///////////////////////////////////////////////////////////
//  cCaballero.cpp
//  Implementation of the Class cCaballero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCaballero.h"
#include "cArquero.h"

cCaballero::cCaballero():cGuerrero((rand() % 11) + 30, (rand() % 21) + 80){
	//Los caballeros tienen un ataque (AT) entre 30-40 y entre 80 y 100 de vida(HP).
}

cCaballero::~cCaballero(){

}

unsigned int cCaballero::Ataque(cGuerrero* Atacado){

	if (dynamic_cast<cArquero*>(Atacado) != NULL)
		return (AT * 0.25); //su ataque aumenta en 0,25
	else
		return 0;
}

unsigned int cCaballero::Contrataque(){
	
	return (AT * 1.25);
}