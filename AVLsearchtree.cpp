#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
int data, height;
node*left, *right;
};

int getheight(node*n)
{
    if(n==NULL)
    return 0;
    return n->height;
}

int getbalance(node*n)
{
    return 0;
    return getheight(n->left)-getheight(n->right);
}

node*createnode(int value)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;

}

node*rightrotate(node*y){
    node*x=y->left;
    node*T2=x->right;
    x->right= y;
    y->left=T2;
    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    return x;
}

node*leftrotate(node*x){
    node*y= x->right;
    node*T2=y->right;
    y->left= x;
    x->right=T2;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    y->height=max(getheight(y->left),getheight(y->right))+1;
    return y;
}

node*insertnode(node*node,int key)
{
 if(node==NULL)
 return createnode(key);
 
 if(key<node->data)
 node->left=insertnode(node->left,key);
 else if(key>node->data)
 node->right=insertnode(node->right, key);
 else
 return node;

 node->height=1+max(getheight(node->left),getheight(node->right));

 int balance = getbalance(node);

if (balance>1 && key<node->left->data)
return rightrotate(node);

if (balance<-1 && key>node->right->data)
return leftrotate(node);

if (balance>1 && key>node->left->data){
node->left=leftrotate(node->left);

return rightrotate(node);

}

if (balance<-1 && key<node->right->data)
{
node->right=rightrotate(node->right);
return leftrotate(node);
}

return node;
}

void inorder(node*root){
    if (root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node*root=NULL;
    int n, value;
    cout<<"HOw many values to insert in AVL tree: ";
    cin>>n;
    cout<<"ENter the values:\n ";
    for (int i=0; i<n;i++){
        cin>>value;
        root=insertnode(root,value);
    }

    cout<<"\ninorder traversal of AVL tree is: ";
    inorder(root);
    cout<<endl;
    return 0;
}



