#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

char s[N][6];

int main(){
	int n, m, i, j, k;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%s", s[i]);

	for(i = 1; i <= n; i++){
		for(j = 0; j < 4; j += 3){
			if(s[i][j] == 'O' && s[i][j + 1] == 'O'){
				s[i][j] = s[i][j + 1] = '+';
				break;
			}
		}

		if(j < 4)
			break;
	}

	if(i <= n){
		printf("YES\n");

		for(i = 1; i <= n; i++)
			printf("%s\n", s[i]);
	}
	else
		printf("NO\n");

	return 0;
}
