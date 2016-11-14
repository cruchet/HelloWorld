/*
 * Polynomial.h
 *
 *  Created on: 17 oct. 2016
 *      Author: Vassili
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <iostream>

using namespace std;

class Polynomial {
public:
	Polynomial();
	Polynomial(int deg, vector<double>* coeff);	//coefficient donné à partir
												//du deg le plus élevé
	virtual ~Polynomial();

	int get_deg();
	void get_coeff(vector<double>* coeff);
	void set_deg(int deg);
	void set_coeff(vector<double>* coeff);

	Polynomial operator + (Polynomial);
	friend ostream& operator<< (ostream&, const Polynomial&);
	friend istream& operator>> (istream&, Polynomial&);

private:
	int deg_;
	vector<double> coeff_;
};

#endif /* POLYNOMIAL_H_ */
