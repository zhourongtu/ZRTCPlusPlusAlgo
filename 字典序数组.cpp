#include<iostream>
#include<vector>

using namespace std;

void recursive(int m,vector<int> &arr,int n){
    if(m>n)
        return;
    for(int i=0;i<=9;i++){
        if(m+i<=n){
            arr.push_back(m+i);
            recursive(m*10,arr,n);
        }
    }        
}

void SortByDict(int n,vector<int> &arr){
    for(int i=1;i<=9;i++){
        if(i<=n){
            arr.push_back(i);
            recursive(i*10,arr,n);
        }
    }
}

int main(){
    int n;
    while(cin>>n){
        vector<int> arr;
        SortByDict(n,arr);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}