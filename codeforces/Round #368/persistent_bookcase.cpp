#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 100001

vector< vector<int> > adj(M);
piii query[M];
bool a[N][N], b[N];
int n, m, totalBooks = 0, books[N], ans[M];

int AddBook(int i, int j){
	if((b[i] ^ a[i][j]) == 0){
		a[i][j] = 1 - a[i][j];
		books[i]++;
		totalBooks++;

		return 1;
	}

	return 0;
}

int RemoveBook(int i, int j){
	if(b[i] ^ a[i][j]){
		a[i][j] = 1 - a[i][j];
		books[i]--;
		totalBooks--;

		return 2;
	}

	return 0;
}

int InvertShelf(int i){
	b[i] = 1 - b[i];
	totalBooks += (m - 2 * books[i]);
	books[i] = m - books[i];

	return 3;
}

void DFS(int i){
	int q = query[i].first;
	int x = query[i].second.first;
	int y = query[i].second.second;

	if(q != 0){
		if(q == 1)
			q = AddBook(x,y);
		else if(q == 2)
			q = RemoveBook(x,y);
		else if(q == 3)
			q = InvertShelf(x);
		else;
	}

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		DFS(k);
	}

	ans[i] = totalBooks;

	if(q != 0){
		if(q == 1)
			RemoveBook(x,y);
		else if(q == 2)
			AddBook(x,y);
		else if(q == 3)
			InvertShelf(x);
		else;
	}
}

int main(){
	int i, j, k, q, x, t;

	scanf("%d%d%d", &n, &m, &q);

	for(x = 1; x <= q; x++){
		scanf("%d", &t);
		scanf("%d", &i);

		if(t < 3)
			scanf("%d", &j);
		else
			j = 0;

		query[x] = MP(t, MP(i,j));

		if(t < 4)
			adj[x - 1].PB(x);
		else
			adj[i].PB(x);
	}

	DFS(0);

	for(i = 1; i <= q; i++)
		printf("%d\n", ans[i]);

	return 0;
}