// TareaCorta2Prueba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListB.h"

int main() {

	List<int> lm("Lista1");
	
	cout << "*******************************************************************" << endl;
	cout << "********************* PRUEBAS PARA LA LISTA Simple *********************" << endl;
	cout << "*******************************************************************" << endl;
	cout << " 1. Largo de la lista and Push_front() " << endl;
	cout << "-- Sin insertar elementos --" << endl;
	lm.print();
	cout << "-- Insertando elementos en solo un nodo --" << endl;
	lm.push_front(60);
	lm.push_front(70);
	lm.print();
	cout << "-- Insertando mas de diez elementos --" << endl;
	lm.push_front(1);
	lm.push_front(2);
	lm.push_front(3);
	lm.push_front(4);
	lm.push_front(5);
	lm.push_front(6);
	lm.push_front(7);
	lm.push_front(8);
	lm.push_front(9);
	lm.push_front(10);
	lm.push_front(11);
	lm.push_front(12);
	lm.push_front(13);
	lm.push_front(14);
	lm.print();
	cout << "\n*******************************************************************" << endl;
	cout << "2. Prueba para pop back.  " << endl;
	while (lm.len() != 1) {
		int x = 0;
		lm.pop_back(x);
		cout << " Resultado: " << x << endl;
	}
	cout << " Prueba pop back para un elemento" << endl;
	lm.print();
	int x = 0;
	lm.pop_back(x);
	cout << " Resultado = " << x << endl;
	lm.print();

	lm.push_front(1);
	lm.push_front(2);
	lm.push_front(3);
	lm.push_front(4);
	lm.push_front(5);
	lm.push_front(6);
	lm.push_front(7);
	lm.push_front(8);
	lm.push_front(9);
	lm.push_front(10);
	lm.push_front(11);
	lm.push_front(12);
	lm.push_front(13);
	lm.push_front(14);

	cout << "\n***********************************************************************************************" << endl;
	cout << "3. Prueba para pop .  " << endl;
	lm.print();
	while (lm.len() != 1) {
		int x = 0;
		lm.pop(x);
		cout << " Resultado: " << x << endl;
	}
	cout << "\n Prueba pop en un elemento" << endl;
	lm.print();
	int x1 = 0;
	lm.pop(x);
	cout << " Resultado = " << x << endl;
	lm.print();


	cout << "\n***********************************************************************************************" << endl;
	cout << " 4. Prueba para Push_back() " << endl;
	cout << "-- Sin insertar elementos --" << endl;
	lm.print();
	cout << "-- Insertando elementos en solo un nodo --" << endl;
	lm.push_back(60);
	lm.push_back(70);
	lm.print();
	cout << "-- Insertando mas de diez elementos --" << endl;
	lm.push_front(1);
	lm.push_front(2);
	lm.push_front(3);
	lm.push_front(4);
	lm.push_front(5);
	lm.push_front(6);
	lm.push_front(7);
	lm.push_front(8);
	lm.push_front(9);
	lm.push_front(10);
	lm.push_front(11);
	lm.push_front(12);
	lm.push_front(13);
	lm.push_front(14);
	lm.print();


	cout << "\n***********************************************************************************************" << endl;
	cout << " 5. Prueba para get_back() and get_front() " << endl;
	cout << " Con los elementos de la ultima prueba " << endl;
	lm.get_back(x);
	cout << " Resultado get_back(): " << x << endl;
	lm.get_front(x);
	cout << "\n Resultado del get_front(): " << x << endl;
	while (lm.len() != 0) {
		int x = 0;
		lm.pop(x);
	}
	cout << "\n Prueba con la lista vacia debe retornar un 0,\n ya que es el elemento con el que se inicia la variable x " << endl;
	x = 0;
	lm.get_back(x);
	cout << " Resultado del get_back: " << x << endl;
	lm.get_front(x);
	cout << "\n Resultado del get_front(): " << x << endl;

	cout << "\n***********************************************************************************************" << endl;
	lm.push_front(1);
	lm.push_front(2);
	lm.push_front(3);
	lm.push_front(4);
	lm.push_front(5);
	lm.push_front(6);
	lm.push_front(7);
	lm.push_front(8);
	lm.push_front(9);
	lm.push_front(10);
	lm.push_front(11);
	lm.push_front(12);
	lm.push_front(13);
	lm.push_front(14);
	cout << " 5. Prueba para get en posicion " << endl;
	cout << " Con la lista ";
	lm.print();
	lm.get(5, x);
	cout << " Resultado de la operacion get(5) :" << x << endl;
	lm.get(13, x);
	cout << " Resultado de la operacion get(13) :" << x << endl;

	cout << "\n***********************************************************************************************" << endl;
	cout << " 5. Prueba para remove en posicion con la lista anterior " << endl;
	bool cierto = lm.remove(13, x);
	cout << "El resultado de la operacion remove(13, x) fue un " << cierto << " y se almaceno el valor " << x << endl;
	lm.print();

	cout << "\n***********************************************************************************************" << endl;
	cout << " Prueba para insert en la lista anterior"<<endl;
	lm.insertar(400, 10);
	cout << "Resultado de la operacion de insertar un 400 en la posicion 10" << endl;
	lm.print();


	/***********************************************************************************************************************************************************************************************/
	ListaB<int, 10> lp("ListaP");
	cout << "\n \n*******************************************************************" << endl;
	cout << "********************* PRUEBAS PARA LA LISTA B *********************" << endl;
	cout << "*******************************************************************" << endl;
	cout << " 1. Largo de la lista and Push_front() " << endl;
	cout << "-- Sin insertar elementos --" << endl;
	lp.print();
	cout << "-- Insertando elementos en solo un nodo --" << endl;
	lp.push_front(60);
	lp.push_front(70);
	lp.print();
	cout << "-- Insertando mas de diez elementos --" << endl;
	lp.push_front(1);
	lp.push_front(2);
	lp.push_front(3);
	lp.push_front(4);
	lp.push_front(5);
	lp.push_front(6);
	lp.push_front(7);
	lp.push_front(8);
	lp.push_front(9);
	lp.push_front(10);
	lp.push_front(11);
	lp.push_front(12);
	lp.push_front(13);
	lp.push_front(14);
	lp.print();
	cout << "\n*******************************************************************" << endl;
	cout << "2. Prueba para pop back.  " << endl;
	while (lp.len() != 1) {
		int x = 0;
		lp.pop_back(x);
		cout << " Resultado: " << x << endl;
	}
	cout << " Prueba pop back para un elemento" << endl;
	lp.print();
	x = 0;
	lp.pop_back(x);
	cout << " Resultado = " << x << endl;
	lp.print();
	
	lp.push_front(1);
	lp.push_front(2);
	lp.push_front(3);
	lp.push_front(4);
	lp.push_front(5);
	lp.push_front(6);
	lp.push_front(7);
	lp.push_front(8);
	lp.push_front(9);
	lp.push_front(10);
	lp.push_front(11);
	lp.push_front(12);
	lp.push_front(13);
	lp.push_front(14);

	cout << "\n***********************************************************************************************" << endl;
	cout << "3. Prueba para pop .  " << endl;
	lp.print();
	while (lp.len() != 1) {
		int x = 0;
		lp.pop(x);
		cout << " Resultado: " << x << endl;
	}
	cout << "\n Prueba pop back para un elemento" << endl;
	lp.print();
	x1 = 0;
	lp.pop(x);
	cout << " Resultado = " << x << endl;
	lp.print();


	cout << "\n***********************************************************************************************" << endl;
	cout << " 4. Prueba para Push_back() " << endl;
	cout << "-- Sin insertar elementos --" << endl;
	lp.print();
	cout << "-- Insertando elementos en solo un nodo --" << endl;
	lp.push_back(60);
	lp.push_back(70);
	lp.print();
	cout << "-- Insertando mas de diez elementos --" << endl;
	lp.push_back(1);
	lp.push_back(2);
	lp.push_back(3);
	lp.push_back(4);
	lp.push_back(5);
	lp.push_back(6);
	lp.push_back(7);
	lp.push_back(8);
	lp.push_back(9);
	lp.push_back(10);
	lp.push_back(11);
	lp.push_back(12);
	lp.push_back(13);
	lp.push_back(14);
	lp.print();


	cout << "\n***********************************************************************************************" << endl;
	cout << " 5. Prueba para get_back() and get_front() " << endl;
	cout << " Con los elementos de la ultima prueba " << endl;
	lp.get_back(x);
	cout << " Resultado get_back(): " << x << endl;
	lp.get_front(x);
	cout << "\n Resultado del get_front(): " << x << endl;
	while (lp.len() != 0) {
		int x = 0;
		lp.pop(x);
	}
	cout << "\n Prueba con la lista vacia debe retornar un 0,\n ya que es el elemento con el que se inicia la variable x " << endl;
	x = 0;
	lp.get_back(x);
	cout << " Resultado del get_back: " << x << endl;
	lp.get_front(x);
	cout << "\n Resultado del get_front(): " << x << endl;

	cout << "\n***********************************************************************************************" << endl;
	lp.push_back(1);
	lp.push_back(2);
	lp.push_back(3);
	lp.push_back(4);
	lp.push_back(5);
	lp.push_back(6);
	lp.push_back(7);
	lp.push_back(8);
	lp.push_back(9);
	lp.push_back(10);
	lp.push_back(11);
	lp.push_back(12);
	lp.push_back(13);
	lp.push_back(14);
	cout << " 5. Prueba para get en posicion " << endl;
	cout << " Con la lista ";
	lp.print();
	lp.get(5,x);
	cout << " Resultado de la operacion get(5) :" << x << endl;
	lp.get(13, x);
	cout << " Resultado de la operacion get(13) :" << x << endl;

	cout << "\n***********************************************************************************************" << endl;
	cout << " 5. Prueba para remove en posicion con la lista anterior " << endl;
	cierto = lp.remove(13, x);
	cout << "El resultado de la operacion remove(13, x) fue un " << cierto << " y se almaceno el valor " << x << endl;
	lp.print();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
