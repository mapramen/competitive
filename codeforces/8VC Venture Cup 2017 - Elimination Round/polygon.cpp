#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> T;

void BITUpdate(int i, int x){
  for( ; i < T.size(); i += (i&-i))
    T[i] += x;
}

int BITQuery(int i){
  int ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

int Query(int i, int k, int n){
  int j = i + k, ans = 0;
  if(j > n)
    j -= n;

  ans = BITQuery(j - 1) - BITQuery(i);

  if(j < i)
    ans += BITQuery(n);

  return ans;
}

int main(){
  int n, k;
  ll ans = 1;

  scanf("%d%d", &n, &k);
  T.resize(n + 1);

  k = min(k, n - k);

  for(int x = 1, i = 1; x <= n; x++){
    ans += (1 + Query(i, k, n));
    int j = i + k;
    if(j > n) j -= n;
    BITUpdate(i, 1);
    BITUpdate(j, 1);
    i = j;
    printf("%lld ", ans);
  }

  printf("\n");

  return 0;
}
