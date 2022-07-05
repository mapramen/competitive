#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000000

int s[N];

int main(){
  for(int i = 1; i < N; ++i){
    s[i] = s[(i / 10)] + (i % 10);
  }

  for(int i = N - 1; i != 0; --i){
    int j = i + s[i];
    s[i] = 0;

    if(j < N){
      s[j] = 1;
    }
  }

  for(int i = 1; i < N; ++i){
    if(s[i] == 0){
      printf("%d\n", i);
    }
  }

  return 0;
}