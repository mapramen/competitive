#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, m, i, j;
	char s[2];
	bool isColor = 0;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++){
			scanf("%s", s);

			isColor = (isColor || s[0] == 'C' || s[0] == 'M' || s[0] == 'Y');
		}

	if(isColor)
		printf("#Color\n");
	else
		printf("#Black&White\n");

	return 0;
}
