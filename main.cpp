#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define N 9
int i,j,a[N+1][N+1],message=0;
clock_t start;
void fload();
void display();
void battlecruiser();
void deluxe();
void fnew();
int main(void)
{
    int p1=12,p2=12,x,y,x1,y1,step=0,kills=0,t,f,move=1,attack=1,w,x2,y2,play,att=0;
    char flist[65];
    FILE *fp;
    deluxe();
    fload();
M:  system("cls");
    if(((x==0) && (y==0)) || (att>20))
        printf("\nCONTINUE - press 36\n");
    else
        fnew();
    printf("\nNEW GAME - press any number\n");
    if((x==0) && (y==0))
        printf("\nSAVE GAME - press 116\n");
    printf("\nLOAD GAME - press -1\n"
           "\nEXIT - press 0\n"
           "\nyour choice: ");
    scanf("%d",&play);
    if((x==0) && (y==0) && (play==116))
        goto SAVE;
    if(att>20)
    {
        getchar();
        printf("\nERROR in the input date\nprogram have to be closed\n"
               "the information with wich you will be able to continue\n"
               "this game will be saved in the text document\n");
        getchar();
SAVE:   fp=fopen("deluxe.txt","w");
        getchar();
        t=0;
        for(i=1;i<N;i++)
            for(j=1;j<N;j++)
            {
                if(a[i][j]==11)
                    flist[t]='1';
                if(a[i][j]==22)
                    flist[t]='2';
                if(a[i][j]==10)
                    flist[t]='3';
                if(a[i][j]==20)
                    flist[t]='4';
                if(a[i][j]==0)
                    flist[t]='0';
                t=t+1;
            }
        flist[65]='\0';
        fputs(flist,fp);
        fclose(fp);
        printf("\ngame saved, press ENTER to finish\n");
        getch();
        if(att>20)
            return 0;
        goto M;
    }
    printf("\n\n");
    if(play==-1)
    {
        if((fp=fopen("deluxe.txt","r"))==NULL)
        {
            printf("\nyou have not saved games\n");
            getch();
            goto M;
        }
        t=0;
        fgets(flist,66,fp);
        for(i=1;i<N;i++)
            for(j=1;j<N;j++)
            {
                if(flist[t]=='1')
                    a[i][j]=11;
                if(flist[t]=='2')
                    a[i][j]=22;
                if(flist[t]=='3')
                    a[i][j]=10;
                if(flist[t]=='4')
                    a[i][j]=20;
                if(flist[t]=='0')
                    a[i][j]=0;
                t=t+1;
            }
        step=flist[64]-'0';
        fclose(fp);
    }
    if((play!=36) && (play!=-1) && (x==0) && (y==0))
    {
        fnew();
        step=0;
    }
    if(play)
        display();
    while(play)
    {
        while(step==0)
        {
            flist[64]='0';
            w=0;
            move=1;
            attack=1;
            step=0;
            if(kills!=0)
            {
                x=x1;
                y=y1;
            }
            else
            {
                printf("\nplayer 1,you have %d checkers\nchoose your checker\n",p1);
                scanf("%d%d",&x,&y);
            }
            att++;
            if(att>20)
            {
                printf("\nerror\n");
                goto M;
                flist[64]='0';
            }
            if((x==0) && (y==0))
                goto M;
            if(a[x][y]==11)
            {
M11:            printf("\nmove your checker\n");
                scanf("%d%d",&x1,&y1);
                att++;
                if(att>20)
                {
                    printf("\nerror\n");
                    flist[64]='0';
                    goto M;
                }
                if((x-x1==1) && (abs(y1-y)==1) && (a[x1][y1]==0))
                {
                    for(i=1;i<N;i++)
                        for(j=1;j<N;j++)
                        {
                            if((a[i][j]==11) &&
                               ((((a[i+1][j+1]==22) || (a[i+1][j+1]==20)) && (a[i+2][j+2]==0)) ||
                               (((a[i+1][j-1]==22) || (a[i+1][j-1]==20)) && (a[i+2][j-2]==0)) ||
                               (((a[i-1][j+1]==22) || (a[i-1][j+1]==20)) && (a[i-2][j+2]==0)) ||
                               (((a[i-1][j-1]==22) || (a[i-1][j-1]==20)) && (a[i-2][j-2]==0))))
                               {
                                   a[i][j]=0;
                                   message=i+10*j;
                                   i=11;
                                   break;
                               }
                            else
                                if(a[i][j]==10)
                                    {
                                        for(t=i+1,f=j+1;t<N && f<N;t++,f++)
                                        {
                                            if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                                break;
                                            if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f+1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i+1,f=j-1;t<N && f>0;t++,f--)
                                        {
                                            if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                                break;
                                            if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f-1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i-1,f=j+1;t>0 && f<N;t--,f++)
                                        {
                                            if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                                break;
                                            if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f+1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i-1,f=j-1;t>0 && f>0;t--,f--)
                                        {
                                            if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                                break;
                                            if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f-1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                    }
                        }
                    a[x1][y1]=a[x][y];
                    a[x][y]=0;
                    if((a[x1][y1]==11) && (x1==1))
                        a[x1][y1]=10;
                    display();
                    step++;
                }
                else
                    if((abs(x-x1)==2) && (abs(y-y1)==2) && ((a[(x+x1)/2][(y+y1)/2]==22) || (a[(x+x1)/2][(y+y1)/2]==20)) && (a[x1][y1]==0))
                    {
                        a[x1][y1]=a[x][y];
                        a[x][y]=0;
                        a[(x+x1)/2][(y+y1)/2]=0;
                        step++;
                        if((a[x1][y1]==11) && (x1==1))
                            a[x1][y1]=10;
                        display();
                        if(kills==1) printf("\nDOUBLEKILL!\n");
                        if(kills==2) printf("\nMULTIKILL!\n");
                        if(kills==3) printf("\nMEGAKILL!\n");
                        if(kills==4) printf("\nULTRAKILL!\n");
                        if(((((a[x1+1][y1+1]==22) || (a[x1+1][y1+1]==20)) && (a[x1+2][y1+2]==0)) ||
                            (((a[x1+1][y1-1]==22) || (a[x1+1][y1-1]==20)) && (a[x1+2][y1-2]==0)) ||
                            (((a[x1-1][y1+1]==22) || (a[x1-1][y1+1]==20)) && (a[x1-2][y1+2]==0)) ||
                            (((a[x1-1][y1-1]==22) || (a[x1-1][y1-1]==20)) && (a[x1-2][y1-2]==0))) &&
                           (a[x1][y1]==11))
                            {
                                kills++;
                                step--;
                            }
                        if(a[x1][y1]==10)
                        {
                            for(t=x1+1,f=y1+1;t<N && f<N;t++,f++)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1+1,f=y1-1;t<N && f>0;t++,f--)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        display();
                        printf("\nuncorrect moving\n");
                        if(kills!=0)
                            goto M11;
                    }

            }
            else
                if(a[x][y]==10)
                {
M10:                printf("\nmove your damka\n");
                    scanf("%d%d",&x1,&y1);
                    att++;
                    if(att>20)
                    {
                        printf("\nerror\n");
                        flist[64]='0';
                        goto M;
                    }
                    if((abs(x1-x)==abs(y1-y)) && (a[x1][y1]==0))
                    {
                         if((x1>x) && (y1>y))
                            for(i=x+1,j=y+1;i<=x1 && j<=y1;i++,j++)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1>x) && (y1<y))
                            for(i=x+1,j=y-1;i<=x1 && j>=y1;i++,j--)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1<x) && (y1>y))
                            for(i=x-1,j=y+1;i>=x1 && j<=y1;i--,j++)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1<x) && (y1<y))
                            for(i=x-1,j=y-1;i>=x1 && j>=y1;i--,j--)
                                if(a[i][j]!=0)
                                    move=0;
                         if(move)
                         {
                            for(i=1;i<N;i++)
                                for(j=1;j<N;j++)
                                {
                                    if((a[i][j]==11) &&
                                       (((a[i+1][j+1]==22) && (a[i+2][j+2]==0)) ||
                                       ((a[i+1][j-1]==22) && (a[i+2][j-2]==0)) ||
                                       ((a[i-1][j+1]==22) && (a[i-2][j+2]==0)) ||
                                       ((a[i-1][j-1]==22) && (a[i-2][j-2]==0))))
                                       {
                                           a[i][j]=0;
                                           message=i+10*j;
                                           i=11;
                                           break;
                                       }
                                    else
                                        if(a[i][j]==10)
                                            {
                                                for(t=i+1,f=j+1;t<N && f<N;t++,f++)
                                                {
                                                    if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                                        break;
                                                    if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f+1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i+1,f=j-1;t<N && f>0;t++,f--)
                                                {
                                                    if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                                        break;
                                                    if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f-1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i-1,f=j+1;t>0 && f<N;t--,f++)
                                                {
                                                    if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                                        break;
                                                    if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f+1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i-1,f=j-1;t>0 && f>0;t--,f--)
                                                {
                                                    if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                                        break;
                                                    if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f-1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                            }
                                }
                                a[x1][y1]=a[x][y];
                                a[x][y]=0;
                                display();
                                step++;
                         }
                         if((x1>x) && (y1>y))
                            for(i=x+1,j=y+1;i<=x1 && j<=y1;i++,j++)
                            {
                                if((a[i][j]==22) || (a[i][j]==20))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==11) || (a[i][j]==10) || (w>1))
                                    attack=0;
                            }
                            for(i=x+1,j=y-1;i<=x1 && j>=y1;i++,j--)
                            {
                                if((a[i][j]==22) || (a[i][j]==20))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==11) || (a[i][j]==10) || (w>1))
                                    attack=0;
                            }
                            for(i=x-1,j=y+1;i>=x1 && j<=y1;i--,j++)
                            {
                                if((a[i][j]==22) || (a[i][j]==20))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==11) || (a[i][j]==10) || (w>1))
                                    attack=0;
                            }
                            for(i=x-1,j=y-1;i>=x1 && j>=y1;i--,j--)
                            {
                                if((a[i][j]==22) || (a[i][j]==20))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==11) || (a[i][j]==10) || (w>1))
                                    attack=0;
                            }
                        if(w==0)
                            attack=0;
                        if(attack)
                        {
                            a[x2][y2]=0;
                            a[x1][y1]=a[x][y];
                            a[x][y]=0;
                            display();
                            step++;
                            if(kills==1) printf("\nDOUBLEKILL!\n");
                            if(kills==2) printf("\nMULTIKILL!\n");
                            if(kills==3) printf("\nMEGAKILL!\n");
                            if(kills==4) printf("\nULTRAKILL!\n");
                            for(t=x1+1,f=y1+1;t<N && f<N;t++,f++)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1+1,f=y1-1;t<N && f>0;t++,f--)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t+1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1-1,f=y1+1;t>0 && f<N;t--,f++)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1-1,f=y1-1;t>0 && f>0;t--,f--)
                            {
                                if(((a[t][f]==11) || (a[t][f]==10)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==22) || (a[t][f]==20)) && (a[t-1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                        }
                        if((attack==0) && (move==0))
                        {
                            display();
                            printf("\nuncorrect moving\n");
                            w=0;
                            attack=1;
                            move=1;
                            if(kills!=0)
                                goto M10;
                        }
                    }
                    else
                    {
                        display();
                        printf("\nuncorrect moving\n");
                        if(kills!=0)
                            goto M10;
                    }
                }
                else
                {
                    display();
                    printf("\nthere is no your checkers on the place %d %d\n",x,y);
                }
        }
        p1=0;
        p2=0;
        step=0;
        kills=0;
        att=0;
        for(i=1;i<N;i++)
            for(j=1;j<N;j++)
                if((a[i][j]==11) || (a[i][j]==10))
                    p1++;
                else
                if((a[i][j]==22) || (a[i][j]==20))
                    p2++;
        if((p1==0) || (p2==0))
            break;
