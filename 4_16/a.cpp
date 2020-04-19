#include<bits/stdc++.h>

using namespace std;

int c, k;

int main(){
	while(scanf("%d%d", &c, &k)!=EOF)
	{
		int orgi = 0;
		int maxi = 0;
		for(int i = 1; i <= k; ++i)
		{
			int x;
			scanf("%d", &x);
			if(i == 1) orgi = x;
			maxi = max(maxi, x);
		}
		if(orgi == 0)	cout << c << endl;
		else			cout << c*maxi/orgi << endl;
	}
}