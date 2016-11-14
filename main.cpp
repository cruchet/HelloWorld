/*
 * main.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: Vassili
 */

#include <iostream>
#include <vector>
#include "Polynomial.h"

using namespace std;
int main() {

	/*int deg1 = 5;
	int deg2 = 3;
	vector<double> coeff1 = {-12,0,3, -2, 7, -8}; //c++11
	vector<double> coeff2 = {10, 0, -3, 4};

	Polynomial p1(deg1, &coeff1);
	Polynomial p2(deg2, &coeff2);*/

	Polynomial p1;
	cin >> p1;

	Polynomial p2;
	cin >> p2;

	cout <<	"P1(x) = "<< p1
		 <<	"P2(x) = "<< p2;
	cout << endl;

	Polynomial p3 = p1 + p2;


	cout << "P1(x) + P2(x) = "<< p3;
	cout << endl;
	return 0;
}


