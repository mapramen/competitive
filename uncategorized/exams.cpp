#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n, m, a[N], d[N];
bool done[N];

bool Check(int mid){
	for(int i = 1; i <= m; i++)
		done[i] = 0;

	int exams_done = 0;
	ll free_days = 0;

	for(int i = mid; i > 0; i--){
		if(d[i] == 0 || done[d[i]] == 1)
			if(free_days < 0)
				free_days++;
			else
				free_days = 0;
		else{
			done[d[i]] = 1;
			free_days -= a[d[i]];
			exams_done++;
		}
	}

	return (exams_done == m && free_days >= 0);
}

int BinarySearch(){
	int x = 1, y = n, z = -1, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(Check(mid)){
			z = mid;
			y = mid - 1;
		}
		else
			x = mid + 1;
	}

	return z;
}

int main(){
	int i, ans;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
		scanf("%d", &d[i]);

	for(i = 1; i <= m; i++)
		scanf("%d", &a[i]);

	printf("%d\n", BinarySearch());

	return 0;
}
