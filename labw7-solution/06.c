#include <stdio.h>

int charcount(char *s)
{
   if (*s == '\0')             
      return 0;                
   else                        
      return charcount(s+1)+1; 
}

void charweave(char *s,char *result)
{  
   int len;                                  
   char *head,*tail;                         
                                             
   len = charcount(s);                       
   head = s;                                 
   tail = s+len-1;                           
   while (*head != '\0') {                   
      *result = *head;                       
      head++;                                
      result++;                              
      *result = *tail;                       
      tail--;                                
      result++;                              
   }                                         
   *result = '\0';                           
}

main()
{  char str[100],result[200];

   printf("String: ");
   gets(str);   /* read a line of characters from the input to "str" variable */
   charweave(str,result);
   printf("Output: %s\n",result);
   return 0;
}