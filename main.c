#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NODE
struct Node{
    int data;
    struct Node* next;
};

//INSERT NODE
// Insert node at any position from 1 to any location
void insertNode( struct Node** node, int location, int data ){

    // Check for validity
    int i = 1;
    struct Node* prevNode;
    struct Node* nextNode;
    struct Node* newNode = ( struct Node* )malloc( sizeof( struct Node ) );

    // This is use for skip insertion
    if ( !newNode || location == 0){
        free(newNode);
        return;
    }

    newNode->data = data;
    nextNode = *node;

    // Insert in the beginning
    if( location == 1 || nextNode == NULL ){
        newNode->next = *node;
        *node = newNode;

    } else{

        // Insert at the location given
        while(nextNode != NULL && (i < location ) ){
            i++;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

// Delete node at any location
void deleteNode( struct Node** node, int location ) {

    int i = 1;
    struct Node* prevNode; //p
    struct Node* nextNode; //q

    // If linked list empty just return
    if ( *node == NULL || location == 0){
        return;
    }

    prevNode = *node;

    //Delete the first node
    if ( location == 1 ){
        *node = (*node)->next;
        free(prevNode);
        return;

    } else{

        // Delete from any other location
        while ( prevNode != NULL && ( i < location ) ){
            i++;
            nextNode = prevNode;
            prevNode = prevNode->next;
        }

        // Delete last node
        if ( prevNode == NULL ){
            // Do nothing
            //printf("location does not exist\n");
            return;

        } else{
            nextNode->next = prevNode->next;
            free(prevNode);
        }
    }

}

int countNodes (struct Node* head ){

    int count = 0;
    while ( head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

// Print the LinkList
void printList( struct Node* head ){
    struct Node* node = head;
    if ( node == NULL ){
        printf("EMPTY");
    }
    while ( node != NULL ){

        printf("%d ", node->data);
        node = node->next;
    }
}
void DestroyLikedList( struct Node** head ){
    struct Node* temp;
    struct Node* iterator;
    iterator = *head;
    while (iterator){
        temp = iterator->next;
        free(iterator);
        iterator = temp;
    }
    *head = NULL;
}
int main(int argc, char* argv[argc+1]) {

    // Initialization
    struct Node* head = NULL;

    // File name from the arguments
    if ( argc != 2 ){
        return EXIT_SUCCESS;
    }

    // Declare the read and write pointers
    FILE* fp;

    fp = fopen(argv[1], "r");

    // Check if the file unable to open
    if (fp == NULL){
        printf("error");
        return EXIT_SUCCESS;
    }
    // Get the number from file
    char action[10];
    int num;
    int push;
    int enqueue;
    int pop;
    while ( fscanf(fp, "%s", action ) != EOF ){
        push = strcmp( action, "PUSH" );
        enqueue = strcmp( action, "ENQUEUE" );
        pop = strcmp( action, "POP" );
        if ( push == 0 ){
            fscanf(fp,"%d", &num);
            insertNode(&head,1,num);

        }else if ( enqueue == 0 ){
            fscanf(fp,"%d", &num);
            if (head == NULL){
                insertNode(&head,1,num);
            } else{
                int loc = countNodes(head);
                insertNode(&head,loc+1,num);
            }

        } else if ( pop == 0 ){
            fscanf(fp,"%d", &num);
            deleteNode(&head,1);

        }
        printList(head);
        printf("\n");
    }
    DestroyLikedList(&head);
    fclose(fp);
    return EXIT_SUCCESS;
}
