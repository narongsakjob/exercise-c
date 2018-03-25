#include <stdio.h>
#include <string.h>

struct cellphone {
  char name[40];     
  char brand[20];    
  int calls;         
  float price;       
  float vat;         
};

int main()
{  int n;
   struct cellphone str;
   strcpy(str.name,"Name56789012345678901234567890123456789");
   strcpy(str.brand,"Brand67890123456789");
   str.calls = 1234.56;
   str.price = 12745.60;
   str.vat   = 345.67;

   scanf("%d\n",&n);
   if (n == 0 || n == 5)
      printf("%s\n",str.name);
   if (n == 1 || n == 5)
      printf("%s\n",str.brand);
   if (n == 2 || n == 5)
      printf("%d\n",str.calls);
   if (n == 3 || n == 5)
      printf("%10.2f\n",str.price);
   if (n == 4 || n == 5)
      printf("%10.2f\n",str.vat);
}