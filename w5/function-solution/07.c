#include <stdio.h>

// Do the count
//
int count_target(int n, int target) {
   int count=0;

   while (n > 0) {
      int x = n % 10;
      if (x == target)
         count++;
      n /= 10;
   }
   return count;
}

int main() {
   int n;
   int target,count;

   scanf("%d",&n);
   scanf("%d",&target);

   count = count_target(n,target);

   // Display output in seperate cases
   //
   if (count <= 0)
      printf ("There is no \"%d\" in %d.\n", target, n);
   else if (count == 1)
      printf("There is only 1 \"%d\" in %d.\n", target, n);
   else
      printf("There are %d \"%d\"(s) in %d.\n", count, target, n);
}