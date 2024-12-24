#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) return; 
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }


    struct Node *current = *head, *prev = NULL;
    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->data == value) {
        free(newNode); 
        return;
    }

    if (prev != NULL) {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void delete(struct Node **head, int value) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int print_list(struct Node *head) {
    struct Node *current = head;
    int count = 0;

    while (current != NULL) {
        if (count > 0) printf("\t");
        printf("%d", current->data);
        current = current->next;
        count++;
    }
    printf("\n");
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("error\n");
        return 1;
    }

    struct Node *head = NULL;
    char command;
    int value;

    while (fscanf(file, "%c\t%d\n", &command, &value) != EOF) {
        if (command == 'i') {
            insert(&head, value);
        } else if (command == 'd') {
            delete(&head, value);
        }
    }

    fclose(file);

    int node_count = 0;
    struct Node *current = head;
    while (current != NULL) {
        node_count++;
        current = current->next;
    }
    printf("%d\n", node_count);

    if (node_count > 0) {
        print_list(head);
    } else {
        printf("\n");
    }

    current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}