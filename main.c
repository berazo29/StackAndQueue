#include <stdio.h>
#include <stdlib.h>

//NODE
struct Node{
    int data;
    struct Node* next;
};

// Print the LinkList
void printList( struct Node* head ){
    struct Node* node = head;
    if ( node == NULL ){
        printf("EMPTY\n");
    }
    while ( node != NULL ){

        printf("%d ", node->data);
        node = node->next;
        if (node == NULL){
            printf("\n");
        }
    }
}

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
    struct Node* prevNode;
    struct Node* nextNode;

    // If linked list empty just return
    if ( *node == NULL || location == 0){
        return;
    }

    nextNode = *node;

    //Delete the first node
    if ( location == 1 ){
        *node = (*node)->next;
        free(nextNode);
        return;

    } else{

        // Delete from any other location
        while ( nextNode != NULL && ( i < location ) ){
            i++;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        // Delete last node
        if ( nextNode == NULL ){
            // Do nothing
            //printf("location does not exist\n");
            return;

        } else{
            prevNode->next = nextNode->next;
            free(nextNode);
        }
    }

}

int main() {
    struct Node* head = NULL;

}
