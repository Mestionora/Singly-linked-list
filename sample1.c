#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insertFront(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        newNode ->next = NULL;
        head = newNode;
    }
    else{
        newNode ->next = head;
        head = newNode;
    }
}

void display(){
    if(head == NULL){
        printf("\nList is empty!");
    }
    else{
        struct Node* temp = head;
        while(temp != NULL){
            printf("<- %d ", temp -> data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void insertEnd(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        newNode ->next = NULL;
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){    //Not (temp != NULL)
            temp = temp->next;
        }
        temp->next = newNode;   //Not newNode = temp->next;
        newNode->next = NULL;
    }
}

void main()
{
    int choice, value, position;
    do
    {
        printf("\n\n#####   MENU    #####");
        printf("\n1.Insertion at front\n2.Insertion at the end\n3.Insertion at a position\n4.Display\n5.Deletion\n6.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        // case 3:
        //     printf("\nEnter the value to insert: ");
        //     scanf("%d", &value);
        //     printf("\nEnter the position: ");
        //     scanf("%d", &position);
        //     insertPosition(value, position);
        //     break;

        case 4:
            display();
            break;

        // case 5:
        //     printf("\nEnter the position: ");
        //     scanf("%d", &position);
        //     deletePosition(position);
        //     break;

        // case 6:
        //     printf("\nExiting...\n\n");
        //     break;

        // default:
        //     printf("\nInvalid choice");
        //     break;
        }
    } while (choice != 6);
}
