#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void convert_to_pig_latin(char *word) {
    int len = strlen(word);

    if (is_vowel(word[0])) {
        printf("%syay", word);  
    } else {
        int i;
        for (i = 0; i < len && !is_vowel(word[i]); i++);  

        if (i == len) {
            printf("%say", word);
        } else {
            printf("%s", word + i);
            for (int j = 0; j < i; j++) printf("%c", word[j]);
            printf("ay");
        }
    }
}


void convert_sentence_to_pig_latin(char *sentence) {
    char *word = strtok(sentence, " ");
    int first_word = 1;

    while (word != NULL) {
        if (!first_word) {
            printf(" ");
        }
        convert_to_pig_latin(word);  
        first_word = 0;
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

    convert_sentence_to_pig_latin(sentence);

    free(sentence);  
    return 0;
}