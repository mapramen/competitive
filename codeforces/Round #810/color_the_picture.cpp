#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsValid(int n, int m, vector<int> a){
  ll cnt = 0;
  bool odd_possible = false;
  for(int x: a){
    int z = x / n;
    if(z <= 1){
      continue;
    }
    cnt += z;
    odd_possible = odd_possible || z > 2;
  }
  return (m <= cnt) && (m % 2 == 0 || m % 2 == 1 && odd_possible);
}

bool Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vector<int> a(k);
  for(int& x: a){
    scanf("%d", &x);
  }

  return IsValid(n, m, a) || IsValid(m, n, a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}