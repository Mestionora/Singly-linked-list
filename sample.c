//SINGLY LL

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertPosition(int data, int position)
{
    if (position < 1)
    {
        printf("Position should be >= 1");
        return;
    }
    if (position == 1)
    {
        insertFront(data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(){
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void deletePosition(int position){
    if (position == 1)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    if(position < 1){
        printf("\nInvalid position!");
        return;
    }

    struct Node* temp = head;
    for(int i = 1; i < position-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);   
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

        case 3:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            printf("\nEnter the position: ");
            scanf("%d", &position);
            insertPosition(value, position);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\nEnter the position: ");
            scanf("%d", &position);
            deletePosition(position);
            break;

        case 6:
            printf("\nExiting...\n\n");
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 6);
}