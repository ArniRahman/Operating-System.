#include<stdio.h>
int main()
{
    int cpu_time[20],remaining[20],wo[20];
    int n,i,total_time,Q,count;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter CPU times:\n");
    for(i=0; i<n; i++)
    {
        printf("Process[%d]: ",i+1);
        scanf("%d",&cpu_time[i]);
    }
    printf("\nEnter time quantum: ");
    scanf("%d",&Q);
    for(i=0; i<n; i++)
        remaining[i]=cpu_time[i];
    total_time=0;
    for(i=0; i<n; i++)
        total_time=total_time+cpu_time[i];
    count=0;
    printf("\n   Gantt Chart   \n");
    printf("0");
    do
    {
        for(i=0; i<n; i++)
        {
            if(remaining[i]==0)
            {
            }
            else
            {
                if(remaining[i]>=Q)
                {
                    remaining[i]=remaining[i]-Q;
                    if(remaining[i]==0)
                    {
                        wo[i]=count;
                    }
                    count=count+Q;
                    printf("---(P%d)---",i+1);
                    printf("%d",count);
                }
                else
                {
                    if(remaining[i]<Q)
                    {
                        count=count+remaining[i];
                        remaining[i]=0;
                        wo[i]=count;
                        printf("---(P%d)---",i+1);
                        printf("%d",count);
                    }
                }
            }
        }
    }
    while(count<total_time);
    printf("\n");
}
