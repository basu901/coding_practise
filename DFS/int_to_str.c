#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

int main(){
    int input;

    printf("Please input number:");
    scanf("%d",&input);

    char buffer[5];
    buffer[4] = '\0';
    int input_copy = input;
    int count=3;

    do{
        int digit=input_copy%10;
        input_copy /= 10;
        buffer[count] = '0' + digit;
        count--;
    }while(input_copy>0 && count>=0);
    
    //char* output =(char *) malloc(sizeof(char) * (strlen(buffer)+1));
    char output[5];
    int j=-1;
    int i=0;
    for(i=count+1,j=0;buffer[i]!='\0';i++,j++)
    {   
        output[j] = buffer[i];
        printf("%d", j);
    }
    printf("%d", j);
    output[j] = '\0';
    
    

    printf("kutput:%s",output);

    return 0;
}