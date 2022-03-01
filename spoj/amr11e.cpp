#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3001

int c[N];
vector<int> a;

void Initialize(){
  a.push_back(0);

  for(int i = 2; i < N; ++i){
    if(c[i] > 2){
      a.push_back(i);
    }

    if(c[i] != 0){
      continue;
    }

    for(int j = i; j < N; j += i){
      ++c[j];
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return a[n];
}

int main(){
  int t;
  scanf("%d", &t);
  Initialize();
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}