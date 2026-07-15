#include<stdio.h>

struct Pair
{
    int max;
    int min;
};

struct Pair maxMin(int arr[],int low,int high)
{
    struct Pair p,left,right;

    if(low==high)
    {
        p.max=p.min=arr[low];
        return p;
    }

    if(high==low+1)
    {
        if(arr[low]>arr[high])
        {
            p.max=arr[low];
            p.min=arr[high];
        }
        else
        {
            p.max=arr[high];
            p.min=arr[low];
        }
        return p;
    }

    int mid=(low+high)/2;

    left=maxMin(arr,low,mid);
    right=maxMin(arr,mid+1,high);

    p.max=(left.max>right.max)?left.max:right.max;
    p.min=(left.min<right.min)?left.min:right.min;

    return p;
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Pair ans=maxMin(arr,0,n-1);

    printf("Maximum = %d\n",ans.max);
    printf("Minimum = %d\n",ans.min);

    return 0;
}