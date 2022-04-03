#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ReadRoom(){
  int r, p;
  scanf("%d%d", &r, &p);
  return p;
}

int Print(char c, ll x){
  printf("%c", c);
  if(x != 0){
    printf(" %lld", x);
  }
  printf("\n");
  fflush(stdout);

  if(c != 'E'){
    return ReadRoom();
  }

  return 0;
}

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  ReadRoom();

  uniform_int_distribution<int> uid = uniform_int_distribution<int>(1, n);
  
  double weighted_sum = 0, sum_of_weights = 0;
  for(int i = 1, y = 0, x = 0; i <= k; ++i, x = y){
    y = i % 2 == 1 ? Print('T', uid(rng)) : Print('W', 0);
    double weight = i % 2 == 1 ? 1 : ((1.0 * x) / y);
    weighted_sum += weight * y, sum_of_weights += weight;
  }
  double avg = weighted_sum / sum_of_weights;

  ll ans = (n * avg) / 2;
  Print('E', ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}