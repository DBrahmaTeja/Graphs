#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
void bfs(int start,vector<int>&vis,vector<int>adj[])
{
    vis[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int current_vertice=q.front();
        q.pop();
        cout<<current_vertice<<" ";
        for(auto x: adj[current_vertice])
        {
            if(!vis[x])
            {
                vis[x]=1;
                q.push(x);
            }
        }

    }
}*/
void bfs(vector<int>graph[],int start,vector<int>&vis,int dis[],int par[])
{
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(q.size()!=0)
    {
        int u=q.front();
        q.pop();
        cout<<u;
        for(int i=0;i<graph[u].size();i++)
        {
            int elem=graph[u][i];
            if(vis[elem]==0)
            {
                q.push(elem);
                vis[elem]=1;
                dis[elem]=dis[u]+1;
                par[elem]=u;
            }
        }
    }
}
/*
int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int>adj[vertices+1];
    for (int  i = 1; i <=edges; i++)
    {
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u); // Considering as a non directed graph.
        adj[u].push_back(v);//If you want to consider it as a directed graph then remove the second PushBack.
    }
    vector<int>vis(vertices+1,0);
   
    
    If there is one component then
    bfs(1,vis,adj)
    
    //If there are multiple Components Then:
    for(int i=1;i<=vertices;i++)
    {
        if(!vis[i])
        bfs(i,vis,adj);
    }
    return 0;
}


*/


int main()
{
    int n,e;
    cin>>n>>e;
     vector<int>graph[n+1];
    for(int i=1;i<=e;i++)
    {
        int v,u;
        cin>>v>>u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
     int dis[n+1]={0};
    int par[n+1]={-1};
    vector<int>vis(n+1,0);
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
        bfs(graph,i,vis,dis,par);
        c++;
        }
    }
    if(e>n-c)
    cout<<"There Exists a cycle"<<endl;
    else if(e==n-c)
    cout<<"No Cycle in Graph"<<endl;
    return 0;
}