#include <cstring>
#include <iostream>
using namespace std;

double cube(int);
double refcube(int&);
int main() {
	double x = 2.0;
	//cout << refcube(x + 3.0);
	return 0;
}

struct Student;
Student createStudent1(int, const char[], const char[]);
Student& createStudent2(int, const char[], const char[]);
Student& createStudent2(int, const char[], const char[]);
const Student& createStudent3(int id, const char[], const char[]);
Student& createStudent4(int id, const char fname[], const char[]);
int main2() {
	Student elisheva;
	elisheva = createStudent1(345, "Elisheva", "Maimon");
	Student st1 = createStudent2(678, "Yossi", "Cohen") = elisheva;
	Student st2 = createStudent3(123, "Amnon", "Levi");
	Student* st4 = &createStudent4(234, "Bibi", "Netaniahu");
	delete st4;
	Student& st5 = createStudent4(456, "Donald", "Trump");
	delete& st5;
	return 0;
}

int main3() {
	char a = 5;
	short b = 9;
	long c = 12;
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	increase(&c, sizeof(long));
	cout << (int)a << ", " << b << ", " << c;
	return 0;
}

using PtrOper = int (*)(int, int);
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
PtrOper subtr = sub;
int oper(int x, int y, PtrOper func) { return func(x, y); }
//	int g = func(x, y);
//	return g;
int main4() {
	int m = oper(7, 5, add); cout << m << endl;    // output: 12
	int n = oper(20, m, subtr); cout << n << endl; // output: 8
	int k = oper(20, m, sub); cout << k << endl;   // output: 8
	return 0;
}

struct Student {
	int id;
	char firstName[20];
	char lastName[30];
	// ...
};
Student createStudent1(int id, const char fname[], const char lname[]) {
	Student temp;
	temp.id = id;
	strncpy(temp.firstName, fname, 19);
	strncpy(temp.lastName, lname, 29);
	return temp;
}

Student& createStudent2(int id, const char fname[], const char lname[]) {
	Student temp;
	temp.id = id;
	strncpy(temp.firstName, fname, 19);
	strncpy(temp.lastName, lname, 29);
	return temp; // illegal!!!
}

const Student& createStudent3(int id, const char fname[], const char lname[]) {
	Student temp;
	temp.id = id;
	strncpy(temp.firstName, fname, 19);
	strncpy(temp.lastName, lname, 29);
	return temp;
}

Student& createStudent4(int id, const char fname[], const char lname[]) {
	Student* temp = new Student;
	temp->id = id;
	strncpy(temp->firstName, fname, 19);
	strncpy(temp->lastName, lname, 29);
	return *temp;
}

double cube(int a) {
	a *= a * a;
	return a;
}
double refcube(int& a) {
	a *= a * a;
	return a;
}

void increase(void* data, int type) {
	switch (type) {
		case sizeof(char): (*((char*)data))++; break;
		case sizeof(short): (*((short*)data))++; break;
		case sizeof(long): (*((long*)data))++; break;
	}
}


