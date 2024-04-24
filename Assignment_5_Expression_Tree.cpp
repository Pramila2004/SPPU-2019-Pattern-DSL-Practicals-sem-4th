#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node{
    public:
        char data;
        Node *left;
        Node *right;

        Node(char x){
            data=x;
            left=NULL;
            right=NULL;
        }

       
    
} ;


class Exp_tree{
    public:

        bool isOperand(char ch) {
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
        }

        bool isOperator(char ch) {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }

         Node *construct_Exp_tree(string prefix){

            stack<Node *> s;
            
            int l=prefix.length();
            for(int i=l-1;i>=0;i--){
                char ch=prefix[i];
                if(isOperand(ch)){
                    Node *newNode=new Node(ch);
                    s.push(newNode);
                }else if(isOperator(ch)){
                    Node *newNode = new Node(ch);

                    newNode->left=s.top();
                    s.pop();

                    newNode->right=s.top();
                    s.pop();
                    
                    s.push(newNode);
                }
            }
            return s.top();
        }

        

        void posorder_without_recursion(Node *head){
            
            stack<Node*> s1;
            stack<Node*> s2;

            s1.push(head);

            while(!s1.empty()){
                Node *t=s1.top();
                s1.pop();
                s2.push(t);
                if(t->left){
                    s1.push(t->left);
                }
                if(t->right){
                    s1.push(t->right);
                }
            }

            //printing

            while(!s2.empty()){
                Node *t=s2.top();
                s2.pop();
                cout<<t->data<<" ";
            }

        }

        void deleteTree(Node* root) {
            if (root == nullptr) return;
                deleteTree(root->left);
                deleteTree(root->right);
                delete root;
        }

};

int main(){

    Node *head=NULL;
    Exp_tree t;
    head=t.construct_Exp_tree("+-a*bc/def");

    cout<<"Post-Order Traversal using stack : ";
    t.posorder_without_recursion(head);

    t.deleteTree(head);



    

    

    

    return 0;
}