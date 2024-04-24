#include<iostream>
using namespace std;


class Node{
        public:
        
                  string label;
                  int count;
                  Node *child[10]
                  ;


};
class General_tree{
        public:
                Node *root;
                General_tree(){
                        
                        Node *root=NULL;
                
                }

                void create(){
                        
                        
                        root=new Node();
                             
                        cout<<"Enter Book Name : ";
                        cin>>root->label;
                                
                        cout<<"Enter no of chapters : ";
                        cin>>root->count;
                        
                        for(int i=0;i<root->count;i++)
                        {
                                root->child[i]=new Node();
                                
                                cout<<"Enter chapter name : ";
                                cin>>root->child[i]->label;
                                
                                
                                cout<<"Enter no of sections : ";
                                cin>>root->child[i]->count;
                                
                                for(int j=0;j<root->child[i]->count;j++){
                                        
                                        root->child[i]->child[j]=new Node();
                                
                                        cout<<"Enter section name : ";
                                        cin>>root->child[i]->child[j]->label;

                                }
                        }
                }
                
                
                void display(){
                
                        cout<<"BOOK NAME : "<<root->label<<endl<<endl;
                        cout<<"YOUR CHAPTERS : "<<endl<<endl;
                        for(int i=0;i<root->count;i++)
                        {
                               
                                cout<<root->child[i]->label<<endl<<endl;
                                
                                cout<<"YOUR SECTIONS : "<<endl;
                                for(int j=0;j<root->child[i]->count;j++){
                                        
                                        
                                        cout<<root->child[i]->child[j]->label<<endl;

                                }
                                cout<<endl;
                        }
                        cout<<endl;

                }
      
                
};






int main(){

        General_tree t;
        t.create();
        cout<<endl<<"Displaying Tree : "<<endl<<endl;
        t.display();
        


return 0;
}
