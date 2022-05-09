#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

set<int> S;
int A[N], C[N], zeros, ones;
bool restored[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    restored[i] = false;
    S.insert(i);
  }
  zeros = 0, ones = 0;
}

void Set(int i, int val){
  if(restored[i]){
    return;
  }

  S.erase(i);
  A[i] = val;
  restored[i] = true;

  zeros += 1 - val;
  ones += val;
}

void SetZero(int i, int j){
  for(i = *S.lower_bound(i); i < j; ++i){
    Set(i, 1);
  }
  Set(j, 0);
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  ll total_zeros = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &C[i]);
    total_zeros += (n - C[i]);
  }
  total_zeros /= n;

  for(int i = 1; i <= n; ++i){
    if(zeros == total_zeros){
      Set(i, 1);
      continue;
    }

    if(ones == 0){
      SetZero(i, C[i] == 0 ? i : C[i] + 1);
    }
    else{
      assert(restored[i]);
      SetZero(i, A[i] == 0 ? C[i] + i : C[i] + 1);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}