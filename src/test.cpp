/*

test.cpp
	2025-06-11 ver.3 add test file

*/

#include <iostream>
#include <format>
#include "tmath_M.hpp"

int main() {
	for (int n = 2; n < 6; n++) {
		std::cout << "check " << n << " bit : ";
		tmath_M::bits a = n;
		tmath_M::bits b = n;
		tmath_M::bits d = n; d[0] = '1';
		for (int y = 0; y < (std::pow(2, n) / 1); y++) {
			b = n;
			for (int x = 0; x < (std::pow(2, n) / 1); x++) {
				{
					auto [s, c] = tmath_M::ADD(a, b);
					tmath_M::bits result = c.data + s.data();
					if (result.value() != (a.value() + b.value())) std::cout << "error + : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() + b.value()) << std::endl;
				}
				{
					auto result = tmath_M::MUL(a, b);
					if (result.value() != (a.value() * b.value())) std::cout << "error * : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() * b.value()) << std::endl;
				}
				if (a.value() >= b.value()) {
					auto [result, c] = tmath_M::SUB(a, b);
					if (result.value() != (a.value() - b.value())) std::cout << "error - : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() - b.value()) << std::endl;
				}
				if (b.value() != 0) {
					tmath_M::bits result = tmath_M::DIV(a, b);
					if (result.value() != (a.value() / b.value())) std::cout << "error / : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() / b.value()) << std::endl;
				}
				auto [s, c] = tmath_M::ADD(b, d); b = s;
			}
			auto [s, c] = tmath_M::ADD(a, d); a = s;
		}
		std::cout << "ok" << std::endl;

	}

	for (int n = 2; n < 6; n++) {
		std::cout << "check " << n << " tbit : ";
		tmath_M::tbits a = n;
		tmath_M::tbits b = n;
		tmath_M::tbits d = n; d[0] = '1';
		for (int y = 0; y < (std::pow(3, n) / 2); y++) {
			b = n;
			for (int x = 0; x < (std::pow(3, n) / 2); x++) {
				{
					auto [s, c] = tmath_M::ADD(a, b);
					tmath_M::tbits result = c.data + s.data();
					if (result.value() != (a.value() + b.value())) std::cout << "error + : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() + b.value()) << std::endl;
				}
				{
					auto result = tmath_M::MUL(a, b);
					if (result.value() != (a.value() * b.value())) std::cout << "error * : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() * b.value()) << std::endl;
				}
				if (a.value() >= b.value()) {
					auto [result, c] = tmath_M::SUB(a, b);
					if (result.value() != (a.value() - b.value())) std::cout << "error - : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() - b.value()) << std::endl;
				}
				if (b.value() != 0) {
					tmath_M::tbits result = tmath_M::DIV(a, b);
					if (result.value() != (a.value() / b.value())) std::cout << "error / : " << a.value() << " : " << b.value() << " : " << result.value() << " : " << (a.value() / b.value()) << std::endl;
				}
				auto [s, c] = tmath_M::ADD(b, d); b = s;
			}
			auto [s, c] = tmath_M::ADD(a, d); a = s;
		}
		std::cout << "ok" << std::endl;

	}

	std::cout << "finish" << std::endl;
	system("pause");

	return 0;
}

