#include<stdio.h>
int main(){
    int process,bt[10],ct[10],ta[10],wt[10],i,j,sum=0;
    float awt=0.0, att=0.0;
    printf("How many process do you like to use: ");
    scanf("%d",&process);
    printf("\nPlease Enter Burst time : \n\n");
    for (i = 0, j=1; i < process,j<=process; i++,j++)
    {
        printf("P%d: =",j);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for (int  i = 1; i < process ; i++ ) { 
        wt[i]=0;
        for(j=0; j<i ;j++){
            wt[i]+=bt[j];
        }
    }
    printf("\n\tProcess\tBT\tTA\twait");
    for(i=0;i<process;i++){
        ta[i]=bt[i]+wt[i];
        awt+=wt[i];
        att+=ta[i];
        printf("\n\tP%d\t%d\t%d\t%d", (i+1),bt[i],ta[i],wt[i]);
    }
    awt/=process;
    att/=process;
    printf("\n\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turn Around Time: %.2f\n",att);
}