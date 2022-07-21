#include<bits/stdc++.h>
    int find(int parent[],int x){
    if(x== parent[x]){
        return x;
    }
    
    return parent[x] = find(parent,parent[x]);
    }
  
    struct edge{
        int u,v,w;
    };
    
    bool comp(edge E1 , edge E2)
    {
        if(E1.w<E2.w)
        return true;
        return false;
    }
int kruskalMST(int V, int E, vector<vector<int>> &adj) {
	// Write your code here.
    
        int cost=0;
        struct edge data[E];
        for(int i=0;i<E;i++)
        {
            data[i].u=adj[i][0];
            data[i].v=adj[i][1];
            data[i].w=adj[i][2];
        }
        sort(data,data+E,comp);
        
        int component[V+1];
        for(int i=1;i<=V;i++)
        component[i]=i;
        for(int i=0;i<E;i++)
        {
            int  u=data[i].u;
            int v=data[i].v;
            int w=data[i].w;
        
            int pu = find(component,u);
            int pv = find(component,v);
            if(pu!=pv)
            {
                cost+=w;
                component[max(pu,pv)]=min(pu,pv);
            }
            
        }
        
        
       return cost; 
        
}