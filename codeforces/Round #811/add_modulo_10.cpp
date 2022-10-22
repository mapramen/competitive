#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ApplyOperation(int n){
  return n + n % 10;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  int zero_count = 0, two_odd_count = 0, two_even_count = 0;
  set<int> S;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);

    for( ; x % 10 != 0 && x % 10 != 2; x = ApplyOperation(x));
    S.insert(x);

    if(x % 10 == 0){
      ++zero_count;
      continue;
    }

    if((x / 10) % 2 == 1){
      ++two_odd_count;
    }
    else{
      ++two_even_count;
    }
  }

  return (zero_count == n && S.size() == 1) || two_odd_count == n || two_even_count == n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}