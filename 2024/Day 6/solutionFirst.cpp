#include <bits/stdc++.h>

using namespace std;
void helper(vector<string> &grid, int i, int j, int dx, int dy, int &stop)
{
    if(stop)return;
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
    {
        stop = 1;
        return;
    }
    
    if(grid[i][j] != '#')grid[i][j]='X';
    
    int new_x = i+dx, new_y = j+dy;
    if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]=='#')
    {
        int xx=0, yy=0;
        
        if(dx == -1 && dy == 0)xx = 0, yy = 1;
        else if(dx == 0 && dy == -1)xx = -1, yy = 0;
        else if(dx == 1 && dy == 0)xx = 0, yy = -1;
        else if(dx == 0 && dy == 1)xx = 1, yy = 0;
        
        // cout<<":"<<xx<<" "<<yy<<endl;
            
        helper(grid, i+xx, j+yy, xx, yy, stop);
    }
    return helper(grid, new_x, new_y, dx, dy, stop);
}

int main()
{
    vector<string> v(130);
    
    for(auto &x : v)cin>>x;
    int ans=0, in_i=-1, in_j=-1;
    for(int i=0; i<130; i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            if(v[i][j] == '^')
            {
                in_i = i, in_j=j;
                break;
            }
        }
        if(in_i != -1)break;
    }
    int stop=0;
    helper(v, in_i, in_j, -1, 0, stop);
    
    for(auto &x : v)
    {
        // cout<<x;
        for(auto &y : x)
        {
            if(y=='X')
            {
                ans++;
            }
        }
        // cout<<endl;
    }
    
    cout<<ans;
    
    return 0;
}
