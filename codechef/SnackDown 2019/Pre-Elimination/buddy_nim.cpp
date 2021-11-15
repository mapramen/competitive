#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

ll A[N], B[N];

void TakeInputsAndProcess(int &n, ll A[]){
  int m = 1;
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &A[m]);
    if(A[m]){
      ++m;
    }
  }
  n = m - 1;
  sort(A + 1, A + n + 1);
  for(int i = 1; i <= n; ++i){
    A[i] += A[i - 1];
  }
}

bool Solve(int n, int m){
  if(n == 0 && m == 0){
    return 0;
  }

  if(n == 0 || m == 0){
    return 1;
  }

  return ((A[n] != B[m]) || Solve(n - 1, m - 1));
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, m;

    scanf("%d%d", &n, &m);
    TakeInputsAndProcess(n, A);
    TakeInputsAndProcess(m, B);

    if(Solve(n, m)){
      printf("Alice\n");
    }
    else{
      printf("Bob\n");
    }
  }

  return 0;
}
