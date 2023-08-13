//binary search
//base on formula mid =(s+e)/2
#include<iostream>

using namespace std;

int binarySearch(int array[],int n,int key){
    int s = 0;
    int e = n;
        while(s<=e){
            int mid = (s+e)/2;
            if(array[mid] == key){
                return mid;

            }
            else if (array[mid]>=key)//if mid is greater than end should be shifted by mid-1
            {
                e=mid-1;
            }
            else{
                s = mid +1;
            }
        }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i =0;i<n;i++){
        cin>>array[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(array,n,key)<<endl;
    return 0;
}
// OUTPUT:
// 5
// 12 13 14 15 16
// 3
// -1