#include <stdio.h>
#include<string.h>
int validation(char str[])
{
    int i=0;
    while(str[i]=='a')
    {
        i++;
    }
    if(str[i]=='b' && str[i+1]=='b' && str[i+2]=='\0' )
    {
        return 1;
    }
    return 0;

}
int main()
{
   char str[20];

   printf("Enter String : ");
   gets(str);

   if(validation(str))
   {
       printf("Valid");
   }
   else
   {

       printf("Invalid");
   }
   return 0;
}
