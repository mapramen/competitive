#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int grundy[N], c[N];

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& x: a){
    scanf("%d", &x);
  }

  for(int i = 1; i < N; ++i){
    for(int x: a){
      if(x <= i){
        ++c[grundy[i - x]];
      }
    }

    int ans = 0;
    for( ; c[ans] != 0; ++ans);
    grundy[i] = ans;

    for(int x: a){
      if(x <= i){
        --c[grundy[i - x]];
      }
    }
  }

  int ans = 0;
  while(n--){
    int i;
    scanf("%d", &i);
    ans ^= grundy[i];
  }

  return ans != 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Ada" : "Vinit");
  }
  return 0;
}