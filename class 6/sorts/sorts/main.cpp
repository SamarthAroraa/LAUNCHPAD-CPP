//
//  main.cpp
//  sorts
//
//  Created by Samarth Arora on 31/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <bits/stdc++.h>
#include<algorithm>


using namespace std;

int main()
{
    vector<int> arr;
    int n,j;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j;
        arr.push_back(j);
    }
//    //bubble sort
//    int k=0;
//    //optimized method
//    while(1){
//        bool is_sorted=false;
//        for(int i=0;i<n-1-k;i++){
//            if(arr[i]>arr[i+1])
//            {
//                swap(arr[i],arr[i+1]);
//                is_sorted=true;
//            }
//        }
//
//        if(is_sorted==false){
//            break;
//        }
//        k++;
//    }
//    for(int j=0;j<n;j++){
//        cout<<arr[j]<<" ";
//    }
//
//
    
    //INSERTION SORT
//    int cand;
//    for(int i=1;i<n;i++){
//        cand=arr[i];
//        int j=i-1;
//        while(cand<arr[j] and j>=0){
//            arr[j+1]=arr[j];
//            j--;
//        }
//        arr[j+1]=cand;
//           }
    
    //  SELECTION SORT
    
    int curr;
    
    for(curr=0;curr<n-1;curr++){
        for(int j=curr+1;j<n;j++){
            if(arr[curr]>arr[j]){
               int temp=arr[curr];
                arr[curr]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    return 0;
    
}

