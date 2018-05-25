#include <stdio.h>
#include <string.h>

 
void encrypt(char password[],int key)
{
    unsigned int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i] - key;
    }
}
 
void decrypt(char password[],int key)
{
    unsigned int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i] + key;
    }
}
int main()
{
    FILE *fp,*fp1;
    char password[20] ;
    char ch,a;
    int i;
    
    fp = fopen("input.txt","r"); // read mode

       if( fp == NULL )
       {
           perror("Error while opening the file.\n");
       }
   
   i=0;
   printf("\nInput data : ");
   while( ( ch = fgetc(fp) ) != EOF )
   {
    printf("%c",ch);
    password[i]=ch;
    i++;
   } 
   encrypt(password,0xABCD);
 
   fp1 = fopen("output.txt","w");
   i=0;
   do
    {
    a=password[i];
    fputc(a,fp1);
    i++;
    }while(a!=EOF);
    
    decrypt(password,0xABCD);
    printf("\nDecrypted Data : %s\n",password);
    return 0;
}