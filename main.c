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
	/*0*/ "Karma has no menu, you get served what you deserve",
    /*1*/ "If anything is worth doing, do it with all your heart",
    /*2*/ "Better to be slapped with the truth than kissed with a lie",
    /*3*/ "The trouble is you think you have time",
    /*4*/ "Let the past make you better, not bitter",
    /*5*/ "It is easy to see faults of others, but difficult to see one's own faults",
    /*6*/ "There is no fear for one whose mind is not filled with desires",
    /*7*/ "Sometimes silence is the best solution",
    /*8*/ "Radiate boundless love towards the entire world",
    /*9*/ "A disciplined mind brings happiness",
    /*10*/ "Give, even if you only have a little",
    /*11*/ "Those who cling to perceptions and views wander the world offending people",
    /*12*/ "Drop by drop is the water pot filled",
    /*13*/ "Conquer anger with non anger, conquer badness with goodness, conquer meanness with generosity",
    /*14*/ "Those who cling to perceptions and views wander the world offending people",
    /*15*/ "I will not look at another's bowl intent on finding fault: a training to be observed",
    /*16*/ "May all beings have happy mind",
    /*17*/ "Delight in heedfulness! Guard well your thoughts!",
    /*18*/ "Live with no sense of mine, not forming attachments to experiences",
    /*19*/ "Resolutely train your self to attain peace",
    /*20*/ "The root of suffering is attachment",
    /*21*/ "understanding is the heartwood of well-spoken words",
    /*22*/ "The only failure in life is not to be true to the best one knows",
    /*23*/ "You cannot travel the path until you have become the path itself",
    /*24*/ "What we think, we become",
    /*25*/ "Nothing remains without change",
    /*26*/ "He will win who knows when to fight and when not to fight.",
    /*27*/ "Life is Suffering",
    /*28*/ "Love the whole world as a mother loves her only child",
    /*29*/ "Health is the gratest gift, contentment is the greatest wealth",
    /*30*/ "Purity and impurity depend on oneself; no one can purify another",
    /*31*/ "whatever has the nature of arising has the nature of ceasing ",
    /*32*/ "I do not dispute with the world; rather it is the world that disputes me",
    /*33*/ "chaos is inherent in all compunded things, strive on with diligence",
    /*34*/ "Intelligence is the ability to adopt to change",
    /*35*/ "Something is better than nothing",
    /*36*/ "Anything too much is not good",
    /*37*/ "Whoever is happy will make others happy too",
};

