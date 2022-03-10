#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

set<pii> visited;
queue<tiii> Q;

void Reset(){
  visited.clear();

  while(!Q.empty()){
    Q.pop();
  }
}

void CheckAndPush(int a, int b, int d){
  if(visited.count({a, b}) == 0){
    visited.insert({a, b});
    Q.push({a, b, d});
  }
}

int Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  Reset();

  CheckAndPush(0, 0, 0);

  while(!Q.empty()){
    int x, y, d;
    tie(x, y, d) = Q.front();
    Q.pop();

    if(x == c || y == c){
      return d;
    }

    ++d;

    CheckAndPush(0, y, d);
    CheckAndPush(x, 0, d);

    CheckAndPush(a, y, d);
    CheckAndPush(x, b, d);

    CheckAndPush(min(a, x + y), max(0, x + y - a), d);
    CheckAndPush(max(0, x + y - b), min(b, x + y), d);
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}