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
#define B 30

map<int,int> M[B];
int c[B];
ll s[B];
char ch[2];

int GetIndex(int x){
  int k = 1;
  for( ; (1 << k) <= x; ++k);
  return k - 1;
}

int Update(int val, int x){
  int k = GetIndex(val);

  M[k][val] += x;
  c[k] += x;
  s[k] += x * val;

  if(M[k][val] == 0){
    M[k].erase(val);
  }

  int ans = 0;
  for(ll p = 0, k = 0, q = 0; k < B; p += s[k], ++k){
    if(c[k] == 0){
      continue;
    }
    ans += c[k];
    if(2 * p < M[k].begin()->first){
      --ans;
    }
  }

  return ans;
}

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    int val;
    scanf("%s%d", ch, &val);
    int x = ch[0] == '+' ? 1 : -1;
    printf("%d\n", Update(val, x));
  }

  return 0;
}