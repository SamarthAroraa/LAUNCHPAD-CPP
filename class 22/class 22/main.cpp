#include<iostream>
#include <queue>
using namespace std;

int  maxdia=0;

class node{
public:
   int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};
node* buildtree(node* root){
   int data;
    cin>>data;

    if(data == -1)
    return NULL;
    if(root == NULL){
        node*n = new node(data);
        root = n;
    }
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}
void display_preorder(node* root){
    if(root==NULL){
        return;
    }
    //NLR
    cout<<root->data<<" ";

    display_preorder(root->left);
    display_preorder(root->right);

}
void display_postorder(node* root){
    //LRN
    if(root==NULL){
        return;
    }
    display_postorder(root->left);
    display_postorder(root->right);
    cout<<root->data<<" ";
}
bool search(node *root, int ele){
if(root==NULL)
return false;
    if(root->data==ele)
    return true;
    if(search(root->left,ele)==true)
    return true;
    else if(search(root->right,ele)==true)
    return true;

    return false;
}

int height(node* root){
    if(root==NULL)
        return -1;
    
    int leftheight=height(root->left);
    int rightheight=height(root->right);
//    if(leftheight>rightheight)
//        return leftheight+1;
//    else
//        return rightheight+1;
    return max(leftheight,rightheight)+1;
}

void LevelOrder(node * root){
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        cout<<q.front()->data<<" ";
    
    if(q.front()->left!=NULL){
        q.push(q.front()->left);
    }
    if(q.front()->right!=NULL){
        q.push(q.front()->right);
    }
        q.pop();
        
        
        
    }
}
void allpaths(node* root,string path){
   
    if(root==NULL){
        
        return;
    }
    if(root->left==NULL and root->right==NULL)
       {char dat=root->data+'0';
           cout<<path+dat<<endl;
           
           return;
       }
    char dat=root->data+'0';
    allpaths(root->left,path+dat);
    allpaths(root->right,path+dat);
    
}
void maxdiam(node* root){
    if(root==NULL){
        return ;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int currh=lh+rh+1;
    if(currh>maxdia)
        maxdia=currh;
    maxdiam(root->left);
    maxdiam(root->right);
}
class DiaHeight{
    int dia;
    int h;
    DiaHeight(){
        dia=0;
        h=-1;
    }
    
};
void optimized_maxdia(node* root,int h){
    
}
bool isbalanced(node* root){
    if(root==NULL)
        return true;
    
    if(isbalanced(root->right) and isbalanced(root->left)){
    int rh=height(root->right);
    int lh=height(root->left);
    int diff=lh-rh;
    if(diff==0 or diff==1 or diff== -1){
        return true;
    }
        
    }
    return false;
}
void lowest_anc(node*root,int el1,int el2){
    if(root==NULL){
        cout<<"Nil";
        return;
    }
    bool srleft=search(root->left,el1)+search(root->left,el2);
    bool srright=search(root->right,el1)+search(root->right,el2);
    if(srleft and srright){
        cout<<root->data<<endl;
        return ;}
    
    else if(srleft){
        lowest_anc(root->left, el1, el2);
    }
    else if(srright){
        lowest_anc(root->right, el1, el2);
    }
    
}
int Replace_csum(node* root){
    if(root==NULL){
        
        return 0;
        
        
    }
    int leftc_sum=Replace_csum(root->left);
    int rightc_sum=Replace_csum(root->right);
    int temp=root->data;
    root->data=leftc_sum+rightc_sum;
    return temp+root->data;
}
void LevelOrder_nl(node * root){
    
    queue<node *> q;
    
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        if(q.front()==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
//                continue;
            }
            continue;
            
        }
    
        cout<<q.front()->data<<" ";
    
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
            
            q.pop();
            
        
        
        
        
         
    }
}
node* lowest_anc_2(node*root,int el1,int el2){
    if(root==NULL){
        
        return NULL;
    }
    bool srleft=search(root->left,el1)+search(root->left,el2);
    bool srright=search(root->right,el1)+search(root->right,el2);
    if(srleft and srright){
        cout<<root->data<<endl;
        return root ;}
    
    else if(srleft){
        lowest_anc_2(root->left, el1, el2);
    }
    else if(srright){
        lowest_anc_2(root->right, el1, el2);
    }
    
return NULL;
    
}
int findDist(node* root,int data1,int data2){
    node* common=lowest_anc_2(root, data1, data2);
    int d1=findDist(int k,node*common);
    
    }
int main(){

    node* root=NULL;
    root=buildtree(root);
    display_preorder(root);
    cout<<endl;
//    cout<<endl;
//    display_postorder(root);
//    std::cout << "\n" <<search(root,9);
//    cout<<"\n"<<height(root)<<endl;
//    LevelOrder_nl(root);
//    cout<<"\n";
//    allpaths(root, "");
//    maxdiam(root);
//    maxdiam(root);
//    cout<<maxdia+1;
//    cout<<isbalanced(root);
//    lowest_anc(root, 1, 3);
//    cout<<Replace_csum(root)<<endl;
//    display_preorder(root);
    return 0;
}
//
//4
//2
//1
//-1
//-1
//3
//-1
//-1
//6
//5
//-1
//-1
//7
//-1
//-1
//


//1
//1
//1
//-1
//-1
//1
//1
//-1
//-1
//-1
//1
//1
//1
//-1
//-1
//1
//-1
//-1
//-1
