#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Prototypes
int *shift_cipher();
int *mandara_crypt();
void usage();

//Global Variables
#define MAX_VALUE 65536
char character;
char text[MAX_VALUE];
char shifted_text[MAX_VALUE];

//Main Function
int main()
{
	//User Input to Enter the Msg
	printf("Enter The MSG to Encrypt: ");
	fgets(text, MAX_VALUE, stdin);
	
	//Shift Cipher
	shift_cipher(text, 5);
	
	//Invoking The Main Crypt
	mandara_crypt(shifted_text);
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

int *mandara_crypt(char *text){

	char db[] = {
		'h',
		'E',
		'J',
		
		};

	printf("TODO\n");
	printf("INSIDE THE CRYPT\n");
	printf("%s\n", text);
}

void usage(){
	printf("TODO USAGE");
}






