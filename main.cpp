#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define SIZEA 10
#define ROWS 8
#define COLS 8
// запонение массива случайными числами
void filla(int *arr, int size)
{
	for(int *p = arr; (p - arr) < size; p++) *p = rand()%19-9;
}
// вывод массива в окно консоли
void printa(int * arr, int size)
{
    for(int *p = arr; (p - arr) < size; p++) printf("%2d ", *p);
    printf("\n");
}
// Найти в массиве все элементы равные min(a[1],a[3],…a[2n-1]). Минимальный среди нечетных.
// нумерация массива начинается с 0
int findmin(int *arr, int size)
{
    int min = 9999999;
    for (int i = 1; i <= (size / 2); ++i)
        if (arr[2 * i - 1] < min)
            min = arr[2 * i - 1];
    return min;
}
// удалить их
void delel(int el, int *arr, int &size)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == el) {
            for (int k = i; k < size; ++k)
                arr[k] = arr[k + 1];
            size -= 1;
            i -= 1;
        }
}
// сдвигаем массив влево на n
void shiftb(int * arr, int n, int cols)
{
    int *p;
    while(n--) {
        int tmp = *arr;
        for(p = arr; (p - arr) < cols - 1; p++)
            *p = *(p + 1);
        *p = tmp;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0)); // иницилизируем генератор случайных чисел
	int sizea = SIZEA, a[SIZEA]; // объявляем перемменную пазмера и массив
	filla(a, sizea); // заполняем массив случайными числами
    printf("Source:\n");
	printa(a, sizea); // выводим массив
    delel(findmin(a, sizea), a, sizea); // ищем и удаляем из массива нужные элементы
    printf("\nResult:\n");
    printa(a, sizea); // выводим результат
    printf("\n");

    const int rows = ROWS, cols = COLS; // обьявляем перемменные размера массива
    int    b[rows][cols], k; // объявляем 2 мерный массив
    printf("enter k: ");
    scanf("%d", &k); // вводим 
    printf("Source:\n");
    for(int i = 0; i < rows; i++)
    {
        int *p = *(b + i);
        filla (p, cols); // заполняем 2 мерный массив случайными числами
        printa(p, cols); // выводим 2 мерный массив
        if (i % 2) // каждую нечетную строку
            shiftb(p, k, cols); // сдвигаем на k элементов влево
    }
    printf("\nResult:\n");
    for(int i = 0; i < rows; i++)
    {
        printa(*(b + i), cols); // вывод результата
    }
    printf("\n");
	return 0;
}