#include <stdio.h>

int remove_vowel(char str[])
{
   int i,j;                                 
                                            
   for(i=j=0;str[i];i++)                    
     if (str[i] == 'a' || str[i] == 'e' ||  
        str[i] == 'i' || str[i] == 'o' ||   
        str[i] == 'u' || str[i] == 'A' ||   
        str[i] == 'E' || str[i] == 'I' ||   
        str[i] == 'O' || str[i] == 'U')     
        ;                                   
     else                                    
        str[j++] = str[i];                  
   str[j] = 0;                              
}

int main()
{  char str[80];

  printf(" Input: ");           
  gets(str);                   
                                
  remove_vowel(str);
  printf("Output: %s\n",str);
  
  return 0;
}