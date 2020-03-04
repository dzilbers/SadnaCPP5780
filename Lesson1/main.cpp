#include <cstring>
#include "dani"
#include "teacher.h"
#include "file2.h"
#include "file3.h"
using namespace std;


enum Stam { LOW, HIGH };

int main() {
	Teachers type = Teachers::HIGH;
	cout << HIGH; // Stam's HIGH
	cout << Teachers::HIGH; // does not work meanwhile :-)

	return 0;
}