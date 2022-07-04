#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Prototypes
char *shift_cipher_encrypt();
char *shift_cipher_decrypt();
char *mandaragupta_encrypt();
void usage();
void logo();

//Global Variables
#define MAX_VALUE 65536
char character;
char text[MAX_VALUE];
char shifted_text[MAX_VALUE];
char unshifted_text[MAX_VALUE];
char test_var[MAX_VALUE];

//DATABASE
char *db[] = {
	/*0*/ "Karma has no menu, you get served what you deserve",
    /*1*/ "If anything is worth doing, fo it with all your heart",
    /*2*/ "Better to be slapped with the truth than kissed with a lie",
    /*3*/ "The trouble is you think you have time",
    /*4*/ "Let the past make you better, not bitter",
    /*5*/ "It is easy to see faults of others, but difficult to see one's own faults",
    /*6*/ "A man is not called wise because he talks and talks again; but is he peaceful, loving and fearless then he is in truth called wise",
    /*7*/ "Sometimes silence is the best solution",
    /*8*/ "Radiate boundless love towards the entire world",
    /*9*/ "A disciplined mind brings happiness",
    /*10*/ "Give, even if you only have a little",
    /*11*/ "Those who cling to perceptions and views wander the world offending people",
    /*12*/ "Drop by drop is the water pot filled",
    /*13*/ "1",
    /*14*/ "1",
    /*15*/ "1",
    /*16*/ "1",
    /*17*/ "1",
    /*18*/ "1",
    /*19*/ "1",
    /*20*/ "1",
    /*21*/ "1",
    /*22*/ "1",
    /*23*/ "1",
    /*24*/ "1",
    /*25*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
    /*11*/ "1",
};

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

    //ENCRYPTION
	//Shift Cipher
	//shift_cipher_encrypt(text, 5);
	//Invoking The Main Crypt
	//mandaragupta_encrypt(shifted_text);

    //DECRYPTION
    printf("%s\n", text);
    shift_cipher_decrypt(text, -5);
    mandaragupta_encrypt(unshifted_text);

    //GENERAL
    printf("%s\n", db[1]);
	return 0;
}


char *shift_cipher_encrypt(char str[], int key)
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

char *shift_cipher_decrypt(char str[], int key){
    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];

        //For Simple Letters
        if (character >= 'a' && character <= 'z')
        {
            character = character + key;
            if(character > 'z')
            {
                character = character + 'z' - 'a' + 1;
            }
            str[i] = character;
        }

        //For Capital Letters
        else if(character >= 'A' && character <= 'Z'){
            character = character + key;
            if(character > 'Z')
            {
                character = character + 'Z' - 'A' + 1;
            }
            str[i] = character;
        }
        strncat(unshifted_text, &str[i], 1);
    }
    printf("Decrypted Message : %s\n", unshifted_text);
}

char *mandaragupta_encrypt(char *text){
    //char *test1[] = {"HELLO WOrld", "AO", "awda", "123"};

	printf("TODO\n");
	printf("INSIDE THE MG_ENCRYPT CRYPT\n");
    //printf("%s\n", db[0]);
	printf("%s\n", unshifted_text);
}

void usage(){
	printf("TODO USAGE");
}
void logo(){
	printf("TODO LOGO");
}






