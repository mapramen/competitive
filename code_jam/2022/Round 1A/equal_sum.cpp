#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100
#define MAXA 1E9
#define MAX_BITS 30

vector<int> A;

void Initialise(){
  for(int k = 0; k < MAX_BITS; ++k){
    A.push_back((1 << k));
  }

  for(int x = MAXA; A.size() < N; --x){
    A.push_back(x);
  }
}

void Print(vector<int> a){
  for(int x: a){
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
}

void Solve(){
  int n;
  scanf("%d", &n);

  Print(A);

  vector<int> B;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    B.push_back(x);
  }

  B.insert(B.end(), A.begin() + MAX_BITS, A.end());
  sort(B.begin(), B.end());

  vector<int> C;
  int s = (1 << MAX_BITS) - 1;
  for(int i = 0; i < B.size(); ++i){
    if(i % 2 == 0){
      C.push_back(B[i]);
      s -= B[i];
    }
    else{
      s += B[i];
    }
  }

  s /= 2;

  for(int k = 0; k < MAX_BITS; ++k){
    if((s & (1 << k)) != 0){
      C.push_back(1 << k);
    }
  }

  Print(C);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  
  while(t--){
    Solve();
  }
  
  return 0;
}