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
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	~ListaB();
	void print();
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

}
