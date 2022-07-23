#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 6

bool Solve(){
  int n;
  scanf("%d", &n);

  int s = 0;
  for(int i = 0; i < N; ++i, n /= 10){
    int d = n % 10;
    s += (2 * i < N ? d : -d);
  }

  return s == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}