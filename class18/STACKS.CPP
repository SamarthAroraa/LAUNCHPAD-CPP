#include<iostream>
#include<stack>
using namespace std;

bool checkbr(string str){
    if(str.length()&1==1){
    // cout<<" 1";
    return false;
}
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            s.push('(');
        }
        else if(str[i]==')'){
            if(s.empty())
            return false;
            if(s.top()=='(')
            s.pop();
            else return false;
        }
        else return false;
    }
return s.empty();
}
int main(){

    string str;
    cin>>str;
    cout<<checkbr(str)<<endl;
    return 0;


}
