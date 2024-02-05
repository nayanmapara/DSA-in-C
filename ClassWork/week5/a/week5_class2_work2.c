#include <stdio.h>

// Structure definiton for type friend with id, name
typedef struct friend
{
  unsigned int id;
  char name[20];
} Friend;


// Structure renaming / alias

int main()
{
  // declare array of structures for 3 friends
  size_t i;
  Friend any[3];

  // read values into array-of-structures
  for (i = 0; i < 3; i++)
  {
    printf("Enter ID of Friend #%Zu: ", i + 1);
    scanf("%u", &any[i].id);

    printf("Enter Name of Friend #%Zu: ", i + 1);
    scanf("%19s", any[i].name);
  }

  // print values from array-of-structures
  printf("Id\tName\n");
  for (i = 0; i < 3; i++)
  {
    printf("%u\t%s\n", any[i].id, any[i].name);
  }
  
}
