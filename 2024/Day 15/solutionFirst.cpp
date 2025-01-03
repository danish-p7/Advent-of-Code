#include <bits/stdc++.h>

using namespace std;

pair<int, int> getDir(char c)
{
	pair<int, int> ans;
	if(c == '^')
	{
		ans = {-1, 0};
	}
	else if(c == 'v')
	{
		ans = {1, 0};
	}
	else if(c == '<')
	{
		ans = {0, -1};
	}
	else
	{
		ans = {0, 1};
	}

	return ans;
}

int main()
{
	vector<string> grid;
	string text;
	string moves;
	bool cellReached=false;
	while(getline(cin, text))
	{
		if(text == "") 
		{
			cellReached = true;
			continue;
		}
		if(!cellReached)grid.push_back(text);
		else moves+=text;
	}

	pair<int, int> curr = {-1, -1};

	for(int i=0; i<50; i++)
	{
		for(int j=0; j<50; j++)
		{
			if(grid[i][j] == '@')
			{
				curr = {i, j};
				break;
			}
		}
		if(curr.first!=-1)break;
	}

	for(auto move : moves)
	{
		pair<int, int> dir = getDir(move);
		int r = curr.first;
		int c = curr.second;
		vector<pair<int, int>> boxes;
		bool space = false;
		while(true)
		{
			r += dir.first;
			c += dir.second;

			if(grid[r][c] == '#')break;
			else if(grid[r][c] == '.')
			{
				space = true;
				break;
			}
			else
			{
				boxes.push_back({r, c});
			}
		}

		if(!space)continue;

		r += dir.first;
		c += dir.second;

		for(auto &x : boxes)
		{
			grid[x.first][x.second] = '.';
		}
		for(auto &x : boxes)
		{
			grid[x.first+dir.first][x.second+dir.second] = 'O';
		}
	}

	long long ans = 0;
	for(int i=0; i<50; i++)
	{
		for(int j=0; j<50; j++)
		{
			if(grid[i][j] == 'O')ans += (i * 100 + j);
		}
	}

	cout<<ans;

	return 0;
}
