#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Prototypes
int *shift_cipher();
int *mandaragupta_encrypt();
void usage();
void logo();

//Global Variables
#define MAX_VALUE 65536
char character;
char text[MAX_VALUE];
char shifted_text[MAX_VALUE];
char test_var[MAX_VALUE];

//Main Function
int main()
{
	//User Input to Enter the Msg
	printf("Enter The MSG to Encrypt: ");
	fgets(text, MAX_VALUE, stdin);
	
	//String To Uppercase
	for (int i = 0; text[i]!='\0'; i++) {
      if(text[i] >= 'a' && text[i] <= 'z') {
         	text[i] = text[i] -32;
      }
   	}

	//Shift Cipher
	shift_cipher(text, 5);
	
	//Invoking The Main Crypt
	mandaragupta_encrypt(shifted_text);
	return 0;
}


int *shift_cipher(char str[], int key)
{
    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];

        //For Simple Letters
        if (character >= 'a' && character <= 'z')
        {
            character = character + key;
            if(character > 'z')
            {
                character = character - 'z' + 'a' - 1;
            }
            str[i] = character;
        }

        //For Capital Letters
        else if(character >= 'A' && character <= 'Z'){
            character = character + key;
            if(character > 'Z')
            {
                character = character - 'Z' + 'A' - 1;
            }
            str[i] = character;
        }
        strncat(shifted_text, &str[i], 1);
    }
    printf("Encrypted Message : %s\n", shifted_text);
}

int *mandaragupta_encrypt(char *text){
	char *db[]= {
		"HELLO1",
        "HELLO2",
        "HELLO3",
	};

    //char *test1[] = {"HELLO WOrld", "AO", "awda", "123"};

	printf("TODO\n");
	printf("INSIDE THE CRYPT\n");
    printf("%s\n", db[0]);
	printf("%s\n", text);
}

void usage(){
	printf("TODO USAGE");
}
void logo(){
	printf("TODO LOGO");
}






