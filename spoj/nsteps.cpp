#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Calculate(int x, int y){
  if(x == y){
    return 2 * x - (x % 2);
  }

  if(x - y == 2){
    return Calculate(x - 2, y) + 2;
  }

  return -1;
}

string Solve(){
  int x, y;
  scanf("%d%d", &x, &y);

  int ans = Calculate(x, y);
  
  return ans == -1 ? "No Number" : to_string(ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}