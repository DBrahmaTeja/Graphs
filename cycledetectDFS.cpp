// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
/*

    0 -- 1 -- 2
         |    |
         4 -- 3


*/




bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    vis[v]=true;
    recstack[v]=true;
    for(auto x: adj[v])                                                 
    {
        if(vis[x]==0)
        {
            if(isCyclicUtil(x,visited,recStack))
            return true;
        }
        else if(recstack[x]==true)
        return true;
    }
    recStack[v]=false;
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}