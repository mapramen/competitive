#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  vector<int> a(n);
  for(int &ai: a){
    scanf("%d", &ai);
  }

  int s = 0;
  for(int x: a){
    s += x;
  }

  if(s % n != 0){
    return -1;
  }

  s /= n;
  
  int ans = 0;
  for(int x: a){
    if(x > s){
      ans += (x - s);
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}