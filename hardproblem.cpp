#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char prv[N], prvR[N], curr[N], currR[N];
int c[N];
ll ans, ansR, inf = 1E16;

void CopyString(char *a, char *b){
	int n = strlen(a);

	for(int i = 0; i <= n; i++)
		b[i] = a[i];
}

void PutReverse(char *a, char *b){
	int n = strlen(a);
	int i = 0, j = n - 1;

	b[n] = '\0';

	for(i = 0; i < n; i++, j--)
		b[i] = a[j];
}

int main(){
	int n, i, j, k, x, y, z;
	ll t1, t2, t3, t4;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	scanf("%s", prv);
	PutReverse(prv, prvR);
	ans = 0;
	ansR = c[1];

	for(k = 2; k <= n; k++){
		scanf("%s", curr);
		PutReverse(curr, currR);

		// cout << prv << ' ' << prvR << ' ' << curr << ' ' << currR << '\n';

		t1 = t2 = t3 = t4 = inf;

		if(strcmp(curr,prv) >= 0)
			t1 = ans;

		if(strcmp(curr,prvR) >= 0)
			t2 = ansR;

		if(strcmp(currR, prv) >= 0)
			t3 = ans + c[k];

		if(strcmp(currR, prvR) >= 0)
			t4 = ansR + c[k];

		// cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << '\n';

		ans = min(t1, t2);
		ansR = min(t3, t4);

		CopyString(curr, prv);
		CopyString(currR, prvR);
	}

	ans = min(ans, ansR);

	if(ans >= inf)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
