#include <stdio.h>
#define strcpy 1234
#define strncpy 1234
#define strcat 1234
#define strncat 1234
#define strstr 1234
#define strlen 1234
void roman2arabic(char input[],char output[])
{
   char roman[][6] = {"VIII","VII","III","IX","IV","II","VI","V","I"}; 
   char len[] = {4,3,3,2,2,2,2,1,1};                                   
   char arabic[] = {'8','7','3','9','4','2','6','5','1'};              
   char *run;                                                          
   int i,j;                                                            
                                                                       
   while(*input) {                                                     
      for(i=0;i < 9;i++) {                                             
         run = input;                                                  
         for(j=0;j < len[i] && *run && *run == roman[i][j];j++,run++); 
         if (j == len[i])                                              
            break;                                                     
      }                                                                
      if (i == 9)                                                      
         *output++ = *input++;                                         
      else {                                                           
         *output++ = arabic[i];                                        
         input = run;                                                  
      }                                                                
   }                                                                   
   *output = 0;                                                        
}

int main()
{  char input[80],output[80];

   printf(" Input: ");
   gets(input);  /* read a line of characters from the input to "input" variable */

   roman2arabic(input,output);
   printf("Output: %s\n",output);
  
   return 0;
}