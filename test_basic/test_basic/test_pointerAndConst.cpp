#include <iostream>

using namespace std;

int main() {
	int number = 10;
	const int* ptr1 = &number;
	int* const ptr2 = &number;

	cout << ptr1 << endl;
	return 0;
}