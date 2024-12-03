#include <bits/stdc++.h>
using namespace std;
bool canMake(int n, vector<int> v)
{
    // int k = v.size();
        bool ok = true;
        bool inc = true;
        bool dec = true;
        for(int i=0; i<n-1; i++)
        {
            int diff = v[i+1] - v[i];
            if(diff > 0)
            {
                dec=false;
            }
            if(diff < 0)
            {
                inc = false;
            }
            
            if(!(1 <= abs(diff) && abs(diff) <= 3))
            {
                ok = false;
            }
        }
        
        if(ok && (inc || dec))return true;
        return false;
}

int main()
{
    // std::cout<<"Hello World";
    int size=1000;
    int ans = 0;
    
    
    while(size--)
    {
        int x=0;
        // cin>>x;
        
        string s; getline(cin, s);
        int num = 0;
        vector<int> v;
        for(int i = 0; i < s.size(); ++i)
        if(s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num*10 + (s[i]-'0');
        v.push_back(num);
        
        if(canMake(v.size(), v))ans++;
        // for(int i=0; i<v.size(); i++)cout<<v[i]<<" ";
        // cout<<endl;
        
    }
    
    
    cout<<ans<<endl;
    
    

    return 0;
}
