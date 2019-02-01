#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > divisors(N);
int mu[N];
ll s[N], inf = 1E18;

void PreProcess(){
  mu[1] = 1;
  for(int i = 1; i < N; ++i)
    for(int j = i + i; j < N; j += i)
      mu[j] -= mu[i];

  for(int i = 2; i < N; ++i)
    for(int j = i; j < N; j += i)
      divisors[j].PB(i);
}

void Update(int x, int val){
  for(auto d : divisors[x])
    s[d] += val;
}

ll Query(int x){
  ll ans = 0;
  for(auto d : divisors[x])
    ans -= mu[d] * s[d];
  return ans;
}

int main(){
  int n;
  ll ans = 0;

  PreProcess();

  scanf("%d", &n);

  for(int i = 1, j = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(x, i);
    ans += ((n - i + 1) * Query(x));
    if(ans > inf){
      printf("-1\n");
      return 0;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
