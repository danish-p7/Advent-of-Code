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
            if(i-1<0 || i+1>=n || j-1<0 || j+1>=m)continue;
            if(v[i][j] == 'A')
            {
                
                string word1=""; 
                word1+=v[i-1][j-1]; 
                word1+=v[i][j];
                word1+=v[i+1][j+1];
                
                string word2 = ""; 
                word2+=v[i-1][j+1]; 
                word2+=v[i][j]; 
                word2+=v[i+1][j-1];
                
                if((word1 == "MAS" || word1 == "SAM") && (word2 == "MAS" || word2 == "SAM"))
                {
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    
    return 0;
}
