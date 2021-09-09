#include <stdio.h>
#include <stdlib.h>

#include "strlib.h"

typedef struct st_string {
    char *c_arr;
    unsigned int size;
    unsigned int cap;
} string;

static int c_arr_calc_size(char *c_arr){
    if(c_arr != NULL){
        int idx = 0;
        while(c_arr[idx] != '\0') idx++;
        idx++;
        return idx;
    } else {
        return -1;
    }
}

static unsigned int str_alloc_cap(unsigned int str_size){
    unsigned int cap = 1;
    while(cap < str_size)cap *= 2;
    return cap;
}

static int str_is_null(string *str){
    if(str == NULL)
        return 1;
    else 
        return 0;
}

static int str_is_not_null(string *str){
    if(str != NULL)
        return 1;
    else 
        return 0;
}

int str_is_empty(string *str){
    if(str_is_not_null(str) == 1 && str->size <= 0)
        return 1;
    else 
        return 0;
}

int str_is_not_empty(string *str){
    if(str_is_not_null(str) == 1 && str->size > 0)
        return 1;
    else 
        return 0;
}

int str_equals_str(string *str1, string *str2){
    if(str1->size == str2->size){
        for(int i = 0; i < str1->size; i++){
            if(str1->c_arr[i] != str2->c_arr[i])return 0;
        }
        return 1;
    } else {
        return 0;
    }
}

int str_equals_c_arr(string *str, char *c_arr){
    if(str->size == c_arr_calc_size(c_arr)){
        for(int i = 0; i < str->size; i++){
            if(str->c_arr[i] != c_arr[i])return 0;
        }
        return 1;
    } else {
        return 0;
    }
}

string *str_new(char *c_arr){
    if(c_arr != NULL){
        string *str = (string *) malloc(sizeof(string));
        str->size = c_arr_calc_size(c_arr);
        str->cap = str_alloc_cap(str->size);
        str->c_arr = (char *) malloc(str->cap * sizeof(char));
        for(int i = 0; i < str->size; i++){
            str->c_arr[i] = c_arr[i];
        }
        return str;
    } else {
        return NULL;
    }
}

void str_free(string *str){
    free(str->c_arr);
    str->cap = 0;
    str->size = 0;
    free(str);
}

void str_append_c_arr(string *str, char *c_arr){
    if(str_is_not_null(str) == 1 && c_arr != NULL){
        int c_arr_size = c_arr_calc_size(c_arr);
        int str_idx = str->size - 1;
        str->size += c_arr_size - 1;
        str->cap = str_alloc_cap(str->size);
        str->c_arr = (char *) realloc(str->c_arr, str->cap * sizeof(char));
        for(int i = 0, j = str_idx; i < c_arr_size; i++){
            str->c_arr[j] = c_arr[i];
            j++;
        }
    }
}

void str_append_str(string *str_dest, string *str_src){
    if(str_is_not_null(str_dest) == 1 && str_is_not_null(str_src) == 1){
        int str_idx = str_dest->size - 1;
        str_dest->size += str_src->size - 1;
        str_dest->cap = str_alloc_cap(str_dest->size);
        str_dest->c_arr = (char *) realloc(str_dest->c_arr, str_dest->cap * sizeof(char));
        for(int i = 0, j = str_idx; i < str_src->size; i++){
            str_dest->c_arr[j] = str_src->c_arr[i];
            j++;
        }
    }
}

char *str_to_char_array(string *str){
    return str->c_arr;
}
