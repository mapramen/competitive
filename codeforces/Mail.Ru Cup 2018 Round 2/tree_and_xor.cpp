#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define B 61

ll a[N];
int nodeNumber[N], nodeStart[N], nodeEnd[N], leftStart[N], leftEnd[N], rightStart[N], rightEnd[N];

void Initialise(int n){
  sort(a + 1, a + n + 1);

  for(int i = 0; i <= n; ++i){
    nodeStart[i] = 0;
    nodeEnd[i] = -1;
    nodeNumber[i] = 1;
  }

  nodeStart[1] = 1;
  nodeEnd[1] = n;
}

void FixStartEnd(int &i, int &j){
  if(i > j){
    i = 0, j = -1;
  }
}

void FillChildNumbers(int n, int k){
  for(int i = 0; i <= n; ++i){
    int j = nodeStart[i];
    for( ; j <= nodeEnd[i] && (a[j] & (1ll << k)) == 0; ++j);
    leftStart[i] = nodeStart[i], leftEnd[i] = j - 1;
    rightStart[i] = j, rightEnd[i] = nodeEnd[i];
    FixStartEnd(leftStart[i], leftEnd[i]);
    FixStartEnd(rightStart[i], rightEnd[i]);
    j = (nodeStart[i] > 0) ? nodeEnd[i] : i;
    nodeStart[i] = 0;
    nodeEnd[i] = -1;
    i = j;
  }
}

ll ZeroBitCount(int n, int k){
  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int targetBit = ((a[i] & (1ll << k)) > 0), j = nodeNumber[i];
    ans += ((targetBit == 1) ? (rightEnd[j] - rightStart[j] + 1) : (leftEnd[j] - leftStart[j] + 1));
  }
  return ans;
}

void TakeZeroBit(int n, int k){
  for(int i = 1; i <= n; ++i){
    int targetBit = ((a[i] & (1ll << k)) > 0), j = nodeNumber[i];
    int x = (targetBit == 1) ? rightStart[j] : leftStart[j];
    tie(nodeStart[x], nodeEnd[x]) = (targetBit == 1) ? MP(rightStart[j], rightEnd[j]) : MP(leftStart[j], leftEnd[j]);
    nodeNumber[i] = x;
  }
}

void TakeOneBit(int n, int k){
  for(int i = 1; i <= n; ++i){
    int targetBit = 1 - ((a[i] & (1ll << k)) > 0), j = nodeNumber[i];
    int x = (targetBit == 1) ? rightStart[j] : leftStart[j];
    tie(nodeStart[x], nodeEnd[x]) = (targetBit == 1) ? MP(rightStart[j], rightEnd[j]) : MP(leftStart[j], leftEnd[j]);
    nodeNumber[i] = x;
  }
}

int main(){
  int n;
  ll m;

  scanf("%d%lld", &n, &m);

  for(int j = 2; j <= n; ++j){
    int i;
    ll w;
    scanf("%d%lld", &i, &w);
    a[j] = (w ^ a[i]);
  }

  Initialise(n);

  ll ans = 0;
  for(int k = B; k > -1; --k){
    FillChildNumbers(n, k);
    ll cnt = ZeroBitCount(n, k);
    if(cnt >= m){
      TakeZeroBit(n, k);
    }
    else{
      ans += (1ll << k);
      m -= cnt;
      TakeOneBit(n, k);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
