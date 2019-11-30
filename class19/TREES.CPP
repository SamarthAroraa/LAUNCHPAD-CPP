#include<iostream>
using namespace std;



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
    if(search(root->left)==true)
    return true;
    else if(search(root->right)==true)
    return true;

    return false;
}

int main(){

    node* root=NULL;
    root=buildtree(root);
    display_preorder(root);
    cout<<endl;
    display_postorder(root);
    std::cout << "\n" <<search(root,3);
    return 0;
}
