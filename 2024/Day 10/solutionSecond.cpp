#include<bits/stdc++.h>

using namespace std;

// set<pair<int, int>> vis;
int ans1=0;
int score(vector<vector<int>> &grid, int i, int j, int height)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return 0;
    
    if(grid[i][j] != height)return 0;
    
    if(grid[i][j] == 9)
    {
        return 1;
    }
    
    
    return score(grid, i+1, j, height+1) + score(grid, i-1, j, height+1) + score(grid, i, j+1, height+1) + score(grid, i, j-1, height+1);
}
int main()
{
    int n=42;
    vector<vector<int>> hike(n, vector<int>(n));
    long long ans=0;
    
    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin, s);
        for(int j=0; j<n; j++)
        {
            hike[i][j] = s[j]-'0';
        }
    }
    for(auto &x : hike)
    {
        for(auto &y : x)cout<<y;
        cout<<endl;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(hike[i][j] == 0)
            {
                // set<pair<int, int>> st;
                // cout<<score(hike, i, j, 0, st)<<endl;
                ans+=score(hike, i, j, 0);
                // ans+=1;
            }
        }
    }
    cout<<ans<<" "<<ans1;
    return 0;
}
