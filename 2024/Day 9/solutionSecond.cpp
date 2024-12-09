#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s="";
    while (getline(cin, s1)) {
    }
    
    vector<pair<long long, long long>> to_make;
    // priority_queue<pair<long long>> pq;
    long long file = 1;
    long long id = 0;
    vector<pair<long long, long long>> gaps;
    for(int i=0; i<s1.size(); i++)
    {
        if(file)
        {
            long long occur = s1[i]-'0';
            // string pocket="";
            to_make.push_back({occur, s.size()});
            while(occur--)
            {
                // pocket += to_string(id);
                s+=to_string(id);
            }
            
            id++;
            file=0;
        }
        else
        {
            long long occur = s1[i]-'0';
            gaps.push_back({occur, s.size()});
            // string pocket="";
            while(occur--)
            {
                // to_make.push_back(".");
                s+=".";
            }
            // // to_make.push_back(pocket);
            // pr.push(occur);
            file=1;
        }
    }
    
    // for(auto &[x, y] : gaps)
    // {
    //     cout<<x<<" : "<<y<<endl;
    // }
    // cout<<endl;
    // for(auto &[x, y] : to_make)
    // {
    //     cout<<x<<" : "<<y<<endl;
    // }
    // cout<<s<<endl;
    // 
    // for(auto &x : to_make)cout<<x;
    
    // cout<<endl;
    
    int i=0, j=to_make.size()-1;
    
    while(j>=0)
    {
        // for(auto &[x, y] : gaps)
        // {
        //     cout<<x<<" : "<<y<<endl;
        // }
        // cout<<endl;
        int sz = to_make[j].first;
        // cout<<sz<<endl;
        for(int i=0; i<gaps.size(); i++)
        {
            if(gaps[i].first>0 && gaps[i].first>=sz)
            {
                for(int k=gaps[i].second; k<gaps[i].second+sz; k++)
                {
                    s[k]=s[to_make[j].second];
                    
                    // cout<<s<<endl;
                }
                for(int k=to_make[j].second; k<to_make[j].second+to_make[j].first; k++)
                {
                    s[k]='.';
                }
                int diff = gaps[i].first-sz;
                gaps[i].first = diff, gaps[i].second = gaps[i].second+sz;
                break;
            }
        }
        j--;
    }
    
    
    // for(auto &x : to_make)cout<<x;
    // cout<<endl;
    cout<<s<<endl;
    
    long long ans = 0;
    long long idid=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='.')
        {
            idid++;
            continue;
        }
        
        ans += ((long long)(s[i]-'0') * idid);
        idid++;
    }
    
    cout<<ans;
    // sus
    
    
    
    
    return 0;
}
