#include <cstring>
#include "dani"
#include "teacher.h"
using namespace std;


enum Stam { LOW, HIGH };

int main() {
	Teachers type = Teachers::HIGH;
	cout << HIGH; // Stam's HIGH
	// cout << Teachers::HIGH; // does not work meanwhile :-)

	return 0;
}