#include <stdio.h>

#define GRADES 5

typedef struct
{
	char
		name[25],
		surname[25];

	int 
		grades[GRADES];

} Student;

int Show(Student* _student)
{
	printf("Imie: %s\nNazwisko: %s\nOceny: ", _student->name, _student->surname);

	for(int i = 0; i < GRADES; i++) printf("%d ", _student->grades[i]);

	return 0;
}

int Average(Student* _student)
{
	int sum = 0;

	for (int i = 0; i < GRADES; i++) sum += _student->grades[i];

	printf("\n\nSrednia ocen: %.1f", (float)sum / GRADES);

	return 0;
}

int main()
{
	Student student = {"Jan", "Kowalski", {4, 3, 4, 2, 5}};

	Show(&student);
	Average(&student);

	getchar();

	return 0;
}
