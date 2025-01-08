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

int main()
{
	string text;
	int i=0;
	vector<vector<int>> grid(71, vector<int>(71, 0));
	while(getline(cin, text) && i<1024)
	{
		int x = stoi(text);
		string s = text.substr(text.find(',') + 1);
		int y = stoi(s);

		// cout<<x<<" "<<y<<endl;
		grid[x][y] = 1;
		i++;
	}

	// for(int i=0; i<71; i++)
	// {
	// 	for(int j=0; j<71; j++)
	// 	{
	// 		cout<<grid[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {0, 0}});
	vector<vector<int>> dist(71, vector<int>(71, INT_MAX));
	dist[0][0]=0;
	while(!pq.empty())
	{
		int dis = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		// cout<<dis<<x<<y<<endl;
		pq.pop();
		// vis[x][y] = true;

		for(auto it : vector<vector<int>>{{0, 1}, {1, 0}, {-1, 0}, {0, -1}})
		{
			// cout<<it[0]<<" "<<it[1]<<endl;
			int nx = x + it[0];
			int ny = y + it[1];
			
			if(nx<0 || nx>=71 || ny<0 || ny>=71)continue;

			if(grid[nx][ny]!=1)
			{
				if(1 + dis < dist[nx][ny])
				{
					// cout<<dis<<":"<<endl;
					dist[nx][ny] = 1 + dis;
					pq.push({1+dis, {nx, ny}});
				}
			}
		}
	}

	cout<<dist[70][70]<<endl;


	return 0;
}
