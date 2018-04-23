#include <stdio.h>
#include <stdlib.h>

typedef struct Node { 
  int value;          
  struct Node *next;  
} node;                

void printList(node *pList) {
  while (pList != NULL) {        
    printf("%d ", pList->value); 
    pList = pList->next;         
  }                              
  printf("\n");                  
}

node* insertNode(int value, node *pList) {
  node *pNode, *pPrev, *pCur;                           
                                                               
  pNode = malloc(sizeof(node));                         
  if ( pNode == NULL)                                   
    exit(1);                                            
                                                        
  pNode->value = value;                                 
  pNode->next = NULL;                                   
  if (pList == NULL) return pNode;                      
                                                        
  pPrev = pList;                                        
  pCur = pList;                                         
  while (pCur != NULL && pNode->value > pCur->value) {  
    pPrev = pCur;                                       
    pCur = pCur->next;                                  
  }                                                     
                                                        
  if (pPrev == pCur) {                                  
    pNode->next = pCur;                                 
    return pNode;                                       
  }                                                     
                                                        
  pPrev->next = pNode;                                  
  pNode->next = pCur;                                   
  return pList;                                         
}

int main() {
  int i, value;
  node *pList=NULL;

  for (i = 0; i < 10; i++) {
    scanf(" %d", &value);
    pList = insertNode(value, pList);
  }

  printList(pList);
}