char *sanskrit_db[] = {
	/*0*/ "कर्मस्य मेनू नास्ति, भवन्तः यत् अर्हन्ति तत् परोक्ष्यन्ति।",
    /*1*/ "यदि किमपि कर्तुं योग्यं भवति तर्हि फो तत् सर्वहृदयेन।",
    /*2*/ "असत्येन चुम्बनात् सत्येन प्रहारं श्रेयस्करम्।",
    /*3*/ "क्लेशः अस्ति यत् भवन्तः मन्यन्ते यत् भवतः समयः अस्ति।",
    /*4*/ "अतीतः भवन्तं श्रेष्ठं करोतु, न तु कटुः।",
    /*5*/ "परदोषदर्शनं सुलभं स्वदोषदर्शनं तु दुष्करम्।",
    /*6*/ "न भयं विद्यते यस्य मनः कामैरपि न भवति।",
    /*7*/ "कदाचित् मौनम् एव उत्तमं समाधानम् अस्ति।",
    /*8*/ "सम्पूर्ण विश्व के प्रति असीम प्रेम विकीर्ण करें।",
    /*9*/ "अनुशासितं मनः सुखं जनयति।",
    /*10*/ "ददातु, यद्यपि भवतः किञ्चित् एव अस्ति।",
    /*11*/ "ये प्रतीतिदृष्टिषु आलम्बन्ते जनाः आक्षेपं कुर्वन्तः लोकं भ्रमन्ति।",
    /*12*/ "बिन्दुः बिन्दुः जलकुम्भः पूरितः अस्ति।",
    /*13*/ "अक्रोधेन क्रोधं जयेत्, सद्भावेन दुष्टं जयेत्, उदारतया नीचतां जयेत्।",
    /*14*/ "ये प्रतीतिदृष्टिषु आलम्बन्ते जनाः आक्षेपं कुर्वन्तः लोकं भ्रमन्ति।",
    /*15*/ "अहं दोषं अन्वेष्टुं परस्य कटोराभिप्रायं न पश्यामि: अवलोकनीयं प्रशिक्षणम्।",
    /*16*/ "सर्वेषां भूतानां सुखमनः भवतु।",
    /*17*/ "Delight in heedfulness! Guard well your thoughts!", /////////////////////////////////////
    /*18*/ "न मम भावेन सह जीवन्तु, अनुभवेषु आसक्तिं न निर्माय।",
    /*19*/ "शान्तिप्राप्त्यर्थं दृढनिश्चयेन स्वस्य आत्मनः प्रशिक्षणं कुरुत।",
    /*20*/ "दुःखस्य मूलं आसक्तिः।",
    /*21*/ "अवगमनं सुभाषितानां हृदयम्।",
    /*22*/ "जीवने एकमात्रं असफलता अस्ति यत् उत्तमं जानाति तस्य सत्यं न भवेत्।",
    /*23*/ "न त्वं मार्गं गन्तुं न शक्नोषि यावत् त्वं मार्ग एव न भवसि।",
    /*24*/ "यत् चिन्तयामः, वयं भवेम।",
    /*25*/ "परिवर्तनं विना किमपि न तिष्ठति।",
    /*26*/ "स विजयिष्यति को जानाति कदा योद्धव्यं कदा न युध्येत इति।",
    /*27*/ "जीवनं दुःखम् अस्ति।",
    /*28*/ "यथा माता एकमेव बालकं प्रेम करोति तथा समग्रं जगत् प्रेम करोतु।",
    /*29*/ "आरोग्यम् कृच्छ्रतमं दानं, सन्तोषं महत्तमं धनम्।",
    /*30*/ "शुद्धिः अशुद्धिः च आत्मनः उपरि निर्भरं भवति; न कश्चित् अन्यस्य शुद्धिं कर्तुं शक्नोति।",
    /*31*/ "यस्योत्पन्नस्वभावो यस्य तस्य निवृत्तिस्वभावः।",
    /*32*/ "अहं लोकेन सह विवादं न करोमि; अपि तु लोकः एव मां विवादयति। ",
    /*33*/ "अराजकता सर्वेषु समासेषु निहितं भवति, यत्नेन प्रयतस्व।",
    /*34*/ "बुद्धिः परिवर्तनं कर्तुं स्वीकर्तुं क्षमता अस्ति।",
    /*35*/ "किमपि न किमपि श्रेयस्करम्।",
    /*36*/ "किमपि अतिशयेन न हितकरम्।",
    /*37*/ "Whoever is happy will make others happy too", /////////////////////////////////////////////
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
	printf("INSIDE THE MG_ENCRYPT CRYPT\n");

    for (int i = 0; i <= strlen(text); i++){
        character2 = text[i];
        char space[] = "damn";
        if(character2 >= 'A' && character2 <= 'Z'){
            //printf("%c\n", character2);
            //strncat(encrypted_text, &character2, 1);
            strcat(encrypted_text, &character2);
        }
        else if(character2 >= '0' && character2 <= '9'){
            //printf("%c\n", character2);
            //strncat(encrypted_text, &character2, 1);
            strcat(encrypted_text, &character2);
        }
        else if(character2 == 32){
            //printf("%c\n", character2);
            //strncat(encrypted_text, &character2, 1);
            strcat(encrypted_text, "&character2");
        }
        else{
            //printf("%c", character2);
            strncat(encrypted_text, &character2, 1);
            //char space[] = "Damn";
            //strcat(encrypted_text, space);
        }
    }
    printf("%s\n", encrypted_text);
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






