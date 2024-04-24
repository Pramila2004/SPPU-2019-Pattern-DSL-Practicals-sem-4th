#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
class Node{

public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
                data=val;
                left=NULL;
                right=NULL;
        
        }


};


class BST{

public:
        Node *root;
        
        BST(){
                root=NULL;
                
        }
        
        Node *create(){
                int d;
                char ch='y';
                do{
                        cout<<"Enter your Data : ";
                        cin>>d;
                        Node *newNode=new Node(d);
                        
                        if(root==NULL){
                                
                                
                                root=newNode;
                        
                        }else{
                        
                             
                                insert(root,newNode);

                        }
                        
                        cout<<"Do you want to insert one more element (y/n) : ";
                        cin>>ch;
                }while(ch=='y' || ch=='Y');
                
                return this->root;
              
        }
        
        void insert(Node *root,Node *newNode){
                
                if(root==NULL){
                        return;
                }
        
                if(root->data>newNode->data){
                        if(root->left==NULL){
                                root->left=newNode;
                        
                        }else{
                                insert(root->left,newNode);
                                return;
                        
                        }
                }else{
                
                        if(root->right==NULL){
                                root->right=newNode;
                        
                        }else{
                                insert(root->right,newNode);
                                return;
                        
                        }
                
                }
        
        
        }
        
        void inorder(Node *root){
                if(root==NULL){
                        return ;
                }else{
                
                        inorder(root->left);
                        cout<<root->data<<"  ";
                        inorder(root->right);
                
                }
        
        }
        
        void preorder(Node *root){
                if(root==NULL){
                        return ;
                }else{
                        cout<<root->data<<"  ";
                        preorder(root->left);
                        preorder(root->right);
                
                }
        
        }
        
         void postorder(Node *root){
                if(root==NULL){
                        return ;
                }else{
                        
                        postorder(root->left);
                        postorder(root->right);
                        cout<<root->data<<"  ";
                
                }
        
        }
        
        
        void inorder_traversal_using_stack(Node *root){
        
                stack<Node *> s;
                
                Node *temp=root;
                
                while(temp!=NULL || !s.empty()){
                
                        while(temp!=NULL){
                                s.push(temp);
                                temp=temp->left;
                        }
                        
                        temp=s.top();
                        s.pop();
                        
                        cout<<temp->data<<" ";
                        
                        temp=temp->right;
                        
                
                
                }
        
        
        }
        
        
         
        
        void preorder_traversal_using_stack(Node *root){
                if(root==NULL){
                        return ;
                }
               stack<Node *> s;
                
                Node *temp=root;
                
                while(temp!=NULL || !s.empty()){
                
                        while(temp!=NULL){
                                s.push(temp);
                                cout<<temp->data<<" ";
                                temp=temp->left;
                        }
                        
                        temp=s.top();
                        s.pop();
                        
                        
                        
                        temp=temp->right;
                        
                
                
                }
                
                
        
        }
       
        
        /*void display(Node *root){
                if(root==NULL){
                        return ;
                }else{
                        cout<<"******************Traversals******************* "<<endl<<endl;
                        cout<<"Inorder traversal : ";
                        inorder(root);
                        cout<<endl;
                        cout<<"Preorder traversal : ";
                        preorder(root);
                        cout<<endl;
                        cout<<"Postorder traversal : ";
                        postorder(root);
       
                }

        }*/
        
        void display(Node *root){
                if(root==NULL){
                        return ;
                }else{
                        cout<<"******************Traversals******************* "<<endl<<endl;
                        cout<<"Inorder traversal using stack: ";
                        inorder_traversal_using_stack(root);
                        cout<<endl;
                        cout<<"Preorder traversal using stack : ";
                        preorder_traversal_using_stack(root);
                        cout<<endl;
                        //cout<<"Postorder traversal : ";
                        //postorder(root);
       
                }

        }
        
        void search(Node *root,int key){

                if(root==NULL){
                        cout<<"Element not found"<<endl;
                
                }else{
                
                        if(root->data==key){
                                cout<<"Element "<<key<<" is found"<<endl;
                        
                        }else if(root->data>key){
                                search(root->left,key);
                        
                        }else{
                        
                                search(root->right,key);
                        
                        }
                
                }

        }
        
        int height(Node *root){
                
                if(root==NULL){
                        return 0;
                
                }
                int left_nodes=height(root->left);
                int right_nodes=height(root->right);
                
                return max(left_nodes,right_nodes)+1;
        
        }
        
        int minimum_data(Node *root){

                if(root->left==NULL){
                        return root->data;
                }
                
                return minimum_data(root->left);
                
        
        
        }
        
        void swap(Node *root){
        
                if(root==NULL){
                
                        return;
                
                }
                Node *temp=root->left;
                root->left=root->right;
                root->right=temp;
                
                swap(root->left);
                swap(root->right);
        
        }
        
        
        
        
        
        




};



int main(){
        Node *root;
        BST b;
        int ch,h,m;
        bool flag=true;
        int key;
        
                cout<<"1. Creating BST"<<endl;
                cout<<"2. Inserting into BST"<<endl;
                cout<<"3. Display BST"<<endl;
                cout<<"4. Search into BST"<<endl;
                cout<<"5. Height of BST"<<endl;
                cout<<"6. Minimum data of BST"<<endl;
                cout<<"7. Swaping of BST"<<endl;
                cout<<"8. Exit"<<endl;
                
                while(flag){
                       cout<<endl<<endl<<"Enter your choice : ";
                       cin>>ch;
                       switch(ch){
                
                                case 1:
                                        root=b.create();  
                                break;
                                
                                case 2:
                                        root=b.create(); 
                                break;
                                
                                case 3:
                                        b.display(root);
                                       // b.display2(root);
                                break;
                                
                                case 4:
                                        cout<<"Enter your element to be search : ";
                                        cin>>key;
                    
                                        b.search(root,key);
                                break;
                                
                                case 5:
                                        h=b.height(root);
                                        cout<<"Height of a tree is "<<h<<endl;
                                break;
                                case 6:
                                        m=b.minimum_data(root);
                                        cout<<"Minimum value from tree is "<<m<<endl;
                                        
                                break;
                                case 7:
                                        b.swap(root);
                                        b.display(root);
                                break;
                                
                                case 8:
                                        flag=false;
                                break;
                          
                       }
                
                
                }
                
        

        
        
        
        return 0;
        
}




















