#pragma once

#include <iostream>
#include <string>
#include <ostream>

#define NMAX 50
using namespace std;

template<class T>
class cListaT
{
protected:
	T** Lista;
	unsigned int CA,TAM;
	bool Delete;
public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cListaT(bool _Delete = true, unsigned int _TAM = NMAX);
	cListaT(cListaT<T>& ListaCopia);
	virtual ~cListaT();
#pragma endregion
#pragma region AGREGAR,QUITAR,ELIMINAR
	void Agregar(T* newItem);
	T* Quitar(const string Key);
	T* QuitarXPos(unsigned int pos);
	void Eliminar(unsigned int pos);
#pragma endregion
	void Redimensionar();
#pragma region BUSCAR
	T* BuscarItem(const string Key);
	T* BuscarXPos(unsigned int Index);
#pragma endregion
#pragma region GETTERS
	unsigned int getIndex(const string Key)const;
	unsigned int getCA() const;
	unsigned int getTAM() const;
#pragma endregion

	void Listar()const;
	string To_String()const;

#pragma region SOBRECARGA
	T* operator[](unsigned int pos);
	void operator+(T* newItem);
	void operator-(unsigned int pos);
	void operator-(T* obj);
	void operator=(cListaT<T>* Copia); //ESTO CREA POR COPIA
#pragma endregion

};

template <class T>
cListaT<T>::cListaT(bool _Delete, unsigned int _TAM)
{
	TAM = _TAM;
	Delete = _Delete;
	CA = 0;

	Lista = new T * [TAM];
	//Creo la lista dinamica
	for (unsigned int i = 0; i < TAM; i++)
	{
		Lista[i] = NULL;
	}
}

template<class T>
T* cListaT<T>::operator[](unsigned int pos)
{
	if (pos >= 0 && pos < CA)
		return Lista[pos];
	return NULL;
}

template<class T>
void cListaT<T>::operator+(T* newItem)
{
	try { Agregar(newItem); }
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error al usar operator+: " + error).c_str());
		throw ex;
	}
	return;
}





template<class T>
cListaT<T>::cListaT(cListaT<T>& ListaCopia)
{
	TAM = ListaCopia.TAM;
	Delete = false;
	CA = 0;

	Lista = new T * [ListaCopia.TAM];

	//Creo la lista dinamica
	for (unsigned int i = 0; i < TAM; i++)
	{
		Lista[i] = NULL;
	}

	//*this = *ListaCopia;

	for (unsigned int i = 0; i < ListaCopia.CA; i++)
	{
		Agregar(ListaCopia[i]); //agrego por copia
	}
}

template <class T>
cListaT<T>::~cListaT()
{
	if (Lista != NULL)
	{
		if (Delete)
		{
			for (unsigned int i = 0; i < CA; i++)
			{
				if (Lista[i] != NULL)
					delete Lista[i];
			}
		}
		delete[] Lista;
	}
}

template<class T>
void cListaT<T>::Agregar(T* newItem)
{
	if (newItem != NULL)
	{
		if (CA == TAM) //si la cant actual es igual al tamanio max
			Redimensionar(); //redimensiono la lista
		try {
			int pos = getIndex(newItem->getClave()); //busco el elemento en la lista
		}
		catch (exception* ex) { //si el elemento no existe
			delete ex;
			Lista[CA++] = newItem; //lo agrego a la lista
			return;
		}
		throw new exception("El item ya esta en la lista");
	}
	throw new exception("El nuevo item que se desea agregar a la lista es NULL");
}

template<class T>
T* cListaT<T>::Quitar(const string Key)
{
	int pos = -1;
	try { pos = getIndex(Key); } //busco el elemento
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex;
	}
	T* aux = Lista[pos]; // si lo encuentra lo guardo
	for (int i = pos; i < CA - 1; i++)
	{
		Lista[i] = Lista[i + 1]; //corro todo una posicion para arriba 
	}
	Lista[--CA] = NULL;
	return aux;
}

