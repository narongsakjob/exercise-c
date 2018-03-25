#include <stdio.h>

struct complex {
  float r, im;   
                 
};

struct complex add_complex(struct complex C, struct complex D)
{
   struct complex E;                                  
                                                      
   E.r  = C.r + D.r;                                  
   E.im = C.im + D.im;                                
   return E;                                          
}

struct complex multiply_complex(struct complex C, struct complex D)
{
   struct complex E;                                  
                                                      
   E.r  = C.r*D.r - C.im*D.im;                        
   E.im = C.r*D.im + C.im*D.r;                        
   return E;                                          
}

void print_complex(char prompt[], struct complex E)
{
   printf("%s",prompt);                               
   if (E.r == 0 && E.im == 0) {                       
      printf("%.1f\n",0);                             
      return;                                         
   }                                                  
   else                                               
   if (E.r == 0.f) {                                  
      printf("%.1fi\n",E.im);                         
      return;                                         
   }                                                  
   else {                                             
      if (E.im == 0.f)                                
         printf("%.1f\n",E.r);                        
      else                                            
         printf("%.1f %s %.1fi\n",E.r,                
            E.im<0?"-":"+",E.im<0?-E.im:E.im);        
   }                                                  
}

int main() 
{
  struct complex C,D,E,F; 

  printf("Enter C: ");
  scanf("%f %f", &C.r, &C.im);
  printf("Enter D: ");                                  
  scanf("%f %f", &D.r, &D.im);                          

  E = add_complex(C, D);
  F = multiply_complex(C, D);

  print_complex("C + D = ", E);
  print_complex("C x D = ", F);

  return 0;
}