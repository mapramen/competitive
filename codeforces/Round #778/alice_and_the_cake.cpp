#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  ll s = 0;
  for(int x: a){
    s += x;
  }

  priority_queue<ll> Q;
  Q.push(s);

  while(!a.empty()){
    s = Q.top();
    Q.pop();

    if(s == a.back()){
      a.pop_back();
      continue;
    }

    if(s < a.back()){
      break;
    }

    Q.push(s / 2);
    Q.push(s - (s / 2));
  }

  return a.empty() && Q.empty();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}