#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int c[N];
vector<int> ans;

void Solve(int n, int g){
  if(n == 1){
    ans.PB(g);
    return ;
  }

  pii p = MP(n / 2, 2);
  for(int i = 2; i <= n; ++i){
    p = max(p, MP(n / i, i));
  }

  int d = p.second;
  for(int i = 1; i <= n; ++i){
    if(i % d != 0){
      ans.PB(g);
    }
  }

  Solve(n / d, g * d);
}

int main(){
  int n;

  scanf("%d", &n);

  Solve(n, 1);

  for(auto i : ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}
