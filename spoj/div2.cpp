#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int d[N];
bool valid[N];

int main(){
  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      ++d[j];
    }
  }

  for(int i = 1; i < N; ++i){
    valid[i] = d[i] > 3;
  }

  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      if(valid[j] && d[j] % d[i] != 0){
        valid[j] = false;
      }
    }
  }

  for(int i = 1, cnt = 0; i < N; ++i){
    if(!valid[i]){
      continue;
    }

    cnt += valid[i];
    if(cnt % 108 == 0){
      printf("%d\n", i);
    }
  }
  
  return 0;
}