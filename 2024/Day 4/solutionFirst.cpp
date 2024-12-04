#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=140, m=140;
    int ans=0;
    vector<string> v(n);
    for(auto &x : v)cin>>x;
    string word = "XMAS";
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int dx = -1; dx<2; dx++)
            {
                for(int dy = -1; dy<2; dy++)
                {
                    int matched=0;
                    for(int dis = 0; dis<4; dis++)
                    {
                        if((i+dx*dis) >= 0 && (i+dx*dis) < n && (j + dy*dis)>=0 && (j + dy*dis)<m &&  v[i+dx*dis][j+dy*dis] == word[dis])matched++;
                    }
                    if(matched == 4)ans++;
                }
            }
        }
    }
    cout<<ans;
    
    return 0;
}
