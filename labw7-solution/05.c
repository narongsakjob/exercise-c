#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* stoupper(const char* s) {
	char* result;                            
	int i = 0, len = 0;                      
	                                         
	if (s == NULL) return NULL;              
	for (i = 0; *(s+i)!= '\0'; i++) {        
	        len += 1;                        
	}                                        
	                                         
	result = malloc((len+1)*sizeof(char));   
	for (i = 0; *(s+i)!= '\0'; i++) {        
	        *(result+i) = toupper(*(s+i));   
	}                                        
	*(result+i) = '\0';                      
	                                         
	return result;                           
}

int main(){
	char s[100];
	char* result;
	
	scanf("%s",s);
	result = stoupper(s);
        if (result == s) printf("ERROR.\n");
	printf("%s\n",result);
}