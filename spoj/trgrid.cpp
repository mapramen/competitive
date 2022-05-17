#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  return n > m
    ? m % 2 == 1 ? "D" : "U"
    : n % 2 == 1 ? "R" : "L";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}