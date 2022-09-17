#pragma once
typedef struct student {
    char* lastName;
    char* firstName;
    long student_ID;
    char* yearOfStudent;
    int expectedGrad;
} student_t;

struct Node {
    student_t* studentData;
    struct Node* next;
    struct Node* prev;
};

struct Node* tail;
