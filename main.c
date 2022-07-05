#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Prototypes
char *shift_cipher_encrypt();
char *shift_cipher_decrypt();
char *mandaragupta_encrypt();
char *mandaragupta_decrypt();
void usage();
void logo();

//Global Variables
#define MAX_VALUE 65536
char character;
char character2;
char text[MAX_VALUE];
char shifted_text[MAX_VALUE];
char unshifted_text[MAX_VALUE];
char encrypted_text[MAX_VALUE];
char test_var[MAX_VALUE];

//DATABASE
char *db[] = {
	/*0 - space*/ "Karma has no menu, you get served what you deserve",                              // 
    /*1 - 0*/ "If anything is worth doing, do it with all your heart",                               //48 - 47 = 1 
    /*2 - 1*/ "Better to be slapped with the truth than kissed with a lie",                          //49 - 47 = 2
    /*3 - 2*/ "The trouble is you think you have time",                                              //50 - 47 = 3
    /*4 - 3*/ "Let the past make you better, not bitter",                                            //51 - 47 = 4
    /*5 - 4*/ "It is easy to see faults of others, but difficult to see one's own faults",           //52 - 47 = 5
    /*6 - 5*/ "There is no fear for one whose mind is not filled with desires",                      //53 - 47 = 6
    /*7 - 6*/ "Sometimes silence is the best solution",                                              //54 - 47 = 7
    /*8 - 7*/ "Radiate boundless love towards the entire world",                                     //55 - 47 = 8
    /*9 - 8*/ "A disciplined mind brings happiness",                                                 //56 - 47 = 9
    /*10 - 9*/ "Give, even if you only have a little",                                               //57 - 47 = 10 
    /*11 - A*/ "Those who cling to perceptions and views wander the world offending people",                            //65 - 54 = 11 
    /*12 - B*/ "Drop by drop is the water pot filled",
    /*13 - C*/ "Conquer anger with non anger, conquer badness with goodness, conquer meanness with generosity",
    /*14 - D*/ "Those who cling to perceptions and views wander the world offending people",
    /*15 - E*/ "I will not look at another's bowl intent on finding fault: a training to be observed",
    /*16 - F*/ "May all beings have happy mind",
    /*17 - G*/ "Delight in heedfulness! Guard well your thoughts!",
    /*18 - H*/ "Live with no sense of mine, not forming attachments to experiences",
    /*19 - I*/ "Resolutely train your self to attain peace",
    /*20 - J*/ "The root of suffering is attachment",
    /*21 - K*/ "understanding is the heartwood of well-spoken words",
    /*22 - L*/ "The only failure in life is not to be true to the best one knows",
    /*23 - M*/ "You cannot travel the path until you have become the path itself",
    /*24 - N*/ "What we think, we become",
    /*25 - O*/ "Nothing remains without change",
    /*26 - P*/ "He will win who knows when to fight and when not to fight.",
    /*27 - Q*/ "Life is Suffering",
    /*28 - R*/ "Love the whole world as a mother loves her only child",
    /*29 - S*/ "Health is the gratest gift, contentment is the greatest wealth",
    /*30 - T*/ "Purity and impurity depend on oneself; no one can purify another",
    /*31 - U*/ "whatever has the nature of arising has the nature of ceasing ",
    /*32 - V*/ "I do not dispute with the world; rather it is the world that disputes me",
    /*33 - W*/ "chaos is inherent in all compunded things, strive on with diligence",
    /*34 - X*/ "Intelligence is the ability to adopt to change",
    /*35 - Y*/ "Something is better than nothing",
    /*36 - Z*/ "Anything too much is not good",                                                                        //90 - 54 = 36
};

