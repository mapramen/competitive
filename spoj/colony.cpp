#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(int y, ll p){
  return y == 0 
    ? true 
    : (p % 2 == 0 ? !Solve(y - 1, p / 2) : Solve(y - 1, p / 2));
}

int main(){
  int y;
  ll p;
  scanf("%d%lld", &y, &p);
  printf("%s\n", Solve(y, p) ? "red" : "blue");
  return 0;
}