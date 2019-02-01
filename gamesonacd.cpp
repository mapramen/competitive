#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000010
#define M 26

char a[2 * N], b[N];
int A[2 * N], B[2 * N], cnt[N / 10];

//-------------------- Aho-Corasick Automation --------------------//
int tr[2 * N][M], au[2 * N][M], f[2 * N], nx = 1;

void Add_String(char *s, int x){
	int i, j, k;

	for(k = 0, i = 0; s[i] != '\0'; i++){
		j = s[i] - 'a';

		if(tr[k][j] == 0)
			tr[k][j] = nx++;

		k = tr[k][j];
	}

	B[k] = x;
}

void Compute_Failure(){
	queue<int> q;

	q.push(0);

	while(!q.empty()){
		int v = q.front();
		q.pop();
		
		for(int i = 0; i < M; i++){
			int u = tr[v][i];
			if(u){
				au[v][i] = u;
				if(v)
					f[u] = au[f[v]][i];
				q.push(u);
			}
			else
				au[v][i] = au[f[v]][i];
		}
	}
}
//-------------------- Aho-Corasick Automation Ends --------------------//

int main(){
	int n, i, j, k, m, g, x, y;

	scanf("%d%d", &n, &k);

	scanf("%s", a);

	scanf("%d", &g);

	for(i = 1; i <= g; i++){
		scanf("%s", b);
		Add_String(b, i);
	}

	Compute_Failure();

	n = n * k;

	for(i = n, j = 2 * n; i > -1; i--, j--)
		a[j] = a[i];

	for(i = 0, x = 0; a[i] != '\0'; i++){
		y = a[i] - 'a';
		x = au[x][y];
		A[i + 1] = B[x];
	}

	for(m = 0; m < k; m++){
		memset(cnt, 0, 4 * (g + 1));
		int distinct_game_length = 0;

		for(i = m, j = i + k; j <= 2 * n; j += k){
			if(A[j] != 0){
				cnt[A[j]]++;
				distinct_game_length += ((cnt[A[j]] == 1) * k);
			}

			if(j - i > n){
			 	if(A[i] != 0){
					cnt[A[i]]--;
					distinct_game_length -= ((cnt[A[i]] == 0) * k);
				}

				i += k;
			}

			if((j - i) == n && distinct_game_length == n)
				break;
		}

		if(j <= 2 * n)
			break;
	}

	if(m == k)
		printf("NO\n");
	else{
		printf("YES\n");
		for(i += k ; i <= j; i += k)
			printf("%d ", A[i]);
		printf("\n");
	}

	return 0;
}
