#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000000

void AddPrimeFactors(vector<int>& v, int x){
  for(int i = 2; i * i <= x; ++i){
    while(x % i == 0){
      v.push_back(i);
      x /= i;
    }
  }

  if(x != 1){
    v.push_back(x);
  }
}

vector<int> ReadNumber(){
  int m;
  scanf("%d", &m);

  vector<int> a;
  while(m--){
    int x;
    scanf("%d", &x);
    AddPrimeFactors(a, x);
  }
  sort(a.begin(), a.end());

  return a;
}

vector<int> Combine(vector<int> a, vector<int> b){
  vector<int> c;

  for(int n = a.size(), m = b.size(), i = 0, j = 0; i < n && j < m; ){
    if(a[i] < b[j]){
      ++i;
      continue;
    }

    if(b[j] < a[i]){
      ++j;
      continue;
    }

    c.push_back(a[i]);
    ++i, ++j;
  }

  return c;
}

int main(){
  ll ans = 1, mod_ans = 1;
  for(int x: Combine(ReadNumber(), ReadNumber())){
    ans = min(1ll * MOD, x * ans);
    mod_ans = (x * mod_ans) % MOD;
  }

  if(ans == MOD){
    printf("%09lld\n", mod_ans);
  }
  else{
    printf("%lld\n", mod_ans);
  }
  
  return 0;
}