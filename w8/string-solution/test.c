#include "stdio.h"
#include "string.h"

void remove_vowel (char sent[]) {
  char check[100] ;
  int j = 0 ;
  for(int i = 0 ; sent[i] != '\0' ; i++ ) {
  if ( (sent[i] != 'a') && (sent[i] != 'e') && (sent[i] != 'i') && (sent[i] != 'o') && (sent[i] != 'u')) {
    check[j] = sent[i] ;
    j++;
  }
    
  }

  strcpy(sent,check) ;
}

int main(void) {
  char sent[100] ;
  printf("input :");
  gets(sent) ;
  
  remove_vowel(sent) ;
  printf("%s" , sent) ;
  
  
  return 0;
}