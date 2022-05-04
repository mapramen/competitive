#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int d[N], pd[N];
bool is_prime[N];

int main(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = true;
  }

  for(int i = 2; i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    for(int j = i; j < N; j += i){
      ++pd[j];
    }

    for(int j = 2 * i; j < N; j += i){
      is_prime[j] = false;
    }
  }

  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      ++d[j];
    }
  }

  for(int i = 1, c = 0; i < N; ++i){
    if(d[d[i]] != 4 || pd[d[i]] != 2){
      continue;
    }

    if(++c % 9 == 0){
      printf("%d\n", i);
    }
  }

  return 0;
}