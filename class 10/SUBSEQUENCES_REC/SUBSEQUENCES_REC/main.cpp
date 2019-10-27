
//
//  main.cpp
//  SUBSEQUENCES_REC
//
//  Created by Samarth Arora on 22/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector <string> subseq;

void subsequences(string str,string ans){
    //base case
    if(str.length()==0){
        
        if(find(subseq.begin(), subseq.end(), ans)==subseq.end())
       {
//            cout<<ans<<" ";
        subseq.push_back(ans);
        }
        return ;
    }
    //recursive
    subsequences(str.substr(1),ans);
//    cout<<ans<<endl;
    subsequences(str.substr(1),ans+str[0]);//important step.. ans+str[0]means changes are being accumulated at the end. If it ha been str[0]+ans changes would be accumultaed at the beginnning
//    cout<<ans<<endl;
    
    
}
int main()
{
    int tests;
    cin>>tests;
    while(tests--){
    string str;
    cin>>str;
    subsequences(str,"");
//    cout<<endl;
//        cout<<subseq.size()<<endl;;
    for(int i=0;i<subseq.size();i++){
        cout<<subseq[i]<<endl;


        str.clear();
        subseq.clear();
    
    }
//    char c=1+'0';
//    cout<<c;
    
    return 0;
}

