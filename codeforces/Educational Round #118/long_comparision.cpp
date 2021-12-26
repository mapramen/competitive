#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char Solve(){
  int x1, x2, p1, p2;

  scanf("%d%d%d%d", &x1, &p1, &x2, &p2);

  int l1 = to_string(x1).size() + p1;
  int l2 = to_string(x2).size() + p2;

  if(l1 < l2){
    return '<';
  }

  if(l1 > l2){
    return '>';
  }

  while(p1 > p2){
    x1 *= 10;
    --p1;
  }

  while(p1 < p2){
    x2 *= 10;
    --p2;
  }

  if(x1 < x2){
    return '<';
  }

  if(x1 > x2){
    return '>';
  }

  return '=';
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%c\n", Solve());
  }

  return 0;
}