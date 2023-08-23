///////////////////////////////////////////////////////////
//  cTropa.h
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_)
#define EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_

#include "cGuerrero.h"
#include "cMago.h"
#include "cArquero.h"
#include "cCaballero.h"
#include "cListaT.h"

class cTropa
{
private:
	string IDTropa; //no es const porque yo puedo agrupar y divir tropas
	cListaT<cGuerrero>* Guerreros; //lista de guerreros
	static unsigned int ContTropas; //contador 

public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cTropa
	* constructor de la clase cTropa
	*/
	cTropa();
	/**
	* ~cTropa
	* destructor de la clase cTropa
	*/
	~cTropa();
	void AsignarGuerreros();

	unsigned int CalcularAT();

#pragma endregion
	/**
	* CalcularAT_Total
	* la recorre la lista de Guerreros y acumula los AT de cada unidad en particular. Retorna el acumulador
	* @return int
	*/
	unsigned int AT_Extra(cTropa* otra);
	/**
	* RecibirDanio
	* Le resta el AT que recibe la unidad como daño. Recorre la lista, y
	* por ejemplo, si el AT de ataque es 1000, el primero recibe 100 (muere), 
	* el segundo recibe 1000-100, etc...
	* @param int AT_ataque
	* @return bool (si se muere toda la tropa es true)
	*/
	bool RecibirDanio(int AT_Ataque);
	bool RecibirDanioXZona(int AT_Ataque);
	cListaT<cGuerrero>* getGuerreros() { return Guerreros; }
	bool operator>(cTropa* otra);
	string getClave() { return IDTropa; }

	template<class TipoGuerrero>
	bool AnalizarTipoGuerrero(cGuerrero* Guerrero1);

	template<class TipoGuerrero>
	bool AnalizarTipoTropa(cListaT<cGuerrero>* Lista);

	void OrdenarXHP();

	string To_string();
};

template<class TipoGuerrero>
bool cTropa::AnalizarTipoGuerrero(cGuerrero* Guerrero1) //Segun nuestra implementacion, las tropas se crean todas con el mimso tipo del guerrero ==> si yo analizo el primero, entonces estoy analizando todas.
{
	return (dynamic_cast<TipoGuerrero*>(Guerrero1) != NULL); 
}


template<class TipoGuerrero>

bool cTropa::AnalizarTipoTropa(cListaT<cGuerrero>* Lista)
{
	return (dynamic_cast<TipoGuerrero*>(Lista) != NULL);
}

#endif // !defined(EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_)
