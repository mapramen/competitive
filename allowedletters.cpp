#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define K 6
#define M (1 << K)

int n, A[K], B[M], C[N], P[M], Q[M];
char s[N];

void TakeInputs(){
  string s;
  cin >> s;
  for(auto c : s){
    int i = c - 'a';
    ++A[i];
  }

  n = s.size();

  for(int i = 0; i < n; ++i){
    C[i] = M - 1;
  }

  int m;
  cin >> m;
  while(m--){
    int i, mask = 0;
    cin >> i >> s;
    for(auto c : s){
      int j = c - 'a';
      mask |= (1 << j);
    }
    --i;
    C[i] = mask;
  }

  for(int i = 0; i < n; ++i){
    ++B[C[i]];
  }
}

bool Check(){
  for(int i = 0; i < M; ++i){
    P[i] = 0;
    Q[i] = B[i];
  }

  for(int k = 0; k < K; ++k){
    P[(1 << k)] = A[k];
  }

  for(int j = 0; j < K; ++j){
    for(int i = 0; i < M; ++i){
      if((i & (1 << j)) > 0){
        P[i] += P[(i ^ (1 << j))];
        Q[i] += Q[(i ^ (1 << j))];
      }
    }
  }

  bool ans = 1;
  for(int i = 0; i < M && ans == 1; ans = (P[i] >= Q[i]), ++i);

  return ans;
}

int main(){
  TakeInputs();

  for(int i = 0; i < n; ++i){
    for(int k = 0; k < K; ++k){
      if(A[k] == 0 || s[i] >= 'a' || ((1 << k) & C[i]) == 0){
        continue;
      }

      --A[k];
      --B[C[i]];

      if(Check()){
        s[i] = 'a' + k;
      }
      else{
        ++A[k];
        ++B[C[i]];
      }
    }

    if(!(s[i] >= 'a')){
      break;
    }
  }

  if(strlen(s) == n){
    printf("%s\n", s);
  }
  else{
    printf("Impossible\n");
  }

  return 0;
}
