#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include <cstring>

using namespace std;

struct pupil {
	char *name;
	int age;
	float rating;
};

void fillpupil(pupil **p, int &count, const char *name, int age, float rating)
{
	pupil *d = new pupil[count + 1]; // выделяем новый массив структур
	pupil *t = *p;
	for (int i = 0; i < count; ++i)
	{
		d[i].age = t[i].age;	// копируем данные из старого массива в новый
		d[i].rating = t[i].rating;
		d[i].name = new char[strlen(t[i].name)];
		strcpy(d[i].name, t[i].name);
	}
	d[count].name = new char[strlen(name)]; // выделяем память под строку
	strcpy(d[count].name, name);	// копируем данные из аргументов функции
	d[count].age = age;
	d[count].rating = rating;
	for (int i = 0; i < count; ++i)
		delete t[i].name; // удаляем старый массив структур
	if (count > 1)	// удаляем только если мы его выделяли
		delete [] t;
	*p = d;
	count++; //инкрементируем количество структур в массиве
}
// выводим массив структур на экран
void printpupil(pupil *p, int count)
{
	for (int i = 0; i < count; ++i)
		printf("Name %-20s Age %3d Rating %f\n", p[i].name, p[i].age, p[i].rating);
}
// оставляем в массиве только те структуры имя который совпадает со строкой search
void searchpupil(pupil **p, int &count, const char *search)
{
	int newcount = 0;
	pupil *d, *t = *p;
	for (int i = 0; i < count; ++i)
		if (strstr(t[i].name, search) != NULL) // если найдена подходящая строка добавляем в новый массив
			fillpupil(&d, newcount, t[i].name, t[i].age, t[i].rating);
	for (int i = 0; i < count; ++i){
		delete t[i].name; // удаляем старый массив
	}
	if (count > 1)
		delete [] t;
	*p = d; // присваеваем новый массив указателю
	count = newcount; // и новое количество
}
int main(int argc, char const *argv[])
{
	int count = 0; // задаем начальное количество
	pupil *p; // обьявляем указатель на струтуры

	fillpupil(&p, count, "Ivanov Ivan", 21, 10.5);	// добавляем структуры в динамический массив
	fillpupil(&p, count, "Petrov Vasya", 17, 17.54);
	fillpupil(&p, count, "Labutenov Petr", 26, 28.285);
	fillpupil(&p, count, "Ivanova Nastya", 20, 32.5);
	fillpupil(&p, count, "Lepestkov Vadim", 18, 99.999);
	printf("Source:\n");
	printpupil(p, count); // выводим на экран содежимое структур

	searchpupil(&p, count, "Ivanov");	// ищем и сохраняем только найденные структуры
	printf("\nResult:\n");
	printpupil(p, count);	// выводим на экран массив структур

	for (int i = 0; i < count; ++i){
		delete p[i].name;	// удаляем из кучи выделенные строки
	}
	delete [] p;	// затем структуры
	return 0;
}