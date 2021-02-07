#include "userio.h"
#include "permlib.h"
#include <iostream>

using namespace std;

int printMenu() {

	cout << "Добре дошли в началното меню! Въведете " << endl;
	cout << "  1 - за да извикате менюто отново" << endl;
	cout << "  2 - за да въведете стойности за х и f(x)" << endl;
	cout << "  3 - за да проверите дали въведената от вас функция е инекция" << endl;
	cout << "  4 - за да проверите дали въведената от вас функция е сюрекция" << endl;
	cout << "  5 - за да проверите дали въведената от вас функция е пермутация на х множеството" << endl;
	cout << "  6 - за да получите общия брой пермутации на множеството" << endl;
	cout << "  7 - за да проверите дали функцията съдържа неподвижни точки" << endl;
	cout << "  8 - за да получите броя неподвижни точки на функцията" << endl;
	cout << "  9 - за да проверите дали функцията е идентитет" << endl;
	cout << " 10 - за да получите пермутацията, представена чрез независими цикли" << endl;
	cout << " 11 - за да получите дължината на всеки от независимите цикли, с които е представена пермутацията" << endl;
	cout << " 12 - за да получите пермутация при зададени независими цикли" << endl;
	cout << " 13 - за да получите композицията на две пермутации" << endl;
	cout << " 14 - за да получите обратната пермутация на въведена от вас пермутация" << endl;
	cout << " 15 - за да получите композицията на въведената от вас пермутация с обратната й и да разберете дали тази композиция е идентитет" << endl;
	cout << " 16 - за да получите доказателство, че ако две пермутации не са идентитет, то операцията композиция между тях не е комутативна" << endl;
	cout << " 17 - за да получите минималното k, за което f на степен k = id" << endl;
	cout << " 19 - за да приключите програмата" << endl;

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