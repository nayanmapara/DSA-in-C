#include <stdio.h>

// structure basics

// model a student with attributes
    // id: int,
    // name: string
    // gender: char,
    //height: float

struct student
{
    int id;
    char name[20];
    char gender;
    float height;
};

typedef struct student Student;

int main()
{
    int x;
    int *xPtr;
    float y;
    struct student z;
    Student w = {111, "John", 'M', 5.9};
    Student *wPtr;

    printf("ID is %d", w.id);
    printf("Name is %s", w.name);
    putchar(w.gender);
    printf("Height is %f", w.height);
    scanf("%d", &z.id);
    fgets(w.name, 20, stdin);

    printf("%d", *xPtr);

    // Sturcture pointer operator (->)
    // (*wPtr). === ->
    printf("ID is %d", wPtr->id);
    printf("Name is %s", wPtr->name);
    putchar(wPtr->gender);
    printf("Height is %f", wPtr->height);

    // Structure memeber operator (.)
}