/*
  Student Grade Application :

  Description: write a program that reads a series of numbers that 
  represent student marks for the PROG20799 course. Your program  
  should inform the user of the corresponding student grade for each 
  mark. Ensure that only valid marks are processed (between 0 -100). Additionally,   compute the average mark for all the students and determine the overall average grade for the class (if students were processed). Use the following test data to test your program:

  80 - 100 : A
  70 - 79  : B
  60 - 69  : C
  50 - 59  : D
   0 - 49  : F
  test values 84, 67, 364, 91, -45, 55, 43, 77, 61, 70
*/
#include <stdio.h>
int main(void)
{
   float mark, totalMark, averageMark;
   unsigned int count = 0;

   printf("Enter Student Mark: ");
   scanf("%f", &mark);
   while( mark != -1)
   {
       if(mark < 0 || mark > 100)// test invalid range ){
      {  
          //Output "Invalid Mark, Please try again"
          puts("Invalid Mark, Please try again");
       }
       else if(mark >= 80)// test A)
       {
          //Output "Student Grade is A"
          puts("Student Grade is A");
          //Accumulate totalMark of all A-marks
          totalMark += mark;

          count++;
       }
       else if(mark >= 70)// test B)
       {
          //Output "Student Grade is B"
          puts("Student Grade is B");
          //Accumulate totalMark of all B-marks
          totalMark += mark;

          count++;
       }
       else if(mark >= 60)// test C)
      {
          //Output "Student Grade is C"
          puts("Student Grade is C");

          //Accumulate totalMark of all C-marks
          totalMark += mark;

          count++;
       }
       else if(mark >= 50)// test D)
       {
          //Output "Student Grade is D"
          puts("Student Grade is D");

          //Accumulate totalMark of all D-marks
          totalMark += mark;

          count++;
       }
       else{
          //Output "Student Grade is F"
          puts("Student Grade is F");

          //Accumulate totalMark of all F-marks
          totalMark += mark;

          count++;
       }

       printf("Enter Student Mark: ");
       scanf("%f", &mark);
   
   }
   
   if (count == 0) //Test if students were processed or not)
   {
     //Output "No Student Processed"
       puts("No Student Processed");
   }
   else 
   {
     // compute averageMark 
     averageMark = totalMark / count;
     // determine average grade of class
      if (averageMark >= 80){
         puts("Average Grade of Class is A");
         }
         else if (averageMark >= 70){
         puts("Average Grade of Class is B");
         }
         else if (averageMark >= 60){
         puts("Average Grade of Class is C");
         }
         else if (averageMark >= 50){
         puts("Average Grade of Class is D");
         }
         else{
         puts("Average Grade of Class is F");
      }
     // output average mark, total mark, number of students and class average
         printf("Total Mark is %.2f\n", totalMark);
         printf("Average Mark is %.2f\n", averageMark);
         printf("Number of Students is %u\n", count);
         printf("Class Average is %.2f\n", averageMark);
   }
}// End of main















