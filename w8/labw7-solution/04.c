#include <stdio.h>

int main(){
    int wordLen, numWords, i, j, diffCount = 0;
    int broken = 0;

    scanf("%d", &wordLen);
    scanf("%d", &numWords);
    
    char words[numWords][wordLen+1];  
    
    for (i = 0; i < numWords; i++) {
        scanf("%s", &words[i]);
    }
    
    for (i = 1; i < numWords; i++){
        for (j = 0; j < wordLen; j++){
            if ( words[i-1][j] != words[i][j] ) {
                diffCount++;
            }
        }
        
        if (diffCount > 2) {
           broken = 1;
           printf("%s\n", words[i-1]);
           break;
        }
        diffCount = 0;
    }
    if (broken == 0) printf("%s\n", words[numWords-1]);
}