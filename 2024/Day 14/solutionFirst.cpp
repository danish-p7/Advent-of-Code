#include <bits/stdc++.h>

using namespace std;

int main()
{
	// p=69,11 v=-25,6
	const int X = 101, Y=103;
	int px, py, vx, vy;
	string text;
	vector<vector<int>> quad(2, vector<int>(2, 0));


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

		if(px != X/2 && py != Y/2)
		{
			quad[px>X/2][py>Y/2]++;
		}

	}

	long long ans = 1ll*quad[0][0]*quad[0][1]*quad[1][0]*quad[1][1];
	cout<<ans<<endl;

	return 0;
}
