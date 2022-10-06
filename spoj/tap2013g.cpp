#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end(), greater<int>());
  return a;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(n);

  int ans = 0;
  while(!a.empty() && !b.empty()){
    if(b.back() <= a.back()){
      b.pop_back();
      continue;
    }

    a.pop_back(), b.pop_back();
    ++ans;
  }

  printf("%d\n", ans);
  
  return 0;
}