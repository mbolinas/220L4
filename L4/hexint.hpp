/*
 * hexint.hpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Marc
 */

#ifndef HEXINT_HPP_
#define HEXINT_HPP_
#include <string>
using namespace std;

class hexint{
	int i;
	string s;
public:
	hexint(int x);
	hexint(string x);

	void hex_to_int();
	void int_to_hex();

	void set_int(int x);
	void set_hex(string x);
	int get_int();
	string get_hex();
};



#endif /* HEXINT_HPP_ */
