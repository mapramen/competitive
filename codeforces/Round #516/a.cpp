#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500000

int m = 0;

int GetCount(int k = 0, int l = 1, int r = N){
  if(k > 1000000){
    printf("%d %d %d\n", k, l, r);
  }
  if(l == r){
    m = max(m, k);
    return 1;
  }
  else{
    int mid = (l + r) / 2, k1 = 2 * k + 1, k2 = k1 + 1;
    return 1 + GetCount(k1, l, mid) + GetCount(k2, mid + 1, r);
  }
}

int main(){
  printf("%d %d %d\n", N, GetCount(), m);
  return 0;
}
