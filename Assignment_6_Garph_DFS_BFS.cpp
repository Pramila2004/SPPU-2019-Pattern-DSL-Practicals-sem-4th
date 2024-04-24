#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;




int main(){

    
    int no_of_vertices;
    int no_of_edges;
    int u,v;

    cout<<"Enter Number of Vertices : ";
    cin>>no_of_vertices;
    cout<<"Enter Number of Edges : ";
    cin>>no_of_edges;

    vector<vector<int>> adjlist(no_of_vertices+1);

    cout<<"Enter Edges : "<<endl;
    for (int  i = 0; i < no_of_edges; i++)
    {
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    //Display Adj list
    cout<<"Your List : "<<endl;
    for(int i=1;i<=no_of_vertices;i++){

        cout<<i<<" |-> ";

        for(auto it:adjlist[i]){
        
            cout<<it<<" -> ";
        
        }
        cout<<endl;

    }
    

    //BFS
    int source;
    cout << "\nEnter your starting Node for BFS: ";
    cin>>source;

    vector<int> visited(no_of_vertices+1,0);
    queue<int> q;

    q.push(source);
    visited[source]=1;

    cout << "\nBFS Traversal: ";
    while(!q.empty()){
        int element=q.front();
        q.pop();

        cout<<element<<"  ";

        for(auto it : adjlist[element]){

            if(!visited[it]){
                
                q.push(it);
                visited[it]=1;
            }
            
            
        }

    }


    //DFS

    int source1;
    cout << "\nEnter your starting Node for DFS: ";
    cin >> source1;

    vector<int> visited1(no_of_vertices + 1, 0);

    stack<int> s;
    s.push(source1);
    visited1[source1] = 1;

    cout << "\nDFS Traversal: ";

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        cout << vertex << " ";

        for (auto it : adjlist[vertex]) {
            if (!visited1[it]) {
                s.push(it);
                visited1[it] = 1;
            }
        }
    }
    cout << endl;

    
       


    

    

    return 0;
}