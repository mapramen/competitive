#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int no_adapters[N], socket_no[N];
pii socket_powers[N], computer_powers[N];

int main(){
	int n, m, i, j, k, ans_c, ans_u, no_zeros, no_adapter;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
		scanf("%d", &computer_powers[i].first);

	for(i = 1; i <= m; i++)
		scanf("%d", &socket_powers[i].first);

	for(i = 1; i <= n; i++)
		computer_powers[i].second = i;

	for(i = 1; i <= m; i++)
		socket_powers[i].second = i;

	sort(computer_powers + 1, computer_powers + n + 1);
	sort(socket_powers + 1, socket_powers + m + 1);

	for(ans_c = ans_u = no_adapter = no_zeros = 0; no_zeros < m; no_adapter++){
		for(i = j = 1; i <= m; i++){
			if(socket_powers[i].first == 0)
				continue;

			for( ; j <= n && computer_powers[j].first < socket_powers[i].first; j++);

			if(j <= n && computer_powers[j].first == socket_powers[i].first){
				ans_c++;
				ans_u += no_adapter;
				no_adapters[socket_powers[i].second] = no_adapter;
				socket_no[computer_powers[j].second] = socket_powers[i].second;
				computer_powers[j].first = 0;
				socket_powers[i].first = 0;
			}
			else
				if(socket_powers[i].first == 1)
					socket_powers[i].first = 0;
				else
					socket_powers[i].first = (socket_powers[i].first + 1) / 2;

			no_zeros += (socket_powers[i].first == 0);
		}
	}

	printf("%d %d\n", ans_c, ans_u);

	for(i = 1; i <= m; i++)
		printf("%d ", no_adapters[i]);
	printf("\n");

	for(i = 1; i <= n; i++)
		printf("%d ", socket_no[i]);
	printf("\n");

	return 0;
}
