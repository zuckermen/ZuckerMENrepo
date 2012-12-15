#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define N 9
int i,j,a[N+1][N+1],message=0;
void display();
void fnew();
int main(void)
{
    int p1=12,p2=12,x,y,x1,y1,step=0,kills=0,x2,y2;
    fnew();
    display();
    while(1)
    {
        while(step==0)
        {
            message=0;
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
            if(a[x][y]==11)
            {
M11:            printf("\nmove your checker\n");
                scanf("%d%d",&x1,&y1);
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
                {
                    display();
                    printf("\nthere is no your checkers on the place %d %d\n",x,y);
                }
        }
        p1=0;
        p2=0;
        step=0;
        kills=0;
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
            if(a[x][y]==22)
            {
M22:            printf("\nmove your checker\n");
                scanf("%d%d",&x1,&y1);
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
                {
                    display();
                    printf("\nthere is no your checkers on the place %d %d\n",x,y);
                }
        }
        p1=0;
        p2=0;
        kills=0;
        step=0;
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
    if(p1==0)
        printf("PLAYER 2, YOU HAVE WON THE MATCH!\n");
    if(p2==0)
        printf("PLAYER 1, YOU HAVE WON THE MATCH!\n");
    return 0;
}
void display()
{
    system("cls");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(((i+j)%2==0) && (i!=0) && (j!=0))
                printf("    ");
            else
                printf("%2d  ",a[i][j]);
        }
        printf("\n\n\n");
    }
    if(message)
        printf("you had to destroy enemy chacker... your checker [%d %d] disappeared\n",message%10,message/10);
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
}
