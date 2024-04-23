/* Doubly linked list in C for Crafting interpreters chapter 1 challenge 3 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct ListNode ListNode;
typedef struct LinkedList LinkedList;

struct ListNode {
    char* string;
    ListNode* prev;
    ListNode* next;
};

struct LinkedList {
    ListNode* head;
};


LinkedList* initList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insert(char* s, LinkedList* list) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->string = (char*)malloc(strlen(s) + 1);
    if (newNode->string == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->string, s);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    ListNode* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = NULL;
}

ListNode* findNode(char* s, LinkedList* list) {
    ListNode* curr = list->head;
    while (curr != NULL) {
        if (!strcmp(curr->string, s)) {
            return curr;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}

char* deleteNode(char* s, LinkedList* list) {
    ListNode* curr = list->head;
    while (curr != NULL) {
        if (!strcmp(curr->string, s)) {
            if (curr == list->head) {
                list->head = curr->next;
            } else {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            char* tmp = curr->string;
            free(curr->string);
            free(curr);
            return tmp;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}

void freeList(LinkedList* list) {
    ListNode* tmp, *curr = list->head;
    while (curr != NULL) {
        tmp = curr;
        curr = curr->next;
        free(tmp->string);
        free(tmp);
    }
    free(list);
}