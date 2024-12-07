// <Header Files>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<cstdio>
#include<complex>
#include<cmath>
#include<cstring>
#include<chrono>
#include<string>
//#include<bignum.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// <\Header Files>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<ll>
#define vb vector<bool>
#define all(a) a.begin(), a.end()
#define ln '\n'
#define ACCELERATE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<setprecision(10);
//cout<<"Case #"<<ttt<<": "<<ans<<ln;

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

//const ll MOD=(ll)(1e9)+7ll;

const ll MOD = 998244353;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
bool isPowerofTwo(long long n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}
int get_bit_count(int n) {return __builtin_popcountll(n);}
int get_first_bit(long long n) {return 63 - __builtin_clzll(n);}
int turnOffK(int n, int k)
{
    if (k <= 0) return n;
    return (n & ~(1 << (k - 1)));
}
int pow(int a, int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a);
        b/=2;
        a=(a*a);
    }
    return ans;
}
ll power(ll x,ll n)
{
    if(n==0)       return 1;
    else if(n==1)  return x;
    else if(n%2)   return (x*power((x*x)%MOD,n/2))%MOD;
    else           return (power((x*x)%MOD,n/2));
}
ll power1(ll x, ll y, ll m = MOD)
{
    if (y == 0) return 1;
    ll p = power1(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}
vector<ll> primeFactors(ll n)
{
    vector<ll> v;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
//        cout << 2 << " ";
        v.push_back(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            v.push_back(i);
//            cout << i << " ";
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        v.push_back(n);
//        cout << n << " ";

    return v;
}
vector <ll> factors(ll x) {
    // We will store all factors in `result`
    vector <ll> result;
    ll i = 1;
    // This will loop from 1 to int(sqrt(x))
    while(i*i <= x) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            result.push_back(i);
            // Handle the case explained in the 4th
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }

    return result;
}

//par.resize(V);
//for(int i = 0; i<V; i++)
//par[i] = i;
//rank.resize(V, 0);
int findParent(int node, vector<int> &par)
{
    if(par[node]==node)return node;
    return par[node]=findParent(par[node], par);
}

void union_dsu( int a, int b, vector<int> &par, vector<int> &rank)
{
    a=findParent(a, par);
    b=findParent(b, par);
    if(rank[a]<rank[b])
    {
        par[a]=b;
    }
    else if(rank[b]<rank[a])
    {
        par[b]=a;
    }
    else
    {
        par[a]=b;
        rank[b]++;
    }
}

bool isConnected(int x,int y, vector<int> &par, vector<int> &rank)
{
    return findParent(x, par)==findParent(y, par);
}

// * PROGRAM BEGINS *........................................................................................................................................................................................................./

bool trueEquations(vector<ll> v, ll i, ll actual, ll calc)
{
    if(i>=v.size())
    {
//        cout<<calc<<endl;
        if(calc == actual)return true;
        return false;
    }

    long long concat;
    string a = to_string(calc);
    string b = to_string(v[i]);
    concat = stoll(a+b);


    return (trueEquations(v, i+1, actual, v[i]+calc) || trueEquations(v, i+1, actual, v[i]*calc) || trueEquations(v, i+1, actual, concat));
}

void Solution(int ttt)
{
    vector<string> v(850);
    for(int i=0; i<850; i++)
    {
        getline(cin, v[i]);
    }

//    for(auto &x : v)cout<<x<<endl;
    ll ans=0;
    for(int i=0; i<850; i++)
    {
        ll actual = 0;
        int j=0;
        string s="";
        for(j=0; j<v[i].size() && v[i][j] != ':'; j++)
        {
            actual = actual*10 + (v[i][j]-'0');
        }
//        cout<<actual<<endl;

        vector<ll> nums;
        j++;
        s="";

        ll num = 0;
        vector<ll> v1;
        for(int k = j; k < v[i].size(); ++k)
            if(v[i][k] == ' ')
            {
                if(num>0)v1.push_back(num);
                num = 0;
            }

            else
                num = num*10 + (v[i][k]-'0');
        if(num>0)v1.push_back(num);

//        for(auto &x: v1)cout<<x<<" ";
//        cout<<endl;


        if(trueEquations(v1, 1, actual, v1[0]))
        {
            ans += actual;
        }


    }

    cout<<ans;

}




signed main()
{
    ACCELERATE;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif


    int tt=1, ttt=0;
//    cin>>tt;

    for(int testCases=0; testCases<tt; testCases++)
    {
        ttt++;
        Solution(ttt);
    }

    return 0;
}
