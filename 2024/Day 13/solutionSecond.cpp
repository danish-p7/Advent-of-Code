#include <bits/stdc++.h>

using namespace std;

int main()
{

	string text;

	long long result1 = 0;
	double result2 = 0;
	
	while (getline(cin, text)) 
	{
		long long x1 = stoi(text.substr(text.find('+')+1));
		long long y1 = stoi(text.substr(text.find(',')+3));
		getline(cin, text);
		long long x2 = stoi(text.substr(text.find('+')));
		long long y2 = stoi(text.substr(text.find(',') + 3));
		

		getline(cin, text);
		long long x3 = stoi(text.substr(text.find("=")+1));
		long long y3 = stoi(text.substr(text.find(",")+4));

		;

		x3+=10000000000000;
		y3+=10000000000000;
		

		getline(cin, text);

		long long denominator = (x1 * y2 - y1 * x2);
        long long a = (x3 * y2 - y3 * x2) / denominator;
        long long b = (y3 * x1 - x3 * y1) / denominator;


        if (a * denominator == (x3 * y2 - y3 * x2) && b * denominator == (y3 * x1 - x3 * y1)) 
        {
            result1 += (3 * a + b);
        }
		
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
	}

	cout<<result1<<endl;



	return 0;
}
