/*
Name: Bishesh Shrestha
ID: 1001556177
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_STRING 100 // the maximum length of string the command line can take at a time

int main(int argc, char**argv){
 int i;
 int switcher = 1;
 while(switcher){
  //Taking the input and print msh every line
    
     printf("msh>");
  
  char stri [100];
  char toks[100][100];
  fgets(stri,100,stdin);
  //printf("%s",stri);
  //parse
  //char* command = strtok(stri," ");
  //char* argue = strtok(NULL," ");
  int s_d = 0;
  int j = 0;
  int control = 0;
int len = strlen(stri);
  
  for(i=0;i<=(strlen(stri));i++)
   {
      if(stri[i]==' ' || stri[i]=='\0')
      {
       
       //space detected
       if(stri[i]==' '){
       s_d = 1;
       }
       if(s_d==1){
       toks[control][j]='\0';
       }
       if(s_d==0){
       toks[control][j-1]='\0';
       }
       j = 0;
       control++;
       s_d = 0;
      }	
      else 
      {
       toks[control][j]=stri[i];
       j++;
      }    	
   }
 int rr = strlen(toks[0]);
 int ret = strcmp(toks[0],"mkdir");
  
 if(ret == 0){
  int pid = fork();
  if(pid==0){
  char* args[]={"mkdir",toks[1], NULL};
  execvp("mkdir",args);
    }
  }
 
// 

 ret = strcmp(toks[0],"ls");
  
 if(ret == 0){
  int pid = fork();
  if(pid==0){
  char* args[]={"ls", NULL};
  execvp("ls",args);
   }
  }    
//  
  ret = strcmp(toks[0],"cd");
  
  if(ret == 0)
  {
     int ret2 = strcmp(toks[1],"..");     
     if(ret2==0)
     {
       chdir("..");
       //printf("argue is : %s",toks[1]);
     }
     else
     {
       chdir(toks[1]);
     }
   }
// implimentig the exit function 
ret = strcmp(toks[0],"exit");
  
   if(ret==0)
   {
     exit(0);
   }
ret = strcmp(toks[0],"quit");
  
   if(ret==0)
   {
     exit(0);
   }
//
j = 0;
control = 0;
toks[1][0]='\0';
 }
//
//

return 0;
}
