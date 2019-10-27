//
//  main.cpp
//  rotations
//
//  Created by Samarth Arora on 07/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int rot;
    cin>>rot;
    int effective=rot%n;
    
    for(int j=n-effective;j<n;j++){
        cout<<arr[j]<<" ";
        
    }
    for(int j=0;j<n-effective;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    return 0;
}
