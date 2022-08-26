#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

set<int> Solve(int n, int m){
  set<int> S;

  int s = n * (n + 1) / 2;
  if(m < -s || m > s || m == -s || m == -s + 4 || m == s - 2 || (s + m) % 2 != 0){
    return S;
  }

  s = (s - m) / 2;

  for(int i = n; i != 0; --i){
    if(i <= s){
      S.insert(i);
      s -= i;
    }
  }

  if(S.count(1) == 0){
    return S;
  }

  S.erase(1);

  for(int k = n; k > 2; --k){
    if(S.count(k) == 0 && S.count(k - 1) != 0){
      S.erase(k - 1), S.insert(k);
      return S;
    }
  }

  int k = *S.begin();
  S.erase(k);
  S.insert(2), S.insert(k - 1);
  return S;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  set<int> S = Solve(n, m);
  if(S.empty() && n * (n + 1) / 2 != m){
    printf("Impossible\n");
    return 0;
  }

  printf("1");
  for(int i = 2; i <= n; ++i){
    putchar(S.count(i) != 0 ? '-' : '+');
    printf("%d", i);
  }
  printf("\n");
  
  return 0;
}