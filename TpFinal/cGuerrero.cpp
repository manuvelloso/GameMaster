///////////////////////////////////////////////////////////
//  cGuerrero.cpp
//  Implementation of the Class cGuerrero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cGuerrero.h"
unsigned int cGuerrero::cantGuerreros = 0;
cGuerrero::cGuerrero(unsigned int _AT, unsigned int _HP_Inicial)
{
	cantGuerreros++;
	AT = _AT;
	HP_Inicial = _HP_Inicial;
	HP_Actual = HP_Inicial;
	ID = to_string(cantGuerreros);
}

cGuerrero::~cGuerrero(){

}

unsigned int cGuerrero::getAT() const
{
	return AT;
}
