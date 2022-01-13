#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int a, int b){
  return a > 0 && b > 0 && a % b == 0;
}

bool Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  b *= 2;

  return Check(a + c, b) || Check(b - a, c) || Check(b - c, a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}