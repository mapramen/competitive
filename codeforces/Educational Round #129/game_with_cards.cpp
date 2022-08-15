#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ReadCards(){
  int n;
  scanf("%d", &n);

  int m = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    m = max(m, x);
  }

  return m;
}

void Solve(){
  int a = ReadCards();
  int b = ReadCards();

  printf("%s\n", a >= b ? "Alice" : "Bob");
  printf("%s\n", b >= a ? "Bob" : "Alice");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}