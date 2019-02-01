#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int a[3];

bool Is_Present(int x){
	bool ans = 0;

	for(int i = 0; i < 3; i++)
		ans |= (a[i] == x);

	return ans;
}

int main(){
	int x, y, ans = 0;

	scanf("%d%d", &x, &y);

	a[0] = a[1] = a[2] = y;

	while(1){
		sort(a, a + 3);

		if(a[1] + a[2] > x){
			ans += 3;
			break;
		}

		a[0] = a[1] + a[2] - 1;

		if(a[0] == x){
			ans += 3;
			break;
		}
		else
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
