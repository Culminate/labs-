#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define SIZE 10
#define ROWS 8
#define COLS 8
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
// удалить элементы с нечетными индексами
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
// добавить К столбцов в начало массива
void addkcols(int **parr, int rows, int &cols, int k)
{
	for (int i = 0; i < rows; ++i)
	{
		int *p = new int[cols + k]; // выделяем новый массив
		fillarr(p, k);	// заполняем первые к столбцов случайными числами
		for (int j = k; j < cols + k; ++j)
			*(p + j) = *(*(parr + i) + j - k); // переносим оставшиеся стобцы в новый массив
		delete *(parr + i); // удаляем старый массив
		*(parr + i) = p; // на его место ставим новый
	}
	cols += k;	// инкрементируем счетчик столбцов
}

int main(int argc, char const *argv[])
{
	int *arr = new int[SIZE], size = SIZE; // объявляем перемменную размера и массив
	srand(time(0)); // иницилизируем генератор случайных чисел
	fillarr(arr, size); // заполняем массив случайными числами
    printf("Source:\n");
	printarr(arr, size); // выводим массив
	deleteodd(&arr, size); // удаляем элементы с нечетными индексами
	printf("\nResult:\n");
	printarr(arr, size); // выводим массив
	delete [] arr; // удаляем массив
	//обьявляем 2 мерный массив и его размеры
	int **tarr = new int*[ROWS], cols = COLS, rows = ROWS;
	for (int i = 0; i < ROWS; ++i)
		*(tarr + i) = new int[COLS]; // обьявляем колнки массива
	printf("\nSource:\n");
	for (int i = 0; i < rows; ++i)
	{
		fillarr(*(tarr + i), cols); // заполняем 2 мерный массив случайными числами
		printarr(*(tarr + i), cols); // выводим 2 мерный массив
	}

	int k;
	printf("\nInput k: ");
	scanf("%d", &k); // вводим k

	addkcols(tarr, rows, cols, k); // добавляем к столбцов в начало массива

	printf("\nResult:\n");
	for (int i = 0; i < rows; ++i)
		printarr(*(tarr + i), cols); // выводим 2 мерный массив

	for (int i = 0; i < rows; ++i)
		delete *(tarr + i); // удаляем колонки массива
	delete [] tarr;	// удаляем строки массива
	return 0;
}