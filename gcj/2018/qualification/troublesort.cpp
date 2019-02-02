#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

int a[N];

void Solve(){
  int n;
  vector< vector<int> > v(2);

  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    v[(i % 2)].PB(x);
  }

  for(int i = 0; i < 2; ++i){
    sort(v[i].begin(), v[i].end());
    for(int j = i, k = 0; j < n; j += 2, ++k)
      a[j] = v[i][k];
  }

  for(int i = 0; i < n - 1; ++i){
    if(a[i] > a[i + 1]){
      printf("%d\n", i);
      return ;
    }
  }

  printf("OK\n");
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
