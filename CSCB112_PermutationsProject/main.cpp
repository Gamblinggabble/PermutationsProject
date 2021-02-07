#include <iostream>
#include <locale>
#include "permlib.h"
#include "userio.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "bulgarian");

	const int rows = 2;
	int cols = 0;
	int** nums = new int*[rows];

	printMenu();

	cout << "�������: ";
	int option;
	while (cin >> option) {
		if (option == 19) break;
		if (option > 2 && option < 15 && cols == 0 ) {
			cout << "�� ��� ������ �������� �� �." << endl;
			continue;
		}
		menu(nums, rows, cols, option);
		
		cout << "�������: ";
	}

	freeMemory(nums);

	return 0;
}

