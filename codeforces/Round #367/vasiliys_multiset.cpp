#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 30

int T[N*B][2], cnt[N*B][2], nxt = 1;

void Update(int i, int x){
	int j, k, y;
	for(j = B - 1, y = 0; j > -1; j--){
		k = i & (1 << j);
		k = (k > 0);

		if(T[y][k] == 0)
			T[y][k] = nxt++;

		cnt[y][k] += x;
		y = T[y][k];
	}
}

int Query(int x){
	int i, j, k, y, ans = 0;

	for(j = B - 1, i = 0; j > -1; j--){
		k = x & (1 << j);
		k = (k > 0);

		if(cnt[i][1 - k]){
			ans |= (1 << j);
			i = T[i][1 - k];
		}
		else
			i = T[i][k];
	}

	return ans;
}

int main(){
	int q, i, j, k;
	char s[2];

	scanf("%d", &q);

	Update(0,1);

	while(q--){
		scanf("%s", s);
		scanf("%d", &k);

		if(s[0] == '+')
			Update(k,1);

		if(s[0] == '-')
			Update(k,-1);

		if(s[0] == '?')
			printf("%d\n", Query(k));
	}

	return 0;
}
