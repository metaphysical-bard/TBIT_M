/*

tbit_M.hpp
	2025-06-09 ver.1 first commit
	2025-06-11 ver.2 add new namespace

*/

#pragma once
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
#include <initializer_list>

namespace tmath_M {

	class bit {
	public:
		char data = '0';

		bit(char init) {
			assert(init == '0' || init == '1');
			data = init;
		}

		int value() {
			if (data == '0') return 0;
			else if (data == '1') return 1;
		}

		bit& operator=(const bit& s) {
			data = s.data;
			return *this;
		}

		bit n() {
			if (data == '0') return bit('1');
			else if (data == '1') return bit('0');
		}

		friend bit operator&(const bit& a, const bit& b) {
			bit result = '1';
			if (a.data == '1' && b.data == '1') result = '0';
			return result;
		}

		friend bit operator|(const bit& a, const bit& b) {
			bit result = '0';
			if (a.data == '0' && b.data == '0') result = '1';
			return result;
		}
	};

	class bits {
	private:
		std::vector<bit> ary = {};

		template<typename T>
		void reset(T& value, bool r = false) {
			ary.assign(value.begin(), value.end());
			if (r) reverse(ary.begin(), ary.end());
			for (int i = 0; i < ary.size(); i++) assert(ary[i].data == '0' || ary[i].data == '1');
		}

	public:
		bits(int n) {
			std::vector<char> init(n, '0');
			reset(init);
		}

		bits(std::initializer_list<int> init) { reset(init); }
		bits(std::vector<char> init) { reset(init); }
		bits(std::string init) { reset(init, true); }
		bits(const char* init) {
			std::string str = init;
			reset(str, true);
		}

		std::string data() {
			std::string str = "";
			for (int i = 0; i < ary.size(); i++) str = ary[i].data + str;
			return str;
		}

		int value() {
			int num = 0;
			for (int i = 0; i < ary.size(); i++) num += (ary[i].value() * std::pow(2, i));
			return num;
		}

		int size() const {
			return ary.size();
		}

		bit operator[](int n) const {
			assert(n >= 0 && n < ary.size());
			return ary[n];
		}

		bit& operator[](int n) {
			assert(n >= 0 && n < ary.size());
			return ary[n];
		}

		bits& operator=(const bits& s) {
			reset(s.ary);
			return *this;
		}

		bits n() {
			bits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n();
			return result;
		}

		friend bits operator&(const bits& a, const bits& b) {
			assert(a.size() == b.size());
			bits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] & b[i];
			return c;
		}

		friend bits operator|(const bits& a, const bits& b) {
			assert(a.size() == b.size());
			bits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] | b[i];
			return c;
		}
	};

	class tbit {
	private:
		static char getTruthValue(char a, char b, char* t) {
			int n = 0;
			if (a == '0') n += 1;
			else if (a == '1') n += 2;
			if (b == '0') n += 3;
			else if (b == '1') n += 6;
			return t[n];
		}

	public:
		char data = '0';

		tbit(char init) {
			assert(init == 'T' || init == '0' || init == '1');
			data = init;
		}

		int value() {
			if (data == 'T') return -1;
			else if (data == '0') return 0;
			else if (data == '1') return 1;
		}

		tbit& operator=(const tbit& s) {
			data = s.data;
			return *this;
		}

		tbit n10T() {
			char table[] = { '1', '0', 'T' };
			tbit result = tbit::getTruthValue(data, 'T', table);
			return result;
		}

		tbit n110() {
			char table[] = { '1', '1', '0' };
			tbit result = tbit::getTruthValue(data, 'T', table);
			return result;
		}

		tbit n100() {
			char table[] = { '1', '0', '0' };
			tbit result = tbit::getTruthValue(data, 'T', table);
			return result;
		}

		tbit n0TT() {
			char table[] = { '0', 'T', 'T' };
			tbit result = tbit::getTruthValue(data, 'T', table);
			return result;
		}

		tbit n00T() {
			char table[] = { '0', '0', 'T' };
			tbit result = tbit::getTruthValue(data, 'T', table);
			return result;
		}

		friend tbit operator&(const tbit& a, const tbit& b) {
			char table[] = {
				'1', '1', '1',
				'1', '0', '0',
				'1', '0', 'T'
			};
			tbit c = tbit::getTruthValue(a.data, b.data, table);
			return c;
		}

		friend tbit operator|(const tbit& a, const tbit& b) {
			char table[] = {
				'1', '0', 'T',
				'0', '0', 'T',
				'T', 'T', 'T'
			};
			tbit c = tbit::getTruthValue(a.data, b.data, table);
			return c;
		}

		friend tbit operator*(const tbit& a, const tbit& b) {
			char table[] = {
				'1', '0', '0',
				'0', '0', '0',
				'0', '0', 'T'
			};
			tbit c = tbit::getTruthValue(a.data, b.data, table);
			return c;
		}

		friend tbit operator+(const tbit& a, const tbit& b) {
			char table[] = {
				'1', '1', '0',
				'1', '0', 'T',
				'0', 'T', 'T'
			};
			tbit c = tbit::getTruthValue(a.data, b.data, table);
			return c;
		}
	};

	class tbits {
	private:

		std::vector<tbit> ary = {};

		template<typename T>
		void reset(T& value, bool r = false) {
			ary.assign(value.begin(), value.end());
			if (r) reverse(ary.begin(), ary.end());
			for (int i = 0; i < ary.size(); i++) assert(ary[i].data == 'T' || ary[i].data == '0' || ary[i].data == '1');
		}

	public:
		tbits(int n) {
			std::vector<char> init(n, '0');
			reset(init);
		}

		tbits(std::initializer_list<int> init) { reset(init); }
		tbits(std::vector<char> init) { reset(init); }
		tbits(std::string init) { reset(init, true); }
		tbits(const char* init) {
			std::string str = init;
			reset(str, true);
		}

		std::string data() {
			std::string str = "";
			for (int i = 0; i < ary.size(); i++) str = ary[i].data + str;
			return str;
		}

		int value() {
			int num = 0;
			for (int i = 0; i < ary.size(); i++) num += (ary[i].value() * std::pow(3, i));
			return num;
		}

		int size() const {
			return ary.size();
		}

		tbit operator[](int n) const {
			assert(n >= 0 && n < ary.size());
			return ary[n];
		}

		tbit& operator[](int n) {
			assert(n >= 0 && n < ary.size());
			return ary[n];
		}

		tbits& operator=(const tbits& s) {
			reset(s.ary);
			return *this;
		}

		tbits n10T() {
			tbits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n10T();
			return result;
		}

		tbits n110() {
			tbits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n110();
			return result;
		}

		tbits n100() {
			tbits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n100();
			return result;
		}

		tbits n0TT() {
			tbits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n0TT();
			return result;
		}

		tbits n00T() {
			tbits result(ary.size());
			for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n00T();
			return result;
		}

		friend tbits operator&(const tbits& a, const tbits& b) {
			assert(a.size() == b.size());
			tbits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] & b[i];
			return c;
		}

		friend tbits operator|(const tbits& a, const tbits& b) {
			assert(a.size() == b.size());
			tbits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] | b[i];
			return c;
		}

		friend tbits operator*(const tbits& a, const tbits& b) {
			assert(a.size() == b.size());
			tbits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] * b[i];
			return c;
		}

		friend tbits operator+(const tbits& a, const tbits& b) {
			assert(a.size() == b.size());
			tbits c(a.size());
			for (int i = 0; i < a.size(); i++) c[i] = a[i] + b[i];
			return c;
		}
	};

}

