/* Test suite for doublyLinkedList.h for Crafting Interpreters Chapter 1 challenge 3 */

#include <stdbool.h>
#include <stdio.h>
#include "doublyLinkedList.h"

bool testInitList() {
    LinkedList* list = initList();
    if (!list) {
        return false;
    } 
    if (list->head != NULL) {
        return false;
    }
    return true;
}

bool testInsert() {
    LinkedList* list = initList();
    char* strings[] = {  "first",
                         "second",
                         "third",
                         "fourth" };
    for (int i = 0; i < 4; i++) {
        insert(strings[i], list);
    }
    int i = 0;
    ListNode* curr = list->head;
    while (i < 4) {
        if (curr == NULL) {
            return false;
        }
        if (strcmp(curr->string, strings[i])) {
            return false;
        }
        curr = curr->next;
        i++;
    }
    return true;
}

bool testFindNode() {
    LinkedList* list = initList();
    char* strings[] = {  "first",
                         "second",
                         "third",
                         "fourth" };
    for (int i = 0; i < 4; i++) {
        insert(strings[i], list);
    }
    int i = 0;
    while (i < 4) {
        if (strcmp(findNode(strings[i], list)->string, strings[i])) {
            return false;
        }
        i++;
    }
    if (findNode("fifth", list) != NULL) {
        return false;
    }
    return true;
}

bool testDeleteNode() {
    LinkedList* list = initList();
    char* strings[] = {  "first",
                         "second",
                         "third",
                         "fourth" };
    char* strings2[] = { "first",
                         "second",
                         "fourth" };
    for (int i = 0; i < 4; i++) {
        insert(strings[i], list);
    }
    int i = 0;
    ListNode* node;
    char* del = deleteNode("third", list);
    if (!strcmp(del, "third")) {
        return false;
    }
    while (i < 3) {
        if ((node = findNode(strings2[i], list)) == NULL || strcmp(node->string, strings2[i])) {
            return false;
        }
        i++;
    }
    deleteNode("second", list);
    if (findNode("second", list) != NULL) {
        return false;
    }
    deleteNode("first", list);
    if (findNode("first", list) != NULL) {
        return false;
    }
    deleteNode("fourth", list);
    if (findNode("fourth", list) != NULL) {
        return false;
    } 
    if (list->head != NULL) {
        return false;
    }
    return true;
}

bool testFreeList() {
    LinkedList* list = initList();
    char* strings[] = {  "first",
                         "second",
                         "third",
                         "fourth" };
    for (int i = 0; i < 4; i++) {
        insert(strings[i], list);
    }
    // run valgrind to know if it worked
}

int main(int argc, char** argv) {
    bool failed = false;

    if (!testInitList()) {
        fprintf(stderr, "Failed on testInitList.\n");
        failed = true;
    } else {
        fprintf(stdout, "testInitList successful.\n");
    }

    if (!testInsert()) {
        fprintf(stderr, "Failed on testInsert.\n");
        failed = true;
    } else {
        fprintf(stdout, "testInsert successful.\n");
    }

    if (!testFindNode()) {
        fprintf(stderr, "Failed on testFindNode.\n");
        failed = true;
    } else {
        fprintf(stdout, "testFindNode successful.\n");
    }

    if (!testDeleteNode()) {
        fprintf(stderr, "Failed on testDeleteNode.\n");
        failed = true;
    } else {
        fprintf(stdout, "testDeleteNode successful.\n");
    }

    if (!testFreeList()) {
        fprintf(stderr, "Failed on testFreeList.\n");
        failed = true;
    } else {
        fprintf(stdout, "testFreeList successful.\n");
    }

    return failed;
}