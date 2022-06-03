#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<int> v;

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

void Initialize(){
  for(int i = 2; i * i < N; ++i){
    if(!IsPrime(i)){
      continue;
    }

    for(int j = i, s = 1; j < N; j *= i){
      s += j;
      if(IsPrime(s)){
        v.push_back(j);
      }
    }
  }
  
  sort(v.begin(), v.end());
}

int GetCount(int n){
  return upper_bound(v.begin(), v.end(), n) - v.begin();
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  return GetCount(r) - GetCount(l - 1);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}