#include <bits/stdc++.h>

using namespace std;

int main()
{
	// p=69,11 v=-25,6
	const int X = 101, Y=103;
	int px, py, vx, vy;
	string text;
	vector<vector<int>> quad(2, vector<int>(2, 0));
	vector<vector<int>> v;


	while(getline(cin, text))
	{
		px = stoi(text.substr(text.find('=')+1));
		py = stoi(text.substr(text.find(',')+1));

		int n1=0, n2=0;
		string text2 = text.substr(text.find('v'));
		vx = stoi(text2.substr(text2.find('=')+1));
		vy = stoi(text2.substr(text2.find(',')+1));

		// cout<<px<<" "<<py<<" "<<vx<<" "<<vy<<endl;

		px = ((px + vx*100) % X + X) % X;
		py = ((py + vy*100) % Y + Y) % Y;

		v.push_back({px, py, vx, vy});

		if(px != X/2 && py != Y/2)
		{
			quad[px>X/2][py>Y/2]++;
		}

	}

	for(int i=0; i<10000; i++)
	{

		cout<<i<<endl;
		vector<vector<int>> grid(X, vector<int>(Y, 0));
		for(auto &x : v)
		{
			int npx = ((x[0] + x[2]*i) % X + X) % X;
			int npy = ((x[1] + x[3]*i) % Y + Y) % Y;
			grid[npx][npy] = 1;

		}

		for(auto &x : grid)
		{
			for(auto &y : x)
			{
				cout<<y;
			}
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}
