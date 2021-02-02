#include "permlib.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int task1(int** arr, int& cols, int rows) {
	//task1 - create an array with rows(2 by default) and cols

	do {
		cout << "Въведете броя елементи на множеството: " << endl;
		cin >> cols;
		clearStream();
	} while (cols <= 0);

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {0};
	}

	return 0;
}
int task2(int** arr, int rows, int& cols) {
	//task2 - initializes array

	cout << "Въведете стойностите за x:" << endl;
	for (int i = 0; i < cols; i++)
	{
		cin >> arr[0][i];
	}
	clearStream();

	cout << "Въведете стойностите за f(x):" << endl;

	for (int i = 0; i < cols; i++)
	{
		cin >> arr[1][i];
	}
	clearStream();

	return 0;
}
bool task3(int** arr, int cols) {
	//task3 - checks if the func is injection(инекция) 
	//1 2 3
	//5 5 6
	for (int i = 0; i < cols - 1; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			if (arr[1][i] == arr[1][j]) //f(x) == f(y) e.g. 5 == 5
			{
				if (arr[0][i] != arr[0][j]) // x != y e.g. 1 != 2 => not an injection
					return false;
			}
		}
	}

	return true;
}
bool task4(int** arr, int cols) {
	//task4 - checks if the func is surjection(сюрекция)
	//имаме двоичен масив с равен брой колони => елементите от f(x) ВИНАГИ имат съответствие в х
	return true;
}
bool task5(int** arr, int cols) {
	//task5 - checks if func is a permutation
	bool isPermutation = false;
	if (task3(arr, cols) && task4(arr, cols)) {
		isPermutation = true;
		for (int i = 0; i < cols; i++)
		{
			bool xExistsInFunc = false;
			for (int j = 0; j < cols; j++)
			{
				if (arr[0][i] == arr[1][j]) {
					xExistsInFunc = true;
					break;
				}
			}
			if (!xExistsInFunc) {
				isPermutation = false;
				break;
			}
		}

	}

	return isPermutation;
}
int task6(int** arr, int cols) {
	//task6 - returns number of permutations

	//how many permutations does 1 1 1 1 have? 1
	int uniqueNumsCnt = 0;
	for (int i = 0; i < cols; i++)
	{
		bool isUnique = true;
		for (int j = i + 1; j < cols; j++)
		{
			if (arr[0][i] == arr[0][j]) {
				isUnique = false;
				break;
			}
		}

		if (isUnique) uniqueNumsCnt++;
	}

	int factorial = 1;
	for (int i = uniqueNumsCnt; i >= 2; i--)
	{
		factorial *= i;
	}

	return factorial;
}
bool task7(int** arr, int cols) {
	//task7 - checks if fixed points exist

	for (int i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i]) return true;
	}

	return false;
}
int task8(int** arr, int cols) {
	//task8 - finds number of fixed points

	int countOfFixed = 0;
	for (int i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i]) countOfFixed++;
	}

	return countOfFixed;
}
bool task9(int** arr, int cols) {
	//task9 - checks if the function is identity(идентитет)

	bool isId = true;
	for (int i = 0; i < cols; i++)
	{
		if (arr[0][i] != arr[1][i]) {
			isId = false;
			break;
		}
	}

	return isId;
}
int task10(int** arr, int cols) {
	//task10 - prints all independent cycles of the permutation

	if (!task5(arr, cols)) {
		cout << "Функцията не е пермутация!" << endl;
		return 0;
	}
	//if the func is identity
	if (task9(arr, cols)) {
		for (int i = 0; i < cols; i++)
		{
			cout << "( " << arr[0][i] << " )";
		}
		cout << endl;
		return 0;
	}

	int* used = new int[cols];
	used[0] = 0;
	int cntOfUsedIndexes = 1;
	int currIndex = 0;
	while (cntOfUsedIndexes < cols) {
		int startNum = arr[0][currIndex];
		int currNum = arr[1][currIndex];
		if (startNum == currNum) {
			findNextUnusedIndex(cols, cntOfUsedIndexes, used, currIndex);
			continue;
		}

		cout << "( " << startNum << " ";
		cout << currNum << " ";
		for (int i = 1; i < cols; i++)
		{
			bool isUsed = false;
			for (int j = 0; j < cntOfUsedIndexes; j++)
			{
				if (i == used[j]) {
					isUsed = true;
					break;
				}
			}
			if (isUsed) continue;

			if (arr[0][i] == currNum) {
				currNum = arr[1][i];
				used[cntOfUsedIndexes++] = i;
				if (currNum == startNum) {
					cout << ")";
					break;
				}
				cout << currNum << " ";
				i = 0;
			}
		}

		findNextUnusedIndex(cols, cntOfUsedIndexes, used, currIndex);
	}
	cout << endl;

	delete[] used;

	return 0;
}
int task11(int** arr, int cols, int* cyclesLenghts) {
	//task11 - fills the array cyclesCnts with the lengths of the cycles

	if (!task5(arr, cols)) {
		cout << "Функцията не е пермутация!" << endl;
		return 0;
	}

	int* used = new int[cols];
	int cntOfUsedIndexes = 0;
	int currIndex;
	int l = 0;
	while (cntOfUsedIndexes < cols) {
		findNextUnusedIndex(cols, cntOfUsedIndexes, used, currIndex);

		int startNum = arr[0][currIndex];
		int currNum = arr[1][currIndex];
		int currCycleCnt = 1;

		//handles fixed points
		if (startNum == currNum) {
			cyclesLenghts[l++] = 1;
			continue;
		}

		for (int i = 1; i < cols; i++)
		{
			if (arr[0][i] == currNum) {
				currNum = arr[1][i];
				used[cntOfUsedIndexes++] = i;
				currCycleCnt++;
				if (currNum == startNum) {
					cyclesLenghts[l++] = currCycleCnt;
					break;
				}
				i = 1;
			}
		}
	}

	return 0;
}
int task12(int** arr, int cols, char* input, int* perm) {
	//task12 - finds permutation of arr from given cycles(input) and saves the elements in array perm

	int colsInPerm = 0;
	int cyclesCnt = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] != ' ' && input[i] != '(' && input[i] != ')' && input[i] != '-') {
			if (input[i + 1] == ' ' || input[i + 1] == ')')
			{
				colsInPerm++;
			}
		}
		if (input[i] == ')') cyclesCnt++;
	}
	//cout << "Cols " << cols << endl;
	//cout << "CyclesCount " << cyclesCnt << endl;

	int* cyclesLengths = new int[cyclesCnt] {0};
	int* allNums = new int[colsInPerm];
	int index = 0;
	int cntNums = 0;
	int currNum = 0;
	bool isNegativ = false;
	for (unsigned int j = 0; j < strlen(input); j++)
	{
		if (input[j] == ')') {
			index++;
			continue;
		}

		if (input[j] == '-') {
			isNegativ = true;
		}

		if (input[j] != ' ' && input[j] != '(' && input[j] != ')' && input[j] != '-') {

			currNum *= 10;
			currNum += input[j] - '0';

			if (input[j + 1] == ' ' || input[j + 1] == ')')
			{
				cyclesLengths[index]++;

				if (isNegativ) currNum *= -1;
				allNums[cntNums++] = currNum;
				currNum = 0;
				isNegativ = false;
			}
		}
	}

	int* x = new int[colsInPerm];
	int* f = new int[colsInPerm];
	//could be executed with only 1 index variable but appears easier to read with 2 variables to me
	int currIndexInX = 0;
	int currIndexInNums = 0;
	for (int j = 0; j < cyclesCnt; j++)
	{
		for (int h = 0; h < cyclesLengths[j]; h++)
		{
			x[currIndexInX] = allNums[currIndexInNums];
			if (h == cyclesLengths[j] - 1) {
				f[currIndexInX] = allNums[currIndexInNums - h];
			}
			else {
				f[currIndexInX] = allNums[currIndexInNums + 1];
			}
			currIndexInX++;
			currIndexInNums++;
		}
	}


	//places the permutation correctly in relation to arr[0] 1->f(1), 2->f(2), ...
	for (int i = 0; i < cols; i++)
	{
		bool isFound = false;
		for (int j = 0; j < colsInPerm; j++)
		{
			if (arr[0][i] == x[j]) {
				perm[i] = f[j];
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			perm[i] = arr[0][i];
		}
	}

	if (x != nullptr) {
		delete[] x;
		x = nullptr;
	}
	if (f != nullptr) {
		delete[] f;
		f = nullptr;
	}
	if (allNums != nullptr) {
		delete[] allNums;
		allNums = nullptr;
	}
	if (cyclesLengths != nullptr) {
		delete[] cyclesLengths;
		cyclesLengths = nullptr;
	}

	return 0;
}
int task13(int** arr, int cols, int* g, int* f, int** composition) {
	//task13 - finds the composition of two permutations f(g(x)) and saves it in the array composition

	composition[0] = new int[cols];
	composition[1] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		composition[0][i] = arr[0][i];
	}

	//prints g and f
	/*cout << "G: ";
	for (int j = 0; j < cols; j++)
	{
		cout << g[j] << " ";
	}
	cout << endl;

	cout << "F: " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << f2[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < cols; i++)
	{
		int currG = g[i];
		int indexF = 0;
		for (int h = 0; h < cols; h++)
		{
			if (arr[0][h] == currG) {
				indexF = h; break;
			}
		}
		composition[1][i] = f[indexF];
	}

	return 0;
}
int task14(int** arr, int cols, int* perm, int* revPerm) {
	//task14 - finds the reversed permutation of perm and saves it in revPerm
	int** perm2 = new int* [2];
	perm2[0] = new int[cols];
	perm2[1] = new int[cols];
	int** revPerm2 = new int* [2];
	revPerm2[0] = new int[cols];
	revPerm2[1] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		perm2[0][i] = arr[0][i];
		perm2[1][i] = perm[i];
		revPerm2[0][i] = arr[0][i];
	}

	for (int i = 0; i < cols; i++)
	{
		int currEl = revPerm2[0][i];
		for (int j = 0; j < cols; j++)
		{
			if (currEl == perm2[1][j]) {
				revPerm2[1][i] = perm2[0][j];
			}
		}
	}


	for (int i = 0; i < cols; i++)
	{
		revPerm[i] = revPerm2[1][i];
	}

	return 0;
}
int task15(int** arr, int cols) {
	//task15 - finds the composition of a perm with its reversed perm and checks if the result is the identity perm

	int* perm = new int[cols];
	bool workWithCycles;
	enterPermutation(workWithCycles, arr, cols, perm);

	int* revPerm = new int[cols];
	task14(arr, cols, perm, revPerm);

	int** composition = new int* [2];
	task13(arr, cols, perm, revPerm, composition);

	bool isIdentity = task9(composition, cols);

	cout << "Композицията на въведената пермутация с нейната обратна " << (isIdentity ? "" : "нe ") << "е идентитет:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << composition[i][j] << " ";
		}
		cout << endl;
	}

	if (perm != nullptr) {
		delete[] perm;
		perm = nullptr;
	}
	if (revPerm != nullptr) {
		delete[] revPerm;
		revPerm = nullptr;
	}
	freeMemory(composition, 2);
	return 0;
}
bool task16(int** arr, int cols) {
	//task16 - checks that if two permutations are not the identity perm, then f(g(x)) != g(f(x))

	bool workWithCycles1;
	bool workWithCycles2;

	cout << "Въведете първата пермутация. ";
	int* perm1 = new int[cols];
	enterPermutation(workWithCycles1, arr, cols, perm1);

	cout << "Въведете втората пермутация.";
	int* perm2 = new int[cols];
	enterPermutation(workWithCycles2, arr, cols, perm2);

	int** permWithOrig1 = new int* [2];
	permWithOrig1[0] = new int[cols];
	permWithOrig1[1] = new int[cols];
	int** permWithOrig2 = new int* [2];
	permWithOrig2[0] = new int[cols];
	permWithOrig2[1] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		permWithOrig1[0][i] = arr[0][i];
		permWithOrig2[0][i] = arr[0][i];
		permWithOrig1[1][i] = perm1[i];
		permWithOrig2[1][i] = perm2[i];
	}

	bool isIdentity1 = task9(permWithOrig1, cols);
	cout << "Първата пермутация(f(x)) " << (isIdentity1 ? "" : "нe ") << "е идентитет." << endl;

	bool isIdentity2 = task9(permWithOrig2, cols);
	cout << "Втората пермутация(g(x)) " << (isIdentity2 ? "" : "нe ") << "е идентитет." << endl;

	int** composition1o2 = new int* [2];
	task13(arr, cols, perm2, perm1, composition1o2);

	int** composition2o1 = new int* [2];
	task13(arr, cols, perm1, perm2, composition2o1);

	bool areEqual = true;
	for (int i = 0; i < cols; i++)
	{
		if (composition1o2[1][i] != composition2o1[1][i])
		{
			areEqual = false;
			break;
		}
	}
	cout << "perm1 o perm2: " << endl;
	printArray(composition1o2, cols, 2);
	cout << "perm2 o perm1: " << endl;
	printArray(composition2o1, cols, 2);

	if (perm1 != nullptr) {
		delete[] perm1;
		perm1 = nullptr;
	}
	if (perm2 != nullptr) {
		delete[] perm2;
		perm2 = nullptr;
	}
	freeMemory(permWithOrig1, 2);
	freeMemory(permWithOrig2, 2);

	return areEqual;
}
int task17A(int** arr, int cols) {
	//returns the minimum k for which Fk = identity perm
	//A - linear examination

	int* perm = new int[cols];
	bool workWithCycles;
	enterPermutation(workWithCycles, arr, cols, perm);

	int** composition = new int* [2];
	composition[0] = new int[cols] {0};
	composition[1] = new int[cols] {1};
	for (int i = 0; i < cols; i++)
	{
		composition[0][i] = perm[i];
		composition[1][i] = perm[i];
	}

	int k = 0;
	int** tempComp = new int* [2];
	while (true)
	{
		k++;
		task13(arr, cols, composition[1], perm, tempComp);
		for (int i = 0; i < cols; i++)
		{
			composition[1][i] = tempComp[1][i];
		}

		/*for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << composition[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;*/

		if (task9(composition, cols)) break;
	}
	

	if (perm != nullptr) {
		delete[] perm;
		perm = nullptr;
	}
	freeMemory(composition, 2);
	freeMemory(tempComp, 2);
	return k;
}
int task17B(int** arr, int cols) {
	//returns the minimum k for which Fk = identity perm
	//A - using cylces lenghts' NOK

	int** perm = new int* [2];
	perm[0] = new int[cols];
	perm[1] = new int[cols];
	int* cyclesLenghts = new int[cols] {0};
	for (int i = 0; i < cols; i++)
	{
		perm[0][i] = arr[0][i];
	}
	bool workWithCycles;
	enterPermutation(workWithCycles, arr, cols, perm[1]);
	task11(perm, cols, cyclesLenghts);

	int cyclesCnt = 0;
	for (int i = 0; i < cols; i++)
	{
		if (cyclesLenghts[i] != 0) cyclesCnt++;
	}

	int k = 0;
	int a = cyclesLenghts[0];
	int b = cyclesLenghts[1];
	k = NOK(a, b);
	if (cyclesCnt == 1) k = a;
	for (int i = 2; i < cyclesCnt; i++)
	{
		a = k;
		b = cyclesLenghts[i];
		k = NOK(a, b);
	}

	if (cyclesLenghts != nullptr) {
		delete[] cyclesLenghts;
		cyclesLenghts = nullptr;
	}
	freeMemory(perm, 2);
	return k;
}


