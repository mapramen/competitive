#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M 105

bitset<N> validMoves, grundies[M];
int a[N], grundyValues[N];
bool isPrime[N];
vector<string> players{"Alice", "Bob"};

void PreProcess(int n, int m){
  vector<int> primes;
  for(int i = 2; i <= n; ++i){
    isPrime[i] = 1;
  }

  validMoves.reset();
  for(int i = 2; i <= n; ++i){
    if(!isPrime[i]){
      continue;
    }

    for(int j = i + i; j <= n; j += i){
      isPrime[j] = 0;
    }

    primes.push_back(i);
    for(int prime : primes){
      if(i * prime > n){
        break;
      }
      validMoves.set(i * prime);
    }
    validMoves.set(i);
  }

  for(int k = 0; k < M; ++k){
    grundies[k].reset();
  }

  validMoves.reset(m);
  grundies[0].set(0);
  grundies[0] |= validMoves;
  for(int i = 1; i <= n; ++i){
    int &k = grundyValues[i];
    for(k = 0; grundies[k][i]; ++k);
    grundies[k] |= (validMoves << i);
  }
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int i = 1, j = 0; i <= n; ++i){
    int b, w, r;
    scanf("%d%d%d", &b, &w, &r);
    a[++j] = w - b - 1;
    a[++j] = r - w - 1;
  }

  n = 2 * n;
  int m = 0;
  for(int i = 1; i <= n; ++i){
    m = max(m, a[i]);
  }

  PreProcess(m, k);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans ^= grundyValues[a[i]];
  }
  ans = (ans == 0) ? 1 : 0;

  for(int i = 0; i < players.size(); ++i){
    cout << players[i ^ ans] << '\n';
  }
  
  return 0;
}