#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

priority_queue<int> Q1;
priority_queue<int,vector<int>,greater<int>> Q2;

void Reset(){
  while(!Q1.empty()){
    Q1.pop();
  }

  while(!Q2.empty()){
    Q2.pop();
  }
}

void Rebalance(){
  while(!Q1.empty() && !Q2.empty() && Q1.top() > Q2.top()){
    Q2.push(Q1.top());
    Q1.pop();
  }

  while(Q1.size() > Q2.size()){
    Q2.push(Q1.top());
    Q1.pop();
  }

  while(Q1.size() < Q2.size()){
    Q1.push(Q2.top());
    Q2.pop();
  }
}

void Solve(){
  Reset();

  while(true){
    int n;
    scanf("%d", &n);

    if(n == 0){
      break;
    }

    if(n == -1){
      printf("%d\n", Q1.top());
      Q1.pop();
      Rebalance();
    }
    else{
      Q1.push(n);
      Rebalance();
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}