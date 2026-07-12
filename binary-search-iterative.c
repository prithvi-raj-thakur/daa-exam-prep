#include<stdio.h>

int binarySearch(int arr[], int n , int key){
    int low = 0;
    int high = n-1; 
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            low = mid + 1;
        else 
            high = mid - 1 ;
    }
    return -1;
}

int main(){
    int n ;
    printf("enter the number of elments: ");
    scanf("%d",&n);

    int arr[n];
    int i;
    printf("enter the elements in sorted manner:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("enter the element to search : ");
    scanf("%d",&key);

    int pos = binarySearch(arr,n,key);

    if(pos == -1)
        printf("element not found...");
    else
        printf("element found at %d position .",pos+1);
    return 0;
}