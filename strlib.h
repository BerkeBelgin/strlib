#ifndef WHATEVER_H_INCLUDED
#define WHATEVER_H_INCLUDED

typedef struct st_string string;

static int c_arr_calc_size(char *c_arr);
static unsigned int str_alloc_cap(unsigned int str_size);
static int str_is_null(string *str);
static int str_is_not_null(string *str);
int str_is_empty(string *str);
int str_is_not_empty(string *str);
int str_equals_str(string *str1, string *str2);
int str_equals_c_arr(string *str, char *c_arr);
string *str_new(char *c_arr);
void str_free(string *str);
void str_append_c_arr(string *str, char *c_arr);
void str_append_str(string *str_dest, string *str_src);
char *str_to_char_array(string *str);

#endif
