#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

int n, m, U[N], V[N], S[2 * N], ans[N];
map< pii, int > P;

int Find(int i, int t){
  int j = P.lower_bound(MP(i, t))->second;
  if(j == i)
    return i;
  else
    return Find(j, t);
}

void Union(int i, int j, int t){
  i = Find(i, t), j = Find(j, t);
  if(i == j)
    return ;
  if(S[i] < S[j])
    swap(i, j);
  S[i] += S[j];
  P[MP(j, t)] = i;
}

int BinarySearch(int i, int j, int k){
  int x = k, y = m + 1, z = -1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Find(i, mid) == Find(j, mid))
      z = mid, x = mid + 1;
    else
      z = mid - 1;
  }
  return z;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    n = 0;
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
      scanf("%d%d", &U[i], &V[i]);
      n = max(n, max(U[i], V[i]));
    }

    for(int i = 0; i <= m; ++i){
      P.clear();
      for(int x = 1; x <= n; ++x){
        P[MP(x, m + 1)] = x;
        S[x] = 1;
      }

      for(int j = 1; j < i; ++j)
        Union(U[j], V[j], m + 1);

      for(int j = m; j >= i; --j)
        Union(U[j], V[j], j);

      for(int x = i; x <= m; ++x){
        int k = BinarySearch(U[k], V[k], x + 1);
        ans[x] += max(0, )
      }
    }
  }

  return 0;
}
