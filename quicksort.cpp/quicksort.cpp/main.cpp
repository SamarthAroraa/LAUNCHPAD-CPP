#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>&v,int l,int h){
    int pivot=v[h];
    int j=l-1;
    for(int i=l;i<h;i++){
        if(v[i]<= pivot)
        {
            j++;
            swap(v[j],v[i]);
        }
    }
    swap(v[j+1],v[h]);
return j+1;}
void quicksort(int l,int h,vector<int>&v){
    if(l<h){
        int q=partition(v,l,h);
        quicksort(l,q-1,v);
        quicksort(q+1,h,v);
    }
}

int main(){
    int j=0;
    vector<int> v;
    int x=0;
    cin>>j;
    j--;
    for(int i=0;i<=j;i++){
        cin>>x;
        v.push_back(x);
    }
    quicksort(0,j,v);
    for(int i=0;i<=j;i++){
        cout<<v[i]<<" ";
    }
return 0;
}

