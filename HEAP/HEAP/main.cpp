//
//  main.cpp
//  HEAP
//
//  Created by Samarth Arora on 16/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int min_rope_join(vector<int> len)
{
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i< len.size();i++){
        pq.push(len[i]);
    }
    int first;
    int sum=0;
    first=pq.top();
    pq.pop();
    int second;
    while (!pq.empty()) {
        second=pq.top();
        pq.pop();
        first+=second;
        sum+=first;
        
    
    }
    
    return sum;
}
int kthlargest(vector<int> arr,int k){
    priority_queue<int , vector<int>, greater<int> > q;
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]<q.top())
            continue;
        else{
            q.push(arr[i]);
            q.pop();
        }
    }
    return q.top();
    
}
void heapify(int arr[],int n, int j){
    while(arr[j]>arr[j/2] and j/2>=1){
        swap(arr[j], arr[j/2]);
        j=j/2;
    }
}
void array_to_heap(int arr[],int n){
    for( int i=n;i>=1;i--){
//        for(int i=1;i<=n;i++){
        heapify(arr,n,i);
//        }
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n******************";
}
void sort_from_heap(int heap[],int n){
    for (int i=n; i>=1; i--) {
        swap(heap[i], heap[1]);
        heapify(heap, i, i);
    }
    for(int i=1;i<=n;i++)
        cout<<heap[i]<<" ";
    
    cout<<"\n******************";
}
void heap_Del(int arr[],int n,int del_el){
    for(int i=1;i<=n;i++){
        if(arr[i]==del_el){
            arr[i]=INT_MIN;
            heapify(arr, n, i/2);
        }
    }n--;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n******************";
}
class ARRAY{
public:
    int val;
    int idx;
    int k;
    ARRAY(int val,int idx,int k){
        this->val=val;
        this->idx=idx;
        this->k=k;
    }
};

class comparator{
public:
    bool operator()(ARRAY A, ARRAY B){
        
        return A.val>B.val;
    }
};


void sort_k_arrays(int k,int col,int arr[3][5]){
    vector<int> resulting;
    priority_queue<ARRAY,vector<ARRAY>,comparator > heap;
    for(int i=0;i<k;i++)
    {
        ARRAY obj(arr[i][0],0,i);
        heap.push(obj);
        
    }
    ARRAY min= heap.top();
    while(min.val!=INT_MAX){
        resulting.push_back(min.val);
        int nwindx=min.idx+1;
        int kth=min.k;
        heap.pop();
        if(arr[kth][nwindx]==0){
            ARRAY obj(INT_MAX,nwindx,kth);
            heap.push(obj);
        }
        else{
        ARRAY obj(arr[kth][nwindx],nwindx,kth);
        heap.push(obj);
        }
        
        min=heap.top();
    }
    for(int i=0;i<resulting.size();i++){
        cout<<" "<<resulting[i];
    }
}

int main()
{
    vector<int> len={1,2,3,4,5,6};
//    int arr[]=;
//
//    int arr2[]=;
//    int arr3[]=;
      int arrparent[3][5]={{2,4,5,8,0},{7,20,30,40,0},{1,3,4,6,0}};
      sort_k_arrays(3,5, arrparent);
//    array_to_heap(arr, 7);
//    sort_from_heap(arr, 7);
//    heap_Del(arr, 7, 5);
//    cout<<min_rope_join(len);
//    cout<<kthlargest(len,2);
    return 0;
}
