#include <stdio.h>
#include <string.h>

#include "strlib.h"

int main(int argc, char **argv){
    string *str = str_new("");
    
    str_append_c_arr(str, "hey");
    printf("%s\n", str_to_char_array(str));
    str_append_c_arr(str, " h e y ");
    printf("%s\n", str_to_char_array(str));
    str_append_c_arr(str, "hey");
    printf("%s\n", str_to_char_array(str));
    //printf("[%s] [%s]\n", str->c_arr, c_arr);

    str_free(str);
}