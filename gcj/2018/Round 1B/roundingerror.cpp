#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MT make_tuple

bool IsRoundedUp(int a, int n){
  int x = (1000 * a) / n;
  return (x % 10 >= 5);
}

int GetPercentage(int a, int n){
  return (100 * a) / n + IsRoundedUp(a, n);
}

int Solve(){
  int n, m, k, ans = 0;
  priority_queue< pii > Q;

  scanf("%d%d", &n, &m);
  k = n;

  while(m--){
    int i;
    scanf("%d", &i);

    if(IsRoundedUp(i, n) || (100 * i) % n == 0){
      ans += GetPercentage(i, n);
    }
    else{
      int j = i;
      for( ; IsRoundedUp(j, n) == 0; ++j);
      Q.push(MP(-(j - i), i));
    }

    k -= i;
  }

  while(!Q.empty()){
    pii p = Q.top();
    Q.pop();

    int x, i;
    tie(x, i) = p;
    x = -x;

    x = min(x, k);
    i += x;
    k -= x;
    ans += GetPercentage(i, n);
  }

  if(k){
    int z = 1;
    for( ; GetPercentage(z, n) == 0; ++z);
    ans += (k / z) * GetPercentage(z, n);
  }

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}
