#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans ^= (x % 2 == 1 ? i : 0);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s Wins\n", Solve() ? "Tom" : "Hanks");
  }
  return 0;
}