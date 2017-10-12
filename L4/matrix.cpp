/*
 * matrix.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Marc
 */



#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "matrix.hpp"


matrix::matrix(){
	x = 0;
	y = 0;
	make();
}

matrix::matrix(int w, int l){
	x = w;
	y = l;
	make();
}

void matrix::make(){
	mat = new string*[x];
	for(int c = 0; c < x; c++){
		mat[c] = new string[y];
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			mat[i][j] = "0";
		}
	}
}

void matrix::print(){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void matrix::add_x(){
	int how_many_x_to_give_to_ya = 5;
	while(how_many_x_to_give_to_ya > 0){
		int i = rand() % x;
		int j = rand() % y;
		if(mat[i][j] != "x"){
			mat[i][j] = "x";
			how_many_x_to_give_to_ya--;
		}
	}
}

matrix::~matrix(){
	for(int i = 0; i < x; i++){
		delete mat[i];
	}
	delete mat;
}
