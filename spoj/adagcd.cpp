#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001
#define MOD 1000000007

int least_prime_divisor[N];

void Initialize(){
  for(int i = N - 1; i != 1; --i){
    for(int j = i; j < N; j += i){
      least_prime_divisor[j] = i;
    }
  }
}

vector<int> ReadNumber(){
  int m;
  scanf("%d", &m);

  vector<int> a;
  while(m--){
    int x;
    scanf("%d", &x);

    while(x != 1){
      int p = least_prime_divisor[x];
      a.push_back(p);
      x /= p;
    }
  }

  sort(a.begin(), a.end());

  return a;
}

vector<int> Combine(vector<int>& a, vector<int>& b){
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
  Initialize();

  int n;
  scanf("%d", &n);

  vector<int> g = ReadNumber();

  while(--n){
    vector<int> a = ReadNumber();
    g = Combine(g, a);
  }

  int ans = 1;
  for(int x: g){
    ans = (1ll * x * ans) % MOD;
  }

  printf("%d\n", ans);
  
  return 0;
}