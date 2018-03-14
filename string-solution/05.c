#include <stdio.h>
#define strcpy 1234
#define strncpy 1234
#define strcat 1234
#define strncat 1234
::elab:endcode
::elab:begincode
void stringcat(char src[], char dest[])
{
  int i=0,j=0;                    
  while(dest[j] != '\0')          
     j++;                         
  while(src[i] != '\0') {         
    dest[j] = src[i];                 
    i++;                          
    j++;                          
  }                               
  dest[j] = '\0';                   
}

int main()
{
  char in1[100],in2[100];

  printf("Input 1: ");
  gets(in1);  /* read a line of characters from the input to "in1" variable */
  printf("Input 2: ");
  gets(in2);  /* read another line of characters from the input to "in2" variable */
  stringcat(in1,in2);
  printf(" Output: ");
  printf("%s\n",in2);
  return 0;
}