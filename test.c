#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    // struct key_value
    // {
    //    int key;
    //    char* value;
    // };

    // struct key_value kv;

    // kv.key = 1;
    // kv.value = "foo";

    // kv.key = 2;
    // kv.value = "HELLO";

    // printf("%i", kv.key);
    // printf("%s", kv.value);
    // char string[] = "Hello";
    // printf("%c\n", string[0]);
    // printf("%c\n", string[1]);
    // printf("%c\n", string[2]);
    // printf("%c\n", string[3]);
    // printf("%c\n", string[4]);
    // printf("%c\n", string[5]);
    // printf("%c\n", string[6]);

    char string[50] = "Hello World How are you!! !";

    char * token = strtok(string, " ");

    while(token != NULL){
       printf("%s\n", token);
       token = strtok(NULL, " ");
    }
    return 0;
}