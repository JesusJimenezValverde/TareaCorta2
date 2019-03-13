#pragma once
#include <iostream>
#include <string>
//using std::string;
//using std::cout;

using namespace std;

template <class T>
class List {
private:
	struct Nodo {
		T elemento;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 } {}
		Nodo(T x, struct Nodo* sig) :elemento{ x }, siguiente{ sig } {}
	};

	typedef struct Nodo * link;

	link primero;        // Puntero al primer elemento de la lista
	int tam;            // Cantidad de elementos de la lista
	string nombreLista;    // Nombre de la lista

	// M�todo de clase
	static void insertR(link &p, T x, int pos);

public:

	List(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	void insertarR(T x, int pos);
	bool remove(int pos, T & x); //T& x
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~List();

};

template<class T>
void List<T>::insertR(link & p, T x, int pos) {
	if (p == NULL)
		p = new Nodo(x);
	else {
		if (pos == 0)
			p = new Nodo(x, p);
		else
			insertR(p->siguiente, x, pos - 1);
	}
}

template<class T>
List<T>::List(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template <class T>
void List<T>::push_front(T x) {
	primero = new Nodo(x, primero);
	tam++;
}

template<class T>
void List<T>::push_back(T x) {
	if (!primero)
		primero = new Nodo(x, primero);
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		p->siguiente = new Nodo(x);
	}
	tam++;
}

template<class T>
void List<T>::insertar(T x, int pos) {
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		if (pos == 0)
			primero = new Nodo(x, primero);
		else {
			link p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			p->siguiente = new Nodo(x, p->siguiente);
		}
	}
	tam++;
}

template<class T>
void List<T>::insertarR(T x, int pos) {
	insertR(primero, x, pos);
	tam++;
}

template<class T>
bool List<T>::remove(int pos, T & x)
{
	if (!primero) {
		cout << "La lista esta vac�a";
		return false;
	}
	else {
		if (len() - 1 < pos) {
			cout << "\nLa posicion a remover no existe, la lista quedara igual.\n" << endl;
			return false;
		}
		if (pos == 0 && primero->siguiente == NULL) {
			link Aeliminar = primero;
			primero = NULL;
			x = Aeliminar->elemento;
			delete Aeliminar;
			return true;
		}
		else if(pos == 0){
			link Aeliminar = primero;
			primero = primero->siguiente;
			x = Aeliminar->elemento;
			delete Aeliminar;
			return true;
		}
		else {
			link p = primero;
			int actual = 0;
			while (p->siguiente && actual+1 < pos) {
				p = p->siguiente;
				actual++;
			}
			link Aeliminar = p->siguiente;
			if (Aeliminar->siguiente == NULL) {
				p->siguiente = NULL;
			}
			else {
				p->siguiente = Aeliminar->siguiente;
			}
			x = Aeliminar->elemento;
			delete Aeliminar;
			return true;
		}
	}
}

template<class T>
bool List<T>::pop(T & x)
{
	link aux = primero;
	x = primero->elemento;
	primero = primero->siguiente;
	delete aux;
	tam--;
	return true;
}

template<class T>
bool List<T>::pop_back(T & x)
{	
	if (primero && len() > 1) {
		//cout << "Camino 1" << endl;
		link aux = primero;
		while (aux) {
			if (aux->siguiente->siguiente == NULL) {
				link aux2 = aux->siguiente;
				x = aux2->elemento;
				aux->siguiente = NULL;
				delete aux2;
				tam--;
				return true;
			}
			aux = aux->siguiente;
		}
	}
	else if (primero && len() == 1) {
		//cout << "Camino 2" << endl;
		x = primero->elemento;
		link aux = primero;
		primero = 0;
		delete aux;
		tam--;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
bool List<T>::get(int pos, T & element)
{
	if (!primero || pos > len()) {
		cout << "La lista se encuentra vac�a" << endl;
		return false;
	}
	else {
		link aux = primero;
		int cont = 0;
		while (aux) {
			if (cont == pos) {
				element = aux->elemento;
				return true;
			}
			cont += 1;
			aux = aux->siguiente;
		}
	}
	return true;
}

template<class T>
bool List<T>::get_front(T & element)
{
	element = primero->elemento;
	return true;
	
}

template<class T>
bool List<T>::get_back(T & element)
{
	link aux = primero;
	while (aux) {
		if (aux->siguiente == NULL)
			element = aux->elemento;
		aux = aux->siguiente;
	}
	return true;
}

template<class T>
void List<T>::print() {
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		cout << p->elemento;
		p = p->siguiente;
		while (p) {
			cout << ", " << p->elemento;
			p = p->siguiente;
		}
	}
	cout << "]";
}

template<class T>
int List<T>::len() {
	return tam;
}

template<class T>
List<T>::~List() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}