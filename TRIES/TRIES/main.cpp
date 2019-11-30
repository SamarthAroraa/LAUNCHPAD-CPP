//
//  main.cpp
//  TRIES
//
//  Created by Samarth Arora on 21/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Node{
public:
    char data;
    unordered_map<char, Node*> map;
    bool isTerminating;
    Node(char data){
        this->data=data;
        this->isTerminating=false;
    }
    
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node('/0');
    }
    void add(string str){
          Node* temp= root;
        for(int i=0;i<str.length();i++){
          
            char ch=str[i];
            if(temp->map.count(ch)){
                temp=temp->map[ch];
            }
            else{
                Node* child= new Node(ch);
                temp->map[ch]=child;
                temp=temp->map[ch];
            }
        }
        temp->isTerminating=true;
        
    }
    bool search(string str){
        Node* temp=root;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp->map.count(ch)){
                temp=temp->map[ch];
            }
            else return false;
        }
        return temp->isTerminating;
    }
    
};
string convert_bin(int  n){
    string ans="";
    for(int i=31;i>=0;i--){
        char ni= (n>>i)&1;
        ans+=ni;
    }
    
    return ans;
}
int max_xor(Trie t,vector<int> nums){
    int ans=INT_MIN;
    Node* temp=t.root;
    
    for(int i=0;i<nums.size();i++){
        int currans=0;
        string curr=convert_bin(nums[i]);
        for(int i=0;i<curr.length();i++){
//            cout<<currans<<endl;
            double factor=pow(2,curr.length()-i-1);
            if(curr[i]=='0'){
                if(temp->map.count('1')){
                    currans+=factor;
//                    if(!temp->isTerminating)
                    temp=temp->map['1'];
                }
                else{
//                    if(!temp->isTerminating)
                    temp=temp->map['0'];
                }
                
            }
            else{
                if(temp->map.count('0')){
                    currans+=factor;
//                    if(!temp->isTerminating)
                    temp=temp->map['0'];
                }
                else{
//                    if(!temp->isTerminating)
                    temp=temp->map['1'];
                }
                
            }
            
        }
    if(currans>ans)
        ans=currans;
        }
    
    
    return ans;}


int main(){
    vector<int> nums={1,2,3,4,5};
    
    
    Trie t;
    for(int i=0;i<nums.size();i++){
        string bin=convert_bin(nums[i]);
        t.add(bin);
    }
    cout<<max_xor(t, nums);
    return 0;
}

