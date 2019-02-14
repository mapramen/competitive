#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, a, k = 0;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &a);

		if(k == 1)
			if(a == 0)
				break;
			else
				k ^= (a & 1);
		else
			k ^= (a & 1);
	}

	if(n > 0 || k != 0)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
