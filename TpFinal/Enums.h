///////////////////////////////////////////////////////////
//  eEstadoJugador.h
//  Implementation of the Enumeration eEstadoJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_DC7EF3D4_FE6F_41d8_B5B3_09AC78CEBDA0__INCLUDED_)
#define EA_DC7EF3D4_FE6F_41d8_B5B3_09AC78CEBDA0__INCLUDED_

enum class eEstadoJugador
{
	PERDEDOR = 0,
	GANADOR,
	ATACANDO,
	DEFENDIENDO,
	ESPERANDO
};

enum class eTipoGuerrero
{
	CABALLERO = 0,
	MAGO,
	ARQUERO
};
#endif // !defined(EA_DC7EF3D4_FE6F_41d8_B5B3_09AC78CEBDA0__INCLUDED_)
