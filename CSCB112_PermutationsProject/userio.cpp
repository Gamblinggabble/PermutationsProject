#include "userio.h"
#include "permlib.h"
#include <iostream>

using namespace std;

int printMenu() {

	cout << "����� ����� � ��������� ����! �������� " << endl;
	cout << "  1 - �� �� �������� ������ ������" << endl;
	cout << "  2 - �� �� �������� ��������� �� � � f(x)" << endl;
	cout << "  3 - �� �� ��������� ���� ���������� �� ��� ������� � �������" << endl;
	cout << "  4 - �� �� ��������� ���� ���������� �� ��� ������� � ��������" << endl;
	cout << "  5 - �� �� ��������� ���� ���������� �� ��� ������� � ���������� �� � �����������" << endl;
	cout << "  6 - �� �� �������� ����� ���� ���������� �� �����������" << endl;
	cout << "  7 - �� �� ��������� ���� ��������� ������� ���������� �����" << endl;
	cout << "  8 - �� �� �������� ���� ���������� ����� �� ���������" << endl;
	cout << "  9 - �� �� ��������� ���� ��������� � ���������" << endl;
	cout << " 10 - �� �� �������� ������������, ����������� ���� ���������� �����" << endl;
	cout << " 11 - �� �� �������� ��������� �� ����� �� ������������ �����, � ����� � ����������� ������������" << endl;
	cout << " 12 - �� �� �������� ���������� ��� �������� ���������� �����" << endl;
	cout << " 13 - �� �� �������� ������������ �� ��� ����������" << endl;
	cout << " 14 - �� �� �������� ��������� ���������� �� �������� �� ��� ����������" << endl;
	cout << " 15 - �� �� �������� ������������ �� ���������� �� ��� ���������� � ��������� � � �� ��������� ���� ���� ���������� � ���������" << endl;
	cout << " 16 - �� �� �������� �������������, �� ��� ��� ���������� �� �� ���������, �� ���������� ���������� ����� ��� �� � �����������" << endl;
	cout << " 17 - �� �� �������� ����������� k, �� ����� f �� ������ k = id" << endl;
	cout << " 19 - �� �� ���������� ����������" << endl;

	return 0;
}

int menu(int** nums, const int rows, int& cols, int option) {

	switch (option)
	{
	case 1: printMenu(); break;
	case 2: loadTask2(nums, cols, rows); break;
	case 3: loadTask3(nums, cols); break;
	case 4: loadTask4(nums, cols); break;
	case 5: loadTask5(nums, cols); break;
	case 6: loadTask6(nums, cols); break;
	case 7: loadTask7(nums, cols); break;
	case 8: loadTask8(nums, cols); break;
	case 9: loadTask9(nums, cols); break;
	case 10: loadTask10(nums, cols); break;
	case 11: loadTask11(nums, cols); break;
	case 12: loadTask12(nums, cols); break;
	case 13: loadTask13(nums, cols); break;
	case 14: loadTask14(nums, cols); break;
	case 15: loadTask15(nums, cols); break;
	case 16: loadTask16(nums, cols); break;
	case 17: loadTask17(nums, cols); break;
	default:
		break;
	}

	return 0;
}