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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > divisors(N);
ll a[N];

void Initialise(){
  for(int i = 1; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      divisors[j].push_back(i);
    }
  }
}

int main(){
  int n;
  Initialise();

  scanf("%d", &n);

  for(int i = 2; i <= n; i += 2){
    int j, m1, m2 = INT_MAX;
    scanf("%d", &j);
    for(auto p : divisors[j]){
      int q = j / p;
      if((p + q) % 2 == 1){
        continue;
      }
      int x = (p + q) / 2, y = q - x;
      if(a[i - 2] < y){
        if(x < m2){
          m1 = y, m2 = x;
        }
      }
    }
    if(m2 == INT_MAX){
      printf("No\n");
      return 0;
    }
    a[i - 1] = m1;
    a[i] = m2;
  }

  for(int i = 1; i <= n; ++i){
    a[i] *= a[i];
  }

  for(int i = n; i > 0; --i){
    a[i] -= a[i - 1];
  }

  printf("Yes\n");
  for(int i = 1; i <= n; ++i){
    printf("%lld ", a[i]);
  }
  printf("\n");
  
  return 0;
}