#include<bits/stdc++.h>
using namespace std;

int searchFloor(int arr[], int lo, int hi, int x){
    if(lo>hi) return -1;
    if(x>=arr[hi]) return arr[hi];

    int mid = (lo+hi)/2;
    if(arr[mid]==x) return arr[mid];
    if(mid>0 && x>=arr[mid-1] && x<arr[mid]) return arr[mid-1];

    if(x<arr[mid]) return searchFloor(arr,lo,mid-1,x);
    return searchFloor(arr,mid+1,hi,x);

}



int main(){
    int arr[] = {1, 2, 4, 6, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 13;
    int index = searchFloor(arr, 0, n-1, x);
    cout<<index<<endl;


}
