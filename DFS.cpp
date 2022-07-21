#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int start,vector<int>&vis,vector<int>adj[])
{
   
        vis[start]=1;
        cout<<start<<" ";
        for(auto x: adj[start])
        {
             if(!vis[x])
                dfs(x,vis,adj);
        }
}

void dfs(vector<int>&graph[],int vis[],int start)
{
    if(vis[start]==1)
    return;
    cout<<start<<" ";
    vis[start]=1;
    for(int i=0;i<graph[start].size();i++)
    {
        int elem=graph[start][i];
        dfs(graph,vis,elem);
    }
}

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
    /*
    If there is one component then
    dfs(1,vis,adj)
    */
    //If there are multiple Components Then:
    for(int i=1;i<=vertices;i++)
    {
        if(!vis[i])
        dfs(i,vis,adj);
    }
    return 0;
}