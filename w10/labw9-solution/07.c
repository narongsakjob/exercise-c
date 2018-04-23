#include <stdio.h>

double findAverage(char *filename) 
{
   FILE *file = fopen(filename, "r");             
   int score, count = 0;                          
   double total = 0;                              
   while (!feof(file)) {                          
      if (fscanf(file, "%d", &score) == 1) {      
         total += score;                           
         count++;                                 
      }                                           
   }                                              
   fclose(file);                                  
   return count > 0 ? total / count : 0;          
}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    average = findAverage(filename);
    printf("Average score is %.4lf\n", average);
}