//DFS+Pruning

void solve(vector<vector<int>> &adj, vector<vector<int>> &cost, int src, int dst, int k, int &fare, int totCost, vector<bool> &visited)
{

    if (k < -1)
        return;
    if (src == dst)
    {

        fare = min(fare, totCost);
        return;
    }
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); ++i)
    {

        if (!visited[adj[src][i]] && (totCost + cost[src][adj[src][i]] <= fare))
            solve(adj, cost, adj[src][i], dst, k - 1, fare, totCost + cost[src][adj[src][i]], visited);
    }
    visited[src] = false;
}

int findCheapestPrice(intn, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<vector<int>> adj(n);
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    for (inti = 0; i < flights.size(); ++i)
    {

        adj[flights[i][0]].pb(flights[i][1]);
        cost[flights[i][0]][flights[i][1]] = flights[i][2];
    }
    vector<bool> visited(n + 1, false); // To break cycles
    int fare = INT_MAX;
    solve(adj, cost, src, dst, K, fare, 0, visited);
    if (fare == INT_MAX)
        return -1;
    return fare;
}
