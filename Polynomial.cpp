/*
 * Polynomial.cpp
 *
 *  Created on: 17 oct. 2016
 *      Author: Vassili
 */

#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

Polynomial::Polynomial() : deg_(0), coeff_(0) {}

//Constructeur parametre
Polynomial::Polynomial(int deg, vector<double>* coeff) {
	deg_ = deg; // une liste d'initialisation aurait été plus efficace
	for(int i=0; i<=deg; i++)
		coeff_.push_back(coeff->at(i));
}

Polynomial::~Polynomial() {
	// TODO Auto-generated destructor stub
}

int Polynomial::get_deg() {
	return deg_;
}

void Polynomial::get_coeff(vector<double>* coeff) {
	for(int i=0; i<=deg_; i++)
		coeff->push_back(coeff_[i]);
}

void Polynomial::set_deg(int deg) {
	deg_ = deg;
	cout << deg_ << endl;
}

void Polynomial::set_coeff(vector<double>* coeff) {
	for(int i=0; i<=deg_; i++)
		coeff_.push_back(coeff->at(i));

	cout << endl;

}

// Affichage
ostream& operator<< (ostream& os, const Polynomial& p) {
	for(int i=0; i<=p.deg_; i++) {
		if(i<(p.deg_ - 1) && p.coeff_[i]!=0)
			os << p.coeff_[i] << "x^" << p.deg_ -i << " + ";
		else if(p.coeff_[i]!=0){
			os << p.coeff_[i] ;
			if(i!=p.deg_)
				os << "x + ";
		}
	}
	os << endl;
	return os;
}


// Entrée
istream& operator>> (istream& is, Polynomial& p) {
	int deg;
	double a;
	vector<double> coeff;
	cout << "Entrée d'un polynôme:\n" << "Degré: ";
	is >> deg;
	cout << endl;
	p.set_deg(deg);

	cout << "Coefficients:" << endl;
	for(int i=0; i<=deg; i++) {
		is >> a;
		coeff.push_back(a);
	}
	p.set_coeff(&coeff);
	return is;
}

Polynomial Polynomial::operator + (Polynomial p) { //utiliser this pour clarifier
	int r_deg = max(deg_ , p.deg_);
	vector<double> r_coeff(r_deg+1);

	Polynomial res(r_deg, &r_coeff);

	int delta_deg = abs(deg_ - p.deg_);

	for(int i=0; i<=res.deg_; i++) {
		if(delta_deg == 0) {
			res.coeff_[i] = coeff_[i] + p.coeff_[i];
		}

		else if(deg_ > p.deg_) {
			if(i>=delta_deg)
				res.coeff_[i] = coeff_[i] + p.coeff_[i-delta_deg];
			else if(i<delta_deg)
				res.coeff_[i] = coeff_[i];
		}

		else if(deg_ < p.deg_) {
			if(i>=delta_deg){
				res.coeff_[i] = coeff_[i-delta_deg] + p.coeff_[i];
			}
			else if(i<delta_deg)
				res.coeff_[i] = p.coeff_[i];  //termes du plus haut degres
		}
	}
	return res; // une référence peut être plus efficace
}
