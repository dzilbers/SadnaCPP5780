#include <iostream>
using namespace std;

extern float f1();
int f2();
float f3();
bool f4();

int main(void) {
	cout << f1() << endl;
	cout << f2() << endl;
	cout << f3() << endl;
	cout << f4() << endl;

	int i;
	while (true) {
		cout << "Enter option: ";
		cin >> i;
		try {
			switch (i) {
			case 1: throw 5;
			case 2: throw "test";
			case 3: throw false;
			case 4: throw 2.5;
			case 0: exit(0);
			}
		}
		catch (int e) { cout << "int:" << e << endl; }
		catch (double e) { cout << "double:" << e << endl; }
		catch (...) { cout << "something\n"; }
		cout << "DONE\n";
	}
	return 0;
}