#include<stdio.h>

struct Job
{
    char id[5];
    int deadline;
    int profit;
};

int main()
{
    int n;

    printf("Enter number of jobs: ");
    scanf("%d",&n);

    struct Job job[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter Job ID Deadline Profit: ");
        scanf("%s%d%d",job[i].id,&job[i].deadline,&job[i].profit);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(job[i].profit<job[j].profit)
            {
                struct Job temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
        }
    }

    int maxDeadline=0;

    for(int i=0;i<n;i++)
        if(job[i].deadline>maxDeadline)
            maxDeadline=job[i].deadline;

    int slot[maxDeadline];
    for(int i=0;i<maxDeadline;i++)
        slot[i]=-1;

    int totalProfit=0;

    printf("Selected Jobs: ");

    for(int i=0;i<n;i++)
    {
        for(int j=job[i].deadline-1;j>=0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                totalProfit+=job[i].profit;
                printf("%s ",job[i].id);
                break;
            }
        }
    }

    printf("\nTotal Profit = %d",totalProfit);

    return 0;
}