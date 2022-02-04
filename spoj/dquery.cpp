#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 300001
#define M 1000001

vector<vector<int>> V(N);
int a[N], nxt[N], previousIndex[M], qr[M], ans[M];
int T[N];

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < M; ++x){
    previousIndex[x] = n + 1;
  }

  for(int i = n; i != 0; --i){
    int x = a[i];
    nxt[i] = previousIndex[x];
    previousIndex[x] = i;
  }

  int q;
  scanf("%d", &q);

  vector<tiii> v;
  for(int k = 1; k <= q; ++k){
    int i;
    scanf("%d%d", &i, &qr[k]);
    V[i].push_back(k);
  }

  for(int i = 1; i <= n; ++i){
    if(previousIndex[a[i]] == i){
      Update(i, 1);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int k: V[i]){
      ans[k] = Query(qr[k]);
    }
    Update(i, -1);
    Update(nxt[i], 1);
  }

  for(int k = 1; k <= q; ++k){
    printf("%d\n", ans[k]);
  }

  return 0;
}