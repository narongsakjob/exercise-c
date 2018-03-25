#include <stdio.h>

struct vector {
  float x, y, z;   
                   
                   
};

int main() 
{
  struct vector u,v,uxv;                                   
                                                           
  printf("Enter u: ");                                     
  scanf("%f %f %f", &u.x, &u.y, &u.z);                     
  printf("Enter v: ");                                     
  scanf("%f %f %f", &v.x, &v.y, &v.z);                     
                                                           
  uxv.x = u.y*v.z - u.z*v.y;                               
  uxv.y = u.z*v.x - u.x*v.z;                               
  uxv.z = u.x*v.y - u.y*v.x;                               
                                                           
  printf("u x v = %.1f %.1f %.1f\n",uxv.x, uxv.y, uxv.z);  
    
  return 0;
}