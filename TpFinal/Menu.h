#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <sstream>
#include "windows.h"

using namespace std;

enum class eOpcion {
	SALIR = 0,
	JUGAR,
	IMPRIMIR_REGLAS,
	IMPRIMIR_PERFILES
};

enum class eMundo {

	AGENTINA = 0,
	AMERICA_LATINA
	//NARNIA,
};

string Caratula(const char* Filename);
string To_StringMenu();
eOpcion ElegirOpcion();
void Instrucciones();

string Caratula(const char* Filename)
{
	FILE* fp = NULL; //file pointer
	fp = fopen(Filename, "r"); //Abrir archivo
	char buffer[200] = "";
	int pos = 0;
	string Cadena = "";

	if (fp == NULL)
		throw new exception(" --- Error al abrir el archivo ---");

	while (!feof(fp))
	{
		fgets(buffer,199, fp); //leo por linea
		Cadena += buffer;
	}

	fclose(fp); //cierro el archivo
	return Cadena;
}

string To_StringMenu() {
	string output = "\n\t----- MENU -----\n";
	output += "\t1. JUGAR\n";
	output += "\t2. IMPRIMIR REGLAS\n";
	output += "\t3. IMPRIMIR PERFILES\n";
	output += "\t0. SALIR\n";

	return output;
}

eOpcion ElegirOpcion() {

	eOpcion opcion = eOpcion::SALIR;
	
	cout << To_StringMenu() << endl;
	scanf_s("%d", &opcion);  //TODO: Despues pasar a CIN
	
	if(opcion < eOpcion::SALIR || opcion > eOpcion::IMPRIMIR_PERFILES)
	{
		cout << "Opcion invalida\n";
		Sleep(2000); 
		system("cls");
		opcion = ElegirOpcion();
	}

	return opcion;
	
}

bool Menu() {
	eOpcion opcion = ElegirOpcion();
	switch (opcion)
	{
	case eOpcion::JUGAR:
		system("cls");
		return true;

	case eOpcion::IMPRIMIR_REGLAS:
		Instrucciones();
		cout << " Presione cualquier tecla para volver al menu\n";
		getchar();
		system("cls");
		Menu();
		break;
		
	//case eOpcion::IMPRIMIR_PERFILES: break;

	case eOpcion::SALIR:
		system("cls");
		return false;

	default: return false;
	}
}

unsigned int ElegirMundo()
{
	unsigned int Mundo = (unsigned int)eMundo::AMERICA_LATINA;
	cout << "\n\t---- MUNDOS -----" << endl;
	cout << "\t1. ARGENTINA Y LIMITROFES" << endl;
	cout << "\t2. AMERICA LATINA" << endl;
	cout << "\t3. NARNIA" << endl;
	cout << "\tIngrese opcion: "; 
	cin >> Mundo;

	if (Mundo < (unsigned int)eMundo::AGENTINA || Mundo > ((unsigned int)eMundo::AMERICA_LATINA)+1)
		Mundo = ElegirMundo();

	system("cls");
	return Mundo;
}

string ConvertMundoString(unsigned int mundo) {

	mundo--;
	switch ((eMundo)mundo)
	{
	case eMundo::AGENTINA: return "Argentina"; break;
	case eMundo::AMERICA_LATINA: return "America Latina"; break;
	}
}

string To_StringInstrucciones() {
	string output;
	output += "\n\t----- INSTRUCCIONES GAME MASTER!! -----\n";
	output += "\tEl objetivo del juego es APODERARSE DEL MUNDO, ocupando con tus tropas todos los paises de los oponentes.\n";
	output += "\tEn este juego existen tres tipos de guerreros : CABALLEROS, MAGOS, ARQUEROS --> CADA TIPO DE GUERRERO TIENE ATRIBUTOS ESPECIALES!\n";
	output += "\tCada jugador comenzara la partida con 5 paises y 10 tropas de algun tipo de guerrero. AL QUE LE TOCA, LE TOCA!LA SUERTE ES LOCA!  :P\n";
	output += "\tEl maximo de tropas que pueden ser enviadas a batallar es de 3.\n";
	output += "\tAl finalizar cada ronda, cada jugador recibe tropas para seguir combatiendo!pero ojo... no podran elegir el tipo de guerrero!\n";
	output += "\tSOLO se puede atacar a paises limitrofes.\n";
	output += "\tAl final de cada turno, se les ofrece la oportunidad de reagrupar las tropas desde el ultimo pais atacado a sus limitrofes.\n";
	output += "\tTienen la oportunidad de renunciar a atacar en la batalla, pero no pueden renunciar a defenderse. A BANCARSELA!\n\n";
	output += "\tYA ESTAN LISTOS PARA LA BATALLA!!\n";

	return output;
}

void Instrucciones() {
	cout << To_StringInstrucciones();
	getchar();
}
