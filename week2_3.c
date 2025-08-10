#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main()
{
FILE *myfile,*ffile;
char myline[MAX],friendline[MAX];
myfile=fopen("mydetails.txt","w");
if(myfile==NULL)
{
perror("Error creating mydetails.txt");
return 1;
}
fprintf(myfile,"NAME: Riya\n");
fprintf(myfile,"AGE: 20\n");
fprintf(myfile,"CITY: Dehradun\n");
fprintf(myfile,"UNIVERSITY: GEHU\n");
fclose(myfile);
ffile=fopen("friendetails.txt","w");
if(ffile==NULL)
{
perror("Error creating friendetails.txt");
return 1;
}
fprintf(ffile,"NAME: Shristi\n");
fprintf(ffile,"AGE: 20\n");
fprintf(ffile,"CITY: Delhi\n");
fprintf(ffile,"UNIVERSITY: GEHU\n");
fclose(ffile);
myfile=fopen("mydetails.txt","r");
ffile=fopen("friendetails.txt","r");
if(myfile==NULL || ffile==NULL)
{
perror("Error opening files for reading");
return 1;
}
printf("Matching lines in both files:\n");
while(fgets(myline,MAX,myfile)!=NULL && fgets(friendline,MAX,ffile)!=NULL)
{
myline[strcspn(myline,"\n")]="\0";
friendline[strcspn(friendline,"\n")]="\0";
if(strcmp(myline,friendline)==0)
{
printf("%s\n",myline);
}
}
fclose(myfile);
fclose(ffile);
return 0;
}
