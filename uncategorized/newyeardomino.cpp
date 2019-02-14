#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

typedef struct node
{
	int l;
	int r;
	int leftEnd;
	int rightEnd;
	int ansx;
}node;

int p[N], h[N];
vector< node > T;

void BuildSegmentTree(int n){
	int B, i, j, x, y;

	for(B = 1; B < n; B = (B << 1));

	T.resize(2*B - 1);

	for(i = B, j = 1; j <= n; i++, j++){
		T[i].l = T[i].r = j;
		T[i].leftEnd = p[j];
		T[i].rightEnd = p[j] + h[j];
		T[i].ansx = 0;
	}

	for( ; i < 2*B; i++, j++){
		T[i].l = T[i].r = j;
		T[i].leftEnd = T[i].rightEnd = T[i].ansx = 0;
	}

	for(i = B - 1; i > 0; i--){
		x = 2*i;
		y = x + 1;
		T[i].l = T[x].l;
		T[i].r = T[y].r;
		T[i].leftEnd = T[x].leftEnd;
		T[i].rightEnd = max(T[x].rightEnd, T[x].rightEnd);
		
	}
}

int main(){
	int n, m, i, j, k, q, x, l, r;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d%d", &p[i], &h[i]);

	BuildSegmentTree(n);

	scanf("%d", &q);

	while(q--){
		scanf("%d%d", &i, &j);
		printf("%d\n", Query(i,j).second);
	}

	return 0;
}