int loadTask2(int** arr, int rows, int& cols) {
	task1(arr, rows, cols);
	task2(arr, rows, cols);

	while (!isValidFunction(arr, cols))
	{
		cout << "Функцията, която въведохте, не е валидна. Опитайте отново." << endl;
		task1(arr, rows, cols);
		task2(arr, rows, cols);
	} 

	return 0;
}
int loadTask3(int** arr, int cols) {

	cout << "Функцията " << (task3(arr, cols) ? "" : "не ") << "е инекция." << endl;
	return 0;
}
int loadTask4(int** arr, int cols) {

	cout << "Функцията " << (task4(arr, cols) ? "" : "не ") << "е сюрекция." << endl;
	return 0;
}
int loadTask5(int** arr, int cols) {

	cout << "Функцията " << (task5(arr, cols) ? "" : "не ") << "е пермутация." << endl;
	return 0;
}
int loadTask6(int** arr, int cols) {

	cout << "Общ брой пермутации на х: " << task6(arr, cols) << endl;
	return 0;
}
int loadTask7(int** arr, int cols) {

	cout << "Функцията " << (task7(arr, cols) ? "има" : "няма") << " неподвижна точка." << endl;
	return 0;
}
int loadTask8(int** arr, int cols) {

	int fixedPointsCnt = task8(arr, cols);
	cout << "Функцията има " << fixedPointsCnt << ((fixedPointsCnt == 1) ? " неподвижна точка." : " неподвижни точки.") << endl;
	return 0;
}
int loadTask9(int** arr, int cols) {

	cout << "Функцията " << (task9(arr, cols) ? "" : "не ") << "е идентитет." << endl;
	return 0;
}
int loadTask10(int** arr, int cols) {

	task10(arr, cols);
	return 0;
}
int loadTask11(int** arr, int cols) {

	int* cyclesLenghts = new int[cols] { 0 };
	task11(arr, cols, cyclesLenghts);
	for (int i = 0; i < cols; i++)
	{
		if (cyclesLenghts[i] != 0)
			cout << cyclesLenghts[i] << " ";
	}
	cout << endl;

	delete[] cyclesLenghts;

	return 0;
}
int loadTask12(int** arr, int cols) {
	//reads and prints all the necessary data for task12

	char input[100];
	cout << "Моля въведете циклите: ";
	clearStream();
	cin.getline(input, 100);

	int* perm = new int[cols];
	task12(arr, cols, input, perm);

	for (int i = 0; i < cols; i++)
	{
		cout << setw(setWParam) << arr[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < cols; i++)
	{
		cout << setw(setWParam) << perm[i] << " ";
	}
	cout << endl;

	if (perm != nullptr) {
		delete[] perm;
		perm = nullptr;
	}
	return 0;
}
int loadTask13(int** arr, int cols) {
	cout << "За намирането на композицията f(g(x)), моля въведете" << endl;
	cout << "1. циклите на g(x): ";
	int* g = new int[cols];
	char inputG[100];
	clearStream();
	cin.getline(inputG, 100);
	task12(arr, cols, inputG, g);

	cout << "2. циклите на f(x): ";
	int* f = new int[cols];
	char inputF[100];
	cin.getline(inputF, 100);
	task12(arr, cols, inputF, f);

	int** composition = new int* [2];

	task13(arr, cols, g, f, composition);

	cout << "Композицията f(x) o g(x) e: " << endl;
	for (int j = 0; j < cols; j++) //for-loop добавен след защита
	{
		cout << composition[0][j] << " ";
	}
	cout << endl;
	for (int j = 0; j < cols; j++)
	{
		cout << composition[1][j] << " ";
	}
	cout << endl;

	if (g != nullptr) {
		delete[] g;
		g = nullptr;
	}
	if (f != nullptr) {
		delete[] f;
		f = nullptr;
	}
	if (composition != nullptr) {
		for (int i = 0; i < 2; i++)
		{
			delete[] composition[i];
		}
		delete[] composition;
		composition = nullptr;
	}
	return 0;
}
int loadTask14(int** arr, int cols) {

	int* perm = new int[cols];
	bool workWithCycles;
	enterPermutation(workWithCycles, arr, cols, perm);

	int* revPerm = new int[cols];
	task14(arr, cols, perm, revPerm);
	cout << "Обратна пермутация: ";
	if (workWithCycles) {
		int** revPerm2 = new int* [2];
		revPerm2[0] = new int[cols];
		revPerm2[1] = new int[cols];
		for (int i = 0; i < cols; i++)
		{
			revPerm2[0][i] = arr[0][i];
			revPerm2[1][i] = revPerm[i];
		}
		task10(revPerm2, cols);

		freeMemory(revPerm2, 2);
	}
	else {

		for (int i = 0; i < cols; i++)
		{
			cout << revPerm[i] << " ";
		}
		cout << endl;
	}

	if (perm != nullptr) {
		delete[] perm;
		perm = nullptr;
	}
	if (revPerm != nullptr) {
		delete[] revPerm;
		revPerm = nullptr;
	}

	return 0;
}
int loadTask15(int** arr, int cols) {

	task15(arr, cols);
	return 0;
}
int loadTask16(int** arr, int cols) {

	cout << "Двете композиции на пермутациите " << (task16(arr, cols) ? "" : "не ") << "са еднакви." << endl;;
	return 0;
}
int loadTask17(int** arr, int cols) {
	
	cout << "Минималното k е " << task17B(arr, cols) << endl;
	return 0;
}


void enterPermutation(bool& workWithCycles, int** arr, int cols, int* perm)
{
	while (true) {

		cout << "Искате ли да въведете пермутацията под формата на независими цикли?" << endl;

		do {
			cout << "Въведете 1 за ДА или 0 за НЕ: ";
			cin >> workWithCycles;
			clearStream();
		} while (workWithCycles != 1 && workWithCycles != 0);

		if (workWithCycles) {
			cout << "Въведете циклите: " << endl;
			char line[100];
			cin.getline(line, 100);
			task12(arr, cols, line, perm);
		}
		else {
			cout << "Въведете елементите на пермутацията: " << endl;
			for (int i = 0; i < cols; i++)
			{
				cin >> perm[i];
			}
		}


		int** currArr = new int* [2];
		currArr[0] = new int[cols];
		currArr[1] = new int[cols];
		for (int i = 0; i < cols; i++)
		{
			currArr[0][i] = arr[0][i];
			currArr[1][i] = perm[i];
		}

		if (!task5(currArr, cols))
		{
			cout << "Функцията не е пермутация!" << endl;
		}
		else
			break;

		freeMemory(currArr, 2);
	}
}
bool isValidFunction(int** arr, int cols) {
	//checks if the input is a valid function
	//1 1 2
	//5 6 8

	for (int i = 0; i < cols - 1; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			if (arr[0][i] == arr[0][j]) //x == y e.g. 1 == 1
			{
				if (arr[1][i] != arr[1][j]) // f(x) != f(y) 5 != 6 => not a func
					return false;
			}
		}
	}

	return true;
}
int clearStream() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return 0;
}
int printArray(int** arr, int cols, int rows) {
	//prints any two-dimensional array

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
int freeMemory(int** arr, int rows) {
	//frees the memory taken from any given two-dimensional array

	if (arr != nullptr) {
		for (int i = 0; i < rows; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}

	return 0;
}
int findNextUnusedIndex(int cols, int& cntOfUsedIndexes, int* used, int& currIndex)
{
	for (int i = 0; i < cols; i++)
	{
		bool indexIsUsed = false;
		for (int j = 0; j < cntOfUsedIndexes; j++)
		{
			if (i == used[j]) {
				indexIsUsed = true;
				break;
			}
		}
		if (!indexIsUsed) {
			currIndex = i;
			used[cntOfUsedIndexes++] = currIndex;
			break;
		}
	}

	return 0;
}
int gcd(int a, int b) {
	//returns Greatest Common Divider
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int NOK(int a, int b) {
	//returns NOK
	return (a / gcd(a, b)) * b;
}