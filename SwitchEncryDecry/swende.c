#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char password[],int key)
{
int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i] - key;
    }

    printf("\nEncrypted data :");
    for(i=0;i<strlen(password);++i)
    {
        printf("%c",password[i]);
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
    int i,k;
    time_t t;
    
    fp = fopen("input.txt","r");

       if( fp == NULL )
       {
           perror("Error while opening the file.\n");
       }



/*----------------------Encryption Part----------------------------*/   

   srand((unsigned) time(&t));
   k=rand()%5+1;
   printf("%d\n",k );
   switch(k)
   {

      case 1: 
              
              i=0;
              printf("\nID 1 -->>Input data : ");
              while( ( ch = fgetc(fp) ) != EOF )
              {
                    printf("%c",ch);
                    password[i]=ch;
                    i++;
               } 
   
               encrypt(password,0xABCD);
 
      break;


      case 2: 
              
              i=0;
              printf("\nID 2 -->>Input data : ");
              while( ( ch = fgetc(fp) ) != EOF )
              {
                    printf("%c",ch);
                    password[i]=ch;
                    i++;
               } 
   
               encrypt(password,0xDCBA);
 
      break;

      case 3: 
              
              i=0;
              printf("\nID 3 -->>Input data : ");
              while( ( ch = fgetc(fp) ) != EOF )
              {
                    printf("%c",ch);
                    password[i]=ch;
                    i++;
               } 
   
               encrypt(password,0xCDAB);
 
      break;


      case 4: 
              
              i=0;
              printf("\nID 4 -->>Input data : ");
              while( ( ch = fgetc(fp) ) != EOF )
              {
                    printf("%c",ch);
                    password[i]=ch;
                    i++;
               } 
   
               encrypt(password,0x0453);
 
      break;


      case 5: 
              
              i=0;
              printf("\nID 5 -->>Input data : ");
              while( ( ch = fgetc(fp) ) != EOF )
              {
                    printf("%c",ch);
                    password[i]=ch;
                    i++;
               } 
   
               encrypt(password,0x6543);
 
      break;

   }  

/*----------------------Decryption Part-------------------------------------------*/

   if(k==1)
   {
 
           fp1 = fopen("output.txt","w");
           i=0;
           do
           {
             a=password[i];
             fputc(a,fp1);
             i++;
           }while(a!=EOF);
    
    decrypt(password,0xABCD);
    printf("\nID 1 -->>Decrypted Data : %s\n",password);
    return 0;
   }

   if(k==2)
   {
 
           fp1 = fopen("output.txt","w");
           i=0;
           do
           {
             a=password[i];
             fputc(a,fp1);
             i++;
           }while(a!=EOF);
    
    decrypt(password,0xDCBA);
    printf("\nID 2 -->>Decrypted Data : %s\n",password);
    return 0;
   }

   if(k==3)
   {
 
           fp1 = fopen("output.txt","w");
           i=0;
           do
           {
             a=password[i];
             fputc(a,fp1);
             i++;
           }while(a!=EOF);
    
    decrypt(password,0xCDAB);
    printf("\nID 3 -->>Decrypted Data : %s\n",password);
    return 0;
   }

   if(k==4)
   {
 
           fp1 = fopen("output.txt","w");
           i=0;
           do
           {
             a=password[i];
             fputc(a,fp1);
             i++;
           }while(a!=EOF);
    
    decrypt(password,0x0453);
    printf("\nID 4 -->>Decrypted Data : %s\n",password);
    return 0;
   }

  if(k==5)
   {
 
           fp1 = fopen("output.txt","w");
           i=0;
           do
           {
             a=password[i];
             fputc(a,fp1);
             i++;
           }while(a!=EOF);
    
    decrypt(password,0x6543);
    printf("\nID 5 -->>Decrypted Data : %s\n",password);
    return 0;
   }


}
