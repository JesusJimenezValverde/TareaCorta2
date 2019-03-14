#pragma once
#include <iostream>
#include <string>
//using std::string;
//using std::cout;

using namespace std;

template <class T, int N = 10>
class ListaB {
	struct Node {
		bool lleno; // Indica si el nodo está lleno
		T elemento[N]; // Cada nodo almacena N elementos

		struct Node * siguiente; // Puntero al siguiente nodo
		// Constructores
		Node() :lleno{ false }, siguiente{ 0 } {}
		Node(struct Node * sig) :lleno{ false },
			siguiente{ sig } {}
	};
	typedef struct Node * link;
	link primero; // Puntero al primer nodo
	int tam; // Cantidad de elementos totales en la lista
	string nombreLista; // Nombre de la lista

public:
	ListaB(string s);     // Listo
	int len();			  // Listo
	void push_front(T x); // Pao
	void push_back(T x);  // Resuelto en clases - Listo
	void insertar(T x, int pos);  // Pao
	bool remove(int pos, T& x);	  // Esteban
	bool pop(T& x);				  //Pao
	bool pop_back(T& x);		  //Esteban - Listo
	bool get(int pos, T& element);	//Pao
	bool get_front(T& element);		//Esteban - Listo
	bool get_back(T& element);		//Cualquiera Esteban - Listo
	~ListaB();						// Listo
	void print();					//Esteban - Listo
};



template<class T, int N>
ListaB<T,N>::ListaB(string s) {
	primero = NULL;
	tam = 0;
	nombreLista = s;
}

template<class T, int N>
int ListaB<T, N>::len() {
	return tam;
}

template<class T, int N>
void ListaB<T, N>::push_front(T x) {
	if (primero == NULL) {
		primero = new Node();
		primero->elemento[0] = x;
	}
}

template<class T, int N>
void ListaB<T, N>::push_back(T x) {
	if (tam == 0) {
		primero = new Node();
		primero->elemento[0] = x;
		tam++;
	}
	else {
		link p = primero;
		while (p->siguiente)
			p = p->siguiente;
		if (p->lleno) {
			p->siguiente = new Node();
			p->siguiente->elemento[0] = x;
			tam++;
		}
		else {
			p->elemento[tam++ % N] = x;
			p->lleno = tam % N == 0;
		}
	}
	cout << "Tamanno es : " << tam << endl;
}

template<class T, int N>
void ListaB<T, N>::insertar(T x, int pos) {


}

template<class T, int N>
bool ListaB<T, N>::remove(int pos, T& x) {
	if (primero) {
		if (pos == 0) {
			pop(x);
			return true;
		}
		else if (pos == tam) {
			pop_back(x);
			return true;
		}
		else
		{
			//por hacer
			return true;
		}
	}
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop(T& x) {
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop_back(T& x) {
	if (tam>0) {
		link p = primero;
		int cont = 0;
		while (p->siguiente != NULL) {
			p = p->siguiente;
			cont += N;
		}
		link aux = primero;	
		if (tam > N) {
			// Este se encarga de poner el puntero del nodo anterior en NULL
			while (aux->siguiente->siguiente != NULL) {
				aux = aux->siguiente;
			}
		}

		int pos = 0;
		while (cont < tam) {
			cont++;
			pos++;
		}
		x = p->elemento[pos - 1];
		p->elemento[pos - 1] = NULL;
		if (pos - 1 == 0) {
			aux->siguiente = NULL;
			delete p;
		}
		tam -= 1;
		return true;
	}
	return false;
}

template<class T, int N>
bool ListaB<T, N>::get(int pos, T& element) {
	return false;
}

template<class T, int N>
bool ListaB<T,N>::get_front(T& element)
{
	if (primero && tam > 0) {
		element = primero->elemento[0];
		return true;
	}
	else {
		return false;
	}
}

template<class T, int N>
bool ListaB<T,N>::get_back(T& element)
{
	if (primero) {
		link p = primero;
		int cont = 0;
		while (p->siguiente != NULL) {
			p = p->siguiente;
			cont += N;
		}
		int pos = 0;
		while (cont < tam) {
			cont++;
			pos++;
		}
		element = p->elemento[pos-1];
		return true;
	}
	return false;
}

template<class T, int N>
ListaB<T,N>::~ListaB() {
	link p;
	while (primero) {
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}

template<class T, int N>
void ListaB<T, N>::print() {
	cout << "Printing" << endl;
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		int pasada = 0;
		while (p!=NULL) {
			int cont = 0;
			while (cont < N && cont+(N*pasada) < tam) {
				cout << p->elemento[cont];
				cont++;
				if (cont + (10 * pasada) < tam) {
					cout << ", ";
				}
			}
			pasada++;
			p = p->siguiente;
		}
	}
	cout << "]";
}