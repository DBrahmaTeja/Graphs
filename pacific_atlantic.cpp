/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

*/
void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& v) {
        int n = grid.size();
        int m = grid[0].size();
        
        v[i][j] = true;
        
        if(i>0 && !v[i-1][j] && grid[i-1][j] >= grid[i][j])
            dfs(grid, i-1, j, v);
        if(j>0 && !v[i][j-1] && grid[i][j-1] >= grid[i][j])
            dfs(grid, i, j-1, v);
        if(i<n-1 && !v[i+1][j] && grid[i+1][j] >= grid[i][j])
            dfs(grid, i+1, j, v);
        if(j<m-1 && !v[i][j+1] && grid[i][j+1] >= grid[i][j])
            dfs(grid, i, j+1, v);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>atl(n, vector<bool>(m, false));
        vector<vector<bool>>pac(n, vector<bool>(m, false));
        
        for(int i=0;i<m;i++) { 
            dfs(grid, 0, i, pac);
            dfs(grid, n-1, i, atl);
        }
        
        for(int i=0;i<n;i++) { 
            dfs(grid, i, 0, pac);
            dfs(grid, i, m-1, atl);
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(atl[i][j] && pac[i][j])
                    ans.push_back({i, j});
        
        return ans;
}
 /*bool is_pacific_possible(int x,int y,vector<vector<int>>heights,int m,int n,vector<vector<int>>&vis)
    {
        if(x<0 or y<0 or x>=m or y>=n or vis[x][y]==1)
            return false;
        if(x==0 or y==0)
            return true;
        vis[x][y]=1;
        bool op1=false,op2=false,op3=false,op4=false;
        if(x>0 and heights[x][y]>=heights[x-1][y])
        op1= is_pacific_possible(x-1,y,heights,m,n,vis);
        
        if(x<m-1 and heights[x][y]>=heights[x+1][y])
        op2= is_pacific_possible(x+1,y,heights,m,n,vis);
        
        if(y>0 and heights[x][y]>=heights[x][y-1])
        op3= is_pacific_possible(x,y-1,heights,m,n,vis);
        
        if(y<n-1 and heights[x][y]>=heights[x][y+1])
        op4= is_pacific_possible(x,y+1,heights,m,n,vis);
        vis[x][y]=0;
        
        return op1 or op2 or op3 or op4;
        
            
    }
        bool is_atlantic_possible(int x,int y,vector<vector<int>>heights,int m,int n,vector<vector<int>>&vis)
    {
        if(x<0 or y<0 or x>=m or y>=n or vis[x][y]==1)
            return false;
        if(x==m-1 or y==n-1)
            return true;
            vis[x][y]=1;
        bool op1=false,op2=false,op3=false,op4=false;
        if(x>0 and heights[x][y]>=heights[x-1][y])
        op1= is_atlantic_possible(x-1,y,heights,m,n,vis);
        
        if(x<m-1 and heights[x][y]>=heights[x+1][y])
        op2= is_atlantic_possible(x+1,y,heights,m,n,vis);
        
        if(y>0 and heights[x][y]>=heights[x][y-1])
        op3= is_atlantic_possible(x,y-1,heights,m,n,vis);
        
        if(y<n-1 and heights[x][y]>=heights[x][y+1])
        op4= is_atlantic_possible(x,y+1,heights,m,n,vis);
        vis[x][y]=0;
        return op1 or op2 or op3 or op4;
        
            
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>>ans;
        int m=heights.size(),n=heights[0].size();
        /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<int>>vis(m,vector<int>(n,0));
                if(is_pacific_possible(i,j,heights,m,n,vis) and is_atlantic_possible(i,j,heights,m,n,vis))
                    ans.push_back({i,j});
            }
        }*/
        
    void dfs(vector<vector<int>>&heights,vector<vector<int>>&oceans,int i,int j,int n,int m)
    {
        if(i<0 || i>n-1 || j<0 || j>m-1) return;
        if(!oceans[i][j])
        {
            oceans[i][j]=1;
            if(i-1>=0 && heights[i-1][j]>=heights[i][j]) dfs(heights,oceans,i-1,j,n,m);
            if(i+1<n && heights[i+1][j]>=heights[i][j]) dfs(heights,oceans,i+1,j,n,m); 
            if(j-1>=0 && heights[i][j-1]>=heights[i][j]) dfs(heights,oceans,i,j-1,n,m);
            if(j+1<m && heights[i][j+1]>=heights[i][j]) dfs(heights,oceans,i,j+1,n,m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0){
                    if(!pacific[i][j])
                    {
                        dfs(heights,pacific,i,j,n,m);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==n-1 || j==m-1){
                    if(!atlantic[i][j])
                    {
                        dfs(heights,atlantic,i,j,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }