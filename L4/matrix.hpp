/*
 * matrix.hpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Marc
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class matrix{
	string **mat;
	int x;
	int y;
public:
	matrix();
	matrix(int width, int length);

	void make();
	void print();
	void add_x();

	~matrix();




};





#endif /* MATRIX_HPP_ */
