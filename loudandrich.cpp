#include <bits\stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    vector<int>ans;
    //richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
    int m,n;
    cin>>m>>n;
    vector<vector<int>>rich;
    vector<int>quiet;
    for(int i=0;i<m;i++)
    {
       int a,b;
       cin>>a>>b;
       rich.push_back({a,b});
    }
    for(int i=0;i<n;i++)
    {
        cin>>quiet[i];
    }
     for(int i=0;i<m;i++)
    {
       cout<< rich[i].first<<rich[i].second<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<quiet[i]<<endl;
    }
}