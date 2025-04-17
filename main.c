# include "string.h"
# include <stdio.h>

int main () {
    String ** array;
    String * S = create_str();
    array = create_str_array(2);
    print_str_array(array);
    printf("\n");
    add_str_to_array(&array, 1);
    print_str_array(array);
    printf("\n");
    change_str_on_array(S, &array, 1);
    print_str_array(array);
    printf("\n");
    clean_str_array(array);
    return 0;
}