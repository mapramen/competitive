#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  deque<int> Q;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Q.push_back(x);
  }

  int ans = 0, z = 0;
  while(!Q.empty()){
    pii a = {Q.front(), 0}, b = {Q.back(), 1};

    if(a > b){
      swap(a, b);
    }

    if(z <= a.first){
      ++ans, z = a.first;
    }

    if(a.second){
      Q.pop_back();
    }
    else{
      Q.pop_front();
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}