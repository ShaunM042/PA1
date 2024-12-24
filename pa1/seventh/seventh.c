#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_last_char(char *word) {
    int len = strlen(word);
    return word[len - 1];
}

void extract_last_chars(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        printf("%c", get_last_char(word));  
        word = strtok(NULL, " ");
    }
    printf("\n");  
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"<sentence>\"\n", argv[0]);
        return 1;
    }

    int length = 0;
    for (int i = 1; i < argc; i++) {
        length += strlen(argv[i]) + 1;  
    }

    char *sentence = malloc(length);
    if (!sentence) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    sentence[0] = '\0';  
    for (int i = 1; i < argc; i++) {
        strcat(sentence, argv[i]);
        if (i < argc - 1) {
            strcat(sentence, " ");  
        }
    }

    extract_last_chars(sentence);

    free(sentence); 
    return 0;
}