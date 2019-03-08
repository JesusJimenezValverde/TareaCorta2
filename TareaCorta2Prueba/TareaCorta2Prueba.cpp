// TareaCorta2Prueba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ListaSimple.h"

int main() {

	List<int> lm("Lista1");

	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	
	lm.push_back(40);
	lm.insertarR(5, 0);
	//lm.insertarR(8, 1);
	//lm.insertarR(15, 5);
	//lm.insertarR(50, 99);
	//lm.insertarR(999, 1);
	lm.print();
	cout << "" << endl;
	
	//************ Pruebas ***************\\

	int devuelve = 0;
	lm.get(2, devuelve);
	cout << "El get obtuvo: " << devuelve << endl;
	//lm.remove(0, devuelve);
	lm.print();
	cout << "\n";
	
	
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();
	cout << "\n";

	//system("pause");
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
