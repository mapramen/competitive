#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002

int a[N];
set<int> S;

void Reset(){
  S.clear();
}

int GetContribution(int n, int i){
  return i < n && a[i] == a[i + 1];
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  Reset();

  int cnt = 0;
  for(int i = 1; i <= n; ++i){
    S.insert(a[i]);
    cnt += GetContribution(n, i);
  }

  int ans = 0;
  for(int i = 1, x = 1; i < n && cnt > 1; ++i){
    if(GetContribution(n, i) == 0){
      continue;
    }

    cnt -= (GetContribution(n, i) + GetContribution(n, i + 1) + GetContribution(n, i + 2));

    for( ; S.count(x) != 0; ++x);
    a[i + 1] = x, a[i + 2] = x;
    S.insert(x);

    cnt += (GetContribution(n, i) + GetContribution(n, i + 1) + GetContribution(n, i + 2));
    ++ans;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}