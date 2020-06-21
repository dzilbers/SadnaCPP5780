#include<iostream>
#include<exception>
#include<fstream>

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
		}
		else {
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

class Exc3 : public Exc1 {
	const char* what() const override {
		return "Very special exception";
	}
};

void foo() {
	throw Exc3();
}

class MyFile : public fstream {
	int* numbers = nullptr;
public:
	MyFile() { numbers = new int[10]; }
	MyFile(const char* name) : fstream(name) {}
	virtual ~MyFile() {
		close();
		delete[] numbers;
	}
	friend fstream& operator <<(fstream&, int);
	friend fstream& operator >>(fstream&, int&);
};
fstream& operator <<(fstream& f, int n) {
	f << n;
	return f;
}
fstream& operator >>(fstream& f, int& n) {
	f >> n;
	return f;
}

void foo1() {
	MyFile f1("yossi.txt");
	f1 << 2;
}

class Class9 {
	float a; // 0
	int b;   // 4
	bool c;  // 8
	bool d;  // 9
	int e;   // 12
	bool b2, b3; // 16
}; // 20

template <typename T>
class ClassA {
	T f1;
	double f2;
	static int counter;
public:
	T f3;
	void foo(ClassA& obj) {
		this->f1 = obj.f1;
		f2 = obj.f2;
	}
	static void incr() { ++counter; }
	static int getCounter() { return counter; }
};

template <typename T> class ClassB : public ClassA<T> {
	using ClassA<T>::f3;
public:
	void boo() {
		cout << f3;
	}
};

template <typename T> class ClassC : public ClassA<int> {
	void boo() {
		cout << f3;
	}

	friend istream& operator >> <>(istream& in, ClassC obj);
};

template <typename T>
istream& operator >> (istream& in, ClassC<T> obj) {
	obj.boo();
	return in;
}

template <typename T>
int ClassA<T>::counter = 0;

int main(void) {
	//Class1 obj1;
	//cout << obj1.increaseAndReturn();
	//Class2 obj2(obj1);
	//Class1 obj3(obj1);
	//Class1 obj5 = obj1; // identical to the previous row
	//Class1 obj4;
	//obj4 = obj1;
	//try {
	//	foo();
	//}
	//catch (Exc2& e) {
	//	cout << "Special treatment\n" << e.what();
	//}
	//catch (Exc1& e) {
	//	cout << "General treatment\n" << e.what();
	//}

//	cout << sizeof Class9 << endl;

	ClassA<int>::incr();
	cout << ClassA<int>::getCounter() << " " << ClassA<double>::getCounter() << endl;

	fstream in("asda", ios::in | ios::binary);
	Clock clk;
	in >> clk;

	return 0;
}

//template <typename T>
//using CalcFuncPtr = T(*)(T, T);
//CalcFuncPtr<int> myCalc = [](int a, int b) -> int { return a + b; };

template <typename T> struct CalcFuncPtr {
	typedef T(*Type)(T, T);
};
CalcFuncPtr<int>::Type myCalc = [](int a, int b) -> int { return a + b; };