char *sanskrit_db[] = {
	/*0 - space*/ "कर्मस्य मेनू नास्ति, भवन्तः यत् अर्हन्ति तत् परोक्ष्यन्ति.\n",
    /*1 - 0*/ "यदि किमपि कर्तुं योग्यं भवति तर्हि फो तत् सर्वहृदयेन.\n",
    /*2 - 1*/ "असत्येन चुम्बनात् सत्येन प्रहारं श्रेयस्करम्.\n",
    /*3 - 2*/ "क्लेशः अस्ति यत् भवन्तः मन्यन्ते यत् भवतः समयः अस्ति.\n",
    /*4 - 3*/ "अतीतः भवन्तं श्रेष्ठं करोतु, न तु कटुः.\n",
    /*5 - 4*/ "परदोषदर्शनं सुलभं स्वदोषदर्शनं तु दुष्करम्.\n",
    /*6 - 5*/ "न भयं विद्यते यस्य मनः कामैरपि न भवति.\n",
    /*7 - 6*/ "कदाचित् मौनम् एव उत्तमं समाधानम् अस्ति.\n",
    /*8 - 7*/ "सम्पूर्ण विश्व के प्रति असीम प्रेम विकीर्ण करें.\n",
    /*9 - 8*/ "अनुशासितं मनः सुखं जनयति.\n\n",
    /*10 - 9*/ "ददातु, यद्यपि भवतः किञ्चित् एव अस्ति.\n",
    /*11 - A*/ "ये प्रतीतिदृष्टिषु आलम्बन्ते जनाः आक्षेपं कुर्वन्तः लोकं भ्रमन्ति.\n",
    /*12 - B*/ "बिन्दुः बिन्दुः जलकुम्भः पूरितः अस्ति.\n",
    /*13 - C*/ "अक्रोधेन क्रोधं जयेत्, सद्भावेन दुष्टं जयेत्, उदारतया नीचतां जयेत्.\n",
    /*14 - D*/ "ये प्रतीतिदृष्टिषु आलम्बन्ते जनाः आक्षेपं कुर्वन्तः लोकं भ्रमन्ति.\n",
    /*15 - E*/ "अहं दोषं अन्वेष्टुं परस्य कटोराभिप्रायं न पश्यामि: अवलोकनीयं प्रशिक्षणम्.\n",
    /*16 - F*/ "सर्वेषां भूतानां सुखमनः भवतु.\n",
    /*17 - G*/ "Delight in heedfulness! Guard well your thought.!\n", /////////////////////////////////////
    /*18 - H*/ "न मम भावेन सह जीवन्तु, अनुभवेषु आसक्तिं न निर्माय.\n",
    /*19 - I*/ "शान्तिप्राप्त्यर्थं दृढनिश्चयेन स्वस्य आत्मनः प्रशिक्षणं कुरुत.\n",
    /*20 - J*/ "दुःखस्य मूलं आसक्तिः.\n",
    /*21 - K*/ "अवगमनं सुभाषितानां हृदयम्.\n",
    /*22 - L*/ "जीवने एकमात्रं असफलता अस्ति यत् उत्तमं जानाति तस्य सत्यं न भवेत्.\n",
    /*23 - M*/ "न त्वं मार्गं गन्तुं न शक्नोषि यावत् त्वं मार्ग एव न भवसि.\n",
    /*24 - N*/ "यत् चिन्तयामः, वयं भवेम.\n",
    /*25 - O*/ "परिवर्तनं विना किमपि न तिष्ठति.\n",
    /*26 - P*/ "स विजयिष्यति को जानाति कदा योद्धव्यं कदा न युध्येत इति.\n",
    /*27 - Q*/ "जीवनं दुःखम् अस्ति.\n",
    /*28 - R*/ "यथा माता एकमेव बालकं प्रेम करोति तथा समग्रं जगत् प्रेम करोतु.\n",
    /*29 - S*/ "आरोग्यम् कृच्छ्रतमं दानं, सन्तोषं महत्तमं धनम्.\n",
    /*30 - T*/ "शुद्धिः अशुद्धिः च आत्मनः उपरि निर्भरं भवति; न कश्चित् अन्यस्य शुद्धिं कर्तुं शक्नोति.\n",
    /*31 - U*/ "यस्योत्पन्नस्वभावो यस्य तस्य निवृत्तिस्वभावः.\n",
    /*32 - V*/ "अहं लोकेन सह विवादं न करोमि; अपि तु लोकः एव मां विवादयति.\n",
    /*33 - W*/ "अराजकता सर्वेषु समासेषु निहितं भवति, यत्नेन प्रयतस्व.\n",
    /*34 - X*/ "बुद्धिः परिवर्तनं कर्तुं स्वीकर्तुं क्षमता अस्ति.\n",
    /*35 - Y*/ "किमपि न किमपि श्रेयस्करम्.\n",
    /*36 - Z*/ "किमपि अतिशयेन न हितकरम्.\n",
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

    logo();
    
    //ENCRYPTION
	//Shift Cipher
	shift_cipher_encrypt(text, 5);
	//Invoking The Main Crypt
	mandaragupta_encrypt(shifted_text);
    printf("END\n");

    //DECRYPTION
    //printf("%s\n", text);
    //shift_cipher_decrypt(text, -5);
    //mandaragupta_encrypt(unshifted_text);

    //GENERAL
    //printf("%s\n", db[1]);
	return 0;
}


