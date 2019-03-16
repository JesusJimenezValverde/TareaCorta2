#pragma once
#include <iostream>
#include <string>

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
	ListaB(string s);     // Esteban - Listo
	int len();			  // Esteban - Listo
	void push_front(T x); // Pao
	void push_back(T x);  // Resuelto en clases - Listo
	void insertar(T x, int pos);  // Pao
	bool remove(int pos, T& x);	  // Esteban
	bool pop(T& x);				  //Pao -- Esteban - Listo
	bool pop_back(T& x);		  //Esteban - Listo
	bool get(int pos, T& element);	//Pao -- Esteban - Listo
	bool get_front(T& element);		//Esteban - Listo
	bool get_back(T& element);		//Cualquiera Esteban - Listo
	~ListaB();						// Esteban - Listo
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
	cout << "-----------------------------------------" << endl;
	if (tam==0) {
		primero = new Node();
		primero->elemento[0] = x;
	}
	else {
		cout << "Caso 2" << endl;
		T movidos = primero->elemento[0];
		link punteroaux = primero;
		link punteroemergente = primero;
		int moviendo = 0; //encargado de la posicion global
		int auxmov = 0; // encargado de la posicion dentro del vector
		while (punteroaux->siguiente != NULL) {
			moviendo += N;
			punteroaux = punteroaux->siguiente;
		}
		while (moviendo < tam-1) {
			moviendo++;
			auxmov++;
			//movidos = punteroaux->elemento[auxmov];
		}
		//cout << "Soy auxmoc " << auxmov << endl;
		while (moviendo > -1) {
			cout << "Soy auxmov = " << auxmov << endl;
			if (auxmov == N - 1) {
				cout << "Caso 2a" << endl;
				link punteroanterior = punteroaux;
				punteroaux->siguiente = new Node();
				punteroaux = punteroaux->siguiente;
				punteroaux->elemento[0] = punteroanterior->elemento[auxmov];
				punteroaux = punteroanterior;
				auxmov--;
				moviendo--;
				tam++;
				print();
				tam--;
			}
			else if (auxmov == 0 && tam>N-1) {
				cout << "Caso 2b moviendo" <<moviendo << endl;
				while (punteroemergente != punteroaux && moviendo>2*N) {
					punteroemergente = punteroemergente->siguiente;
				}
				punteroaux->elemento[auxmov] = punteroemergente->elemento[N - 1];
				auxmov = N - 2;
				punteroaux = punteroemergente;
				moviendo--;
				tam++;
				print();
				tam--;
			}
			else {
				cout << "Caso 2c, mov "<< auxmov << endl;
				punteroaux->elemento[auxmov + 1] = punteroaux->elemento[auxmov];
				auxmov--;
				moviendo--;
				tam++;
				print();
				tam--;
			}

		}
		primero->elemento[0] = x;
	}
	tam++;
	print();
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
	int i = pos / 10;
	link index = primero;
	for (int j = 0; j < i; j++) {
		index = index->siguiente;
		if (index == NULL) {
			push_back(x);
			return;
		}
	}
	i = pos % 10;
	T aux = index->elemento[i];
	T aux2 = index->elemento[i + 1];
	index->elemento[i] = x;
	while (aux2 != NULL) {
		index->elemento[i] = aux;
		aux = aux2;
		aux2 = index->elemento[i + 1];
		i++;
		if (i == 8) {
			index->elemento[i + 1] = aux;
			aux = aux2;
			if (index->siguiente == NULL) {
				index->siguiente = new Node();
			}
			index = index->siguiente;
			aux2 = index->elemento[0];
			i = 0;
		}
	}
	index->elemento[i + 1] = aux;
}

template<class T, int N>
bool ListaB<T, N>::remove(int pos, T& x) {
	if (tam>0 && pos<=tam) {
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
			T movidos = primero->elemento[0];
			link punteroaux = primero;
			int moviendo = 0; //encargado de la posicion global
			int auxmov = 0; // encargado de la posicion dentro del vector
			while (pos > N && punteroaux->siguiente!= NULL) {
				moviendo += N;
				punteroaux = punteroaux->siguiente;
			}
			while (auxmov < N && moviendo < pos) {
				moviendo++;
				auxmov++;
				movidos = punteroaux->elemento[auxmov];
			}
			while (moviendo < tam) {
				if (auxmov == N-1) {
					link punteroanterior = punteroaux;
					punteroaux = punteroaux->siguiente;
					punteroanterior->elemento[auxmov] = punteroaux->elemento[0];
					auxmov = 0;
					moviendo++;
				}
				else {
					punteroaux->elemento[auxmov] = punteroaux->elemento[auxmov + 1];
					auxmov++;
					moviendo++;
				}
			}
			tam--;
			return true;
		}
	}
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop(T& x) {
	if (tam < 1) {
		return false;
	}
	else {
		x = primero->elemento[0];
		link punteroaux = primero;
		int moviendo = 0;
		int auxmov = 0;
		while (moviendo < tam) {
			if (auxmov == N - 1) {
				link punteroanterior = punteroaux;
				punteroaux = punteroaux->siguiente;
				punteroanterior->elemento[auxmov] = punteroaux->elemento[0];
				auxmov = 0;
				moviendo++;
			}
			else {
				punteroaux->elemento[auxmov] = punteroaux->elemento[auxmov + 1];
				auxmov++;
				moviendo++;
			}
		}
		tam--;
		return true;
	}
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
	if (pos > tam || tam==0) {
		return false;
	}
	link punteroaux = primero;
	int moviendo = 0; //encargado de la posicion global
	int auxmov = 0; // encargado de la posicion dentro del vector
	while (pos > N && punteroaux->siguiente != NULL) {
		moviendo += N;
		punteroaux = punteroaux->siguiente;
	}
	while (auxmov < N && moviendo < pos) {
		moviendo++;
		auxmov++;
	}
	element = punteroaux->elemento[auxmov];
	return true;
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
	if (tam>0) {
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
	cout << "Printing ";
	cout << nombreLista << " = [";
	if (tam>0) {
		link p = primero;
		int pasada = 0;
		while (p!=NULL) {
			int cont = 0;
			while (cont < N && cont+(N*pasada) < tam) {
				cout << p->elemento[cont];
				cont++;
				if (cont + (N * pasada) < tam) {
					cout << ", ";
				}
			}
			pasada++;
			p = p->siguiente;
		}
	}
	cout << "] \n";
}