#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define SIZEA 10
#define ROWS 8
#define COLS 8
// запонение массива случайными числами
void fillarr(int *arr, int size)
{
	for(int *p = arr; (p - arr) < size; p++) *p = rand()%19-9;
}
// вывод массива в окно консоли
void printarr(int * arr, int size)
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
    for(int *p = arr; (p - arr) < size; p++)
        if (*p == el) {
            for (int *k = p; (k - arr) < size; k++)
                *k = *(k + 1);
            size -= 1;
            p--;
        }
}
// сдвигаем массив влево на n
void shiftarr(int * arr, int n, int size)
{
    int *p;
    while(n--) {
        int tmp = *arr;
        for(p = arr; (p - arr) < size - 1; p++)
            *p = *(p + 1);
        *p = tmp;
    }
}

void reverstring(char *str)
{
    bool chet = true, firstchar = true;
    while(*str) { // пока не конец строки
        char *start;
        if (firstchar) {
            start = str; // устанавливаем первый символ слова
            firstchar = false;
        }
        if (*str == ' ' || *(str + 1) == '\0') { // если пробел или конец строки
            if (chet) { // если четное слово
                char *end = *(str + 1) == '\0' ? str : str - 1; // устанавливаем конец слова
                    while (start < end) { // меняем местами буквы в слове XOR перестановкой
                        *start ^= *end;
                        *end ^= *start;
                        *start++ ^= *end--;
                    firstchar = true;
                    chet = false;
                }
            } else {
                firstchar = true;
                chet = true;
            }
        }
        str++;
    }
}
int main(int argc, char const *argv[])
{
    srand(time(0)); // иницилизируем генератор случайных чисел
	int sizea = SIZEA, a[SIZEA]; // объявляем перемменную размера и массив
	fillarr(a, sizea); // заполняем массив случайными числами
    printf("Source:\n");
	printarr(a, sizea); // выводим массив
    delel(findmin(a, sizea), a, sizea); // ищем и удаляем из массива нужные элементы
    printf("\nResult:\n");
    printarr(a, sizea); // выводим результат
    printf("\n");

    const int rows = ROWS, cols = COLS; // обьявляем перемменные размера массива
    int    b[rows][cols], k = 2; // объявляем 2 мерный массив
    printf("Input k: ");
    scanf("%d", &k); // вводим 
    fflush(stdin); // очистить входной буффер для работы gets
    printf("Source:\n");
    for(int i = 0; i < rows; i++)
    {
        int *p = *(b + i);
        fillarr (p, cols); // заполняем 2 мерный массив случайными числами
        printarr(p, cols); // выводим 2 мерный массив
        if (i % 2) // каждую нечетную строку
            shiftarr(p, k, cols); // сдвигаем на k элементов влево
    }
    printf("\nResult:\n");
    for(int i = 0; i < rows; i++)
    {
        printarr(*(b + i), cols); // вывод результата
    }
    printf("\n");
    printf("input string: ");
    char s[100];
    gets(s);
    reverstring(s);
    printf("Result string: %s\n", s);
    return 0;
}