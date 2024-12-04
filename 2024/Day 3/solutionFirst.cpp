#include <bits/stdc++.h>
using namespace std;
pair<int, int> getNum(string &s, int i)
{
    pair<int, int> ans = {-1, -1};
    int x=0;
    while(x<1000 && isdigit(s[i]))
    {
        x = ((10*x) + (s[i]-'0'));
        i++;
    }
    if(s[i]==',')
    {
        ans.first = x;
    }
    x=0;i++;
    
    while(x<1000 && isdigit(s[i]))
    {
        x = ((x*10) + (s[i]-'0'));
        i++;
    }
    if(s[i]==')')
    {
        ans.second = x;
    }
    
    return ans;
}
int main()
{
    string s="";
    char c;
    // cin>>s;
    while(scanf("%c", &c) != EOF)
    {
        s += c; 
    }
    int ans = 0;
    s+="######################################";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'm')
        {
            if(s[i+1] == 'u' && s[i+2] == 'l' && s[i+3]=='(')
            {
                pair<int, int> nums = getNum(s, i+4);
                if(nums.first != -1 && nums.second != -1)
                {
                    // cout<<nums.first<<" "<<nums.second<<endl;
                    ans += (nums.first * nums.second);
                }
                
            }
        }
    }
    
    // cout<<s<<endl;
    cout<<ans<<endl;

    return 0;
}
