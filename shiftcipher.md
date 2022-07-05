# String to Upper case func

```
#include <stdio.h>
#include <string.h>
int main() {
   char s[100];
   int i;
   printf("\nEnter a string : ");
   gets(s);
   for (i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'a' && s[i] <= 'z') {
         s[i] = s[i] -32;
      }
   }
   printf("\nString in Upper Case = %s", s);
   return 0;
}
```

# Split by delimiter func
```
char string[50] = "Hello World How are you!! !";

char * token = strtok(string, " ");

while(token != NULL){
   printf("%s\n", token);
   token = strtok(NULL, " ");
}
```

# Rand Numbers
```
#include<time.h>
int i, n;
    time_t t;

    n = 100; //amnt of no.

    srand((unsigned) time(&t));
    
    for(i = 0; i < n; i++){
        printf("%d\n", rand() % 5); //between 5 excluding 5
    }
```