/*
 * exo1.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: ythierry
 */


#include "strutil.h"

#include <iostream>

using namespace pr;
using namespace std;


int main () {
	const char * str = "Hello";
	char * copy = newcopy(str);

	cout << str << length(str) << endl;
	cout << copy << length(copy) << endl;

	// A ajouter dans un deuxieme temps
	delete[] copy;

	return 0;
}

