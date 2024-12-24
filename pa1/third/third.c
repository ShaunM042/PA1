#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETS 1000

struct Node {
    int data;
    struct Node *next;
};

int hash(int key) {
    return abs(key % BUCKETS);  
}

void insert(struct Node **table, int value) {
    int bucket = hash(value);
    struct Node *current = table[bucket];

    while (current != NULL) {
        if (current->data == value) {
            printf("duplicate\n");
            return;
        }
        current = current->next;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        fprintf(stderr, "Failed to allocate memory\n");
        return;  
    }
    new_node->data = value;
    new_node->next = table[bucket];
    table[bucket] = new_node;
    printf("inserted\n");
}

void search(struct Node **table, int value) {
    int bucket = hash(value);
    struct Node *current = table[bucket];

    while (current != NULL) {
        if (current->data == value) {
            printf("present\n");
            return;
        }
        current = current->next;
    }
    printf("absent\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "error opening file\n");
        return 1;
    }

    struct Node *table[BUCKETS] = { NULL };
    char command;
    int value;

    while (fscanf(file, "%c\t%d\n", &command, &value) != EOF) {
        if (command == 'i') {
            insert(table, value);
        } else if (command == 's') {
            search(table, value);
        }
    }

    fclose(file);
    return 0;
}
