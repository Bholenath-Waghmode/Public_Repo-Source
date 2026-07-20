// Revese   string
#include<stdio.h>

typedef unsigned int uint32_t;


void printStr(char str[]){
	
	for (uint32_t i=0; str[i]!='\0'; i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}


void reverseString(char str[]){
	static uint32_t strLen=0,j=0;
	char temp=0;
	printf("Str to Revese: ");
	printStr(str);
	for(uint32_t i=0; str[i]!='\0'; i++){
		strLen++;

	}
	printf("Str Len: %d\n",strLen);
	j=strLen-1;
	for (uint32_t i=0;i<(strLen/2);i++){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
        j--;
	}
		printf("Revesed Str: ");
		printStr(str);
}


void main(){
	
	char myStr[100]="abcde";
	reverseString(myStr);
}

