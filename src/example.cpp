/*

example.cpp

*/

#include <iostream>
#include "tbit_M.hpp"

int main() {

	std::cout << "BIT TEST" << std::endl;

	std::cout << std::endl;

	bits_M r = "01";
	bits_M p0 = "00";
	bits_M p1 = "11";

	std::cout << "not : " << r.n().data() << std::endl;

	std::cout << std::endl;

	std::cout << "nand   01" << std::endl;
	std::cout << "   0 : " << (r & p0).data() << std::endl;
	std::cout << "   1 : " << (r & p1).data() << std::endl;

	std::cout << std::endl;

	std::cout << "nor    01" << std::endl;
	std::cout << "   0 : " << (r | p0).data() << std::endl;
	std::cout << "   1 : " << (r | p1).data() << std::endl;

	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "TBIT TEST" << std::endl;

	std::cout << std::endl;

	tbits_M a = "T01";
	tbits_M bT = "TTT";
	tbits_M b0 = "000";
	tbits_M b1 = "111";

	std::cout << "not (10T) : " << a.n10T().data() << std::endl;
	std::cout << "not (110) : " << a.n110().data() << std::endl;
	std::cout << "not (100) : " << a.n100().data() << std::endl;
	std::cout << "not (00T) : " << a.n00T().data() << std::endl;
	std::cout << "not (0TT) : " << a.n0TT().data() << std::endl;

	std::cout << std::endl;

	std::cout << "nand   T01" << std::endl;
	std::cout << "   T : " << (a & bT).data() << std::endl;
	std::cout << "   0 : " << (a & b0).data() << std::endl;
	std::cout << "   1 : " << (a & b1).data() << std::endl;

	std::cout << std::endl;

	std::cout << "nor    T01" << std::endl;
	std::cout << "   T : " << (a | bT).data() << std::endl;
	std::cout << "   0 : " << (a | b0).data() << std::endl;
	std::cout << "   1 : " << (a | b1).data() << std::endl;

	std::cout << std::endl;

	std::cout << "ncons  T01" << std::endl;
	std::cout << "   T : " << (a * bT).data() << std::endl;
	std::cout << "   0 : " << (a * b0).data() << std::endl;
	std::cout << "   1 : " << (a * b1).data() << std::endl;

	std::cout << std::endl;

	std::cout << "nany   T01" << std::endl;
	std::cout << "   T : " << (a + bT).data() << std::endl;
	std::cout << "   0 : " << (a + b0).data() << std::endl;
	std::cout << "   1 : " << (a + b1).data() << std::endl;

	std::cout << std::endl;

	return 0;
}

