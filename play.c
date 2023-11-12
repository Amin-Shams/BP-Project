#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void accountAdmin();
void login();
void addTeam();
void forgot();
void acountCoach();
void addPlayer();
void showTeams();
void showPlayers();
void mainDuty();
void changePassword();
void buyPlayer();
void sellPlayer();
void sort(int arr[100][2], int num);
void sumbitSquad(int );
void selectSquad(int );
void fixtures();
void upcomingOpponent(int );
void game(int ,int );
int leagueStanding();
void swap(int* , int* );
void sort1(int arr[4][5],int num);
char strt[200][40];
char strp[500][30];
int var[165];
char strg[50][20];
FILE* ftptr;
FILE* fpptr;
FILE* frptr;
FILE* fgptr;
int i=0;
int p=0;
int r=0;
int g=0;
int main(){
    int n;
    ftptr=fopen("team.txt","a+");
    fseek(ftptr,0,SEEK_SET);
    while(!feof(ftptr))
    {
        fscanf(ftptr,"%s",strt[i]);
        i++;
    }   
    i--;
    fclose(ftptr);
    fpptr=fopen("player.txt","a+");
    fseek(fpptr,0,SEEK_SET);
    while(!feof(fpptr))
    {
        fscanf(fpptr,"%s",strp[p]);
        p++;
    }   
    p--;
    fclose(fpptr);
    frptr=fopen("result.txt","a+");
    fseek(frptr,0,SEEK_SET);
    while(!feof(frptr))
    {
        fscanf(frptr,"%d",var+r);
        r++;
    }   
    r--;
    fclose(frptr);
    fgptr=fopen("game.txt","a+");
    fseek(fgptr,0,SEEK_SET);
    while(!feof(fgptr))
    {
        fscanf(fgptr,"%s",strg[g]);
        g++;
    }   
    g--;
    fclose(fgptr);
    if (g==0)
    {
        strcpy(strg[0],"0");
        g++;
        strcpy(strg[1],"0");
        g++;
    }
    while (1)
    {   
        printf("1-Login\n");
        printf("2-Forgot Password\n");
        printf("3-Exit\n");
        printf("Choose number 1 to 3: ");
        scanf("%d",&n);
        if (n==1)
        {
            login();
        }
        else if (n==2)
        {
            forgot();
        }
        else if (n==3)
        {
            FILE* ftptr;
            ftptr=fopen("team.txt","w");
            for (int z=0;z<i;z++)
            {
                fprintf(ftptr,"%s\n",strt[z]);                
            }
            fclose(ftptr);
            FILE* fpptr;
            fpptr=fopen("player.txt","w");
            for (int z=0;z<p;z++)
            {
                fprintf(fpptr,"%s\n",strp[z]);                
            }
            fclose(fpptr);
            FILE* frptr;
            frptr=fopen("result.txt","w");
            for (int z=0;z<r;z++)
            {
                fprintf(frptr,"%d\n",var[z]);                
            }
            fclose(frptr);
            FILE* fgptr;
            fgptr=fopen("game.txt","w");
            for (int z=0;z<g;z++)
            {
                fprintf(fgptr,"%s\n",strg[z]);                
            }
            fclose(fgptr);            
            break;
        }  
    }
}
void login(){
    char team[40];
    char password[30];
    int flag=0;
    printf("Enter team name: ");
    scanf("%s",team);
    printf("Enter your password: ");
    scanf("%s",password);
    if (strcmp(team,password)==0 && strcmp(team , "Admin")==0)
    {
        accountAdmin();
    }
    else
    {
        for (int j = 0; j <=i ; j=j+8)
        {
            if (strcmp(team,strt[j])==0 && strcmp(password,strt[j+2])==0)
            {    
                acountCoach(team);
                flag=1;
            }
        }
        if (flag==0)
            printf("Your team name or password was wrong.\n");
    }    
}
void accountAdmin(){
    int num;
    while (1)
    {
        printf("1- Add Team\n");
        printf("2- Add Player\n");
        printf("3- Show Teams\n");
        printf("4- Show Players\n");
        printf("5- ...\n");
        printf("6- Exit\n");
        printf("Choose number 1 to 6: ");
        scanf("%d",&num);
        if (num==1)
            addTeam();
        else if (num==2)
            addPlayer();
        else if (num==3)
            showTeams();
        else if (num==4)
            showPlayers();
        else if (num==5)
            mainDuty();        
        else if (num==6)
        {
            return;
        }
    }                       
}
void addTeam(){
    printf("Team name: ");
    scanf("%s",strt[i]);    
    for (int f =0 ; f <i ; f+=8 )
    {
        if (strcmp(strt[f],strt[i])==0)
        {
            printf("This name has already been mentioned, so enter another team name.\n");
            printf("Team name: ");
            scanf("%s",strt[i]);
        }
    }
    printf("Coach email: ");
    i++;
    scanf("%s",strt[i]);
    strcpy(strt[i+1],strt[i]);
    i++;
    printf("ID: ");
    i++;
    scanf("%s",strt[i]);
    i++;
    strcpy(strt[i],"0");
    i++;
    strcpy(strt[i],"100");
    i++;
    strcpy(strt[i],"0");
    i++;
    strcpy(strt[i],"0");
    i++;
    return;
}
void addPlayer(){
    strcpy(strp[p],"Free-Agent");
    printf("ID: ");
    p++;
    scanf("%s",strp[p]);
    printf("Name: ");
    p++;
    scanf("%s",strp[p]);
    printf("Attacking power: ");
    p++;
    scanf("%s",strp[p]);
    printf("Defencing power: ");
    p++;
    scanf("%s",strp[p]);
    printf("Value: ");
    p++;
    scanf("%s",strp[p]);
    p++;
    return;
}
void showTeams(){
    char name[20];
    for (int k = 0; k <i ; k+=8)
    {
        printf("Team name: %s\nnumber of cups: %s\n",strt[k],strt[k+7]);
        printf("**********\n");
    }
    printf("Enter team name that you want to see its players: ");
    scanf("%s",name);
    for (int z = 0; z < p; z+=6)
    {
      if (strcmp(strp[z],name)==0)
      {
        printf("ID: %s\n",strp[z+1]);
        printf("Player's name: %s\n",strp[z+2]);
        printf("Attacking power: %s\n",strp[z+3]);
        printf("Defencing power: %s\n",strp[z+4]);
        printf("Value: %s\n",strp[z+5]);
        printf("\n");
      } 
    } 
}
void showPlayers(){
    for (int j = 0 ;  j < p  ; j+=6)
    {
        printf("Team name: %s\n",strp[j]);
        printf("ID: %s\n",strp[j+1]);
        printf("Player's name: %s\n",strp[j+2]);
        printf("Attacking power: %s\n",strp[j+3]);
        printf("Defencing power: %s\n",strp[j+4]);
        printf("Value: %s\n",strp[j+5]);
        printf("\n");
    }
    return; 
}
void mainDuty(){
    int m=0,n;
    int choice[20];
    for (int f = 6; f < i; f+=8)
    {
        if (strcmp(strt[f],"1")==0)
        {    
            choice[m]=f-6;
            m++;
        }   
    }

    if (m>3 && strcmp(strg[0],"0")==0)
    {
        int c1 ,c2;
        srand(time(NULL));
        printf("1-Start League: \n");
        for (int ct=0;ct<20;ct++)
        {
            c1=rand()%m;
            c2=rand()%m;
            swap(choice+c1 ,choice+c2);           
        }
        
        for (int f=0;f<i;f+=8)
        {
            if (f==choice[0] || f==choice[1] || f==choice[2] || f==choice[3])
            {
                continue;
            }
            else
            {
                strcpy(strt[f+6],"0");
            }
        }
    }
    else if(m<4)
    {
        printf("Number of teams that participated in league is lower than 4.\n");
        return;
    }    
    if (strcmp(strg[1],"0")==0) 
        printf("2-Close Transfer Window\n");
    else
        printf("2-Open Transfer Window\n");
    if (strcmp(strg[0],"1")==0 && strcmp(strg[49],"9-9")==0)
    {    
        printf("3-Start Week i-th Games\n");
    }
    if (strcmp(strg[49],"9-9")!=0 && g>10)    
    printf("4-End Season and Announce The Champion\n");
    printf("Choose number: ");
    scanf("%d",&n);
    if (n==1)
    {
        if (g==0)
        {
            strcpy(strg[0],"0");
            g++;
            strcpy(strg[1],"0");
            g++;
        }
        strcpy(strg[0],"1");
        strcpy(strg[1],"1");
        int c1,c2;
        printf("Selected teams:\n\n");
        for (int y=1;y<5;y++)
        {
            printf("%d- %s\n",y,strt[choice[y-1]]);
        }
        printf("\n");
        srand(time(NULL));
        for (int ct=0;ct<10;ct++)
        {
            c1=rand()%4;
            c2=rand()%4;
            swap(choice+c1 ,choice+c2);           
        }   
        for(int t=0 ; t<4 ;t++)
        {      
            strcpy(strg[g],strt[choice[t]]);
            g++;
            strcpy(strg[g],strt[choice[t]+3]);
            g++;
            strcpy(strg[g],"0");
            g++;                       
        }
        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        
        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        g=2;
        srand(time(NULL));
        for (int ct=0;ct<10;ct++)
        {
            c1=rand()%4;
            c2=rand()%4;
            swap(choice+c1 ,choice+c2);    
        }
        for(int t=0 ; t<4 ;t++)
        {      
            strcpy(strg[g],strt[choice[t]]);
            g++;
            strcpy(strg[g],strt[choice[t]+3]);
            g++;
            strcpy(strg[g],"0");
            g++;                       
        }
        g=32;      
        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        
        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],"9-9");
        g++;

        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        
        strcpy(strg[g],strg[5]);
        g++;
        strcpy(strg[g],strg[8]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        
        strcpy(strg[g],strg[2]);
        g++;
        strcpy(strg[g],strg[11]);
        g++;
        strcpy(strg[g],"9-9");
        g++;
        for (; r < 164; r++)
        {
            var[r]=0;
        }
        var[0]=atoi(strg[3]);
        var[41]=atoi(strg[6]);
        var[82]=atoi(strg[9]);
        var[123]=atoi(strg[12]);
        for (int t=0,t1=9; t<p;t+=6)
        {
            if(strcmp(strg[2],strp[t])==0)
            {
                var[t1]=atoi(strp[t+1]);
                t1++;
                var[t1]=atoi(strp[t+3]);
                t1++;
                var[t1]=atoi(strp[t+4]);
                t1++;
                var[t1]=0;
                t1++;
            }
        }
        for (int t=0,t1=50; t<p;t+=6)
        {
            if(strcmp(strg[5],strp[t])==0)
            {
                var[t1]=atoi(strp[t+1]);
                t1++;
                var[t1]=atoi(strp[t+3]);
                t1++;
                var[t1]=atoi(strp[t+4]);
                t1++;
                var[t1]=0;
                t1++;
            }
        }
        for (int t=0,t1=91; t<p;t+=6)
        {
            if(strcmp(strg[8],strp[t])==0)
            {
                var[t1]=atoi(strp[t+1]);
                t1++;
                var[t1]=atoi(strp[t+3]);
                t1++;
                var[t1]=atoi(strp[t+4]);
                t1++;
                var[t1]=0;
                t1++;
            }
        }
        for (int t=0,t1=132; t<p;t+=6)
        {
            if(strcmp(strg[11],strp[t])==0)
            {
                var[t1]=atoi(strp[t+1]);
                t1++;
                var[t1]=atoi(strp[t+3]);
                t1++;
                var[t1]=atoi(strp[t+4]);
                t1++;
                var[t1]=0;
                t1++;
            }
        }   
    }
    else if (n==2)
    {
        if (strcmp(strg[1],"0")==0)
        {    
            strcpy(strg[1],"1");
            printf("You closed Transfer Window.\n");
        }
        else
        {    
            strcpy(strg[1],"0");
            printf("You opened Transfer Window.\n");
        }        
    }
    else if (n==3)
    {
        if (strcmp(strg[4],"1")==0 && strcmp(strg[7],"1")==0 && strcmp(strg[10],"1")==0 && strcmp(strg[13],"1")==0)
        {
            int flag=0;
            for (int q=16;;q+=3)
            {
                if (strcmp(strg[q],"9-9")==0)
                {
                    game(q-2,q-1);
                    flag++;
                    if (flag == 2)
                    {
                        strcpy(strg[4],"0");
                        strcpy(strg[7],"0");
                        strcpy(strg[10],"0");
                        strcpy(strg[13],"0");
                        break;
                    }
                }
            }
            if (strcmp(strg[31],"9-9")!=0 && strcmp(strg[34],"9-9")==0 )
            {
                printf("*****************\nThe first half of the season is over.\n*****************\n");
                for (int e=9;e<39;e+=4)
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (var[e]==atoi(strp[k]))
                        {
                            var[e+1]=atoi(strp[k+2]);
                            var[e+2]=atoi(strp[k+3]);
                            break;
                        }
                    }
                }
                for (int e=50;e<80;e+=4)
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (var[e]==atoi(strp[k]))
                        {
                            var[e+1]=atoi(strp[k+2]);
                            var[e+2]=atoi(strp[k+3]);
                            break;
                        }
                    }
                }
                for (int e=91;e<121;e+=4)
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (var[e]==atoi(strp[k]))
                        {
                            var[e+1]=atoi(strp[k+2]);
                            var[e+2]=atoi(strp[k+3]);
                            break;
                        }
                    }
                }
                for (int e=132;e<162;e+=4)
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (var[e]==atoi(strp[k]))
                        {
                            var[e+1]=atoi(strp[k+2]);
                            var[e+2]=atoi(strp[k+3]);
                            break;
                        }
                    }
                } 
            }
        }
        else
        {
            printf("\nThere are teams that don't select squad.\nSo we can't start game.\n\n");
            return;
        }   
    }
    else if (n==4)
    {
        int h;
        h=leagueStanding();
        for (int u=3 ;u<i ;u+=8)
        {
            if (h==atoi(strt[u]))
            {
                sprintf(strt[u+4], "%d", atoi(strt[u+4])+1);
                break;
            }
        }
        r=0;
        g=0;
        for (int l=6;l<i;l+=8)
        {
            strcpy(strt[l],"0");
        }
        strcpy(strg[0],"0");
    }
}
void game(int q1 , int q2){
    int w1=2,w2=2;
    int u=q2+1;
    for (;w1<13;w1+=3)
    {
        if (strcmp(strg[q1],strg[w1])==0)
            {
                q1=atoi(strg[w1+1]);
                break;
            }
    }
    for (;w2<13;w2+=3)
    {
        if (strcmp(strg[q2],strg[w2])==0)
            {
                q2=atoi(strg[w2+1]);
                break;
            }
    }
    int suma1=0,sumd1=0;
    for (int e=0;e<125;e+=41)
    {
        if (q1==var[e])
        {
            var[e+1]+=1;
            e+=12;
            for (int a=0;a<8;e+=4)
            {
                if (var[e]==1)
                {
                    suma1+=var[e-2];
                    var[e-2]=var[e-2]-5;
                    sumd1+=var[e-1];
                    var[e-1]=var[e-1]-5;
                    var[e]=0;
                    a++;
                }
                else
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (atoi(strp[k])==var[e-3])
                        {
                            if (var[e-2]<atoi(strp[k+2]))
                            {
                                var[e-2]+=5;
                                var[e-1]+=5;
                                break;
                            }
                        }
                        
                    }
                    a++;
                    continue;
                }
            }
            
        }
    }
    int suma2=0,sumd2=0;
    for (int e=0;e<125;e+=41)
    {
        if (q2==var[e])
        {
            var[e+1]+=1;
            e+=12;
            for (int a=0;a<8;e+=4)
            {
                if (var[e]==1)
                {
                    suma2+=var[e-2];
                    var[e-2]=var[e-2]-5;
                    sumd2+=var[e-1];
                    var[e-1]=var[e-1]-5;
                    var[e]=0;
                    a++;
                }
                else
                {
                    for (int k=1;k<p;k+=6)
                    {
                        if (atoi(strp[k])==var[e-3])
                        {
                            if (var[e-2]<atoi(strp[k+2]))
                            {
                                var[e-2]+=5;
                                var[e-1]+=5;
                                break;
                            }
                        }
                        
                    }
                    a++;
                    continue;
                }
            }
        }
    }
    char gf1[5], gf2[5];
    int  GF1=(suma1-sumd2)/100;
    int  GF2=(suma2-sumd1)/100;
    if (GF2<0)
    {
        GF2=0;
    }
    if (GF1<0)
    {
        GF1=0;
    }
    sprintf(gf1, "%d", GF1);
    strcat(gf1,"-");
    sprintf(gf2, "%d", GF2);
    strcat(gf1,gf2);
    strcpy(strg[u],gf1);
    if (GF1>GF2)
    {
        for (int e1,e2,e=0;e<125;e+=41)
        {
            if (q1==var[e])
            {
                e1=e;
                e1+=2;
                var[e1]+=1;
                e1+=3;
                var[e1]+=GF1;
                e1++;
                var[e1]+=GF2;
                e1++;
                var[e1]+=GF1-GF2;
                e1++;
                var[e1]+=3;
            }
            if (q2==var[e])
            {
                e2=e;
                e2+=4;
                var[e2]+=1;
                e2++;
                var[e2]+=GF2;
                e2++;
                var[e2]+=GF1;
                e2++;
                var[e2]+=GF2-GF1; 
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q1)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+5);
                break;
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q2)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+1);
                break;
            }
        }
    }
    else if (GF2>GF1)
    {
        for (int e1,e2,e=0;e<125;e+=41)
        {
            if (q2==var[e])
            {
                e2=e;
                e2+=2;
                var[e2]+=1;
                e2+=3;
                var[e2]+=GF2;
                e2++;
                var[e2]+=GF1;
                e2++;
                var[e2]+=GF2-GF1;
                e2++;
                var[e2]+=3;
            }
            if (q1==var[e])
            {
                e1=e;
                e1+=4;
                var[e1]+=1;
                e1++;
                var[e1]+=GF1;
                e1++;
                var[e1]+=GF2;
                e1++;
                var[e1]+=GF1-GF2; 
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q2)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+5);
                break;
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q1)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+1);
                break;
            }
        }
    }
    else
    {
        for (int e1,e2,e=0;e<125;e+=41)
        {
            if (q2==var[e])
            {
                e2=e;
                e2+=3;
                var[e2]+=1;
                e2+=2;
                var[e2]+=GF2;
                e2++;
                var[e2]+=GF1;
                e2++;
                var[e2]+=GF2-GF1;
                e2++;
                var[e2]+=1;
            }
            if (q1==var[e])
            {
                e1=e;
                e1+=3;
                var[e1]+=1;
                e1+=2;
                var[e1]+=GF1;
                e1++;
                var[e1]+=GF2;
                e1++;
                var[e1]+=GF1-GF2;
                e1++;
                var[e1]+=1;
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q2)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+3);
                break;
            }
        }
        for (int k=3;k<i;k+=8)
        {
            if (atoi(strt[k])==q1)
            {
                sprintf(strt[k+2], "%d",atoi(strt[k+2])+3);
                break;
            }
        }
    }
} 
void forgot(){
    char name[30] ,email[50];
    printf("Enter your team name: ");
    scanf("%s",name);    
    printf("Enter your email: ");
    scanf("%s",email);
    for (int j = 0; j <=i ; j=j+8)
    {
        if (strcmp(name,strt[j])==0 && strcmp(email,strt[j+1])==0)
            {
                char new[25];
                printf("Enter new password: ");
                scanf("%s",new);
                strcpy(strt[j+2],new);
                printf("Your password changed.\n");
                acountCoach(name);
                break;
            }
    }
}  
void acountCoach(char team[20]){
    int f =0;
    for ( ; f <i ; f+=8 )
    {
        if (strcmp(strt[f],team)==0)
        {
            break;
        }
    }
    while (1)
    {
        int n=0, flag=0;
        printf("   *******\nCurrent budget: %s\n   *******\n",strt[f+5]);
        if(strcmp(strg[0],"0")==0 || strcmp(strg[1],"0")==0)
        {    
            printf("1-Buy a Player: \n");
            printf("2-Sell a Player: \n");
            flag=1;
        }    
        if(strcmp(strt[f+6],"0")==0)
            printf("3-Sumbit Squad: \n");
        else
            printf("3-Select Squad: \n");
        printf("4-League Standing: \n");
        printf("5-Fixture: \n");
        printf("6-Upcoming Opponent: \n");
        printf("7-Change Password: \n");
        printf("8-Exit \n");
        if (flag==1)
            printf("Choose number 1 to 8: ");
        else
            printf("Choose number 3 to 8: ");
        scanf("%d",&n);
        if (n==1)
        {
            if(strcmp(strg[0],"0")==0 || strcmp(strg[1],"0")==0)
                buyPlayer(team);
        }
        else if (n==2)
        {
            if(strcmp(strg[0],"0")==0 || strcmp(strg[1],"0")==0)
                sellPlayer(team);
        }
        else if (n==3)
        {
            if(strcmp(strt[f+6],"0")==0)
                sumbitSquad(f);
            else if(g>10)
                selectSquad(f);     
        }
        else if (n==4)
        {
            leagueStanding();
        }
        else if (n==5)
        {
            fixtures();
        }
        else if (n==6)
        {
            upcomingOpponent(f);
        }
        else if (n==7)
        {
            changePassword();
        }
        else if (n==8)
        {
            return;
        }
    }
}
void buyPlayer(char team[20]){
    int arr[100][2],j=0,budget,nop;
    char ID[10];
    int f =0;
    for ( ; f <i ; f+=8 )
    {
        if (strcmp(strt[f],team)==0)
        {
            break;
        }
    }
    nop=atoi(strt[f+4]);
    budget=atoi(strt[f+5]);
    for (int z =0 ; z <p ; z+=6 )
    {
        if (strcmp(strp[z],"Free-Agent")==0)
        {
            arr[j][0]=atoi(strp[z+5]);
            arr[j][1]=atoi(strp[z+1]);
            j++;
        }
    }
    j--;
    sort(arr,j);
    for (int z = j; z >=0; z--)
    {
        for (int k=5 ; k<p; k+=6 )
        {
            if (arr[z][0]==atoi(strp[k]) && arr[z][1]==atoi(strp[k-4]))
            {
                printf("Team name: %s\n",strp[k-5]);
                printf("ID: %s\n",strp[k-4]);
                printf("Player's name: %s\n",strp[k-3]);
                printf("Attacking power: %s\n",strp[k-2]);
                printf("Defencing power: %s\n",strp[k-1]);
                printf("Value: %s\n",strp[k]);
                printf("\n");
                break;
            }
        }
    }
    printf("Please enter palyer's ID who you want to buy: ");
    scanf("%s",ID);//sprintf(text, "%d", number);
    for (int k = 1; k < p; k+=6)
    {
        if (strcmp(strp[k],ID)==0)
        {
            if (budget-atoi(strp[k+4])>= 0 && nop<8)
            {
                strcpy(strp[k-1],team);
                nop++;
                budget=budget-atoi(strp[k+4]);
                sprintf(strt[f+4], "%d", nop);
                sprintf(strt[f+5], "%d", budget);
                int u=0;
                for (;u<125;u+=41)
                {
                    if (atoi(strt[f+3])==var[u])
                    {
                        u+=9;
                        break;
                    }
                }
                for (int t=0;t<8;t++,u+=4)
                {
                    if (var[u]==-1)
                    {
                        var[u]=atoi(strp[k]);
                        var[u+1]=atoi(strp[k+2]);
                        var[u+2]=atoi(strp[k+3]);
                        var[u+3]=0;
                        break;
                    }
                }
                printf("You bought %s\n",strp[k+1]);
                break;
            }
            else
                {
                    printf("You can't buy\n");
                    break;
                }
        }
    }
}
void sellPlayer(char team[20]){
    int nop,budget;
    char ID[10];
    int f =0;
    for ( ; f <p ; f+=8 )
    {
        if (strcmp(strt[f],team)==0)
        {
            break;
        }
    }
    nop=atoi(strt[f+4]);
    budget=atoi(strt[f+5]);
    for (int z = 0; z < p ; z+=6)
    {
        if (strcmp(strp[z],team)==0)
        {
                printf("ID: %s\n",strp[z+1]);
                printf("Player's name: %s\n",strp[z+2]);
                printf("Attacking power: %s\n",strp[z+3]);
                printf("Defencing power: %s\n",strp[z+4]);
                printf("Value: %s\n",strp[z+5]);
                printf("\n");
        }
    }
    printf("Please enter palyer's ID who you want to sell: ");
    scanf("%s",ID);
    for (int k = 1; k < p; k+=6)
    {
        if (strcmp(strp[k],ID)==0)
        {
            budget=budget+atoi(strp[k+4]);
            strcpy(strp[k-1],"Free-Agent");
            nop--;
            sprintf(strt[f+4], "%d", nop);
            sprintf(strt[f+5], "%d", budget);
            int u=0;
            for (;u<125;u+=41)
            {
                if (atoi(strt[f+3])==var[u])
                {
                    u+=9;
                    break;
                }
            }
            for (int t=0;t<8;t++,u+=4)
            {
                if (var[u]==atoi(ID))
                {
                    var[u]=-1;
                    break;
                }
            }
            printf("You sold %s\n",strp[k+1]);
            break;
        }
    }
}
void changePassword(){
    char email[30], password[30];
    printf("Enter coach email: ");
    scanf("%s",email);
    printf("Enter password: ");
    scanf("%s",password);
    for (int j = 1; j <=i ; j=j+8)
    {
        if (strcmp(email,strt[j])==0 && strcmp(password,strt[j+1])==0)
        {    
            char new[25];
            printf("Enter new password: ");
            scanf("%s",new);
            strcpy(strt[j+1],new);
            printf("Your password changed.\n");
            return;
        }
    }
    printf("You entered email or password wrongly\nPlease try an other time.\n");
    return;
}
void sort(int arr[100][2],int num){
    int a ,b;
    for (int k = 0; k < num; ++k) 
    {
        for (int j = k + 1; j <= num; ++j)
        {
            if ( arr[k][0] > arr[j][0] ) 
            {
                a =  arr[k][0];
                b =  arr[k][1];
                arr[k][0]  = arr[j][0];
                arr[k][1]  = arr[j][1];
                arr[j][0] = a;
                arr[j][1] = b;
            }
        }
    }
}
void sumbitSquad(int f){
    if (strcmp(strg[0],"1")==0)
    {
        printf("\nThe league is running.\nYou can't participate in league.\n\n");
        return;
    }
    
    if (strcmp(strt[f+4],"8")==0)
    {    
        strcpy(strt[f+6],"1");
        printf("You participated in league.\n");
    }
    else
        printf("You have less than eight players so you can't participate in league.\n");   
}
void selectSquad(int f){
    for (int e=2 ;e<13 ;e+=3)
    {
        if (strcmp(strt[f],strg[e])==0)
        {
            if (strcmp(strg[e+2],"1")==0)
            {
                printf("\nYou selected before.\n\n");
                return;
            }
            
        }
        
    }
    
    int ID;
    int y=0, flag=0;
    for (;y<r;y+=41)
    {
        if (atoi(strt[f+3])==var[y])
        {
            flag=1;
            break;
        }   
    }
    if (flag==0)
    {
        printf("You didn't participate in league\n.");
        return;
    }
    for (int z = y+9; z < y+41; z+=4)
    {
        printf("ID: %d\n",var[z]);
        printf("Attacking power: %d\n",var[z+1]);
        printf("Defencing power: %d\n",var[z+2]);
        printf("\n");
    }
    for(int num=0;num<5;num++)
    {    
        printf("Enter player's ID that you want to play: ");
        scanf("%d",&ID);
        for (int t=y+9; t<y+41; t+=4)
        {
            if (ID==var[t])
            {
                var[t+3]=1;
                printf("Player with %d ID plays in future game.\n",ID);
            }
        }
    }
    for (int t=2;t<14;t+=3)
    {
        if (strcmp(strt[f],strg[t])==0)
        {
            strcpy(strg[t+2],"1");
        }
    }
}
void fixtures(){
    for (int t = 14,t1=1; t <50 ;t1++)
    {
        printf("games on week %d:\n",t1);
        printf("%s vs %s\n",strg[t],strg[t+1]);
        t+=2;
        if (strcmp(strg[t],"9-9")!=0)
        {
            printf("%s\n",strg[t]);
        }
        printf(" ********\n");
        t++;
        printf("%s vs %s\n",strg[t],strg[t+1]);
        t+=2;
        if (strcmp(strg[t],"9-9")!=0)
        {
            printf("%s\n",strg[t]);
        }
        printf("\n\n");
        t++;
    }
}
void upcomingOpponent(int f){
    int t=16;
    if(strcmp(strt[f+6],"0")==0)
    {
        printf("Your team isn't in league.\n");
        return;
    }
    for (;;t+=3)
    {
        if (strcmp(strg[t],"9-9")==0)
        {
            if (strcmp(strt[f],strg[t-2])==0)
            {
                t=t-1;
                break;
            }
            else if (strcmp(strt[f],strg[t-1])==0)
            {
                t=t-2;
                break;
            }
            else
            {
                continue;
            }
        }       
    }
    int y=2;
    for (;y<13;y+=3)
    {
        if (strcmp(strg[y],strg[t])==0)
        {
            y=atoi(strg[y+1]);
            break;
        }
    }
    for (int suma=0,sumd=0,e=0;e<125;e+=41)
    {
        if (y==var[e])
        {
            e+=9;
            for (int z=0 ; z <8;z++)
            {
                
                printf("ID: %d\n",var[e]);
                e++;
                printf("Attacking power: %d\n",var[e]);
                suma+=var[e];
                e++;
                printf("Defencing power: %d\n",var[e]);
                sumd+=var[e];
                e+=2;
                printf("\n");
            }
            printf("\nTotal Attacking power: %d\n",suma);
            printf("Total Defencing power: %d\n",sumd);
            break;
        }
    } 
}
int leagueStanding(){
    int arr[4][5];
    arr[0][0]=var[8];
    arr[0][1]=var[7];
    arr[0][2]=var[5];
    arr[0][3]=var[6];
    arr[0][4]=var[0];
    
    arr[1][0]=var[49];
    arr[1][1]=var[48];
    arr[1][2]=var[46];
    arr[1][3]=var[47];
    arr[1][4]=var[41];

    arr[2][0]=var[90];
    arr[2][1]=var[89];
    arr[2][2]=var[87];
    arr[2][3]=var[88];
    arr[2][4]=var[82];
    
    arr[3][0]=var[131];
    arr[3][1]=var[130];
    arr[3][2]=var[128];
    arr[3][3]=var[129];
    arr[3][4]=var[123];
    sort1(arr,4);
    for(int q=3;0<=q;q--)   
    {    
        char name[20];
        for (int a=3;a<i;a+=8)
        {
            if (arr[q][4]==atoi(strt[a]))
            {   
                strcpy(name,strt[a-3]);
                break;
            }
        }
        for (int k=0;k<150;k+=41)
        {
            if (arr[q][4]==var[k])
            {
                printf("Team Name: %s  Played: %d  Won: %d  Drawn: %d  Lost: %d  GF: %d  GA: %d  GD: %d  Points: %d\n"
                ,name,var[k+1],var[k+2],var[k+3],var[k+4],var[k+5],var[k+6],var[k+7],var[k+8]);
                break;
            }
            
        }
    }
    return arr[3][4];
}   
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort1(int arr[4][5],int num){
    for (int k = 0; k < num; ++k) 
    {
        for (int j = k + 1; j <= num; ++j)
        {
            if ( arr[k][0] > arr[j][0] ) 
            {
                for(int u1=0;u1<5;u1++)
                    swap(&arr[k][u1],&arr[j][u1]);
            }
            else if (arr[k][0] == arr[j][0])
            {
                if (arr[k][1] > arr[j][1] )
                {
                    for(int u1=0;u1<5;u1++)
                        swap(&arr[k][u1],&arr[j][u1]);
                }
                else if (arr[k][1] == arr[j][1])
                {
                    if (arr[k][2] > arr[j][2] )
                    {
                        for(int u1=0;u1<5;u1++)
                            swap(&arr[k][u1],&arr[j][u1]);
                    }
                    else if (arr[k][2] == arr[j][2] )
                    {
                        if ( arr[k][3] < arr[j][3] )
                        {
                            for(int u1=0;u1<5;u1++)
                                swap(&arr[k][u1],&arr[j][u1]);
                        }   
                    }   
                }   
            }  
        }
    }
}
