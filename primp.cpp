#include<iostream>
using namespace std;

int main()
{
   
int v, e,u1,u2,w;
int visited[20]={0};
int adj[20][20];
int inf=999;

cout<<"enter number of cities[vertices]"<<endl;
cin>>v;
cout<<"enter number of routes[edges]"<<endl;
cin>>e;

for(int i=0; i<v ;i++)
{
    for(int j=0;j<v;j++)
    {
        if(i==j)
        {
            adj[i][j]=0;
        }
        else{
            adj[i][j]=inf;
        }
    }
}

for(int i=0; i<e; i++)
{
    cout<<"enter the city nodes (eg. 0, 1, 2, 3....)"<<endl;
    cin>>u1>>u2;
    cout<<"enter weight"<<endl;
    cin>>w;

    adj[u2][u1]=w;
    adj[u1][u2]=w;
}

visited[0]=1;
int totalcost=0;
int edges =0;
while(edges< v-1)
{
    int min=inf;
    int a=-1, b=-1;

    for(int i=0; i<v; i++)
    {
        if(visited[i])
        {
            for(int j=0; j<v;j++)
            {
                if(!visited[j] && adj[i][j]<min)
                {
                    min=adj[i][j];
                    a=i;
                    b=j;

                }
            }
        }
    }

    if(a!= -1 && b!= -1)
    {
        cout<<"route [edge] selected : "<<a<<" - "<<b<<" cost : "<<adj[a][b]<<endl;
        visited[b]=1;
        totalcost += adj[a][b];
        edges++;
    } 

}
cout << "Total cost of the minimum spanning tree: " << totalcost << endl;
}

