#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int c[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    c[i] = 1;
  }

  for(int i = 2; i * i * i < N; ++i){
    int x = i * i * i;
    for(int y = x; y < N; y += x){
      c[y] = 0;
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] += c[i - 1];
  }
}

string Solve(){
  int n;
  scanf("%d", &n);
  return c[n] == c[n - 1] ? "Not Cube Free" : to_string(c[n]);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %s\n", k, Solve().c_str());
  }

  return 0;
}