//_______________________________________________________________________________________
     while(step==0)
        {
            flist[64]='1';
            w=0;
            move=1;
            attack=1;
            step=0;
            message=0;
            if(kills!=0)
            {
                x=x1;
                y=y1;
            }
            else
            {
                printf("\nplayer 2,you have %d checkers\nchoose your checker\n",p2);
                scanf("%d%d",&x,&y);
            }
            att++;
            if(att>20)
            {
                printf("\nerror\n");
                flist[64]='1';
                goto M;
            }
            if((x==0) && (y==0))
            {
                step=-1;
                goto M;
            }
            if(a[x][y]==22)
            {
M22:            printf("\nmove your checker\n");
                scanf("%d%d",&x1,&y1);
                att++;
                if(att>20)
                {
                    printf("\nerror\n");
                    flist[64]='1';
                    goto M;
                }
                if((x1-x==1) && (abs(y1-y)==1) && (a[x1][y1]==0))
                {

                    for(i=1;i<N;i++)
                        for(j=1;j<N;j++)
                        {
                            if((a[i][j]==22) &&
                               ((((a[i+1][j+1]==11) || (a[i+1][j+1]==10)) && (a[i+2][j+2]==0)) ||
                               (((a[i+1][j-1]==11) || (a[i+1][j-1]==10)) && (a[i+2][j-2]==0)) ||
                               (((a[i-1][j+1]==11) || (a[i-1][j+1]==10)) && (a[i-2][j+2]==0)) ||
                               (((a[i-1][j-1]==11) || (a[i-1][j-1]==10)) && (a[i-2][j-2]==0))))
                               {
                                   a[i][j]=0;
                                   message=i+10*j;
                                   i=11;
                                   break;
                               }
                            else
                                if(a[i][j]==20)
                                    {
                                        for(t=i+1,f=j+1;t<N && f<N;t++,f++)
                                        {
                                            if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                                break;
                                            if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f+1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i+1,f=j-1;t<N && f>0;t++,f--)
                                        {
                                            if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                                break;
                                            if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f-1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i-1,f=j+1;t>0 && f<N;t--,f++)
                                        {
                                            if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                                break;
                                            if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f+1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                        for(t=i-1,f=j-1;t>0 && f>0;t--,f--)
                                        {
                                            if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                                break;
                                            if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f-1]==0))
                                            {
                                                a[i][j]=0;
                                                message=i+10*j;
                                                i=11;
                                                break;
                                            }
                                        }
                                    }
                        }
                    a[x1][y1]=a[x][y];
                    a[x][y]=0;
                    if((a[x1][y1]==22) && (x1==8))
                        a[x1][y1]=20;
                    display();
                    step++;
                }
                else
                    if((abs(x-x1)==2) && (abs(y-y1)==2) && ((a[(x+x1)/2][(y+y1)/2]==11) || (a[(x+x1)/2][(y+y1)/2]==10)) && (a[x1][y1]==0))
                    {
                        a[x1][y1]=a[x][y];
                        a[x][y]=0;
                        a[(x+x1)/2][(y+y1)/2]=0;
                        step++;
                        if((a[x1][y1]==22) && (x1==8))
                            a[x1][y1]=20;
                        display();
                        if(kills==1) printf("\nDOUBLEKILL!\n");
                        if(kills==2) printf("\nMULTIKILL!\n");
                        if(kills==3) printf("\nMEGAKILL!\n");
                        if(kills==4) printf("\nULTRAKILL!\n");
                        if(((((a[x1+1][y1+1]==11) || (a[x1+1][y1+1]==10)) && (a[x1+2][y1+2]==0)) ||
                            (((a[x1+1][y1-1]==11) || (a[x1+1][y1-1]==10)) && (a[x1+2][y1-2]==0)) ||
                            (((a[x1-1][y1+1]==11) || (a[x1-1][y1+1]==10)) && (a[x1-2][y1+2]==0)) ||
                            (((a[x1-1][y1-1]==11) || (a[x1-1][y1-1]==10)) && (a[x1-2][y1-2]==0))) &&
                           (a[x1][y1]==22))
                            {
                                kills++;
                                step--;
                            }
                        if(a[x1][y1]==20)
                        {
                            for(t=x1-1,f=y1+1;t>0 && f<N;t--,f++)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1-1,f=y1-1;t>0 && f>0;t--,f--)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        display();
                        printf("\nuncorrect moving\n");
                        if(kills!=0)
                            goto M22;
                    }

            }
            else
                if(a[x][y]==20)
                {
M20:                printf("\nmove your damka\n");
                    scanf("%d%d",&x1,&y1);
                    att++;
                    if(att>20)
                    {
                        printf("\nerror\n");
                        flist[64]='1';
                        goto M;
                    }
                    if((abs(x1-x)==abs(y1-y)) && (a[x1][y1]==0))
                    {
                         if((x1>x) && (y1>y))
                            for(i=x+1,j=y+1;i<=x1 && j<=y1;i++,j++)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1>x) && (y1<y))
                            for(i=x+1,j=y-1;i<=x1 && j>=y1;i++,j--)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1<x) && (y1>y))
                            for(i=x-1,j=y+1;i>=x1 && j<=y1;i--,j++)
                                if(a[i][j]!=0)
                                    move=0;
                         if((x1<x) && (y1<y))
                            for(i=x-1,j=y-1;i>=x1 && j>=y1;i--,j--)
                                if(a[i][j]!=0)
                                    move=0;
                         if(move)
                         {
                            for(i=1;i<N;i++)
                                for(j=1;j<N;j++)
                                {
                                    if((a[i][j]==22) &&
                                       (((a[i+1][j+1]==11) && (a[i+2][j+2]==0)) ||
                                       ((a[i+1][j-1]==11) && (a[i+2][j-2]==0)) ||
                                       ((a[i-1][j+1]==11) && (a[i-2][j+2]==0)) ||
                                       ((a[i-1][j-1]==11) && (a[i-2][j-2]==0))))
                                       {
                                           a[i][j]=0;
                                           message=i+10*j;
                                           i=11;
                                           break;
                                       }
                                    else
                                        if(a[i][j]==20)
                                            {
                                                for(t=i+1,f=j+1;t<N && f<N;t++,f++)
                                                {
                                                    if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                                        break;
                                                    if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f+1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i+1,f=j-1;t<N && f>0;t++,f--)
                                                {
                                                    if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                                        break;
                                                    if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f-1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i-1,f=j+1;t>0 && f<N;t--,f++)
                                                {
                                                    if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                                        break;
                                                    if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f+1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                                for(t=i-1,f=j-1;t>0 && f>0;t--,f--)
                                                {
                                                    if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                                        break;
                                                    if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f-1]==0))
                                                    {
                                                        a[i][j]=0;
                                                        message=i+10*j;
                                                        i=11;
                                                        break;
                                                    }
                                                }
                                            }
                                }
                                a[x1][y1]=a[x][y];
                                a[x][y]=0;
                                display();
                                step++;
                         }
                            for(i=x+1,j=y+1;i<=x1 && j<=y1;i++,j++)
                            {
                                if((a[i][j]==11) || (a[i][j]==10))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==22) || (a[i][j]==20) || (w>1))
                                    attack=0;
                            }
                            for(i=x+1,j=y-1;i<=x1 && j>=y1;i++,j--)
                            {
                                if((a[i][j]==11) || (a[i][j]==10))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==22) || (a[i][j]==20) || (w>1))
                                    attack=0;
                            }
                            for(i=x-1,j=y+1;i>=x1 && j<=y1;i--,j++)
                            {
                                if((a[i][j]==11) || (a[i][j]==10))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==22) || (a[i][j]==20) || (w>1))
                                    attack=0;
                            }
                            for(i=x-1,j=y-1;i>=x1 && j>=y1;i--,j--)
                            {
                                if((a[i][j]==11) || (a[i][j]==10))
                                {
                                    w++;
                                    x2=i;
                                    y2=j;
                                }
                                if((a[i][j]==22) || (a[i][j]==20) || (w>1))
                                    attack=0;
                            }
                        if(w==0)
                            attack=0;
                        if(attack)
                        {
                            a[x2][y2]=0;
                            a[x1][y1]=a[x][y];
                            a[x][y]=0;
                            display();
                            step++;
                            if(kills==1) printf("\nDOUBLEKILL!\n");
                            if(kills==2) printf("\nMULTIKILL!\n");
                            if(kills==3) printf("\nMEGAKILL!\n");
                            if(kills==4) printf("\nULTRAKILL!\n");
                            for(t=x1+1,f=y1+1;t<N && f<N;t++,f++)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1+1,f=y1-1;t<N && f>0;t++,f--)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t+1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t+1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1-1,f=y1+1;t>0 && f<N;t--,f++)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f+1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f+1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                            for(t=x1-1,f=y1-1;t>0 && f>0;t--,f--)
                            {
                                if(((a[t][f]==22) || (a[t][f]==20)) || ((a[t][f]!=0) && (a[t-1][f-1]!=0)))
                                    break;
                                if(((a[t][f]==11) || (a[t][f]==10)) && (a[t-1][f-1]==0))
                                {
                                    kills++;
                                    step=0;
                                    break;
                                }
                            }
                        }
                        if((attack==0) && (move==0))
                        {
                            display();
                            printf("\nuncorrect moving\n");
                            w=0;
                            attack=1;
                            move=1;
                            if(kills!=0)
                                goto M10;
                        }
                    }
                    else
                    {
                        display();
                        printf("\nuncorrect moving\n");
                        if(kills!=0)
                            goto M20;
                    }
                }
                else
                {
                    display();
                    printf("\nthere is no your checkers on the place %d %d\n",x,y);
                }
        }
        p1=0;
        p2=0;
        kills=0;
        step=0;
        att=0;
        message=0;
        for(i=1;i<N;i++)
            for(j=1;j<N;j++)
                if((a[i][j]==11) || (a[i][j]==10))
                    p1++;
                else
                if((a[i][j]==22) || (a[i][j]==20))
                    p2++;
        if((p1==0) || (p2==0))
            break;
    }
    if((p1==0) && (play))
    {
        start=clock();
        while(clock()-start<3*CLOCKS_PER_SEC);
        battlecruiser();
        printf("PLAYER 2, YOU HAVE WON THE MATCH!\n");
    }
    if((p2==0) && (play))
    {
        start=clock();
        while(clock()-start<3*CLOCKS_PER_SEC);
        battlecruiser();
        printf("PLAYER 1, YOU HAVE WON THE MATCH!\n");
    }
    if(play==0)
        return 0;
    getch();
    goto M;
}
void display()
{
    system("cls");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(((i+j)%2==0) && (a[i][j]==0))
                printf("    ");
            else
                if(a[i][j]==0)
                    printf("--  ");
                else
                    if(a[i][j]==11)
                       printf("%c%c  ",'\333','\333');
                    else
                        if(a[i][j]==22)
                            printf("%c%c  ",'\260','\260');
                        else
                            if(a[i][j]==10)
                                printf("%c%c  ",'\2','\2');
                            else
                                if(a[i][j]==20)
                                    printf("%c%c  ",'\3','\3');
                        else
                            printf("%2d  ",a[i][j]);
        }
        printf("\n\n\n");
    }
    if(message)
        printf("you had to destroy enemy chacker... your checker [%d %d] disappeared\n",message%10,message/10);
}
float sec=0.075;
clock_t delay=sec*CLOCKS_PER_SEC;
void fload()
{
    clock_t start=clock();
    while(clock()-start<delay);
    printf(" C H E C K E R S   D E L U X E   G A M E\n");
    printf(" _______________________________________\n ");
    for(i=0;i<39;i++)
    {
    clock_t start=clock();
    while(clock()-start<delay);
        printf("%c",'\333');
    }
    printf("\npress ENTER to begin");
    getch();
}
void battlecruiser()
{
    static int b[8][12];
    int sp=1,k,space=0;
    for(i=0;i<16;i++)
        for(j=0;j<12;j++)
        {
            if(((i==0) || (i==7)) && (j<=7))
                b[i][j]=1;
            if((((i>=1) && (i<=2)) || ((i>=5) && (i<=6))) && (((j>=3) && (j<=4)) || (j==10)))
                b[i][j]=1;
            if((i>=3) && (i<=4))
                b[i][j]=1;
        }
    system("cls");
    printf("\n\n\n\n\n");
    j=10;
    for(sp=1;sp<70;sp++)
    {
        if(sp>12)
            space=space+1;
        for(k=1;k<=space;k++)
            printf(" ");
        if(sp>50)
            for(i=0,j=12+50-sp;i<8;i++)
                b[i][j]=0;
        for(i=0;i<8;i++)
        {
            if(j!=0)
                j=12-sp;
            if(sp>=12)
                j=0;
            for(;j<12;j++)
                if(b[i][j]==1)
                    printf("%c",'\333');
                else
                    printf(" ");
            printf("\n");
            for(k=1;k<=space;k++)
                printf(" ");
        }
        system("cls");
        printf("\n\n\n\n");
        clock_t start=clock();
        while(clock()-start<delay);
    }
    printf("\n");
    getchar();
}
void deluxe()
{
    printf(" %c%c%c   %c%c%c%c%c %c     %c    %c %c      %c %c%c%c%c%c",'\333','\333','\333','\333','\333','\333','\333','\333'
           ,'\333','\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf("\n %c  %c  %c     %c     %c    %c  %c    %c  %c\n",'\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c   %c %c     %c     %c    %c   %c  %c   %c\n",'\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c   %c %c%c%c%c%c %c     %c    %c    %c%c    %c%c%c%c%c\n",'\333','\333','\333','\333','\333','\333','\333'
           ,'\333','\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c   %c %c     %c     %c    %c    %c%c    %c\n",'\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c   %c %c     %c     %c    %c   %c  %c   %c\n",'\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c   %c %c     %c     %c    %c  %c    %c  %c\n",'\333','\333','\333','\333','\333','\333','\333','\333','\333');
    printf(" %c%c%c%c  %c%c%c%c%c %c%c%c%c%c  %c%c%c%c  %c      %c %c%c%c%c%c\n\n",'\333','\333','\333','\333','\333','\333','\333'
           ,'\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333','\333'
           ,'\333','\333');
}
void fnew()
{
            for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            {
                if(((i+j)%2==1) && (i!=4) && (i!=5) && (i>=6))
                    a[i][j]=11;
                else
                    if(((i+j)%2==1) && (i!=4) && (i!=5) && (i<=3))
                        a[i][j]=22;
                            else
                                a[i][j]=0;
            }
        for(i=0,j=0;i<N;i++)
        {
            a[i][j]=i;
            a[j][i]=i;
        }
        for(i=N,j=0;j<=N;j++)
            a[i][j]=-1;
        for(j=N,i=0;i<=N;i++)
            a[i][j]=-1;
}
