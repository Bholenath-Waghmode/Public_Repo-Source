// Revese   string

typedef unsinged int uint32_t;


void printStr(char str[]){
	
	for (uint32_t i; i!='\0';i++)
	{
		printf("%s",str[i]);
	}
	printf("\n");
}


void reverseString(char str[]){
	static uint32_t strLen,j;
	char temp[100];
	printf("Str to Revese: ");
	printStr(str);
	for(uint_32 i=0;i!='\0';i++;
	{
		strLen++;
	}
	for (i=0;i<strlen/2;i++){
		temp=[str[i];
		str[i]=str[strLen];
		str[strLen]=srt[i];
	}
		printf("Revesed Str: ");
		printStr(str);
}


void main(){
	
	char myStr[100]="abcd";
	
	
}

