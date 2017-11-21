#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define SIZE 10
// вывод массива в окно консоли
void printarr(int * arr, int size)
{
    for(int *p = arr; (p - arr) < size; p++) printf("%2d ", *p);
    printf("\n");
}
// запонение массива случайными числами
void fillarr(int *arr, int size)
{
	for(int *p = arr; (p - arr) < size; p++) *p = rand()%19-9;
}
void deleteodd(int **parr, int &size)
{
	int *arr = *parr;
	for(int *p = arr + 1; (p - arr) < size; p++) {
		for(int *t = p; (t - arr) < size - 1; t++)
            *t = *(t + 1);
        size--;
	}
	*parr = new int[size]; // выделяем память под новый массив
	for (int i = 0; i < size; ++i)
		*(*parr + i) = *(arr + i);	// переносим в него все данные
	delete [] arr; // удаляем старый
}
int main(int argc, char const *argv[])
{
	int *a = new int[SIZE], size = SIZE; // объявляем перемменную размера и массив
	srand(time(0)); // иницилизируем генератор случайных чисел
	fillarr(a, size); // заполняем массив случайными числами
    printf("Source:\n");
	printarr(a, size); // выводим массив
	deleteodd(&a, size);
	printf("\nResult:\n");
	printarr(a, size); // выводим массив
	delete [] a; // удаляем массив


	return 0;
}