template<class T>
T* cListaT<T>::QuitarXPos(unsigned int pos)
{
	T* aux = NULL;
	try { aux = BuscarXPos(pos); } //busco el elemento
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex;
	}
	for (unsigned int i = pos; i < CA - 1; i++)
	{
		Lista[i] = Lista[i + 1]; //corro todo una posicion para arriba 
	}
	Lista[--CA] = NULL;
	return aux;
}

template<class T>
void cListaT<T>::Eliminar(unsigned int pos)
{
	T* aux = NULL;
	if (Lista != NULL)
	{
		try { aux = QuitarXPos(pos); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("No se puede eliminar el item: " + error).c_str());
			throw ex;
		}
		delete aux;
		return;
	}
	throw new exception("Error al eliminar: la lista es NULL");
}

template<class T>
void cListaT<T>::Redimensionar()
{
	unsigned int n = 2 * TAM;
	T** aux = new T * [n]; //se redimensiona al doble del tam original
	
	//---------
	for (unsigned int i = 0; i < TAM * 2; i++)
	{
		aux[i] = NULL;
	}
	for (unsigned int i = 0; i < TAM; i++)
	{
		aux[i] = Lista[i];
	}
	//----------

	delete[]Lista;
	Lista = aux;
	TAM += TAM;

}

template<class T>
T* cListaT<T>::BuscarItem(const string Key)
{
	int pos = -1;
	if (Lista != NULL)
	{
		
		try { pos = getIndex(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("Error al buscar item: " + error).c_str());
			throw ex;
		}
		return Lista[pos];
		
	}
	throw new exception("Error al buscar el item");
}

template<class T>
T* cListaT<T>::BuscarXPos(unsigned int Index)
{
	if (Index < 0 ||Index > CA)
		throw new exception(("La posicion " + to_string(Index) + " no existe en la lista").c_str());
	return Lista[Index];
}

template<class T>
unsigned int cListaT<T>::getIndex(const string Key) const
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista[i]->getClave() == Key)
			return i;
	}
	throw new exception((Key + " el item no existe").c_str());
}

template<class T>
unsigned int cListaT<T>::getCA() const
{
	return CA; //EXCEPCION
}

template<class T>
unsigned int cListaT<T>::getTAM() const
{
	return TAM;
}

template<class T>
void cListaT<T>::Listar() const
{
	for (unsigned int i = 0; i < CA; i++)
	{
		cout << "\n\t# " << i + 1 << endl;
		cout << Lista[i]->To_String();
	}
}

template<class T>
void cListaT<T>::operator-(unsigned int pos)
{
	try
	{
		Eliminar(pos);
	}
	catch (exception* ex)
	{
		string error = ex->what();
		delete ex;
		ex = new exception((error + " :: No se pudo eliminar con el operator al recibir una pos").c_str());
		throw ex;
	}
}

template<class T>
void cListaT<T>::operator-(T*obj)
{
	try
	{
		unsigned int pos=getIndex(obj->getClave());
		Eliminar(pos);
	}
	catch (exception* ex)
	{
		string error = ex->what();
		delete ex;
		ex = new exception((error + " :: No se pudo eliminar con el operator al recibir un obj").c_str());
		throw ex;
	}
}

template<class T>
inline void cListaT<T>::operator=(cListaT<T>* Copia)
{

	*this = new cListaT<T>(*Copia); //me creo la lista (toda en null)

	return;
}

template <class T>
ostream& operator<<(ostream& os, const cListaT<T>& Lista)
{
	os << Lista.To_String() << endl;
	return os;
}

template<class T>
string cListaT<T>::To_String() const
{
	string output;
	for (unsigned int i = 0; i < CA; i++)
	{
		if(Lista[i]!=NULL)
		{
			output += '\t' + Lista[i]->To_string() + '\n'; // imprimir
		}
	}
	return output;
}