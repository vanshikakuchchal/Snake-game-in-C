/*
    TITLE :- SNAKE GAME CODED IN C LANGUAGE AND CONNECTED WITH AWS S3 BUCKET
    WITHOUT USING ANY FRONT END LANGUAGE
    THIS SNAKE GAME IS DESIGNED AND CODED BY:-

*/

#include<stdio.h> //Header file for standard input and output
#include<stdlib.h> //Header file for rand() function
#include<conio.h> //Header file for function getch()
#include<windows.h> //Header file for function system()
#define height 30 //Macro for Height of the boundary where snake will move
#define width 149 //Macro for Width of the boundary where snake will move
void food(); //This function will randomly generate the position of food within the boundaries
void snake(); //This function will change co-ordinates of snake or move snake when we press arrow keys
void drawsnake(); //This function will print snake
void gotoxy(int,int); //Gotoxy function to move the cursor on specific positions
void swapcoordinates(); /*This function swaps the co-ordinates of the snake so that when snake
                         will move its tail will follow head*/
void boundary(); //This function will print boundary
void welcome(); //This function is for printing welcome
void menu1(); //This function will print menu excluding resume option
void menu(); //This function will print menu including resume option
void newgame(); //This function is to start the game from beginning
void highscore(); //This function will print all the past scores
void help(); //This function will show  "how we can play this game".
void about(); //This function print content of about option which is in menu
void quit(); //Function is for stopping the game in between
void data_file(); //This function will write your highscores into a file with your name
void initial(); //This function is for intialising the initial values to all variables
int fx,fy,sx,sy,gx,gy,score,xc[200],yc[200],count,exitgame,life,game=0,res;
char ch;
void initial()
{
    ch=' '; //For input of arrow keys
    sx=15; //x co-ordinate of snake
    sy=75; //y co-ordinate of snake
    gx=26; //variable used to move cursor in x co-ordinate with the help of gotoxy function
    gy=7; //variable used to move cursor in y co-ordinate with the help of gotoxy function
    score=0; //variable to store score
    count=1; //variable decide menu1 function will call or menu function
    exitgame=0; //variable decide when game should be over
    life=3; //variable for total number of chances given in a program
    res=0; //variable used to decide to generate new position of food
}
void welcome()
{

    system("color CF"); //Function to change console color C for red background F for white text
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@        @@  @@@@@@@@  @@        @@@@@@@@  @@@@@@@@  @@      @@  @@@@@@@@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@        @@  @@        @@        @@        @@    @@  @@@@  @@@@  @@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@        @@  @@        @@        @@        @@    @@  @@  @@  @@  @@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@   @@   @@  @@@@@@    @@        @@        @@    @@  @@      @@  @@@@@@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@ @@  @@ @@  @@        @@        @@        @@    @@  @@      @@  @@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@@@    @@@@  @@        @@        @@        @@    @@  @@      @@  @@\n");
    printf("\t\t\t\t\t\t\t\t\t");
    printf("@@        @@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@      @@  @@@@@@@@\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("PRESS ANY KEY TO CONTINUE.....");
    getch();
    system("cls"); //It will clear screen
}
void menu1()
{
    system("color 80"); //Function to change console color 8 for gray background 0 for black text
    int i=18,option=0;
    char ch;
    while(1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**NEW GAME**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**HIGH SCORE**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**HELP**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**ABOUT**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**QUIT**");
        gotoxy(101,i);
        printf("## ");
        option=getch();
        if(option==13)
        break;
        ch=getch();
        switch(ch)
       {
           case 'H' : i=i-2;
                      break;
           case 'P' : i=i+2;
                      break;
       }
       if(i<18)
        i=26;
       if(i>26)
        i=18;
     system("cls");
    }
    system("cls");
    if(i==18)
    {
        initial();
        newgame();
    }
    else if(i==20)
        highscore();
    else if(i==22)
        help();
    else if(i==24)
        about();
    else
        quit();
}
void menu()
{
    system("color 80");
    int i=16,option=0;
    game=1;
    char ch;
    while(1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**RESUME**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**NEW GAME**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**HIGH SCORE**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**HELP**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**ABOUT**");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t**QUIT**");
        gotoxy(101,i);
        printf("## ");
        option=getch();
        if(option==13)
        break;
        ch=getch();
        switch(ch)
       {
           case 'H' : i=i-2;
                      break;
           case 'P' : i=i+2;
                      break;
       }
       if(i<16)
        i=26;
       if(i>26)
        i=16;
     system("cls");
    }
    system("cls");
    if(i==18)
    {
        initial();
        newgame();
    }
    else if(i==16)
    {
     res=1;
     newgame();
    }
    else if(i==20)
        highscore();
    else if(i==22)
        help();
    else if(i==24)
        about();
    else
        quit();
}
void newgame()
{
    fflush(stdin);
    fflush(stdout);
    int i,j,k,x=0;
    char c;
    boundary();
    if(res==0)
      {
          food();
      }
    gotoxy(32,5);
    printf("%d",score);
    gotoxy(53,5);
    printf("%d",life);
    while(life!=0)
    {
        gotoxy(gx,gy);
        drawsnake();
        if(count%7==0)
        {
            gotoxy(96,36);
            printf("**BONUS**");
        }
        else
        {
           gotoxy(96,36);
            printf("          ");
        }
        if(kbhit())
        {
            x=getch();
             if(x==27)
                {
                   system("cls");
                   menu();
                }
                c=getch();
            if(ch=='H'&&c=='P')
                ch='H';
            else if(ch=='K'&&c=='M')
                ch='K';
            else if(ch=='P'&&c=='H')
                ch='P';
            else if(ch=='M'&&c=='K')
                ch='M';
            else
                ch=c;
        }
        if(sx==-1||sx==28||sy==-1||sy==147||exitgame==1)
        {
            life--;
            sx=15;
            sy=75;
            count=1;
            exitgame=0;
            gotoxy(53,5);
            printf("%d",life);
        }
    }
    system("cls");
    system("color 80");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tGAME OVER");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tSCORE %d",score);
    getch();
    if(score>0)
      data_file();
}
void data_file()
{
    system("cls");
    char name[100];
    FILE *fptr;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tENTER YOUR NAME ");
    gets(name);
    fptr=fopen("highscore.txt","a");
    fprintf(fptr,"%s %d\n",name,score);
    fclose(fptr);
    system("aws s3 cp C:\\Users\\hp\\Desktop\\Project_SEM_3\\highscore.txt s3://snakesnake");
    getch();
    exit(1);
}
void highscore()
{
    FILE *fptr;
    char ch;
    printf("\n\n\n\n\n\n\n\n\t\t\tHIGH SCORES \n\n\n");
    fptr=fopen("highscore.txt", "r");
    ch=fgetc(fptr);
    while (ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fptr);
    }
    fclose(fptr);
    getch();
    system("cls");
    if(game==1)
        menu();
    else
        menu1();
}
void help()
{
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPRESS ARROW KEYS TO MOVE SNAKE");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tPRESS ESC KEY TO PAUSE THE GAME");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tIF SNAKE WILL TOUCH THE BOUNDARY OR OWN BODY THEN GAME WILL BE OVER");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tFOR EACH FOOD YOU WILL BE AWARDED +10 SCORE");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tAFTER EVERY 6 FOOD A BONUS WILL BE GIVEN");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tPRESS ANY KEY TO GO TO MENU");
    getch();
    system("cls");
    if(game==1)
        menu();
    else
        menu1();
}
void about()
{
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTHIS GAME IS CODED AND DESIGNED BY:");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tVANSHIKA KUCHCHAL SEC B");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tMAYANK AGGARWAL SEC E");
    getch();
    system("cls");
    if(game==1)
        menu();
    else
        menu1();
}
void quit()
{
    system("color CF");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tSCORE : %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",score);
    getch();
    exit(1);
}
void drawsnake()
{
    int i,j,flag=0;
        for(j=0;j<(width-2);j++)
        {
           if((fx==(gy-7))&&(j==fy))
            {
                if(count%7==0)
                    printf("B");
                 else
                    printf("@");
            }
            else if((sx==(gy-7))&&(j==sy))
            {
                if(ch=='H')
                    printf("^");
                else if(ch=='M')
                    printf(">");
                else if(ch=='K')
                    printf("<");
                else if(ch=='P')
                    printf("v");
                else
                    printf("V");
            }
            else
            {
                flag=0;
                for(i=0;i<count;i++)
                {
                    if(j==yc[i]&&xc[i]==(gy-7))
                        {
                            printf("o");
                            flag=1;
                        }
                }
                if(flag==0)
                printf(" ");
            }
        }
        gy++;
        gotoxy(gx,gy);
        if(gy==35)
            {
                gy=7;
                snake();
                if(fx==sx&&(fy==sy||fy==(sy-1)||fy==(sy+1)))
                {
                    if(count%7==0)
                        score=score+50;
                    else
                        score=score+10;
                    gotoxy(32,5);
                    printf("%d",score);
                    food();
                    count++;
                }
            }
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void snake()
{
    int i;
    switch(ch)
    {
        case 'H':
            {
                sx--;
            }
        break;
        case 'P':
            {
                sx++;
            }
        break;
        case 'K':
            {
                sy=sy-2;
            }
        break;
        case 'M':
            {
                sy=sy+2;
            }
    }
    for(i=1;i<count;i++)
    {
        if(sx==xc[i]&&sy==yc[i])
            exitgame=1;
    }
    swapcoordinates();
}
void food()
{
   label:
    fx=rand()%30;
    fy=rand()%150;
    if(fx<=0||fy<=0||fx>27||fy>147)
        goto label;
}
void boundary()
{
    system("color CF");
    if(res==0)
     {
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE...");
         getch();
     }
    system("cls");
    int i,j;
    printf("\n\n\n\n\n");
    printf("\t\t\t  SCORE:\t\tLIFE: \n");
    for(i=0;i<height;i++)
    {
        printf("\t\t\t");
        for(j=0;j<width;j++)
        {
            if(i==0)
                printf(":");
            else if(i==(height-1))
                printf(":");
            else if(j==0||j==(width-1))
                printf("||");
            else
               printf(" ");
        }
        if(i==0||i==(height-1))
            printf("::");
        printf("\n");
    }
}
void swapcoordinates()
{
    int i;
    int x1=xc[0],y1=yc[0],x2,y2;
    xc[0]=sx;
    yc[0]=sy;
    for(i=1;i<count;i++)
    {
        x2=xc[i];
        y2=yc[i];
        xc[i]=x1;
        yc[i]=y1;
        x1=x2;
        y1=y2;
    }
}
int main()
{
    fflush(stdin);
    fflush(stdout);
    welcome();
    menu1();
    getch();
    return 0;
}
