/*
 * hexint.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Marc
 */


#include "hexint.hpp"
#include <math.h>

using namespace std;

hexint::hexint(int x){
	i = x;
	s = "";
	int_to_hex();
}

hexint::hexint(string x){
	s = x;
	i = 0;
	hex_to_int();
}

void hexint::hex_to_int(){
	string st = s;
	int power = 0;
	while(st != ""){
		string last = st.substr(st.length() - 1, 1);
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
		st.pop_back();
		conv = conv * pow(16,power);
		i = i + conv;
		power++;
	}
}

void hexint::int_to_hex(){
	int x = i;
	while(x > 0){
		int temp = x % 16;
		string st = "";

		if(temp == 15){
			st = "F";
		}
		else if(temp == 14){
			st = "E";
		}
		else if(temp == 13){
			st = "D";
		}
		else if(temp == 12){
			st = "C";
		}
		else if(temp == 11){
			st = "B";
		}
		else if(temp == 10){
			st = "A";
		}
		else{
			st = to_string(temp);
		}
		x = x / 16;
		s = st + s;
	}
}

string hexint::get_hex(){
	return s;
}

int hexint::get_int(){
	return i;
}
