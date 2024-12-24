#include <stdio.h>
#include <stdlib.h>


struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

struct BSTNode* create_node(int value) {
    struct BSTNode *new_node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}


int insert(struct BSTNode **root, int value, int height) {
    if (*root == NULL) {
        *root = create_node(value);
        printf("inserted %d\n", height);
        return height;
    }

    if (value < (*root)->data) {
        return insert(&(*root)->left, value, height + 1);
    } else if (value > (*root)->data) {
        return insert(&(*root)->right, value, height + 1);
    } else {
        printf("duplicate\n");
        return height;
    }
}

int search(struct BSTNode *root, int value, int height) {
    if (root == NULL) {
        printf("absent\n");
        return -1;
    }

    if (value == root->data) {
        printf("present %d\n", height);
        return height;
    } else if (value < root->data) {
        return search(root->left, value, height + 1);
    } else {
        return search(root->right, value, height + 1);
    }
}

struct BSTNode* find_min(struct BSTNode *node) {
    struct BSTNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct BSTNode* delete(struct BSTNode *root, int value) {
    if (root == NULL) {
        printf("fail\n");
        return root;
    }

    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {

        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("success\n");
            return NULL;
        }

        if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            free(root);
            printf("success\n");
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            free(root);
            printf("success\n");
            return temp;
        }

        struct BSTNode *min_right = find_min(root->right);
        root->data = min_right->data;
        root->right = delete(root->right, min_right->data);
    }

    return root;
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

    struct BSTNode *root = NULL;
    char command;
    int value;

    while (fscanf(file, "%c\t%d\n", &command, &value) != EOF) {
        if (command == 'i') {
            insert(&root, value, 1);
        } else if (command == 's') {
            search(root, value, 1);
        } else if (command == 'd') {
            root = delete(root, value);
        }
    }

    fclose(file);

    return 0;
}