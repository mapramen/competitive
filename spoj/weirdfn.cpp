#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

priority_queue<int> Q1;
priority_queue<int,vector<int>,greater<int>> Q2;

void Reset(){
  Q1 = priority_queue<int>();
  Q2 = priority_queue<int,vector<int>,greater<int>>();
}

void Add(int x){
  if(Q1.size() > Q2.size()){
    if(Q1.top() <= x){
      Q2.push(x);
    }
    else{
      Q2.push(Q1.top());
      Q1.pop();
      Q1.push(x);
    }
  }
  else{
    if(x <= Q2.top()){
      Q1.push(x);
    }
    else{
      Q1.push(Q2.top());
      Q2.pop();
      Q2.push(x);
    }
  }
}

ll Solve(){
  int n, a, b, c;
  scanf("%d%d%d%d", &a, &b, &c, &n);

  Reset();

  ll ans = 1;
  Q1.push(1);

  for(int i = 2; i <= n; ++i){
    int x = (1ll * a * Q1.top() + 1ll * b * i + c) % MOD;
    Add(x);
    ans += x;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}