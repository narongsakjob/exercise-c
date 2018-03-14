#include <stdio.h>

int main() {
  char str[40];
  int  i=0, count;

  char c;

  printf("String <without a space>: ");
  scanf("%s",str);

  while (str[i] != '\0') {                
    c = str[i];                           
    if (c=='a'                            
     || c=='e'                            
     || c=='i'                            
     || c=='o'                            
     || c=='u'                            
     || c=='A'                            
     || c=='E'                            
     || c=='I'                            
     || c=='O'                            
     || c=='U') {                         
      printf("%c ",str[i]);               
      count++;                            
    }                                     
    i++;                                  
  }                                       
                                          
  printf("\nThis string contains %d vowel%s.\n",count,count>1?"s":"");
  return 0;
}
