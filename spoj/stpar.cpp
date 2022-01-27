#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  reverse(a.begin(), a.end());

  stack<int> S;
  for(int x = 1; x <= n; ++x){
    if(!S.empty() && S.top() == x){
      S.pop();
      continue;
    }

    if(a.empty()){
      return false;
    }

    if(a.back() != x){
      S.push(a.back());
      --x;
    }
    a.pop_back();
  }

  return true;
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "yes" : "no");
  }
  return 0;
}