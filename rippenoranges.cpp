/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/


#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int r, int c)
{
    // Write your code here. 
    queue<pair<int,int>>q;
    int fresh=0,level=-1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
            if(grid[i][j]==1)
            {
                fresh++;
            }
        }
    }
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    while(q.size()>0)
    {
        level++;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(pair<int,int> d:dir){
                    int nx=x+d.first;
                    int ny=y+d.second;
                    if(nx<0||nx>=r||ny<0||ny>=c||grid[nx][ny]==2)
                        continue;
                    else if(grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
        }
    }
    if(fresh)
        return -1;
    if(level==-1)
        return 0;
    return level;
}