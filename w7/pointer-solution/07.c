#include <stdio.h>

void removeKilled(int *array, int size, int killedPrisoner);

int main() 
{
	int numPrisoners, m, i;

	scanf("%d", &numPrisoners);
	scanf("%d", &m);

	int prisoners[numPrisoners];
	int killed[numPrisoners];

	// generate array 1 to numPrisoners
	for (i = 0; i < numPrisoners; i++) {
		prisoners[i] = i + 1;
	}
	
	int *killerPtr = &prisoners[0];

	// printf("@@ &prisoners[0] %d\n", (int) &prisoners[0]);
	// printf("@@ &prisoners[%d] %d\n", numPrisoners - 1, (int) &prisoners[numPrisoners - 1]);

	// Select prisoner to be killed
	for (i = 0; i < numPrisoners; i++) {
		int remain = numPrisoners - i;                                             
		if (i == numPrisoners - 1) {                                               
		   killed[i] = prisoners[0];                                               
		   break;                                                                  
		}                                                                          
		int k;                                                                     
		for (k = 1; k < m; k++) {                                                  
		   if (*killerPtr == 0) {                                                  
		      killerPtr = &prisoners[0];                                           
		      k--;                                                                 
		      continue;                                                            
		   }                                                                       
		   killerPtr++;                                                            
		   if ((int) killerPtr > (int) &prisoners[remain] || *killerPtr == 0) {    
		      killerPtr = &prisoners[0];                                           
		   }                                                                       
		}                                                                          
		                                                                           

		// append number of prisoner who is killed to array `killed`
		killed[i] = *killerPtr;
		// remove number killed prisoner from array `prisoners`
		removeKilled(&prisoners[0], numPrisoners, *killerPtr);

	}

	for (i = 0; i < numPrisoners; i++) {
		printf("%d ", killed[i]);
	}
}

void removeKilled(int *array, int size, int killedPrisoner)
{
	int i;                                                               
	for (i = 0; *array != killedPrisoner && i < size; array++, i++) {    
	 ;                                                                   
	}                                                                    
	                                                                     
	for (; *array != 0 && i < (size - 1); array++, i++) {                
	      *array = *(array + 1);                                         
	}                                                                    
	*array = 0;                                                          
}