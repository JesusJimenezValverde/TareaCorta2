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
	ListaB(string s);
	int len();
	void push_front(T x); // Pao
	void push_back(T x);  // Profe
	void insertar(T x, int pos);  // Pao
	bool remove(int pos, T& x);	  // Esteban
	bool pop(T& x);				  //Pao
	bool pop_back(T& x);		  //Esteban
	bool get(int pos, T& element);	//Pao
	bool get_front(T& element);		//Esteban
	bool get_back(T& element);		//Pao
	~ListaB();
	void print();					//Esteban
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
		while (primero->siguiente)
			primero = primero->siguiente;
		if (primero->lleno) {
			primero->siguiente = new Node();
			primero->siguiente->elemento[0] = x;
			tam++;
		}
		else {
			primero->elemento[tam++ % N] = x;
			primero->lleno = tam % N == 0;
		}
	}
}

template<class T, int N>
void ListaB<T, N>::insertar(T x, int pos) {


}

template<class T, int N>
bool ListaB<T, N>::remove(int pos, T& x) {
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop(T& x) {
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop_back(T& x) {
	return false;
}

template<class T, int N>
bool ListaB<T, N>::get(int pos, T& element) {
	return false;
}

template<class T, int N>
bool ListaB<T,N>::get_front(T& element)
{
	return false;
}

template<class T, int N>
bool ListaB<T,N>::get_back(T& element)
{
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
