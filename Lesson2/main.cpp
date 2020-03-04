#include <cstring>
using namespace std;

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

//enum Stam { LOW, HIGH };

int main() {
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