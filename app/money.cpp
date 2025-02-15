#include "money.h"
#include <algorithm>

namespace vsite::oop::v7
{
	money& money::operator+= (const money& m) {
		total += m.total;
		return *this;
	}

	money& money::operator-= (const money& m) {
		total -= m.total;
		return *this;
	}

	std::istream& operator >> (std::istream& is, money& m) {
		int euro; int cent;
		is >> euro >> cent;
		m.total = euro * 100 + cent;
		return is;
	}

	std::ostream& operator << (std::ostream& os, const money& m) {
		int euro; int cent;
		euro = m.total / 100;
		cent = m.total % 100;
		if (cent == 0) {
			os << euro << " Eura.";
			return os;
		}
		else if (euro == 0)
		{
			os << cent << " centi.";
			return os;
		}
		else {
			os << euro << "� i " << cent << " centa.";
			return os;
		}
	}

	money::money(int e, int c) {
		total = e * 100 + c;
	}

	int money::get_value() const {
		return total;
	}

	void money::add_value(int addt, int dec) {
		total += addt * 100 + dec;
	}

	void money::sub_value(int subs, int dec) {
		total -= (subs * 100 + dec);
	}
}