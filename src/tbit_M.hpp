/*

tbit_M.hpp
	2025-06-09 ver.1

*/


#pragma once
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
#include <initializer_list>

class bit_M {
public:
	char data = '0';

	bit_M(char init) {
		assert(init == '0' || init == '1');
		data = init;
	}

	int value() {
		if (data == '0') return 0;
		else if (data == '1') return 1;
	}

	bit_M& operator=(const bit_M& s) {
		data = s.data;
		return *this;
	}

	bit_M n() {
		if (data == '0') return bit_M('1');
		else if (data == '1') return bit_M('0');
	}

	friend bit_M operator&(const bit_M& a, const bit_M& b) {
		bit_M result = '1';
		if (a.data == '1' && b.data == '1') result = '0';
		return result;
	}

	friend bit_M operator|(const bit_M& a, const bit_M& b) {
		bit_M result = '0';
		if (a.data == '0' && b.data == '0') result = '1';
		return result;
	}
};

class bits_M {
private:
	std::vector<bit_M> ary = {};

	template<typename T>
	void reset(T& value) {
		ary.assign(value.begin(), value.end());
		for (int i = 0; i < ary.size(); i++) assert(ary[i].data == '0' || ary[i].data == '1');
	}

public:
	bits_M(int n) {
		std::vector<char> init(n, '0');
		reset(init);
	}

	bits_M(std::initializer_list<int> init) { reset(init); }
	bits_M(std::string init) { reset(init); }
	bits_M(std::vector<char> init) { reset(init); }
	bits_M(const char* init) {
		std::string str = init;
		reset(str);
	}

	std::string data() {
		std::string str = "";
		for (int i = 0; i < ary.size(); i++) str += ary[i].data;
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

	bit_M operator[](int n) const {
		assert(n >= 0 && n < ary.size());
		return ary[n];
	}

	bit_M& operator[](int n) {
		assert(n >= 0 && n < ary.size());
		return ary[n];
	}

	bits_M& operator=(const bits_M& s) {
		reset(s.ary);
		return *this;
	}

	bits_M n() {
		bits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n();
		return result;
	}

	friend bits_M operator&(const bits_M& a, const bits_M& b) {
		assert(a.size() == b.size());
		bits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] & b[i];
		return c;
	}

	friend bits_M operator|(const bits_M& a, const bits_M& b) {
		assert(a.size() == b.size());
		bits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] | b[i];
		return c;
	}
};

class tbit_M {
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

	tbit_M(char init) {
		assert(init == 'T' || init == '0' || init == '1');
		data = init;
	}

	int value() {
		if (data == 'T') return -1;
		else if (data == '0') return 0;
		else if (data == '1') return 1;
	}

	tbit_M& operator=(const tbit_M& s) {
		data = s.data;
		return *this;
	}

	tbit_M n10T() {
		char table[] = { '1', '0', 'T' };
		tbit_M result = tbit_M::getTruthValue(data, 'T', table);
		return result;
	}

	tbit_M n110() {
		char table[] = { '1', '1', '0' };
		tbit_M result = tbit_M::getTruthValue(data, 'T', table);
		return result;
	}

	tbit_M n100() {
		char table[] = { '1', '0', '0' };
		tbit_M result = tbit_M::getTruthValue(data, 'T', table);
		return result;
	}

	tbit_M n0TT() {
		char table[] = { '0', 'T', 'T' };
		tbit_M result = tbit_M::getTruthValue(data, 'T', table);
		return result;
	}

	tbit_M n00T() {
		char table[] = { '0', '0', 'T' };
		tbit_M result = tbit_M::getTruthValue(data, 'T', table);
		return result;
	}

	friend tbit_M operator&(const tbit_M& a, const tbit_M& b) {
		char table[] = {
			'1', '1', '1',
			'1', '0', '0',
			'1', '0', 'T'
		};
		tbit_M c = tbit_M::getTruthValue(a.data, b.data, table);
		return c;
	}

	friend tbit_M operator|(const tbit_M& a, const tbit_M& b) {
		char table[] = {
			'1', '0', 'T',
			'0', '0', 'T',
			'T', 'T', 'T'
		};
		tbit_M c = tbit_M::getTruthValue(a.data, b.data, table);
		return c;
	}

	friend tbit_M operator*(const tbit_M& a, const tbit_M& b) {
		char table[] = {
			'1', '0', '0',
			'0', '0', '0',
			'0', '0', 'T'
		};
		tbit_M c = tbit_M::getTruthValue(a.data, b.data, table);
		return c;
	}

	friend tbit_M operator+(const tbit_M& a, const tbit_M& b) {
		char table[] = {
			'1', '1', '0',
			'1', '0', 'T',
			'0', 'T', 'T'
		};
		tbit_M c = tbit_M::getTruthValue(a.data, b.data, table);
		return c;
	}
};

class tbits_M {
private:

	std::vector<tbit_M> ary = {};

	template<typename T>
	void reset(T& value) {
		ary.assign(value.begin(), value.end());
		for (int i = 0; i < ary.size(); i++) assert(ary[i].data == 'T' || ary[i].data == '0' || ary[i].data == '1');
	}

public:
	tbits_M(int n) {
		std::vector<char> init(n, '0');
		reset(init);
	}

	tbits_M(std::initializer_list<int> init) { reset(init); }
	tbits_M(std::string init) { reset(init); }
	tbits_M(std::vector<char> init) { reset(init); }
	tbits_M(const char* init) {
		std::string str = init;
		reset(str);
	}

	std::string data() {
		std::string str = "";
		for (int i = 0; i < ary.size(); i++) str += ary[i].data;
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

	tbit_M operator[](int n) const {
		assert(n >= 0 && n < ary.size());
		return ary[n];
	}

	tbit_M& operator[](int n) {
		assert(n >= 0 && n < ary.size());
		return ary[n];
	}

	tbits_M& operator=(const tbits_M& s) {
		reset(s.ary);
		return *this;
	}

	tbits_M n10T() {
		tbits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n10T();
		return result;
	}

	tbits_M n110() {
		tbits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n110();
		return result;
	}

	tbits_M n100() {
		tbits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n100();
		return result;
	}

	tbits_M n0TT() {
		tbits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n0TT();
		return result;
	}

	tbits_M n00T() {
		tbits_M result(ary.size());
		for (int i = 0; i < ary.size(); i++) result[i] = ary[i].n00T();
		return result;
	}

	friend tbits_M operator&(const tbits_M& a, const tbits_M& b) {
		assert(a.size() == b.size());
		tbits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] & b[i];
		return c;
	}

	friend tbits_M operator|(const tbits_M& a, const tbits_M& b) {
		assert(a.size() == b.size());
		tbits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] | b[i];
		return c;
	}

	friend tbits_M operator*(const tbits_M& a, const tbits_M& b) {
		assert(a.size() == b.size());
		tbits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] * b[i];
		return c;
	}

	friend tbits_M operator+(const tbits_M& a, const tbits_M& b) {
		assert(a.size() == b.size());
		tbits_M c(a.size());
		for (int i = 0; i < a.size(); i++) c[i] = a[i] + b[i];
		return c;
	}
};

