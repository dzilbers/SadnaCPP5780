#include<iostream>
#include<exception>

using namespace std;

class Clock {
	int h, m, s, d;
public:
	Clock& operator++() {
		++s;
		if (s > 60) {
			s = 0;
			++m;
			if (m > 60) {
				m = 0;
				++h;
				if (h > 24) {
					h = 0;
					++d;
				}
			}
		}
		return *this;
	}
	Clock operator++(int) {
		Clock clk;
		clk.s = this->s + 1;
		if (clk.s <= 60) {
			clk.m = this->m;
			clk.h = this->h;
			clk.d = this->d;
		} else {
			clk.s = 0;
			clk.m = this->m + 1;
			if (clk.m <= 60) {
				clk.h = this->h;
				clk.d = this->d;
			}
			else {
				clk.m = 0;
				clk.h = this->h + 1;
				if (clk.h <= 24) {
					clk.d = this->d;
				}
				else {
					clk.h = 0;
					clk.d = this->d + 1;
				}
			}
		}
		return clk;
	}
	friend istream& operator>>(istream&, Clock&);
};

istream& operator>>(istream& in, Clock& clk) {
	in >> clk.d >> clk.h >> clk.m >> clk.s;
	return in;
}

class Class1 {
	int _field = 0;
	void incr() {
		++_field;
	}
	friend void increase(Class1&);
public:
	Class1() {}
	Class1(Class1& other) {
		_field = other._field;
	}
	Class1(int number) : _field(number) {}

	int increaseAndReturn() {
		incr();
		return _field;
	}
	friend class Class2;
};

void increase(Class1& obj) {
	obj.incr();
	--obj._field;
	Class1* obj2 = new Class1;
	obj2->_field = 0;
}

class Class2 {
	static int sum;
public:
	Class2(Class1& obj1) {
		sum += obj1._field;
	}
};

int Class2::sum = 0;

class Exc1 : public exception {
public:
	Exc1() {}
	virtual ~Exc1() {}
};

class Exc2 : public Exc1 {};
class Exc3 : public Exc1 {};

void foo() {
	throw Exc2();
}

int main(void) {
	//Class1 obj1;
	//cout << obj1.increaseAndReturn();
	//Class2 obj2(obj1);
	//Class1 obj3(obj1);
	//Class1 obj5 = obj1; // identical to the previous row
	//Class1 obj4;
	//obj4 = obj1;
	try {
		foo();
	}
	catch (Exc2&) {
		cout << "Special treatment\n";
	}
	catch (Exc1&) {
		cout << "General treatment\n";
	}
	return 0;
}