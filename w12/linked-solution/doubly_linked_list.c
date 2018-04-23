#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Linked List system */

typedef struct _node {
    void* data;
    struct _node* next;
    struct _node* pre;
} Node;

typedef struct {
    long size;
    Node* head;
    Node* tail;
} Linked_list;

Linked_list* create_new_linked_list(){
    Linked_list* list = (Linked_list*) malloc(sizeof(Linked_list));
    if(list != NULL){
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
    }
    
    return list;
}

Node* create_new_node(void* data){
    Node* n = (Node*) malloc(sizeof(Node));
    if(n != NULL){
        n->data = data;
        n->next = NULL;
        n->pre  = NULL;
    }
    return n;
}

// Add at the end
void append_linked_list(Linked_list* list, void* data){
    Node* node = create_new_node(data);
    if(node == NULL) exit(1);
    
    if(list->size < 1){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        node->pre = list->tail;
        list->tail = node;
    }
    list->size++;
}

// Add at the head
void prepend_linked_list(Linked_list* list, void* data){
    Node* node = create_new_node(data);
    if(node == NULL) exit(1);
    
    if(list->size < 1){
        list->head = node;
        list->tail = node;
    }else{
        list->head->pre = node;
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

// Insert at position n and shift existing node to the right
// Return 0 when fail, 1 when ok
int insert_linked_list(Linked_list* list, void* data, long n){
    Node* node = create_new_node(data);
    Node* pos = NULL;
    if(node == NULL) exit(1);
    
    if(n < 0 | n > list->size){
        return 0;
    }
    
    if(n == 0){
        prepend_linked_list(list,data);
        return 1;
    }
    if(n == list->size){
        append_linked_list(list,data);
        return 1;
    }
    
    pos = list->head;
    for (long i = 0; i < n; i++) {
        pos = pos->next;
    }
    node->pre = pos->pre;
    node->pre->next = node;
    pos->pre = node;
    node->next = pos;
    
    list->size++;
    
    return 1;
}

// Remove at the tail
void* remove_last_linked_list(Linked_list* list){
    Node* node = NULL;
    void* data;
    
    if(list->size < 1){
        return NULL;
    }
    node = list->tail;
    list->tail = node->pre;
    if(list->size == 1){
        list->head = NULL;
    }
    list->size--;
    data = node->data;
    free(node);
    return data;
}

// Remove at the tail
void* remove_first_linked_list(Linked_list* list){
    Node* node = NULL;
    void* data;
    
    if(list->size < 1){
        return NULL;
    }
    node = list->head;
    list->head = node->next;
    if(list->size == 1){
        list->tail = NULL;
    }
    list->size--;
    data = node->data;
    free(node);
    return data;
}

// Remove at the n position
void* remove_n_linked_list(Linked_list* list, long n){
    Node* node = NULL;
    void* data;
    // Lets start index with 1 to be easier to understand
    n = n+1;
    
    if(list->size < n || n < 1){
        return NULL;
    }
    node = list->head;
    for(long i = 1; i < n; i++){
        node = node->next;
    }
    data = node->data;
    if(list->head == node){
        list->head = node->next;
    }
    if(list->tail == node){
        list->tail = node->pre;
    }
    if(node->pre != NULL){
        node->pre->next = node->next;
    }
    if(node->next != NULL){
        node->next->pre = node->pre;
    }
    
    list->size--;
    data = node->data;
    free(node);
    return data;
}

void clear_linked_list(Linked_list* list,void(*free_data)(void*)){
    list->size = 0;
    Node* n = list->head;
    Node* f = NULL;
    while(n != NULL){
        f = n;
        n = n->next;
        free_data(f->data);
        free(f);
    }
    list->head = NULL;
    list->tail = NULL;
}

void print_linked_list(Linked_list* list, void (*data_print)(void*)){
    printf("Linked list: size = %li\nHead->",list->size);
    Node* n = list->head;
    for(int i = 1; i <= list->size; i++){
        (*data_print)(n->data);
        n = n->next;
        printf("->");
    }
    printf("\nTail->");
    n = list->tail;
    for(long i = 1; i <= list->size; i++){
        (*data_print)(n->data);
        printf("->");
        n = n->pre;
    }
    printf("\n");
}

/* ----- */

void print_i(void* i){
    printf("%li",(long)i);
}

void free_i(void* i){
    // Does nothing
}

void ex1(){
    Linked_list* list = create_new_linked_list();
    for(int i = 0; i < 10; i++){
        append_linked_list(list,(void*)i);
    }
    print_linked_list(list,print_i);
    
    clear_linked_list(list,free_i);
    
    print_linked_list(list,print_i);
    
    for(int i = 0; i < 10; i++){
        prepend_linked_list(list,(void*)i);
    }
    
    print_linked_list(list,print_i);
    
    // Test remove last
    int i = (int)remove_last_linked_list(list);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    for(int i = 1; i <= 8; i++){
        remove_last_linked_list(list);
    }
    // Remove last element
    print_linked_list(list,print_i);
    i = (int)remove_last_linked_list(list);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    // Remove from empty list
    remove_last_linked_list(list);
    print_linked_list(list,print_i);
    
    for(int i = 0; i < 10; i++){
        prepend_linked_list(list,(void*)i);
    }
    
    // Test remove first
    i = (int)remove_first_linked_list(list);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    for(int i = 1; i <= 8; i++){
        remove_first_linked_list(list);
    }
    // Remove last element
    print_linked_list(list,print_i);
    i = (int)remove_first_linked_list(list);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    // Remove from empty list
    remove_first_linked_list(list);
    print_linked_list(list,print_i);
    
    for(int i = 0; i < 10; i++){
        prepend_linked_list(list,(void*)i);
    }
    
    // Test remove n
    printf("Test remove n\n");
    // First value
    i = (int)remove_n_linked_list(list,0);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    // Last value
    i = (int)remove_n_linked_list(list,8);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    // Beyond first
    i = (int)remove_n_linked_list(list,-1);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    // Beyond last
    i = (int)remove_n_linked_list(list,10);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    // Somewhere in list
    i = (int)remove_n_linked_list(list,5);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    // Empty till one left
    for(int i = 1; i <= 6; i++){
        remove_n_linked_list(list,0);
    }
    print_linked_list(list,print_i);
    i = (int)remove_n_linked_list(list,0);
    printf("Remove %i\n",i);
    print_linked_list(list,print_i);
    
    printf("Test insert\n");
    insert_linked_list(list,10,0);
    print_linked_list(list,print_i);
    insert_linked_list(list,9,0);
    print_linked_list(list,print_i);
    insert_linked_list(list,11,2);
    print_linked_list(list,print_i);
    insert_linked_list(list,8,1);
    print_linked_list(list,print_i);
    insert_linked_list(list,7,2);
    print_linked_list(list,print_i);
    insert_linked_list(list,100,-1);
    print_linked_list(list,print_i);
    insert_linked_list(list,100,10);
    print_linked_list(list,print_i);
}

/*-----------*/

// Exmple of real usage
const int NAME_LENGTH = 200;
typedef struct _card{
    char name[NAME_LENGTH];
    int atk;
    int def;
} Card;

Card* create_card(const char* name, int atk, int def){
    Card* c = (Card*) malloc(sizeof(Card));
    if(c == NULL) exit(1);
    strcpy(c->name,name);
    c->atk = atk;
    c->def = def;
    return c;
}

void print_card(void* c){
    Card* card = (Card*)c;
    printf("(%s, Atk: %i, Def:%i)",
           card->name,card->atk,card->def);
}

Card* read_card(){
    Card* c = (Card*)malloc(sizeof(Card));
    if(c==NULL) exit(1);
    printf("Card Name: ");
    fgets(c->name,NAME_LENGTH-1,stdin);
    char* x = strchr(c->name,'\n');
    if(x!=NULL){
        *x = '\0';
    }
    printf("      Atk: ");
    scanf("%d",&(c->atk));
    printf("      Def: ");
    scanf("%d",&(c->def));
    getchar();
    return c;
}

void ex2(){
    Linked_list* player1 = create_new_linked_list();
    Linked_list* player2 = create_new_linked_list();
    
    printf("\n\n\nLets play card game!\n");
    
    // Get player 1 cards
    printf("Enter card for player 1:\n");
    char choice = 'n';
    do{
        append_linked_list(player1, read_card());
        printf("Do you have more card?[y/n]:");
        choice = getchar();
        getchar();
        printf("\n");
    }while(choice != 'n');
    
    // Get player 2 cards
    printf("Enter card for player 2:\n");
    choice = 'n';
    do{
        append_linked_list(player2, read_card());
        printf("Do you have more card?[y/n]:");
        choice = getchar();
        getchar();
        printf("\n");
    }while(choice != 'n');
    
    // Play the game
    Card* player1_card;
    Card* player2_card;
    // Draw cards
    player1_card = remove_first_linked_list(player1);
    player2_card = remove_first_linked_list(player2);
    // Player wins if there are no more cards
    while(1){
        if(player1_card == NULL){
            if(player2_card == NULL){
                printf("Noone has card left. It's a tie\n");
                return;
            }else{
                printf("Player 1 has no card left. Player 2 wins.\n");
                return;
            }
        }else{
            if(player2_card == NULL){
                printf("Player 2 has no card left. Player 1 wins.\n");
                return;
            }else{
                // Compare cards
                print_card(player1_card);
                printf(" vs ");
                print_card(player2_card);
                printf("\n");
                int p1_draw = 0;
                int p2_draw = 0;
                if(player1_card->atk >= player2_card->def){
                    printf("Player 2 card is destroyed\n");
                    p2_draw = 1;
                }
                if(player2_card->atk >= player1_card->def){
                    printf("Player 1 card is destroyed\n");
                    p1_draw = 1;
                }
                if(p2_draw){
                    free(player2_card);
                    player2_card = remove_first_linked_list(player2);
                }
                if(p1_draw){
                    free(player1_card);
                    player1_card = remove_first_linked_list(player1);
                }
            }
        }
    }
}

int main(int argn, char** args){
    ex1();
    ex2();
}
