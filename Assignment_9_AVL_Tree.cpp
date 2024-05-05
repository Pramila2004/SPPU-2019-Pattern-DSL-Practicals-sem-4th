#include <iostream>
using namespace std;

class Node
{
public:
	string key;
	string meaning;
	Node *left;
	Node *right;
};

class AVL{
    Node *root;
    public:
        AVL(){
            root=NULL;

        }

        void create();
        Node *insert(Node *cur,Node *temp);
        Node *balance(Node *temp);
        int height(Node *temp);
        int diff(Node *temp);

        Node *LL(Node *par);
        Node *RR(Node *par);
        Node *LR(Node *par);
        Node *RL(Node *par);


        void ascending(Node *temp);
        void descending(Node *temp);
        void display();

        bool search(Node *cur,string key);
        void search_value();

        bool update(Node *cur,string key);
        void update_value();


        Node* delete_n(Node *root,string key1);
        Node* extractmin(Node *t);
        void delete_value();
            	

};


void AVL:: create(){
    char ch;
    Node *temp;
    do{
        temp=new Node();
        cout<<"Enter keyword : ";
        cin>>temp->key;
        cout<<"Enter meaning : ";
        cin>>temp->meaning;

        temp->left=temp->right=NULL;

        root=insert(root,temp);

        cout<<"Do you want to insert again(y/n) : ";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
}

Node *AVL :: insert(Node *cur,Node *temp){

    if(cur==NULL){
        return temp;
    }
    else if (cur->key>temp->key)
    {
        cur->left=insert(cur->left,temp);
        cur=balance(cur);
    }else if(cur->key<temp->key)
    {
        cur->right=insert(cur->right,temp);
        cur=balance(cur);
    }

    return cur;

}


Node *AVL :: balance(Node *temp){
    int balance_factor=diff(temp);
    if(balance_factor>=2){
        if(diff(temp->left)<0){
            temp=LR(temp);
        }else{
             temp=LL(temp);
        }
    }else if(balance_factor<=-2){

        if(diff(temp->right)<0){
            temp=RR(temp);
        }else{
            temp=RL(temp);
        }

    }

    return temp;
}


int AVL :: diff(Node *temp){
    int l,r;
    l=height(temp->left);
    r=height(temp->right);

    return (l-r);
}

int AVL :: height(Node *temp){
    if(temp==NULL){
        return -1;
    }
    return(max(height(temp->left),height(temp->right))+1);
}


Node *AVL :: LL(Node *par){
    Node *temp=par->left;
    Node *temp1=temp->right;
    temp->right=par;
    par->left=temp1;
    return temp;

}
Node *AVL :: RR(Node *par){
    Node *temp=par->right;
    Node *temp1=temp->left;
    temp->left=par;
    par->right=temp1;
    return temp;

}

Node *AVL :: LR(Node *par){
    par->left=RR(par->left);
    return (LL(par));
}
Node *AVL :: RL(Node *par){
    par->right=LL(par->right);
    return (RR(par));
}

void AVL :: ascending(Node *temp){
    if(temp!=NULL){
        ascending(temp->left);
        cout<<temp->key<<" : "<<temp->meaning<<endl;
        ascending(temp->right);
    }
}

void AVL :: descending(Node *temp){
    if(temp!=NULL){
        descending(temp->right);
        cout<<temp->key<<" : "<<temp->meaning<<endl;
        descending(temp->left);
    }
}


void AVL :: display(){

    cout<<"\n The keywords in ascending order are : \n";
    ascending(root);
    cout<<"\n The keywords in descending order are : \n";
    descending(root);

}


void AVL :: search_value(){
    string val;

    cout<<"Enter key to be search : ";
    cin>>val;

    bool found=search(root,val);

    if(found){
        cout<<"Entered key is preesnt "<<endl;
    }else{
        cout<<"Entered key is not preesnt "<<endl;
    }


}

bool AVL :: search(Node *cur,string val){
    if(cur){
        if(cur->key==val){
            return true;
        }else if(cur->key>val){
            return search(cur->left,val);
        }else{
            return search(cur->right,val);
        }
    }
    return false;
}


void AVL :: update_value(){
    string val;

    cout<<"Enter key to be update meaning : ";
    cin>>val;

    bool found=update(root,val);

    if(found){
        cout<<"Entered key is updated "<<endl;
    }else{
        cout<<"Entered key is not preesnt "<<endl;
    }


}

bool AVL :: update(Node *cur,string val){
    if(cur){
        if(cur->key==val){
            string mean;
            cout<<"Enter new Meaning : ";
            cin>>mean;
            cur->meaning=mean;
            return true;
        }else if(cur->key>val){
            return update(cur->left,val);
        }else{
            return update(cur->right,val);
        }
    }
    return false;
}


Node* AVL::delete_n(Node* cur,string key1)
{
    if ( !cur)
    	return cur;
    if ( key1 < cur->key )
        cur->left = delete_n(cur->left, key1);

    else if( key1 > cur->key )
        cur->right = delete_n(cur->right, key1);

    else
    {
        Node *l = cur->left;
        Node *r = cur->right;
        delete cur;
        if ( !r )
        	return l;
        Node *m=r;
        
        while(m->left)
        	m=m->left;
        m->right = extractmin(r);
        m->left = l;
        return balance(m);
    }
    return balance(cur);
}

Node* AVL::extractmin(Node *t)
{
    if ( !t->left ) 
    return t->right;
    t->left = extractmin(t->left);
    return balance(t);
}

void AVL::delete_value()
{
	string key;
	cout<<"\n Enter the keyword to be deleted : ";
	cin>>key;
	root=delete_n(root,key);
}







int main(){

    int ch;
    bool flag=true;
    AVL a;
    while(flag){
        cout<<"*********************************";
        cout<<"\n 1.Insert a keyword in AVL tree.";
        cout<<"\n 2.Display the AVL tree.";
        cout<<"\n 3.Search a keyword in AVL tree";
        cout<<"\n 4.update a meaning of keyword in AVL tree";
        cout<<"\n 5.Delete keyword From AVL tree";
        cout<<"\n 6.Exit";
        cout<<"\n Enter your choice : ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            a.create();
            break;
        case 2:
            a.display();
            break;
        case 3:
            a.search_value();
            break;
        
        case 4:
            a.update_value();
            break;
        
        case 5:
            a.delete_value();
            break;
        
        case 6:
            flag=false;
            break;
        
        default:
            cout<<"\n Wrong choice ! ";
            break;
        }

    }

    

    return 0;
}