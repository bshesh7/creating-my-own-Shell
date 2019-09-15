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
pid_t pid_array[100];  // this array stores the pids 
int p_t = 0; // is a pid pointer to the last element
char hist[100][100]; // this array stores the history of commands
int hist_p = 0; // index to the history array 
char  cmdarr[5][100]; 
int size_cmd=0;
int abc=0;

int main(int argc, char**argv){
 
 int i;
 int switcher = 1;


 while(switcher){


  //Prints msh every line
  printf(" msh>");
     
  
   // Taking the input  
     char nth [10];
     	char stri [100];
     		char toks[100][100];  
     			fgets(stri,100,stdin);
  
  


  // storing the history 
  	label:   
  		strcpy(hist[hist_p],stri);
  			hist_p++;


  //parse
  
  int s_d = 0;
  	int j = 0;
  		int control = 0;
  			int len = strlen(stri);
  

  
  for(i=0;i<=(strlen(stri));i++)
   {
      if(stri[i]==' ' || stri[i]=='\0')
      {
       
       //space detected
       if(stri[i]==' ')
       {
         s_d = 1;
       }
       if(s_d==1)
       {
         toks[control][j]='\0';
       }
       if(s_d==0)
       {
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
 	int status;


 if(ret == 0)
 {
  abc = 1;
     int pid = fork();
     

  if(pid==0)
   {
    char* args[]={"mkdir",toks[1], NULL};
    	status = execvp("mkdir",args);
    }
   else
   {
    pid_array[p_t] = pid;
    	p_t++;
   }
 }
 
// 

 ret = strcmp(toks[0],"ls");
  
if(ret == 0){
      if(toks[1][0]!='\0')
        {
          printf("invalid option -- %s ",toks[1]);
          goto bbh;
        }
         abc = 1;
      
            int pid = fork();
  
  
               if(pid==0)
               {
 
                 char* args[]={"ls", NULL};
                   execvp("ls",args);
  
               }
               else
               {
                    pid_array[p_t] = pid;
                      p_t++;
                }
            
}    
//  
  bbh:
  	ret = strcmp(toks[0],"cd");
  
  
  if(ret == 0)
  {
     abc = 1;
     	int ret2 = strcmp(toks[1],"..");     
     		if(ret2==0)
     			{

       			chdir("..");
       				pid_array[p_t] = getpid();
       					p_t++;
     			}
     		else
     			{
       				chdir(toks[1]);
       					pid_array[p_t] = getpid();
       						p_t++;
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
ret = strcmp(toks[0],"listpids");
   if(ret==0)
   {
     abc = 1;
     for(i=0;i<=p_t;i++)
     {
       printf("%d\n",pid_array[i]);   
    
     }
   }


//
ret = strcmp(toks[0],"history");
char nth_num_str[10];   
if(ret==0)
    {
      abc = 1;
      if(hist_p>15)
       {
       int a = hist_p - 15;
       for(i = a;i<=hist_p;i++)
        {
        printf(" %d -- %s",i,hist[i]);
        }
       }
      if(hist_p<15){
       for(i=0;i<=hist_p;i++)
       {
         printf(" %d -- %s",i,hist[i]);
       }
      }
         printf("\n");
         	 printf("msh> ");
           		char ee[10];
           			char eee[10]; 
           				fgets(ee,10,stdin);
           if(ee[0] == '!')
             {
              
              int k =0;
              int l =1;
     	       while(ee[l]!='\0')
                {
      		 eee[k] = ee[l];
                  l++;
                   k++;
     	        }  
      
              int nth = atoi(eee);
              
                 strcpy(stri,hist[nth]); 
                 goto label;
             }
   }

ret = strcmp(toks[0],"");
if(ret == 0){
 abc = 1; 
}
    

ret = strcmp(toks[0],"echo");
 if(ret == 0)
 {
   abc = 1;   
  int pid = fork();
     

  if(pid==0)
   {
    char* args[]={"echo",toks[1], NULL};
    execvp("echo",args);
    }
   else
   {
    pid_array[p_t] = pid;
    p_t++;
   }
 }

//
// Takes care of all other command in the /bin/local directory
if(abc!=1)
  {
    int pid = fork();
     if(pid==0)
   {
    char* args[]={toks[0],toks[1], NULL};
    execvp(toks[0],args);
   }
  }


// prints command not found 
if(abc != 1){
printf("\n Command not found \n");
}
j = 0;
control = 0;
toks[1][0]='\0';
abc = 0;
 }
//
//

return 0;
}

