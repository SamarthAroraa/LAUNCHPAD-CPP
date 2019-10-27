//
//  main.cpp
//  subarrays
//
//  Created by Samarth Arora on 31/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;

    for(int size=0;size<n;size++){
        for(int j=0;j+size<n;j++){
            int strt=j, end=j+size;
            for(int k=strt;k<=end;k++){
                cout<<arr[k];
            }cout<<endl;
        }
    }
    return 0;

}
