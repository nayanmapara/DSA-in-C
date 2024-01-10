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
       if(// test invalid range ){
          //Output "Invalid Mark, Please try again"
       }
       else if(// test A){
          //Output "Student Grade is A"
          //Accumulate totalMark of all A-marks
       }
       else if(// test B){
          //Output "Student Grade is B"
          //Accumulate totalMark of all B-marks
       }
       else if(// test C){
          //Output "Student Grade is C"
          //Accumulate totalMark of all C-marks
       }
       else if(// test D){
          //Output "Student Grade is D"
          //Accumulate totalMark of all D-marks
       }
       else{
          //Output "Student Grade is F"
          //Accumulate totalMark of all F-marks
       }
   
   }
   
   if (//Test if students were processed or not)
   {
     //Output "No Student Processed"
   }
   else 
   {
     // compute averageMark 
     
     // determine average grade of class
     // output average mark, total mark, number of students and class average
   }
}// End of main















