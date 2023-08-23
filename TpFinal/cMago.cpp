///////////////////////////////////////////////////////////
//  cMago.cpp
//  Implementation of the Class cMago
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cMago.h"
#include "cCaballero.h"

cMago::cMago():cGuerrero((rand() % 11) + 10, (rand() % 21) + 40){
	//10 - 20 y entre 40 y 60 de vida
}

cMago::~cMago(){

}

/**
 * Lo que dijo el Pampa: reparte su ataque en toda la tropa
 */
unsigned int cMago::Ataque(cGuerrero* Atacado){

	if (dynamic_cast<cCaballero*>(Atacado) != NULL)
		return (AT * 0.25); //su ataque aumenta en 0,25
	else
		return 0;
}

