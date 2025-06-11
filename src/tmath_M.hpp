/*

tmath_M.hpp
	2025-06-11 ver.2 add new namespace
	2025-06-11 ver.3 improve div

*/

#pragma once
#include <tuple>
#include "tbit_M.hpp"

namespace tmath_M {

	std::tuple<bit, bit> HA(bit& a, bit& b) {
		return { ((a & b) & (a | b).n()).n(), (a & b).n() };
	}

	std::tuple<bit, bit> FA(bit& a, bit& b, bit& c) {
		auto [s0, c0] = HA(a, b);
		auto [s1, c1] = HA(s0, c);
		return { s1, (c0 | c1).n() };
	}

	std::tuple<bits, bit> ADD(bits& a, bits& b, bool inc = false) {
		assert(a.size() == b.size());
		bits s(a.size());
		bit c = inc ? '1' : '0';
		for (int i = 0; i < a.size(); i++) {
			auto [si, ci] = FA(a[i], b[i], c);
			s[i] = si;
			c = ci;
		}
		return { s, c };
	}

	std::tuple<bits, bit> SUB(bits& a, bits& b) {
		assert(a.size() == b.size());
		bits bn = b.n();
		auto [s, c] = ADD(a, bn, true);
		return { s, c };
	}

	bits MUL(bits& a, bits& b) {
		assert(a.size() == b.size());
		bits s(a.size() * 2);
		for (int i = 0; i < b.size(); i++) {
			if (b[i].data == '1') {
				bits f(b.size() - i), e(i);
				f = f.data() + a.data() + e.data();
				auto [si, ci] = ADD(s, f);
				s = si;
			}
		}
		return s;
	}

	bits DIV(bits& a, bits& b) {
		assert(a.size() == b.size() && a.size() >= 2 && b.value() != 0);
		bits d(a.size());
		bits ra = d.data() + a.data() + d.data();
		bits rb = d.data() + b.data() + d.data();
		d = a.size() * 3;
		d[a.size() * 2 + 1] = '1';
		while (rb.value() != (std::pow(2, a.size() * 2) - 1)) {
			auto [r, c] = SUB(d, rb);
			ra = MUL(ra, r).data().substr(a.size(), a.size() * 3);
			rb = MUL(rb, r).data().substr(b.size(), b.size() * 3);
		}
		d = a.size() * 3;
		d[0] = '1';
		auto [s, c] = ADD(ra, d);
		ra = s.data().substr(0, a.size());
		return ra;
	}

	std::tuple<tbit, tbit> HA(tbit& a, tbit& b) {
		tbit s = a * b;
		return { (((a + b).n10T() + s).n10T() + s).n10T(), s.n10T() };
	}

	std::tuple<tbit, tbit> FA(tbit& a, tbit& b, tbit& c) {
		auto [s0, c0] = HA(a, b);
		auto [s1, c1] = HA(s0, c);
		return { s1, (c0 + c1).n10T() };
	}


	std::tuple<tbits, tbit> ADD(tbits& a, tbits& b) {
		assert(a.size() == b.size());
		tbits s(a.size());
		tbit c = '0';
		for (int i = 0; i < a.size(); i++) {
			auto [si, ci] = FA(a[i], b[i], c);
			s[i] = si;
			c = ci;
		}
		return { s, c };
	}

	std::tuple<tbits, tbit> SUB(tbits& a, tbits& b) {
		assert(a.size() == b.size());
		tbits bn = b.n10T();
		auto [s, c] = ADD(a, bn);
		return { s, c };
	}

	tbits MUL(tbits& a, tbits& b) {
		assert(a.size() == b.size());
		tbits s(a.size() * 2);
		for (int i = 0; i < b.size(); i++) {
			if (b[i].data != '0') {
				tbits f(b.size() - i), e(i);
				tbits d = (b[i].data == '1') ? a : a.n10T();
				f = f.data() + d.data() + e.data();
				auto [si, ci] = ADD(s, f);
				s = si;
			}
		}
		return s;
	}

	tbits DIV(tbits& a, tbits& b) {
		assert(a.size() == b.size() && a.size() >= 2 && b.value() != 0);
		if (b.value() == 1) return a;
		tbits d(a.size());
		tbits ra = d.data() + a.data() + d.data();
		tbits rb = d.data() + b.data() + d.data();
		d = a.size() * 3;
		d[a.size() * 2 + 1] = '1';
		d[a.size() * 2 + 0] = 'T';
		while (rb.value() != std::pow(3, a.size() * 2)) {
			auto [r, c] = SUB(d, rb);
			ra = MUL(ra, r).data().substr(a.size(), a.size() * 3);
			rb = MUL(rb, r).data().substr(b.size(), b.size() * 3);
		}
		tbit cmp_a = '0';
		for (int i = a.size(); i < a.size() * 2; i++) { cmp_a = (cmp_a + ra[i]) + (cmp_a.n10T() * ra[i]); }
		ra = ra.data().substr(0, a.size());
		tbit cmp_ra = '0';
		for (int i = 0; i < a.size(); i++) { cmp_ra = (cmp_ra + ra[i]) + (cmp_ra.n10T() * ra[i]); }
		if (cmp_a.data == 'T' && cmp_ra.data == '1') {
			d = a.size();
			d[0] = '1';
			auto [s, c] = SUB(ra, d);
			ra = s;
		}
		return ra;
	}

}

