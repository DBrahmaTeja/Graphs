vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>>hs;
        vector<int>time(V,INT_MAX);
        time[S]=0;
        hs.insert({0,S});
        while(hs.size()!=0)
        {
            pair<int,int>data=*hs.begin();
            hs.erase(data);
            int d=data.first;
            int u=data.second;
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i][0];
                int w=adj[u][i][1];
                if(time[v]>time[u]+w)
                {
                    if(time[v]!=INT_MAX)
                    hs.erase({time[v],v});
                    time[v]=time[u]+w;
                    hs.insert({time[v],v});
                }
            }
        }
        return time;
        
    }