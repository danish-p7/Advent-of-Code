#include <bits/stdc++.h>

using namespace std;


// int count=0;


bool loops(vector<string>& grid, int r, int c, int rows, int cols) {
    int dr = -1, dc = 0;

    set<vector<int>> seen;

    while (true) {
        seen.insert({r, c, dr, dc});
        
        
        if (r + dr < 0 || r + dr >= rows || c + dc < 0 || c + dc >= cols) {
            return false;
        }
        
        if (grid[r + dr][c + dc] == '#') {
           
            if(dr == -1 && dc == 0)dr = 0, dc = 1;
            else if(dr == 0 && dc == -1)dr = -1, dc = 0;
            else if(dr == 1 && dc == 0)dr = 0, dc = -1;
            else if(dr == 0 && dc == 1)dr = 1, dc = 0;
            
        } else {
            
            r += dr;
            c += dc;
        }
        
        // cout<<r<<" "<<c<<endl;

        
        if (seen.find({r, c, dr, dc}) != seen.end()) {
            return true;
        }
    }
}
void helper(vector<string> &grid, int i, int j, int dx, int dy, int &stop, int in_i, int in_j, int &count)
{
    if(stop)return;
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
    {
        stop = 1;
        return;
    }
    
    
    if(grid[i][j] == '.')
    {
        grid[i][j] = '#';
        if (loops(grid, in_i, in_j, grid.size(), grid[0].size())) 
        {
            count++;  
        }
        grid[i][j] = '.';
    }
    
    grid[i][j]='X';
    
    int new_x = i+dx, new_y = j+dy;
    if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]=='#')
    {
        int xx=0, yy=0;
        
        if(dx == -1 && dy == 0)xx = 0, yy = 1;
        else if(dx == 0 && dy == -1)xx = -1, yy = 0;
        else if(dx == 1 && dy == 0)xx = 0, yy = -1;
        else if(dx == 0 && dy == 1)xx = 1, yy = 0;
        
        // cout<<":"<<xx<<" "<<yy<<endl;
            
        helper(grid, i+xx, j+yy, xx, yy, stop, in_i, in_j, count);
    }
    return helper(grid, new_x, new_y, dx, dy, stop, in_i, in_j, count);
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
    
    // int count=0;
    
    // for(auto &x: v)cout<<x<<endl;
    int count=0;
    for (int cr = 0; cr < 130; cr++) {
        for (int cc = 0; cc < v[0].size(); cc++) {
            if (v[cr][cc] != '.') continue;
            v[cr][cc] = '#';  
            
            if (loops(v, in_i, in_j, 130, v[0].size())) {
                count++;  
            }

            v[cr][cc] = '.';  
        }
    }
    // for(auto &x: v)cout<<x<<endl;
    
    // int stop=0;
    
    // helper(v, in_i, in_j, -1, 0, stop, in_i, in_j, count);

    cout << count << endl;
    
    return 0;
}
