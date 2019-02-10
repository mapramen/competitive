#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26

char s[N];
int a[N], cnt[N];
bool v[N + 1];

int main(){
	int m, n, i, j, k, x, y, z, total = 0;

	scanf("%d", &m);
	scanf("%s", s);

	n = strlen(s);

	for(i = 0; i < n; i++)
		a[i + 1] = s[i] - 'a';

	for(i = 0; i < B; i++){
		for(j = 1; j <= n; j++)
			v[j] = (a[j] < i);

		v[n + 1] = 1;

		for(x = j = n + 1; x > 0 && x + m >= j; x--){
			if(v[x] == 1)
				y = j = x;
			else{
				if(a[x] == i)
					y = x;

				if(x + m == j)
					if(y != j){
						v[y] = 1;
						x = y + 1;
					}
					else
						break;
			}
		}

		if(x <= 0)
			break;
	}

	for(i = 1; i <= n; i++){
		if(v[i] == 0)
			continue;

		cnt[a[i]]++;
	}

	for(i = 0; i < B; i++)
		while(cnt[i]--)
			putchar('a' + i);
	printf("\n");

	return 0;
}
