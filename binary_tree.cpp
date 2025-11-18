#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
int data;
node*left,*right;
};

node*creatnode(int value)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data= value;
    newnode->left= NULL;
    newnode->right= NULL;
    return newnode;

}

void inorder (node*root)
{
    if (root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int a, b, c, d,e;
    cin>>a>>b>>c>>d>>e;
    node*root= creatnode(a);
    root->left=creatnode(b);
    root->right=creatnode(c);
    root->left->left= creatnode(d);
    root->left->right=creatnode(e);
    cout<<"inorder traversal:-";
    inorder(root);
    cout<<"\n";
    return 0;

}