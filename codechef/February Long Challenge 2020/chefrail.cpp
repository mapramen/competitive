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
#define N 100001

vector< vector<int> > negativeAxisList(N), positiveAxisList(N);
int a[N], squareRootQuotient[N], squareRootRemainder[N];
bool negativeX[N], positiveX[N], negativeY[N], positiveY[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    squareRootQuotient[i] = 1;
    squareRootRemainder[i] = 1;
    a[i] = i;
  }

  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      int k = 0;
      for( ; a[j] % i == 0; a[j] /= i, ++k);
      if(k % 2 == 1){
        squareRootRemainder[j] *= i;
      }
      k /= 2;
      while(k--){
        squareRootQuotient[j] *= i;
      }
    }
  }
}

void FillAxisList(bool x[N], vector< vector<int> > &axisList){
  for(int i = 1; i < N; ++i){
    axisList[i].clear();
    if(x[i]){
      axisList[squareRootRemainder[i]].push_back(squareRootQuotient[i]);
    }
  }
}

ll Compute(bool negativeX[N], bool positiveX[N], bool negativeY[N], bool positiveY[N]){
  FillAxisList(negativeX, negativeAxisList);
  FillAxisList(positiveX, positiveAxisList);

  ll ans = 0;
  for(int i = 1; i < N; ++i){
    for(int x : negativeAxisList[i]){
      for(int y : positiveAxisList[i]){
        ll z = 1ll * i * x * y;
        if(z < N){
          ans += (negativeY[z] + positiveY[z]);
        }
      }
    }
  }

  return ans;
}

void TakeInput(int n, bool negativeX[N], bool positiveX[N]){
  for(int i = 0; i < N; ++i){
    negativeX[i] = false;
    positiveX[i] = false;
  }
  
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x < 0){
      negativeX[-x] = true;
    }
    else{
      positiveX[x] = true;
    }
  }
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  TakeInput(n, negativeX, positiveX);
  TakeInput(m, negativeY, positiveY);

  ll ans = 0;
  if(positiveX[0] == true){
    ans = 1ll * (n - 1) * m;
  }

  if(positiveY[0] == true){
    ans = 1ll * n * (m - 1);
  }

  ans += Compute(negativeX, positiveX, negativeY, positiveY);
  ans += Compute(negativeY, positiveY, negativeX, positiveX);

  return ans;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}