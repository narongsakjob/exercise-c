#include <stdio.h>

#define arraySize  5
struct student {
  char id[11];      
  int midterm; 
  int final;   
  char grade;  
};

char calculateGrade(struct student *pRec) 
{
  char grade;                              
  int total;                               
  total = pRec->midterm + pRec->final;     
                                                  
  if (total >= 80) grade = 'A';            
  else if (total >= 70) grade = 'B';       
  else if (total >= 60) grade = 'C';       
  else if (total >= 50) grade = 'D';       
  else grade = 'F';                        
                                           
                                           
  return grade;
}

int main() 
{
  struct student students[arraySize];
  int i;

  for (i=0; i <  arraySize; i++) {
    printf("Enter Student ID: ");
    scanf("%s", students[i].id);
    printf("Enter Student Midterm: ");
    scanf("%d", &students[i].midterm);
    printf("Enter Student Final: ");
    scanf("%d", &students[i].final);

    students[i].grade = calculateGrade(&students[i]);
  }

  for (i=0; i <  arraySize; i++) {
    printf("Student ID %s receives grade %c.\n", students[i].id, students[i].grade);
  }
  
  return 0;
}