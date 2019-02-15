#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 19

char s[2*N], t[N];
int M, lcp[2*N], stringPosition[N], SAPosition[N], stringNo[2*N], c[2*N], temp[2*N], b[(5 * N) / 2], length[N];
vector< vector<int> > positions(N);
vector< vector< pair< pii, pii > > > queries(N + 1);

//-------------------------------------------- Suffix Array --------------------------------------------//
int SATable[LOGN][4*N], SArray[2*N];
piii L[2*N];

void BuildSuffixArray(int n){
	M = -1;

	for(int i = 1; i <= n; M++, i = (i << 1));

	for(int i = 1; i <= n; i++)
		SATable[0][i] = s[i - 1] - 'a' + 1;

	for(int k = 1; k <= M; k++){
		for(int i = 1; i <= n; i++)
			L[i].first.first = SATable[k - 1][i], L[i].first.second = SATable[k - 1][i + (1 << (k - 1))], L[i].second = i;

		sort(L + 1, L + n + 1);

		for(int i = 1; i <= n; i++)
			SATable[k][L[i].second] = L[i].first == L[i - 1].first ? SATable[k][L[i - 1].second] : i;
	}

	for(int i = 1; i <= n; i++)
		SArray[SATable[M][i]] = i;
}

int LCP(int i, int j, int n){
	int ans = 0, k;

	if(i == j)
		return n - i + 1;
	else
		for(k = M; k >= 0 && i <= n && j <= n; k--)
			if(SATable[k][i] == SATable[k][j])
				ans += (1 << k), i += (1 << k), j += (1 << k);

	return ans;
}
//-------------------------------------------- Suffix Array Ends --------------------------------------------//

//-------------------------------------------- RMQ Sparse Table --------------------------------------------//
int T[LOGN][4*N], lg[2*N];

void BuildSparseTable(int n){
	for(int i = 1; i <= n; i++)
		T[0][i] = lcp[i];

	for(int i = 2; i <= n; i++)
		lg[i] = 1 + lg[i / 2];

	M = -1;

	for(int i = 1; i <= n; M++, i = (i << 1));

	for(int k = 1; k <= M; k++)
		for(int i = 1; i <= n - (1 << k) + 1; i++)
			T[k][i] = min(T[k - 1][i], T[k - 1][i + (1 << (k - 1))]);
}

int RMQ(int i, int j){
	if(i > j)
		swap(i,j);

	int k = lg[j - i + 1];
	j = j - (1 << k) + 1;

	return min(T[k][i], T[k][j]);
}
//-------------------------------------------- RMQ Sparse Table Ends--------------------------------------------//

//-------------------------------------------- BIT --------------------------------------------//
void BITUpdate(int i, int n, int x){
	for( ; i <= n; i += (i&-i))
		c[i] += x;
}

int BITQuery(int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans += c[i];

	return ans;
}
//-------------------------------------------- BIT Ends --------------------------------------------//

void BuildConsecutiveLCP(int n){
	for(int i = 1; i < n; i++)
		lcp[i] = LCP(SArray[i], SArray[i + 1], n);
}

int BinarySearchLeftEnd(int i, int len){
	int x = 1, y = i - 1, z = i, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(RMQ(mid,i - 1) >= len){
			z = mid;
			y = mid - 1;
		}
		else
			x = mid + 1;
	}

	return z;
}

int BinarySearchRightEnd(int i, int len, int n){
	int x = i, y = n, z = i, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(RMQ(i,mid) >= len){
			z = mid + 1;
			x = mid + 1;
		}
		else
			y = mid - 1;
	}

	return z;
}

int main(){
	int n, q, m, i, j, k, x, y, z, l, r;

	scanf("%d%d", &n, &q);

	for(k = 1, x = 0; k <= n; k++, x++){
		stringPosition[k] = x + 1;
		scanf("%s", t);

		for(i = 0; t[i] != '\0'; i++, x++){
			s[x] = t[i];
			temp[x + 1] = k;
		}

		length[k] = i;
		s[x] = 'a' - 1;
	}

	s[x] = '\0';
	m = x;
	// printf("%d\n", m);

	// printf("%s\n", s);

	BuildSuffixArray(m);
	BuildConsecutiveLCP(m);
	BuildSparseTable(m);

	SArray[1] = m;

	// for(i = 1; i <= m; i++)
	// 	printf("%d %s %d\n", i, s + SArray[i] - 1, lcp[i]);

	for(i = 1; i <= m; i++){
		stringNo[i] = temp[SArray[i]];
		positions[stringNo[i]].PB(i);
	}

	for(i = 1; i <= m; i++)
		temp[SArray[i]] = i;

	for(i = 1; i <= n; i++){
		SAPosition[i] = temp[stringPosition[i]];
		// printf("%d %d\n", i, SAPosition[i]);
	}

	for(x = 1; x <= q; x++){
		scanf("%d%d%d", &i, &j, &k);
		l = BinarySearchLeftEnd(SAPosition[k], length[k]);
		r = BinarySearchRightEnd(SAPosition[k], length[k], m);
		// printf("%d %d %d\n", k, l, r);
		queries[i].PB(MP(MP(l,r),MP(x,1)));
		queries[j + 1].PB(MP(MP(l,r),MP(x,-1)));
	}

	for(i = 1; i <= m; i++)
		if(stringNo[i] != 0)
			BITUpdate(i,m,1);

	for(x = 1; x <= n; x++){
		for(y = 0; y < queries[x].size(); y++){
			i = queries[x][y].first.first;
			j = queries[x][y].first.second;
			k = queries[x][y].second.first;
			z = queries[x][y].second.second;

			b[k] += (z * (BITQuery(j) - BITQuery(i - 1)));
		}

		for(y = 0; y < positions[x].size(); y++){
			z = positions[x][y];
			BITUpdate(z,m,-1);
		}
	}

	for(i = 1; i <= q; i++)
		printf("%d\n", b[i]);

	return 0;
}