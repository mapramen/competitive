#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

int T[N];

void Reset(){
  for(int i = 0; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i, int val){
  for( ; i != 0 && i < N; i += (i & -i)){
    T[i] += val;
  }
}

void Update(int l, int r, int val){
  Update(l, val), Update(r + 1, -val);
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Solve(){
  int n, u;
  scanf("%d%d", &n, &u);

  Reset();

  while(u--){
    int l, r, val;
    scanf("%d%d%d", &l, &r, &val);
    
    ++l, ++r;
    Update(l, r, val);
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int i;
    scanf("%d", &i);

    ++i;
    printf("%d\n", Query(i));
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