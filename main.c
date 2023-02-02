#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getText();
void repeatKey();
void changeKey();
void encryption(); //encrypts the text file using key and text
void decryption(); //decrypts the encrypted text and the key

int menu = 0; //global variable for menu as functions use it to go back to menu screen

char text[255]=""; //delare the vaibles
int textLen;
char key[] = "sagnjk";
char newKey[18] = "";
char repKey[256] = "";

char letters[26][26]; // Letters is a 2D array which is 26 by 26

int main()
{
    printf("Samuel Gandy Course Work 2 Programming \n");

    printf(" The Vigenere Cipher Matrix \n");

    int let = 97; //set the let variable to 97 which is a

    int i; //declare i
    int x; //declare x

    for(i = 0;i < 26; i++){ //i starts at 0 and runs through amount of letters of alphabet (26) for the y axis
        for(x = 0; x < 26; x++){ //i starts at 0 and runs through amount of letters of alphabet (26) for the x axis
            letters[i][x] = let; //let is equal is the number that i and x equal to in the matrix

            if(let < 122){ //if below the ASCII of Z then add one
                let++;
                for(int i;i < textLen; i++){
                printf("%c", repKey[i]);
                }
            } else { //if not below z then set to ACSII for a
                let = 97;
            }
        }
        let = 97 + i + 1;//reset back to a and then plus value i plus one so the number is always increasing
    }

    for(i = 0; i < 26; i++){ //start at 0 and run through to 26
        printf("\n"); //set a new line
        for(x = 0; x < 26; x++){ //start at 0 and run through to 26
            printf(" %c", letters[i][x]); //print the letter in the matrix with the x and y
        }
    }

//----------menu starts here ------

    while(menu !=4){

    printf("\n MENU SCREEN \n 1. Encryption \t 2. Decryption \t 3. New Key \t 4. Exit Program \n");
    scanf("%d",&menu);
    switch (menu){
         case (1):
            printf("Option 1 Encryption \n load file 5 to 256 characters in length (ONLY LOWER CASE and White Spaces).\n ");
            getText();
            printf("\n text is %s \t key is %s ", text, key);
            repeatKey();
            printf("\n The read text is =   %s \n The  repeated key is  = %s ", text, repKey);
            printf("\n-----------------ENCRYPTION FUNCTION ----------\n");
            encryption();

         break;

         case (2):
            printf("Option 2 Decryption \n load file 5 to 256 characters in length (ONLY LOWER CASE and White Spaces).\n ");
            getText();
            printf("\n text is %s \t key is %s ", text, key);
            repeatKey(key);
            printf("\n The read text is = %s \n The  repeated key is  = %s ", text, repKey);
            printf("\n-----------------DECRYPTION FUNCTION ----------\n");
            decryption();


         break;

         case (3):
            printf("changing key option \n");
            changeKey();

         break;

         case (4):
           printf("You are exiting the program");
         break;
   }
 }
}

void getText(){
    printf("\n  ---- Text Function ---- \n \n");
     FILE *pFile; //file is pointer pFile

     char word[255];
     char defaultText[255] = "hello this text can be encrypted instead";

     pFile = fopen("Text.txt", "r"); //read file

     if (pFile == NULL){
         printf("Didn't work so creating a new file \n"); //print
         pFile = fopen("Text.txt","w"); //create file

     }
     else
     {
       fscanf(pFile,"%s", text); //scan the data and read the data

//      printf(" %s \n", text); //print the varibles in console (debugging)

      while(!feof(pFile)) //while there is only one space.
      {
          fscanf(pFile," %s ", word); //scan and read the varibles
//          printf(" %s \n", word); //print the varibles in console  (debugging)

          strcat(strcat(text, " "), word); //adds a string onto the end of the other with a space in between (This allows for spaces strcat(strcat(text, " "), word); )
          fflush(stdin); //clears all the access information in console
      }
    }
    fclose(pFile); //close the file

    textLen = strlen(text);

    //This is the checking the text is to the spec
    printf("\n The new text length is %d \n ", textLen);

    if(textLen > 4 && textLen < 256){
        printf("%s \n", text); //print the variables in console

        int x;

        for(x = 0; x < textLen; x++){
            if((text[x] >= 97 && text[x] <= 122)|| text[x] == 32){
                printf("\n char lower %c", text[x]);
            } else {
                printf("\n not lower back to default text");
                strcpy(text, defaultText); //text is default text
            }
        }

     } else {
        printf("\n invalid text set to default");
        strcpy(text, defaultText); //text becomes the default key
        printf("\n %s \n", text); //print the variables in console
     }

    printf("\n--- TEXT IS %s", text);
}

