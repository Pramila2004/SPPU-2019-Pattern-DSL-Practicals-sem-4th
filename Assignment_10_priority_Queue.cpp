

#include <iostream>
#include <string>
using namespace std;

struct Patient{
   
    string name;
    int priority;

};

class operations{
    public:
        static const int MAX_SIZE = 100;
        Patient patients[MAX_SIZE];
        int size;

        operations(){
            size=0;
        }
        
        void insert(const string &n,int p){

            if(size>=MAX_SIZE){
                cout<<"Queue is full"<<endl;;
                return;
            }
            patients[size].name=n;
            patients[size].priority=p;

            int current=size++;

            while(current>0){
                int parent=(current-1)/2;
                if(patients[parent].priority > patients[current].priority){
                    swap(patients[parent],patients[current]);
                    current=parent;
                }else{
                    break;
                }
            }

        }

        Patient pop(){
            if (size == 0) {
                return {"",0};
            }

            Patient top_p=patients[0];
            patients[0]=patients[--size];
             int i = 0;

            while(i < size){
                int leftChild = (2 * i)+1;
                int rightChild = (2 * i)+2;

                if(leftChild < size && patients[leftChild].priority < patients[i].priority){
                    swap(patients[leftChild] , patients[i]);
                    i = leftChild;
                }
                else if (rightChild < size && patients[rightChild].priority < patients[i].priority){
                    swap(patients[rightChild] , patients[i]);
                    i = rightChild;
                } else {
                    break;
                }
            }

            return top_p;

        }


};


int main(){

    int n,priority;
    string name;

    operations op;

    cout<<"Enter Number of Patients : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int priority;
        string name;
        cout<<"Enter Name of the Priority : ";
        cin>>name;
        cout<<"Enter Priority : ";
        cin>>priority;

        op.insert(name,priority);


    }

    cout<<"Parients served : "<<endl;
    Patient p;
    while((p=op.pop()).name!=""){
        cout<<p.name<<endl;
    }


    

    return 0;
}