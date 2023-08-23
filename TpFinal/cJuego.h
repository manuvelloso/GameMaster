///////////////////////////////////////////////////////////
//  cJuego.h
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
#define EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_

#include "cMundo.h"
#include "cJugador.h"
class cJuego
{
private:
	cListaT<cJugador>* Jugadores; //lista de jugadores
	static unsigned int Rondas; //contador de la cantidad de rondas
	unsigned int TurnoPrevio; //el numero del turno previo
	cMundo* Mundo; //ptr a mundo

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cJuego
	* constructor de la clase cJuego
	*/
	cJuego(unsigned int cantjugadores);
	/**
	* ~cJuego
	* destructor de la clase cJuego
	*/
	~cJuego();

#pragma endregion

#pragma region METODOS DEL JUEGO

#pragma endregion

	void AsignarTurno();
	void JugadorAtacando(unsigned int pos);
	void Batallar(cJugador* JugadorAtacando, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas);

	cJugador* DuenioPais(cPais *Pais);
	
	void Reagrupar(unsigned int pos, cPais* PaisAtacante);
	void FindeRondaEntera();

	cJugador* BuscarXEstado(eEstadoJugador estado)const;

#pragma region SETUPS

	void SetUpMundo(unsigned int mundo); //FUNCIONA
	//void SetUpJugadores(string username); //FUNCIONA
	void SetUpJugadores();

#pragma endregion

#pragma region GETTERS & SETTERS

	static int getRondas();
	cMundo* getMundo()const;

#pragma endregion

#pragma region IMPRIMIR & TO STRING

	void ImprimirEstados() const;

#pragma endregion

	cJuego& operator++() {
		this->SetUpJugadores();
		return *this;
	}

	void AsignarPaisesRandom(); //FUNCIONA

};
//istream& operator>>(istream& in, cJugador* Jugador)
//{
//	int pospais = -1; //para inicializar
//	unsigned int cont = 0;
//	if (cont % 2 == 0) {
//		cout << "\n ---- JUGADOR " << Jugador->getUsername() << " ---- " << endl;
//		cout << " Introduzca el numero pais al que quiere atacar: \n";
//		in >> pospais;
//	}
//	else {
//		cout << "\n ---- JUGADOR " << Jugador->getUsername() << " ---- " << endl;
//		cout << " Introduzca el numero pais desde el que quiere atacar: \n";
//		in >> pospais;
//	}
//
//	return in;
//}

bool VerificarPaisOrigen(cJugador* Jugador, unsigned int pospais);
static unsigned int CalcularResiduo(int Num1, int Num2)
{
	if (Num2 != 0)
	{
		float Division = (float)Num1 / Num2;
		int ParteEntera = Num1 / Num2;
		int Residuo = (int)(Division - ParteEntera) * Num2;
		return Residuo;
	}
	else
		throw new exception(" --- Division por cero --- ");
}


#endif // !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)


