#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <time.h>
 
void dateAvenir(int m,int ans,int jour,int jp){
	jour+=jp;
	if((m%2==1 && m<=7 && m!=2) || (m%2==0 && m>7)){
	while(jour>=31){
		jour-=31;
		
		m++;
	
	}
	if(m>=12){
		m-=12;
		ans++;
	}
}
else if((m%2==0 && m<7) || (m%2==1 && m>7)){
	while(jour>=30){
		jour-=30;
		
		m++;
	
	}
	if(m>=12){
		m-=12;
		ans++;
	}
	
}
else if(m==2){
	 if(ans%4==0 && ans%100!=0){
		 while(jour>=29){
		jour-=29;
		
		m++;
	
	}
	if(m>=12){
		m-=12;
		ans++;
	}
		 
	 }
	 else{
		  while(jour>=28){
		jour-=28;
		
		m++;
	
	}
	if(m>=12){
		m-=12;
		ans++;
	}
	 }
 }
	
		printf("<div style=\"background-color:blueviolet;width:30vw;color:white; display:flex;justify-content:center;align-items:center;height:7vw;margin-left:38vw;font-size:4vw;border-radius:30vw; text-align:center;margin-top:8vw;\">%02d/%02d/%d</div>\n",jour,m,ans);
}

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
	char*val=getenv("QUERY_STRING");
	printf("Content-type: text/html\n\n");
	printf("<html lang=\"en\">");
	printf("<head>");
	printf(" <meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>testformulaire</title>");
    printf("</head>");
    printf("<body width=50vw>");
    time_t now=time(NULL);
	int dmod=0;
	char jour[50];
	char mois[50];
  int year=0;
	char nbjr[10];
	char heure[100];
	char ans[20];
    char*string_now=ctime(&now);
	sscanf(string_now,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ]",jour,mois,nbjr,heure,ans);
	dmod=atoi(nbjr);
	year=atoi(ans);
	char**cal=malloc((sizeof(char*)*13));
	for(int i=0;i<13;i++){
		cal[i]=(char*)malloc(100);}
	
		strcpy(cal[1],"January");
		strcpy(cal[2],"February");strcpy(cal[12],"Desember");
		strcpy(cal[3],"March");strcpy(cal[11],"Novamber");
		strcpy(cal[4],"April");strcpy(cal[10],"October");
		strcpy(cal[5],"May");strcpy(cal[9],"September");
		strcpy(cal[6],"June");strcpy(cal[7],"July");strcpy(cal[8],"August");
		//int nbMois[12];
    char opt[200];
    sscanf(val ,"choix=%s",opt);
    if(strstr(opt,"option1")!=NULL){
		int jp=120;
		printf("<center><h2 > <font color=\"darkred\" size=\"15\">Date de limite des Mineurs est</font></h2></center>");
		   int u=nombremois(mois,cal);
		dateAvenir(u,year,dmod,jp);
   // 
    }
    if(strstr(opt,"option2")!=NULL){
		int jp=45;
		printf("<center><h2 > <font color=\"darkred\" size=\"15\">Date de limite des Majeurs est</font></h2></center>");
		   int u=nombremois(mois,cal);
		dateAvenir(u,year,dmod,jp);
   // printf("<h1> %d  %d</h1>",d,year);
    }
    if(strstr(opt,"option3")!=NULL){
		int jp=50;
		printf("<center><h2 > <font color=\"darkred\" size=\"15\">Date de limite des adolescents est</font></h2></center>");
		   int u=nombremois(mois,cal);
		dateAvenir(u,year,dmod,jp);
   // printf("<h1> %d  %d</h1>",d,year);
    }
    if(strstr(opt,"option4")!=NULL){
		int jp=250;
		printf("<center><h2> <font color=\"darkred\" size=\"15\">Date de limite des OBS est</font></h2></center>");
		  int u=nombremois(mois,cal);
		dateAvenir(u,year,dmod,jp);
   // printf("<h1> %d  %d</h1>",d,year);
    }
    
    
    
   //int u=2; nombremois(mois,cal);
       printf("</body>");
   printf("</html>");  


	return 0;
}
	
