// Question Link: https://adventofcode.com/2024/day/17#part2

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
#include<limits.h>

using namespace std;

int ra, rb, rc;
int combo(int x)
{
	if(x==4)return ra;
	if(x==5)return rb;
	if(x==6)return rc;

	return x;
}

int main()
{
	int rptr = 0;
	
	vector<int> v;
	string text;
	while(getline(cin, text))
	{
		if(rptr==0)ra = stoi(text.substr(text.find(':') + 2));
		if(rptr==1)rb = stoi(text.substr(text.find(':') + 2));
		if(rptr==2)rc = stoi(text.substr(text.find(':') + 2));
		if(rptr==4)
		{
			// string s2 = text.substr(text.find(':' + 1));
			for(int i=9; i<text.size(); i+=2)
			{
				v.push_back(text[i]-'0');
			}
		}
		rptr++;
	}

	cout<<ra<<" "<<rb<<" "<<rc<<endl;
	for(auto x : v)cout<<x<<" ";
	cout<<endl;

	// vector<pair<int, int>> vec;
	// for(int i=0; i<v.size()-1; i+=2)
	// {
	// 	vec.push_back({v[i], v[i+1]});
	// }

	// vector<int> ans;
	int i=0, n=v.size();
	while(i<n)
	{
		int x = v[i], y = v[i+1];
		switch(x)
		{
			case 0:
				ra>>=combo(y);
				break;
			case 1:
				rb^=y;
				break;
			case 2:
				rb = combo(y)%8;
				break;
			case 3:
				if(ra!=0)i=y-2;
				break;
			case 4:
				rb^=rc; 
				break;
			case 5: 
				cout<<(combo(y)%8)<<",";
				break;
			case 6: 
				rb = ra >> combo(y);
				break;
			case 7: 
				rc = ra >> combo(y);
				break; 
		}

		i+=2;
	}
	

	return 0;
}
