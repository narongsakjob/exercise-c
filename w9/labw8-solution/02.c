#include <stdio.h>
#include <string.h>

typedef struct {
	char id[12]; 
	int score;   
} studentRecord;

void init(studentRecord list[], int size) {
      int i;                                                 
      char data[][12] = {"55100001","55100002", "55100003"}; 
                                                             
      for (i = 0; i < size; i++) {                           
              strcpy(list[i].id, data[i]);                   
              list[i].score = 0;                             
      }                                                      
}

void enterScore(studentRecord list[], int size){
      char id[12];                            
      int score, i;                           
                                              
      scanf("%s %d", id, &score);             
      for (i = 0; i < size; i++) {            
              if (strstr(list[i].id, id)) {   
                      list[i].score = score;  
                      break;                  
              }                               
      }                                       
}

void printRecords(studentRecord list[], int size) {
	int i;
	
	printf("   ID        Score\n");
	for (i = 0; i < size; i++) {
		printf("%s       %d\n", list[i].id, list[i].score);
	}
}

 void init2(studentRecord list[], int size) {
      int i;                                                 
      char data[][12] = {"49041234","49045678", "49040987"};                                                            
      for (i = 0; i < size; i++) {                           
              strcpy(list[i].id, data[i]);                   
              list[i].score = 0;                             
      }                                                      
 }



int main() {
	int enter;
	studentRecord list[3];
	
	init(list, 3);
	printRecords(list, 3);
	scanf("%d", &enter);
	if (enter == 1)	
    enterScore(list, 3);
     else if (enter == 2) {
         init2(list, 3);
         enterScore(list, 3);
     }
	printRecords(list, 3);
	
}