# include "string.h"
# include <stdio.h>
# include <stdlib.h>

struct string {
    char * private_str;
};

String * create_str () {
    String * Str;
    int i;
    Str = (String*)malloc(sizeof(String*));
    if (Str == NULL) {
        exit(1);
    }
    Str->private_str = (char*)malloc(sizeof(char));
    scanf("%c", &Str->private_str[0]);
    for (i = 1; Str->private_str[i - 1] != '\n'; i++) {
        Str->private_str = (char*)realloc(Str->private_str, (i + 1) * sizeof(char));
        scanf("%c", &Str->private_str[i]);
    }
    Str->private_str[i - 1] = '\0';
    return Str;
}

void clean_str (String * str) {
    if (str != NULL) {
        free(str);
    }
}

void print_str (String * str) {
    printf("%s", str->private_str);
}

String ** create_str_array (int n_strings) {
    String ** str_array;
    int i;
    str_array = (String**)malloc((n_strings + 1) * sizeof(String*));
    for (i = 0; i < n_strings; i++) {
        str_array[i] = create_str();
    }
    str_array[i] = NULL;
    return str_array;
}

void print_str_array (String ** str_array) {
    int i;
    printf("[");
    for (i = 0; str_array[i] != NULL; i++) {
        print_str(str_array[i]);
        if (str_array[i + 1] != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

int add_str_to_array (String *** str_array, int n_string) {
    int i, current_size = 0, new_size;
    if ((*str_array) == NULL) {
        return 0;
    }
    for (i = 0; (*str_array)[i] != NULL; i++) {
        current_size++;
    }
    new_size = current_size + n_string;
    *str_array = (String**)realloc(*str_array, (new_size + 1) * sizeof(String*));
    for (i = current_size; i < new_size; i++) {
        (*str_array)[i] = create_str();
    }
    (*str_array)[i] = NULL;
    return 1;
}

int change_str_on_array (String * str, String *** str_array, int index) {
    int i, current_size = 0;
    for (i = 0; (*str_array)[i] != NULL; i++) {
        current_size++;
    }
    if (index <= current_size - 1) {
       if (str != NULL) {
            (*str_array)[index] = str;
            return 1;
       } 
    }
    return 0;
}

void clean_str_array (String ** str_array) {
    int i;
    if (str_array != NULL) {
        for (i = 0; str_array[i] != NULL; i++) {
            free(str_array[i]);
        }
        free(str_array);
    }
}

