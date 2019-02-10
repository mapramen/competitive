#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3
#define M 101

int A[N][N], B[N][N], D[N][N], pa[M], pb[M];

int main(){
  ll k, a, b;

  cin >> k >> a >> b;

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j){
      cin >> A[i][j];
      A[i][j]--;
    }

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j){
      cin >> B[i][j];
      B[i][j]--;
    }

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      D[i][j] = -1;

  a--, b--;
  ll c = 1, ca = 0, cb = 0, i, j;
  for(i = a, j = b; D[i][j] == -1; ++c){
    D[i][j] = c;
    ca += ((i - j == 1) || (j - i == 2));
    cb += ((j - i == 1) || (i - j == 2));
    pa[c] = ca;
    pb[c] = cb;
    int ix = A[i][j], jx = B[i][j];
    i = ix, j = jx;
  }

  ll k1 = D[i][j], k2 = c, m = k2 - k1;
  ca -= pa[k1 - 1], cb -= pb[k1 - 1];

  ll l = max(0ll, (k - k1) / m);
  ll ansa = l * ca, ansb = l * cb;

  k -= l * m;

  for(i = a, j = b; k > 0; --k){
    ansa += ((i - j == 1) || (j - i == 2));
    ansb += ((j - i == 1) || (i - j == 2));
    int ix = A[i][j], jx = B[i][j];
    i = ix, j = jx;
  }

  cout << ansa << ' ' << ansb << '\n';

  return 0;
}
