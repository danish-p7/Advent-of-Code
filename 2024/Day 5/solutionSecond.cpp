#include <bits/stdc++.h>

using namespace std;
bool notContains(map<int, vector<int>> &mpp, int i, int x)
{
    auto it = find(mpp[i].begin(), mpp[i].end(), x);
    if(it == mpp[i].end())return true;
    return false;
}
int main()
{
    int n = 1176;
    int ans=0;
    vector<string> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    
    map<int, vector<int>> mpp;
    // vector<vector<int>> v(n);
    for(auto &x : v)
    {
        int n1 = stoi(x.substr(0, 2));
        int n2 = stoi(x.substr(3, 2));
        
        // cout<<n1<<" "<<n2<<endl;
        
        mpp[n1].push_back(n2);
    }
    
    vector<vector<int>> v1(175);
    for(int i=0; i<175; i++)
    {
        string s;
        cin>>s;
        
        for(int j=0; j<s.size(); j++)
        {
            string t="";
            while(j<s.size() && s[j]!=',')
            {
                t += s[j];
                j++;
            }
            
            v1[i].push_back(stoi(t));
        }
    }
    
    // for(auto &[x, y] : mpp)
    // {
    //     cout<<x<<" | ";
    //     for(auto z : y)cout<<z<<" ";
    //     cout<<endl;
    // }
    
    // for(auto x : v1)
    // {
    //     for(auto y : x)cout<<y<<" ";
    //     cout<<endl;
    // }
    
    for(int i=0; i<175; i++)
    {
        bool isCorrect = true;
        int sz = v1[i].size();
        for(int j = 0; j<sz; j++)
        {
            for(int k=j+1; k<sz; k++)
            {
                auto it = find(mpp[v1[i][j]].begin(), mpp[v1[i][j]].end(), v1[i][k]);
                if(it == mpp[v1[i][j]].end())isCorrect=false;
            }
        }
        if(!isCorrect)
        {
            // ans += v1[i][sz/2];
            
            for(int j=0; j<sz; j++)
            {
                for(int k=j+1; k<sz; k++)
                {
                    if(notContains(mpp, v1[i][j], v1[i][k]))swap(v1[i][j], v1[i][k]);
                }
            }
            ans += v1[i][sz/2];
        }
    }
    
    cout<<ans<<endl;
    

    return 0;
}