char *shift_cipher_encrypt(char str[], int key)
{
    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];

        //For Simple Letters
        // if (character >= 'a' && character <= 'z')
        // {
        //     character = character + key;
        //     if(character > 'z')
        //     {
        //         character = character - 'z' + 'a' - 1;
        //     }
        //     str[i] = character;
        // }

        //For Capital Letters
        if(character >= 'A' && character <= 'Z'){
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
	printf("INSIDE THE MG_ENCRYPT CRYPT\n");
    for (int i = 0; i <= strlen(text); i++){
        character2 = text[i];
        int index = 0;
        if(character2 >= 'A' && character2 <= 'Z'){
            index = character2 - 54;
            strcat(encrypted_text, sanskrit_db[index]);
        }
        else if(character2 >= '0' && character2 <= '9'){
            index = character2 - 47;
            strcat(encrypted_text, sanskrit_db[index]);
        }
        else if(character2 == 32){
            index = character2 - 32;
            strcat(encrypted_text, sanskrit_db[index]);
        }
        else{
            strncat(encrypted_text, &character2, 1);
        }
        strcat(encrypted_text, "");
    }
    printf("%s", encrypted_text);
}

char *mandaragupta_decrypt(char *text){
	printf("INSIDE THE MG_DECRYPT CRYPT\n");
    //printf("%s\n", db[0]);
	printf("%s\n", unshifted_text);
}

void usage(){
	printf("TODO USAGE");
}
void logo(){
    char *logo[] = {
        /*0*/
        "███╗░░░███╗░█████╗░███╗░░██╗██████╗░░█████╗░██████╗░░█████╗░░░░░░░░██████╗░██╗░░░██╗██████╗░████████╗░█████╗░\n████╗░████║██╔══██╗████╗░██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗░░░░░░██╔════╝░██║░░░██║██╔══██╗╚══██╔══╝██╔══██╗\n██╔████╔██║███████║██╔██╗██║██║░░██║███████║██████╔╝███████║█████╗██║░░██╗░██║░░░██║██████╔╝░░░██║░░░███████║\n██║╚██╔╝██║██╔══██║██║╚████║██║░░██║██╔══██║██╔══██╗██╔══██║╚════╝██║░░╚██╗██║░░░██║██╔═══╝░░░░██║░░░██╔══██║\n██║░╚═╝░██║██║░░██║██║░╚███║██████╔╝██║░░██║██║░░██║██║░░██║░░░░░░╚██████╔╝╚██████╔╝██║░░░░░░░░██║░░░██║░░██║\n╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░░░░░╚═════╝░░╚═════╝░╚═╝░░░░░░░░╚═╝░░░╚═╝░░╚═╝\n",
        /*1*/
        "██████████████████████████████████████████████████████████▀██████████████████████████\n█▄─▀█▀─▄██▀▄─██▄─▀█▄─▄█▄─▄▄▀██▀▄─██▄─▄▄▀██▀▄─██▀▀▀▀▀██─▄▄▄▄█▄─██─▄█▄─▄▄─█─▄─▄─██▀▄─██\n██─█▄█─███─▀─███─█▄▀─███─██─██─▀─███─▄─▄██─▀─█████████─██▄─██─██─███─▄▄▄███─████─▀─██\n▀▄▄▄▀▄▄▄▀▄▄▀▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▀▀▄▄▀▄▄▀▄▄▀▄▄▀▄▄▀▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▀▀▀▀▄▄▄▀▀▄▄▀▄▄▀\n"
    };

    time_t t;
    int n = 1; //amount of numbers

    srand((unsigned) time(&t));
    for(int i = 0; i < n; i++){
        //printf("%d\n", rand() % 100); //between
        printf("%s", logo[rand() % 2]);
    }

    // printf("%s", logo[0]);
}






