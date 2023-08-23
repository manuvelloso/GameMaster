///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTropa.h"
#include "Enums.h"

class cMago;
class cCaballero;
class cArquero;
unsigned int cTropa::ContTropas = 0;

cTropa::cTropa(){
	ContTropas++;
	IDTropa = to_string(ContTropas);
	Guerreros = new cListaT<cGuerrero>();
	AsignarGuerreros();
}

cTropa::~cTropa(){
	if (Guerreros != NULL)
		delete Guerreros;
}

void cTropa::AsignarGuerreros()
{
	int i = 0;
	eTipoGuerrero random = eTipoGuerrero(rand() % 3);
	switch (random)
	{
	case eTipoGuerrero::CABALLERO:
		for (i = 0; i < (rand() % 11) + 10; i++)
			Guerreros->Agregar(new cCaballero());
		break;
	case eTipoGuerrero::MAGO:
		for (i = 0; i < (rand() % 21) + 20; i++)
			Guerreros->Agregar(new cMago());
		break;
	case eTipoGuerrero::ARQUERO:
		for (i = 0; i < (rand() % 16) + 15; i++)
			Guerreros->Agregar(new cArquero());
		break;
	}

}

unsigned int cTropa::CalcularAT()
{
	unsigned int AT = 0;
	for (unsigned int i = 0; i < Guerreros->getCA(); i++)
	{
		AT += (*Guerreros)[i]->getAT();
	}
	return AT;
}

unsigned int cTropa::AT_Extra(cTropa* otra) {

	unsigned int ATExtra = 0;

	for (unsigned int i = 0; i < Guerreros->getCA(); i++)
		ATExtra += (*Guerreros)[i]->Ataque((*otra->Guerreros)[0]); //uso la otra tropa para saber contra quien estoy combatiendo
	
	return ATExtra;
}


bool cTropa::operator>(cTropa* otra)
{
	//MAGO VS CABALLERO -> fuerte mago
	//ARQUERO VS MAGO -> fuerte arquero
	//CABALLERO VS ARQUERO -> fuerte caballero

	if(AnalizarTipoGuerrero<cMago>((*Guerreros)[0]) && AnalizarTipoGuerrero<cCaballero>(otra->Guerreros->BuscarXPos(0)))
		return true;
	if (AnalizarTipoGuerrero<cArquero>((*Guerreros)[0]) && AnalizarTipoGuerrero<cMago>(otra->Guerreros->BuscarXPos(0)))
		return true;
	if (AnalizarTipoGuerrero<cCaballero>((*Guerreros)[0]) && AnalizarTipoGuerrero<cArquero>(otra->Guerreros->BuscarXPos(0)))
		return true;

	return false;
}

void cTropa::OrdenarXHP()
{
	cGuerrero* aux = NULL;
	for (unsigned int i = 0; i < (Guerreros->getCA()) - 1; i++)
	{
		int cont_cambios = 0;
		for (unsigned int k = 0; k < (Guerreros->getCA()) - 1; k++)
		{
			if ((*Guerreros)[k]->getHP() > (*Guerreros)[k+1]->getHP())
			{
				aux = (*Guerreros)[k];
				*(*Guerreros)[k] = *(*Guerreros)[k+1]; //quiero que el puntero me apunte al guerrero de menor hp
				*(*Guerreros)[k + 1] = *(aux);
				cont_cambios++;
			}
		}
		if (cont_cambios == 0)
			break;
	}
}

string cTropa::To_string()
{
	if(Guerreros!=NULL)
	{
		if (Guerreros->getCA() > 0)
		{
			string output = "\t\t TROPA N " + IDTropa + ": " + to_string(Guerreros->getCA());

			if (dynamic_cast<cCaballero*>((*Guerreros)[0]) != NULL)
				output += " Caballeros\n";
			else if (dynamic_cast<cMago*>((*Guerreros)[0]) != NULL)
				output += " Magos\n";
			else if (dynamic_cast<cArquero*>((*Guerreros)[0]) != NULL)
				output += " Arqueros\n";
			return output;
		}
	}

	
}

bool cTropa::RecibirDanio(int AT_Ataque) {

	OrdenarXHP(); //ordeno de más vida a menod vida
	unsigned int i = 0;
	do
	{
		int aux = (*Guerreros)[i]->getHP(); //me fijo cuanta vida tengo
		
		(*(*Guerreros)[i]) -= AT_Ataque; //le resto el AT con el que me atacaron

		if ((*Guerreros)[i]->VerificarVida()) //me fijo si estoy vivo
		{
			Guerreros->Eliminar(i); //si no lo estoy paso a mejor vida
			--i; //menos guerreros 
		}
		AT_Ataque -= aux; //el AT con el que me atacaron disminuye
		i++;

	} while (AT_Ataque > 0 && i < Guerreros->getCA()); //esto se repite hasta que el AT que me mandaron sea 0 o se elimine toda la tropa
	if (Guerreros->getCA() == 0) //me quede sin guerreros en la tropa
	{
		delete Guerreros; //bai bai
		return true; //no tengo tropa
	}
	return false; //todavía tendo tropa ;)
}

bool cTropa::RecibirDanioXZona(int AT_Ataque)
{
	OrdenarXHP(); //ordeno de más vida a menod vida

	for (unsigned int i = 0; i < Guerreros->getCA(); i++) //recorro la lista de guerreros
	{
		(*(*Guerreros)[i]) -= AT_Ataque; //le resto el AT con el que me atacaron (este AT es el del mago que ataca por zona)
		if ((*Guerreros)[i]->VerificarVida()) //me fijo si estoy vivo
			Guerreros->Eliminar(i); //si no lo estoy paso a mejor vida
	}
	
	if (Guerreros->getCA() == 0) //me quede sin guerreros en la tropa
	{
		delete Guerreros; //bai bai
		return true; //no tengo tropa
	}

	return false; //todavía tendo tropa ;)
}
