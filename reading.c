#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define TXT ".txt"


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
} 


void readprocess(){
delay(2);
    FILE *fpipe;
     FILE *fp;
     char *command = "TASKLIST";
    char c = 0;
 
    
    
    
    //Get pc name
 	char buffer[MAX_COMPUTERNAME_LENGTH + 1]; 
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1 ;

  	GetComputerName( buffer, &size );
  
 	 printf( "Client Computer name = %s\n", buffer );
 	 	*((char *)mempcpy(buffer + strlen(buffer), TXT, 5)); 
  	getchar();
  	time_t t;   // not a primitive datatype
    time(&t);
    printf("%s\n", ctime(&t));
    printf("Reading processing.............");
 	delay(4);
    
    
//file open
     fp = fopen(buffer,"w+");
    
  
    if(fp == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
  fprintf(fp,"Client pc name %s\n", buffer);
   fprintf(fp,"Read time %s", ctime(&t));
   
   
   
//connection for pipe
    if (0 == (fpipe = (FILE*)popen(command, "r")))
    {
        perror("popen() failed.");
        exit(EXIT_FAILURE);
    }

    while (fread(&c, sizeof c, 1, fpipe))
    {
       fprintf(fp,"%c", c);
       	 printf("%c", c);
    
    }
  	fclose(fp);
    pclose(fpipe);

   
}
int selecion(){
		int sel;

printf("========================Read Background process of Client coumpuet============================\n");	
printf("");
printf("");
printf("Do you want to read    press 1\n");
printf("Exit                   press  0\n");
scanf("%d",&sel);
printf("\n\n\n\n");

return sel;
}


void main()
{
switch(selecion()){
	case(0):
system("cls");
		printf("Thanks for Using me");
		exit(0);
		break;
	case(1):
 
system("cls");
		readprocess();
		printf("\n\n\n\n");
		
		main();
		break;

}
   
}
