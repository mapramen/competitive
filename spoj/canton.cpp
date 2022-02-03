#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n;
  scanf("%d", &n);

  int x = 1, y = n;
  for( ; x < y; y -= x, ++x);

  x = x - y + 1;

  if((x + y - 1) % 2 == 0){
    swap(x, y);
  }

  return "TERM " + to_string(n) + " IS " + to_string(x) + "/" + to_string(y);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}