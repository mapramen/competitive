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
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 200001

vector< vector<int> > divisors(N);
vector<int> v;
int a[N], c[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      divisors[j].push_back(i);
    }
  }
}

int GetAns(){
  const int n = v.size();
  int ans = n;

  for(int d : divisors[n]){
    for(int r = 0; r < d; ++r){
      bool valid = true;
      
      for(int i = r; i < n && valid == true; i += d){
        valid = v[i] == v[r];
      }

      if(valid){
        ans = d;
        break;
      }
    }

    if(ans < n){
      break;
    }
  }

  v.clear();
  return ans;
}

int Solve(){
  int n;

  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  int ans = n;
  for(int i = 1; i <= n; ++i){
    if(a[i] == -1){
      continue;
    }

    for(int j = i; a[j] != -1; ){
      v.push_back(c[j]);

      int k = a[j];
      a[j] = -1;
      j = k;
    }

    ans = min(ans, GetAns());
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();
  
  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}