void repeatKey(){
    printf("\n  ---- repeat key function ---- \n \n ");

    textLen = strlen(text);
    char newRepKey[256]="";

    printf("-The starting text is %s %d \n", text, textLen);
    printf("-The starting key is %s \n", key);

    int j;
    int k;

    for(k = 0, j = 0; k < textLen; k++, j++){


        if(text[k]==' '){ //if text is a space
         --j;
        newRepKey[k]= ' '; //repkey char  = text char
          //skips a value
         continue;
        }
        if(j==strlen(key))
        j = 0;
        newRepKey[k] = key[j];
        }

    int repKeyLen = strlen(newRepKey);

    printf("\n ---length of repeated key is %d", repKeyLen);



    strcpy(repKey, newRepKey);
    fflush(stdout); //clears the standard output buffer
    printf("\n ---the key could be %s",repKey);

    for(int i;i < textLen; i++){
        printf("- %c", repKey[i]);
    }
}

void encryption(){
    printf("\n  ---- Encryption function ---- \n ");

    fflush(stdin);

    char encrypted[256] = "";

    int xStr; //a string to hold numbers of the coordinates on x axis
    int yStr; //a string to hold numbers of the coordinates on y axis

    int k; //the variable for the for loop for text

    printf("\n Encryption Function \n");

    printf("Using this key  %s and text and %s", repKey, text); //show the key and the text to show the code is passing properly

    for(k = 0; k < textLen; k++){
       xStr = repKey[k] - 97;
        yStr = text[k]- 97;
      if(text[k] == ' '){
        encrypted[k] = ' ';
        continue; }
        printf("\n %c %d ", repKey[k], repKey[k] - 97); //prints the number

         //skips rest of the loop
        encrypted[k] = letters[xStr][yStr];
        printf("%c", encrypted[k]); //printing the new
    }

    printf("\n Encrypted text = %s ", encrypted);

    FILE *pWrite;

    pWrite = fopen("Text.txt","w");
    fprintf(pWrite, encrypted);

    fclose(pWrite);
}

void decryption(){
    printf("\n  ---- Decryption function ---- \n ");

    printf("\n Decryption Function \n");
    printf("Key = %s \n encrypted tint textLen = strlen(text);ext = %s \n", repKey, text);

    fflush(stdin); //clears all the access information in console

    int d = 0;
    int j = 0;

    for(d = 0; d < strlen(repKey); d++){
        for(j = 0;j < 26; j++){
            if(letters[repKey[d]-97][j]==text[d]){
                text[d] = j + 97; //changed text from decrypted this could cause problems
                break;
            }
        }
    }
    printf("\n the decryption is %s", text); //changed text from decrypted this could cause problems

    FILE *pWrite;

    pWrite = fopen("Text.txt","w");
    fprintf(pWrite, text);

    fclose(pWrite);
}

void changeKey(){
    printf("\n  ---- change Key function ---- \n ");

    printf("option 3 CW2\n");
    fflush(stdin); //clears all the access information in console

    printf("\n Please Enter a new key \n");
    gets(newKey); //get string from console
    int newKeyLen = strlen(newKey); //the newKeyLength is the length of the string from console
    printf("\n The new key is %s and is %d", newKey, newKeyLen); //print the new key and the length of new key

    if(newKeyLen > 1 && newKeyLen < 17){ //check the length of the key and make sure its between 2 and 16
        printf("\n new key is the correct length"); //if between 2 and 16 then print correct length

        for(int i = 0; i < newKeyLen; i++){ //for loop to run through the string
            if(newKey[i] >= 'a' && newKey[i] <= 'z'){ //checking each char is between a and z lower case
               printf("\n Character is lower case %c", newKey[i]); //print the letter and message saying lower case
            } else {
               printf("\n Not lower case %c \n Going back to main menu", newKey[i]); //if not a lower case letter then print invalid
               menu = 0;
            }
        }

      strcpy(key, newKey); //Key is now the new key
      printf("\n Key is %s", key); //print the key to check

    } else {
        printf("\n Invalid Key reset back to %s ", key); //if the string is more then 16 or less then 2 chars print key is default
    }
}

