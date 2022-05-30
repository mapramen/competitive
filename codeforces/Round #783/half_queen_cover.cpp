#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  int k = 1;
  while(2 * (n - k) - 1 > k){
    ++k;
  }

  int nk = n - k;
  int odd = nk - nk % 2, even = 2 * nk - 1 - odd;

  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  reverse(p.begin(), p.begin() + odd);
  reverse(p.begin() + odd, p.begin() + odd + even);

  printf("%d\n", k);
  for(int i = 0; i < k; ++i){
    printf("%d %d\n", i + 1, p[i] + 1);
  }

  return 0;
}