/*
 * Marc Bolinas
 * Brian Phillips
 *
 * TA: Eeshita Biswas
 *
 * 10/11/17
 * LAB 4
 *
 *
 *
 */


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "matrix.hpp"
#include "hexint.hpp"
#include <math.h>
using namespace std;







string to_ithag(string s, int &length);

bool is_vowel(string s);

int hex_to_int(string hex);

int hti(string hex, int power);

string int_to_hex(int i);

string ** gen_matrix(int &i, int &j);

void print_matrix(string **mat, int x, int y);

void gen_x(string **mat, int x, int y);









int main(){
	srand(time(NULL));

	cout << "********************************************************" << endl;
	cout << "PROBLEM 1" << endl;
	int l1 = 5;
	int l2 = 7;
	int l3 = 3;
	cout << to_ithag("hello",l1) << endl;
	cout << "size : " << l1 << endl;
	cout << to_ithag("friends",l2) << endl;
	cout << "size : " << l2 << endl;
	cout << to_ithag("bye",l3) << endl;
	cout << "size : " << l3 << endl;

	cout << "********************************************************" << endl;
	cout << "PROBLEM 2" << endl;
	cout << hex_to_int("1A4") << endl;
	cout << hex_to_int("6A4C") << endl;
	cout << hex_to_int("24E") << endl;

	cout << "********************************************************" << endl;
	cout << "PROBLEM 3" << endl;
	cout << int_to_hex(27212) << endl;
	cout << int_to_hex(590) << endl;
	cout << int_to_hex(120) << endl;

	cout << "********************************************************" << endl;
	cout << "PROBLEM 4" << endl;
	hexint *hi1 = new hexint(345);
	hexint *hi2 = new hexint(4322);
	hexint *hi3 = new hexint(483);
	hexint *hi4 = new hexint("AAA");
	hexint *hi5 = new hexint("234");
	hexint *hi6 = new hexint("4CE3A");
	cout << hi1->get_hex() << endl;
	cout << hi2->get_hex() << endl;
	cout << hi3->get_hex() << endl;
	cout << hi4->get_int() << endl;
	cout << hi5->get_int() << endl;
	cout << hi6->get_int() << endl;

	cout << "********************************************************" << endl;
	cout << "PROBLEM 5" << endl;
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	string **mat1 = gen_matrix(x1, y1);
	string **mat2 = gen_matrix(x2, y2);
	string **mat3 = gen_matrix(x3, y3);
	gen_x(mat1, x1 , y1);
	gen_x(mat2, x2 , y2);
	gen_x(mat3, x3 , y3);
	print_matrix(mat1, x1, y1);
	print_matrix(mat2, x2, y2);
	print_matrix(mat3, x3, y3);

	cout << "********************************************************" << endl;
	cout << "PROBLEM 6" << endl;
	matrix *m1 = new matrix(3,4);
	matrix *m2 = new matrix(7,7);
	matrix *m3 = new matrix(3,8);
	m1->add_x();
	m2->add_x();
	m3->add_x();
	m1->print();
	m2->print();
	m3->print();


//	for(int x = 0; x < i; x++){
//		delete m[x];
//	}
//
//	delete m;

	return 0;
}





string to_ithag(string s, int &length){
	for(int i = 0; i < length; i++){
		if(is_vowel(s.substr(i, 1))){
			string temp = s.substr(i, length-i);
			string new_s = s.substr(0, i) + "ithag" + temp;
			s = new_s;
			length = length + 5;
			i = i + 5;
		}
	}
	return s;
}

bool is_vowel(string s){
	if(s == "a"){
		return true;
	}
	else if(s == "e"){
		return true;
	}
	else if(s == "i"){
		return true;
	}
	else if(s == "o"){
		return true;
	}
	else if(s == "u"){
		return true;
	}
	else if(s == "y"){
		return true;
	}
	else{
		return false;
	}
}

int hex_to_int(string hex){
	return hti(hex, 0);
}

int hti(string hex, int power){
	if(hex == ""){
		return 0;
	}
	else{
		string last = hex.substr(hex.length() - 1, 1);
		int conv = 0;
		if(last == "A"){
			conv = 10;
		}
		else if(last == "B"){
			conv = 11;
		}
		else if(last == "C"){
			conv = 12;
		}
		else if(last == "D"){
			conv = 13;
		}
		else if(last == "E"){
			conv = 14;
		}
		else if(last == "F"){
			conv = 15;
		}
		else{
			conv = stoi(last);
		}
		hex.pop_back();
		conv = conv * pow(16,power);
		return (hti(hex, power + 1) + conv);
	}
}

string int_to_hex(int i){
	if(i == 0){
		return "";
	}
	else{
		int temp = i % 16;
		string s = "";

		if(temp == 15){
			s = "F";
		}
		else if(temp == 14){
			s = "E";
		}
		else if(temp == 13){
			s = "D";
		}
		else if(temp == 12){
			s = "C";
		}
		else if(temp == 11){
			s = "B";
		}
		else if(temp == 10){
			s = "A";
		}
		else{
			s = to_string(temp);
		}
		return int_to_hex(i / 16) + s;
	}
}

string ** gen_matrix(int &i, int &j){
	i = rand() % 7 + 3;
	j = rand() % 7 + 3;

	string **mat = new string*[i];
	for(int c = 0; c < i; c++){
		mat[c] = new string[j];
	}
	for(int x = 0; x < i; x++){
		for(int y = 0; y < j; y++){
			mat[x][y] = "0";
		}
	}

	return mat;
}

void print_matrix(string **mat, int x, int y){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void gen_x(string **mat, int x, int y){
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


