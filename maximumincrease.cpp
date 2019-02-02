#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, i, j, l, ans = 0;

	l = j = 0;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);

		if(i > j)
			l++;
		else
			l = 1;

		ans = max(l, ans);
		j = i;
	}

	printf("%d\n", ans);

	return 0;
}
