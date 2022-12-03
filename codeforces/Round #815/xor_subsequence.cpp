#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define B 30

int a[N];
int T[2][4 * B * N], dp[4 * B * N], nxt = 0;

void Reset(){
  T[0][0] = 0, T[1][0] = 0;
}

int GetKthBit(int k, int a){
  return (a & (1 << k)) != 0;
}

int GetKey(int key, int ak, bool for_add){
  if(key == -1){
    return -1;
  }

  if(T[ak][key] != 0){
    return T[ak][key];
  }

  if(!for_add){
    return -1;
  }

  return T[ak][key] = ++nxt;
}

int GetKey(int key, int ak, int bk, bool for_add){
  return GetKey(GetKey(key, ak, for_add), bk, for_add);
}

int GetCharacteristicKey(int key, int ak, int bk, bool for_add){
  if(ak == 1){
    ak ^= 1, bk ^= 1;
  }
  return GetKey(key, ak, bk, for_add);
}

void Update(int key, int val){
  dp[key] = max(dp[key], val);
}

int Query(int key){
  return key == -1 ? 0 : dp[key];
}

void Add(int a, int b, int val){
  ll key = 0;
  for(int k = B - 1; k > -1; --k){
    int ak = GetKthBit(k, a), bk = GetKthBit(k, b);
    Update(GetKey(key, ak, bk, true), val);
    key = GetCharacteristicKey(key, ak, bk, true);
  }
}

int Calculate(int a, int b){
  int ans = 0;
  ll key = 0;
  for(int k = B - 1; k > -1; --k){
    int ak = GetKthBit(k, a), bk = GetKthBit(k, b);
    ans = max(ans, Query(GetKey(key, bk, 1 ^ ak, false)));
    key = GetCharacteristicKey(key, bk, ak, false);
  }
  return 1 + ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  Reset();

  int ans = 0;
  for(int i = 0; i < n; ++i){
    int ansx = Calculate(a[i], i);
    Add(a[i], i, ansx);
    ans = max(ans, ansx);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}