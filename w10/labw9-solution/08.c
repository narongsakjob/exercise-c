#include <stdio.h>
#include <string.h>

typedef struct _product {
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++) {
        printf("%-20s|%6d|%10.2lf\n",
            stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void init(Product stock[], int nStock)                                      
{                                                                           
    int i;                                                                  
    for (i = 0; i < nStock; i++) {                                          
        stock[i].name[0] = '\0';                                            
        stock[i].amount = 0;                                                
        stock[i].totalCost = 0.0;                                           
    }                                                                       
}                                                                           
                                                                            
void addToStock(Product stock[], int nStock, Product p)                     
{                                                                           
    int i, found = -1;                                                      
    for (i = 0; i < nStock; i++) {                                          
        if (strcmp(stock[i].name, p.name) == 0) {                           
            found = i;                                                      
        }                                                                   
    }                                                                       
    if (found == -1) {                                                      
        for (i = 0; i < nStock; i++) {                                      
            if (stock[i].amount == 0) {                                     
                strcpy(stock[i].name, p.name);                              
                stock[i].name[strlen(p.name)] = '\0';                       
                stock[i].amount = p.amount;                                 
                stock[i].totalCost = p.totalCost;                           
                break;                                                      
            }                                                               
        }                                                                   
    } else {                                                                
        stock[found].amount += p.amount;                                    
        stock[found].totalCost += p.totalCost;                              
    }                                                                       
}                                                                           
                                                                            
void reportStock(char *filename)                                            
{                                                                           
    int number;                                                             
    FILE *file = fopen(filename, "r");                                      
    int amount;                                                             
    double cost;                                                            
    fscanf(file, "%d", &number);                                            
    Product stock[number];                                                  
    init(stock, number);                                                    
    char line[1000];                                                        
    while (fgets(line, 1000, file) != NULL) {                               
        char *token = strtok(line, ",");                                    
        int count = 0;                                                      
        Product pLine;                                                      
        while (token != NULL) {                                             
            switch (count) {                                                
                case 2:                                                     
                    strcpy(pLine.name, token);                              
                    pLine.name[strlen(token)] = '\0';                       
                    break;                                                  
                case 3:                                                     
                    pLine.amount = atoi(token);                             
                    break;                                                  
                case 4:                                                     
                    sscanf(token, "%lf", &pLine.totalCost);                 
                    break;                                                  
            }                                                               
            token = strtok(NULL, ",");                                      
            count++;                                                        
        }                                                                   
        if (pLine.amount > 0 && pLine.totalCost > 0) {                      
            addToStock(stock, number, pLine);                               
        }                                                                   
    }                                                                       
    fclose(file);                                                           
    printStock(stock, number);                                              
}                                                                           

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    reportStock(filename);
}