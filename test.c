#include<stdlib.h>
#include<stdio.h>

int main(){
    struct key_value
    {
       int key;
       char* value;
    };

    struct key_value kv;

    kv.key = 1;
    kv.value = "foo";

    kv.key = 2;
    kv.value = "HELLO";

    printf("%i", kv.key);
    printf("%s", kv.value);
    return 0;
}