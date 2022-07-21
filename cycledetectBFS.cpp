// This function returns true if there is a cycle
// in directed graph, else returns false.
bool Graph::isCycle()
{
    // Create a vector to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    vector<int> in_degree(V, 0);
 
    // Traverse adjacency lists to fill indegrees of
    // vertices. This step takes O(V+E) time
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u])
            in_degree[v]++;
    }
 
    // Create an queue and enqueue all vertices with
    // indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
 
    // Initialize count of visited vertices
    // 1 For src Node
    int cnt = 1;
 
    // Create a vector to store result (A topological
    // ordering of the vertices)
    vector<int> top_order;
 
    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while (!q.empty()) {
 
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        
        for (int i=0;i<adj[u].size();i++)
 
            // If in-degree becomes zero, add it to queue
            if (--in_degree[adj[u][i]] == 0)
            {
              q.push(adj[u][i]);
              //while we are pushing elements to the queue we will incrementing the cnt
              cnt++;
            }
 
        
    }
 
    // Check if there was a cycle
    if (cnt != V)
        return true;
    else
        return false;
}