#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int nombremois(char*m,char**car){
	int n=1;
		for(int i=1;i<13;i++){
			if(strstr(car[i],m)!=NULL){
			n=i;
		    }
        }
			//printf(" %s\n",car[n]);
		 
		 return n;
}
int main(){
	char*valeur=getenv("QUERY_STRING");
	  printf("Content-type:text/html\n\n");
	  printf("<html>");
	  printf("<head>");
	  printf("<meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>testformulaire</title>");
       printf("</head>");
       
      printf("<body>");
      char*before=malloc(20);
	    char*after=malloc(20);
	     strcpy(before,strtok(valeur,"="));
	     strcpy(before,strtok(NULL,"="));
	     strcpy(after,before); 
	   //  printf("<h2>%s</h2>",after); 
	     time_t now=time(NULL);
	int dmod=0;
	char jour[50];
	char mois[50];

	char nbjr[10];
	char heure[100];
	char ans[20];
	int jourmark=atoi(after);
	char*string_now=ctime(&now);
	sscanf(string_now,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ]",jour,mois,nbjr,heure,ans);
	dmod=atoi(nbjr);
	char**cal=malloc((sizeof(char*)*13));
	for(int i=0;i<13;i++){
		cal[i]=(char*)malloc(100);}
	
		strcpy(cal[1],"January");
		strcpy(cal[2],"February");strcpy(cal[12],"Desember");
		strcpy(cal[3],"March");strcpy(cal[11],"Novamber");
		strcpy(cal[4],"April");strcpy(cal[10],"October");
		strcpy(cal[5],"May");strcpy(cal[9],"September");
		strcpy(cal[6],"June");strcpy(cal[7],"July");strcpy(cal[8],"August");
		int nbMois[12];
		int journew=0;
		int j=1;
		//int*jourmois=(int*)malloc(sizeof(int)*j);
		printf("<A  style=\"color:violet; size:20%%; text-decoration:none;\"href=\"http://www.lahoussa.com/dat.html\">parametrer la date </A>");
		int m=nombremois(mois,cal);
		
		for(int i=1;i<13;i++){
			
		    nbMois[i]=i;
		    
		}printf("<div style=\"font-family:arial;color:teal; size:25;\">Hello ,we are on %sday %d %s %s</div>",jour,dmod,mois,ans);
		printf("<div  style=\"background-color:pink; width:40%% ;height:70%%;border:outset turquoise;border-radius:20%%;padding-left:2%%;background: linear-gradient(to right,black,lightblue);\">");
		printf("<div style=\"background-color:darkkhaki;width:40%% ;background: linear-gradient(to right,violet,rgb(220, 223, 245),bisque,turquoise);height:20%%;border:solid coral;border-radius:10%%;text-align:center;padding-left:2%%;\"><font color=black size=20 >%s</font></div>",cal[m]);
		for(int i=1;i<13;i++){
	        if(nbMois[i]==m){
			   if((nbMois[i]%2==1 && nbMois[i]<=7 && nbMois[i]!=2) || (nbMois[i]%2==0 && nbMois[i]>7)){
				 journew=31;
				   while(j<=journew){
					   if(j%7==0){
						   printf("<BR>");
					   }
					   
					   if(jourmark==j){
						printf("<font color=red size=12> %d </font>",j);
						
                        // printf("</div>");
					   }
					   else if(dmod==j){
							printf("<font color=blue size=12>  %d </font>",j);
						//printf("</div>");   
					   }
					   else{
                           printf("<font color=white size=12> %d </font>",j);
					  //printf("</div>"); 
				        }
					  j++;
					  
					} 
			
				}
		        else if(nbMois[i]==2){
					    journew=29;
					 while(j<=journew){
						  if(jourmark==j){
						printf("<font color=pink size=12>%d</font>",j);   
					       }
					       else if(dmod==j){
						printf("<font color=bleu size=12>%d</font>",j);   
					   }
					       else{
					       printf("<font color=white size=12>%d</font>",j);
						    }
					        j++;
					    }
					
			     }
			    else if((nbMois[i]%2==0 && nbMois[i]<7) || (nbMois[i]%2==1 && nbMois[i]>7)){
					journew=30;
					while(j<=journew){
						    if(jourmark==j){
						     printf("<font color=pink size=12>%d</font>",j);   
					        }
					       else if(dmod==j){
						    printf("<font color=blue size=12>%d</font>",j);  
					       }
					       else{
					         printf("<font color=white size=12>%d</font>",j);
					      }
					     j++;
					 }
			     }

		       }
		   }printf("</div>");
		    printf("<h3 style=\"color:sienna;font-size:4vw;\">N'oubliez pas vous avez marquer le jour <center><div style=\"text-align:center;font-size:4vw;margin-top:2%%;background-color:firebrick; width:5vw;height:5vw;border-radius:50%%;color:skyblue;\">%d </div></center></h3>",jourmark);
	    
	        
       printf("</body>");
       printf("</html>");
       return 0;
   }
