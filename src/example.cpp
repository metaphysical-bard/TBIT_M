/*

example.cpp
	2025-06-09 ver.1
	2025-06-11 ver.2

*/

#include <iostream>
#include <format>
#include "tmath_M.hpp"

int main() {
	{
		std::cout << "BIT TEST" << std::endl;

		std::cout << std::endl;

		tmath_M::bits a = "01";
		tmath_M::bits b0 = "00";
		tmath_M::bits b1 = "11";

		std::cout << "not : " << a.n().data() << std::endl;

		std::cout << std::endl;

		std::cout << "nand   01" << std::endl;
		std::cout << "   0 : " << (a & b0).data() << std::endl;
		std::cout << "   1 : " << (a & b1).data() << std::endl;

		std::cout << std::endl;

		std::cout << "nor    01" << std::endl;
		std::cout << "   0 : " << (a | b0).data() << std::endl;
		std::cout << "   1 : " << (a | b1).data() << std::endl;

		std::cout << std::endl;

		std::cout << std::endl;
	}

	{
		std::cout << "TBIT TEST" << std::endl;

		std::cout << std::endl;

		tmath_M::tbits a = "T01";
		tmath_M::tbits bT = "TTT";
		tmath_M::tbits b0 = "000";
		tmath_M::tbits b1 = "111";

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

		std::cout << std::endl;
	}

	{
		std::cout << "four arithmetic operations (bits)" << std::endl;

		std::cout << std::endl;

		tmath_M::bits a = "1100";
		tmath_M::bits b = "0010";
		tmath_M::bits result = '0';

		auto [sa, ca] = tmath_M::ADD(a, b);
		result = ca.data + sa.data();
		std::cout << std::format("{} ({}) + {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		auto [ss, cs] = tmath_M::SUB(a, b);
		result = ss.data();
		std::cout << std::format("{} ({}) - {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		result = tmath_M::MUL(a, b);
		std::cout << std::format("{} ({}) * {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		result = tmath_M::DIV(a, b);
		std::cout << std::format("{} ({}) / {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		std::cout << std::endl;

		std::cout << std::endl;
	}

	{
		std::cout << "four arithmetic operations (tbits)" << std::endl;

		std::cout << std::endl;

		tmath_M::tbits a = "0110";
		tmath_M::tbits b = "001T";
		tmath_M::tbits result = '0';

		auto [sa, ca] = tmath_M::ADD(a, b);
		result = ca.data + sa.data();
		std::cout << std::format("{} ({}) + {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		auto [ss, cs] = tmath_M::SUB(a, b);
		result = ss.data();
		std::cout << std::format("{} ({}) - {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		result = tmath_M::MUL(a, b);
		std::cout << std::format("{} ({}) * {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		result = tmath_M::DIV(a, b);
		std::cout << std::format("{} ({}) / {} ({}) = {} ({})", a.data(), a.value(), b.data(), b.value(), result.data(), result.value()) << std::endl;

		std::cout << std::endl;

		std::cout << std::endl;
	}

	return 0;
}

