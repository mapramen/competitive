#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define BASE 10
#define LENGTH 60

ll C[LENGTH + 1][LENGTH + 1], A[BASE + 1][LENGTH + 1], B[BASE + 1][LENGTH + 1][BASE + 1], D[BASE + 1], oddCount;

void Initialise(){
  for(int i = 0; i <= LENGTH; ++i){
    C[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }

  A[0][0] = 1;
  for(int i = 1; i <= BASE; ++i)
    for(int j = 0; j <= LENGTH; ++j)
      for(int x = 2; x <= j; x += 2)
        A[i][j] += C[j][x] * A[i - 1][j - x];

  for(int i = 0; i <= BASE; ++i){
    for(int j = 0; j <= LENGTH; ++j){
      for(int k = 0; k <= i && k <= j; ++k)
        B[i][j][0] += (C[i][k] * A[k][j]);

      for(int k = 1; k <= i; ++k)
        for(int x = 1; x <= j; x += 2)
          B[i][j][k] += C[j][x] * B[i - 1][j - x][k - 1];
    }
  }
}

void ResetDigitCount(){
  for(int i = 0; i <= BASE; ++i)
    D[i] = 0;
  oddCount = 0;
}

void UpdateDigitCount(int i, int x){
  D[i] += x;
  if(D[i] % 2 == 1)
    oddCount++;
  else
    oddCount--;
}

ll Query(ll b, ll n){
  ll ans = 0;
  vector<int> v, c;

  for(ll _n = n; _n > 0; _n /= b)
    v.PB(_n % b);

  if(v.size() == 0)
    v.PB(0);

  reverse(v.begin(), v.end());
  c.resize(b);
  ResetDigitCount();

  for(int l = 1; l < v.size(); ++l)
    ans += (b - 1) * B[b][l - 1][1];

  for(int i = 0, l = v.size(); i < v.size(); ++i, --l){
    for(int j = (i == 0); j < v[i]; ++j){
      UpdateDigitCount(j, 1);
      ans += B[b][l - 1][oddCount];
      UpdateDigitCount(j, -1);
    }
    UpdateDigitCount(v[i], 1);
  }

  ans += (oddCount == 0);

  return ans;
}

ll Query(ll b, ll l, ll r){
  return Query(b, r) - Query(b, l - 1);
}

int main(){
  Initialise();

  int q;
  scanf("%d", &q);
  while(q--){
    ll b, l, r;
    scanf("%lld%lld%lld", &b, &l, &r);
    printf("%lld\n", Query(b, l, r));
  }

  return 0;
}
