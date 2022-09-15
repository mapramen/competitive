#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 11000001

int c[N], d[N];
vector<int> a(1);
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

void Initialize(){
  for(int i = 1; i < N; ++i){
    d[i] = i;
  }

  for(int i = 2; i < N; ++i){
    if(c[i] != 0){
      continue;
    }
    for(int j = i; j < N; j += i){
      ++c[j], d[j] /= i;
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] = (c[i] == 2 && d[i] == 1) + c[i - 1];
    if(c[i] != c[i - 1]){
      a.push_back(i);
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return a[n];
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}