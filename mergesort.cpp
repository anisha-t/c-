#include<iostream>
using namespace std;
void merge(int arr[],int l ,int mid, int r)
{
    int n1 = mid-l + 1;
    int n2 = r-mid;
    // Temporary array
    int a[n1];
    int b[n2];

    for(int i = 0; i<n1;i++){
        a[i]=array[l+i];
    }
    for(int i = 0; i<n2;i++){
        a[i]=array[mid+1+i];
    }
//pointers for doing the merge on two different array
int i = 0;
int j=0;
int k =l;
while(i<n1 && j<n2)
{//Compare kar agar 1 se 3 chota h toh 1 dal array me merge vala aur age bad bvale array me a ka pointer vese he rahega
    if(a[i]<b[j])
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    //varna a ka pointer badega
else  {
    arr[k] = b[j];
        k++;
        j++;
    }
}
//agar a vale me elements bache h par b ke katam h toh a vale sorted karke krdo
while (i<n1)
{
    arr[k] = a[i];
        k++;
        i++;
}
while (j<n2)
{
    arr[k] = b[j];
        k++;
        j++;
}



}

void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid + 1,r)
        merge(arr,l,mid,r);

    }
    
}