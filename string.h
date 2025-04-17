typedef struct string String;

String * create_str ();

void clean_str (String * str);

void print_str (String * str);

String ** create_str_array (int n_strings);

int change_str_on_array (String * str, String *** str_array, int index);

int add_str_to_array (String *** str_array, int n_string);

void print_str_array (String ** str_array);

void clean_str_array (String ** str_array);





