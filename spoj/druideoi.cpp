#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], left_greater_index[N], right_greater_index[N];
stack<int> S;

void Compute(int n, int greater_index[], int start, int step){
  for(int i = start, k = 0; k < 2 * n; i = (n + (i - 1) + step) % n + 1, ++k){
    while(!S.empty() && a[S.top()] <= a[i]){
      S.pop();
    }
    greater_index[i] = S.empty() ? -1 : S.top();
    S.push(i);
  }

  while(!S.empty()){
    S.pop();
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  Compute(n, left_greater_index, 1, 1);
  Compute(n, right_greater_index, n, -1);

  for(int i = 1; i <= n; ++i){
    printf("%d %d\n", left_greater_index[i], right_greater_index[i]);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}