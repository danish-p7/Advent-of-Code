#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    vector<long long> to_make;
    long long file = 1;
    long long id = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(file)
        {
            long long occur = s[i]-'0';
            while(occur--)
            {
                to_make.push_back(id);
            }
            id++;
            file=0;
        }
        else
        {
            long long occur = s[i]-'0';
            while(occur--)
            {
                to_make.push_back(-1);
            }
            file=1;
        }
    }
    
    // for(auto &x : to_make)cout<<x;
    
    // cout<<endl;
    
    int i=0, j=to_make.size()-1;
    while(i<j)
    {
        if(to_make[i] != -1)i++;
        if(to_make[j] == -1)j--;
        
        if(to_make[i]==-1 && to_make[j]!=-1)
        {
            // cout<<i<<" : "<<j<<endl;
            swap(to_make[i], to_make[j]);
            i++, j--;
        }
    }
    
    
    // for(auto &x : to_make)cout<<x;
    // cout<<endl;
    
    long long ans = 0;
    long long idid=0;
    for(int i=0; i<=to_make.size(); i++)
    {
        if(to_make[i]==-1)break;
        
        ans += ((long long)(to_make[i]) * (idid));
        idid++;
    }
    
    cout<<ans;
    
    return 0;
}
