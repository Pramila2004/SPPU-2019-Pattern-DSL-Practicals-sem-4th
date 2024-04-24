#include <iostream>
#include <climits>
using namespace std;
int main(){

    int n,w,col,row,min,mincost=0;
    char ch;
    

    cout<<"Enter no of Vertices : ";
    cin>>n;

    int cost[n+1][n+1];
    int visited[n+1];


    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cost[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<"Do you want connection b/w "<<i<<" and "<<j<<" : ";
            cin>>ch;
            if(ch=='Y' || ch=='y'){
                cout<<"Enter weight : ";
                cin>>w;
                cost[i][j]=w;
                cost[j][i]=w;
            }
        }
    }
    visited[1]=1;
    for(int k=0;k<n-1;k++){
        min=INT_MAX;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=n;j++){
                if(visited[i]==1){
                    if(visited[j]==0 && cost[i][j]!=-1 && min>cost[i][j]){
                        min=cost[i][j];
                        row=i;
                        col=j;
                    }
                }
            }
        }
        mincost+=min;
        visited[col]=1;
        cout<<row<<" -> "<<col<<endl;
        cost[row][col]=cost[col][row]=-1;
    }

    cout<<"Minimum cost : "<<mincost<<endl;


    return 0;
}