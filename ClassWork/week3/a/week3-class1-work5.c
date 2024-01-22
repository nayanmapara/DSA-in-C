// Introduction to working with strings
#include<stdio.h>
#include<stdlib.h>
int main() 
{
  char word2[]="This is a test";   // declaring and initialising strings
  char word1[20];
  char word[6]={'h','e','l','l','o','\0'}; 
  char word3[6]="Hello";

  // printf("%c %c \n", word[2], word3[4]); // printing character in a string
  // printf("%s \n %s \n",word, word2);     // printing entire string
  // puts(word3);
  
  //int x = 7;
  //printf("The address of x is %p \n", &x);
  //printf("The value of x is %d \n", x);   
  
  puts("Enter a string of length 19 characters");
  scanf("%19s", word1);      // reading string and preventing array overflow

  printf("The value of the string is %s \n", word1);

  printf("The address of the string is %p \n", word1);
  printf("The address of the string is %p \n", &word1[0]);
  printf("The address of the string is %p \n", &word1);

}
