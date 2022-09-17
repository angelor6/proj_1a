
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable : 4996)
#define BUFFERSIZE 128

#include "Header.h";


/*
Takes in current head of list and the new struct of student
traverses through list and adds new struct of student to end of list
*/
void addNode(struct Node** head, student_t* new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head;

    new_node->studentData = new_data;

    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        tail = new_node;

        return;
    }

    while (last->next != NULL) {
        last = last->next;
        tail = last->next;
    }

    last->next = new_node;
    tail = new_node;
    new_node->prev = last;
    return;
}
/*
Traverse through list starting at head and prints each node until reaches end
*/
void printList(struct Node* node) {
    struct Node* last;
    printf("\n");
    while (node != NULL) {
        printf(" %s ", node->studentData->lastName);
        last = node;
        node = node->next;
    }
    printf("\n\n");
}

/*
Traverses through list starting at the tail and prints each node until it reaches the head
*/
void printListReverse(struct Node* node) {
    struct Node* last = tail;

    printf("\n");
    while (last != NULL) {
        printf(" %s ", last->studentData->lastName);
        last = last->prev;
    }
    printf("\n\n");
}

/*
Will delete node and relink the list depending on cases
case 1: the node is not at the end
case 2: the node is not the first node
case 3: the node is not the head
*/
void deleteStudent(struct Node** head, struct Node* curr) {


    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    else {
        tail = tail->prev;
    }


    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }

    if (curr == *head) {
        *head = curr->next;
        if (*head == NULL) {
            tail = NULL;
        }
    }

    free(curr);

    return;
}

/*
traverses through list and check if the key matches each node
if the key matches node, then delete
if it doesn't, then go to next node
*/
void searchStudent(struct Node** head, char* key) {
    struct Node* curr = *head;

    while (curr != NULL) {
        if (strcmp(curr->studentData->lastName, key) == 0) {
            deleteStudent(head, curr);
            curr = *head;
        }
        else {
            curr = curr->next;
        }
    }
}


int main()
{
    char buffer[BUFFERSIZE];
    student_t* student = NULL;
    int len;
    char* choice;
    int tracker = 1;

    struct Node* head = NULL;



    while (tracker == 1) {
        printf("1: Add student\n2: Delete student\n3: Print list from beginning to end\n4: Print list from end to beginning\n5: Exit");
        printf("\nChoose (1-5): ");
        fgets(buffer, BUFFERSIZE, stdin);
        choice = buffer;

        switch (atoi(choice)) { 
        case 1:
            printf("\nEnter last name: ");
            if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
                len = (int)strlen(buffer);
                buffer[len - 1] = '\0';
                student = (student_t*)malloc(sizeof(student_t));
                student->lastName = (char*)malloc(len);
                strcpy(student->lastName, buffer);
            }



            printf("Enter first name: ");
            if (fgets(buffer, BUFFERSIZE, stdin)) {
                len = (int)strlen(buffer);
                buffer[len - 1] = '\0';
                student->firstName = (char*)malloc(len);
                strcpy(student->firstName, buffer);
            }

            printf("Enter Student ID: ");
            if (fgets(buffer, BUFFERSIZE, stdin)) {
                len = (int)strlen(buffer);
                student->student_ID = (long)buffer;
            }

            printf("Enter year of student: ");
            if (fgets(buffer, BUFFERSIZE, stdin)) {
                len = (int)strlen(buffer);
                buffer[len - 1] = '\0';
                student->yearOfStudent = (char*)malloc(len);
                strcpy(student->yearOfStudent, buffer);
            }

            if (printf("Enter year of expected graduation: ")) {
                fgets(buffer, BUFFERSIZE, stdin);
                len = (int)strlen(buffer);
                student->expectedGrad = (long)buffer;
            }

            addNode(&head, student);
            break;
        case 2:
            printf("Delete student: ");
            fgets(buffer, BUFFERSIZE, stdin);
            len = (int)strlen(buffer);
            buffer[len - 1] = '\0';
            searchStudent(&head, buffer);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printListReverse(head);
            break;
        case 5:
            tracker = 0;
            break;
            ;
        }
    }

    free(student);
    return 0;
}
