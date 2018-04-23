#include <stdio.h>
#include <string.h>

enum DaysOfWeek { SUN=3, MON, TUE, WED, THU, FRI, SAT }; 
                                                         
                                                         
                                                         

int main()
{  char day_names[][10]={"", "", "",
                        "Sunday", "Monday", "Tuesday",
                        "Wednesday", "Thursday", "Friday",
                        "Saturday"};
   enum DaysOfWeek today;
	 
   int n;
   scanf("%d",&n);
   if (n <= 1)
      printf("%s\n", day_names[MON]);   
   if (n <= 2)
      printf("%s\n", day_names[TUE]);   
   if (n <= 3)
      printf("%s\n", day_names[WED]);   
   if (n <= 4)
      printf("%s\n", day_names[THU]);   
   if (n <= 5)
      printf("%s\n", day_names[FRI]);   
   if (n <= 6)
      printf("%s\n", day_names[SAT]);   
   if (n <= 7)
      printf("%s\n", day_names[SUN]);   

   today = MON;
   printf("The day after %s is %s\n", day_names[today], day_names[today+1]);
   printf("Two days after %s is %s\n", day_names[today], day_names[today+2]);
}