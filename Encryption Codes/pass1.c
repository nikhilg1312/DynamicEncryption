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
    char password[20] ;
    printf("Enter the password: \n ");
    scanf("%s",password);
    printf("Passwrod     = %s\n",password);
    encrypt(password,0xFADB);
    printf("Encrypted value = %s\n",password);
    decrypt(password,0xFADB);
    printf("Decrypted value = %s\n",password);
    return 0;
}