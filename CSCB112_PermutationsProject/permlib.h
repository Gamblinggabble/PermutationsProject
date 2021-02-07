#ifndef PERM_LIB_H
#define PERM_LIB_H

#define setWParam 4

int task1(int**, int& , int=2);
int task2(int**, int, int=2);
bool task3(int**, int);
bool task4(int**, int);
bool task5(int**, int);
int task6(int**, int);
bool task7(int**, int);
int task8(int**, int);
bool task9(int**, int);
int task10(int**, int);
int task11(int**, int, int*);
int task12(int**, int, char*, int*);
int task13(int**, int, int*, int*, int**);
int task14(int**, int, int*, int*);
int task15(int**, int);
bool task16(int**, int);
int task17A(int**, int);
int task17B(int**, int);

int loadTask2(int**, int&, int);
int loadTask3(int**, int);
int loadTask4(int**, int);
int loadTask5(int**, int);
int loadTask6(int**, int);
int loadTask7(int**, int);
int loadTask8(int**, int);
int loadTask9(int**, int);
int loadTask10(int**, int);
int loadTask11(int**, int);
int loadTask12(int**, int);
int loadTask13(int**, int);
int loadTask14(int**, int);
int loadTask15(int**, int);
int loadTask16(int**, int);
int loadTask17(int**, int);



void enterPermutation(bool& workWithCycles, int** arr, int cols, int* perm);
bool isValidFunction(int**, int);
int clearStream();
int printArray(int**, int, int = 2);
int freeMemory(int**, int = 2);
int findNextUnusedIndex(int, int&, int*, int&);
int gcd(int, int);
int NOK(int, int);

#endif
