#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N], b[N];
bool visited[N];

int main(){
	int n, i, j, k, ans = 0;
	vector< pii > v;

	scanf("%d", &n);

	for(i = n; i > 0; i--)
		scanf("%d%d", &a[i], &b[i]);

	v.PB(MP(0,0));

	for(i = 1; i <= n; i++){
		b[i] += a[i];
		v.PB(MP(a[i], i));
	}

	sort(v.begin(), v.end());

	for(i = 1; 2 * i <= n; i++)
		swap(v[i], v[n - i + 1]);

	k = 1;

	while(1){
		for(i = n; i > 0; i--){
			int x = v[i].second;

			if(visited[x] == 1)
				continue;

			int s = 0;

			for(j = i - 1; j > 0; j--){
				int y = v[j].second;

				if(MP(b[y], y) < MP(a[x], x)){
					s--;

					if(MP(b[x], x) < MP(b[y], y))
						s--;
				}
				
				if(MP(a[y], y) < MP(b[x], x)){
					s++;

					if(MP(b[x], x) < MP(b[y], y))
						s++;
				}
			}

			if(s >= 0){
				a[x] = v[i].first = b[x];
				visited[x] = 1;
				break;
			}
		}

		if(i == 0)
			break;

		for( ; i > 1 && v[i] > v[i - 1]; i--, ans++)
			swap(v[i], v[i - 1]);

		for( ; i < n && v[i] < v[i + 1]; i++, ans++)
			swap(v[i], v[i + 1]);

		k++;
	}


	printf("%d\n", ans);

	return 0;
}
