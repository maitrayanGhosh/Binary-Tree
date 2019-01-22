

#include <iostream>
using namespace std;



class Node{
public:
    int data;
    Node *right;
    Node *left;
    Node(int val){
        data=val;
        left=NULL;//initialize the left and right pointer to NULL
        right=NULL;//then we do not require the create function
    }
};

Node *insert(Node *root , int val);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);


Node *Create(int val);
int main() {



    Node *root=NULL;

    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,12);
    root=insert(root,25);

    inorder(root);

    return 0;
}



Node *insert(Node *root, int val){
    if(root==NULL){
        Node *newNode = new Node(val);
        root=newNode;
    }

    else if(root->data<=val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    else {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node *root){
    if(root==NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}


Node *Create(int val){// this return a address of node which is of type node
    Node *newNode = new Node();
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}


void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
