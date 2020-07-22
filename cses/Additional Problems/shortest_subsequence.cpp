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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000005
#define B 4

int a[B], nxt[N], d[N];

int main(){
  string s;
  cin >> s;

  int n = s.size();
  for(int i = 0; i < B; ++i){
    a[i] = n + i;
    nxt[n + i] = -1;
  }

  for(int i = n - 1; i > -1; --i){
    int j = a[0];
    for(int k = 1; k < B; ++k){
      if(d[a[k]] < d[j]){
        j = a[k];
      }
    }

    nxt[i] = j;
    d[i] = 1 + d[j];
    a[((s[i] - 'A' + 1) % (B + 1))] = i;
  }

  s.push_back('T');
  s.push_back('A');
  s.push_back('G');
  s.push_back('C');

  int i = 0;
  for(int k = 0; k < B; ++k){
    if(d[a[k]] < d[i]){
      i = a[k];
    }
  }

  string ans;
  for( ; i != -1; i = nxt[i]){
    ans.push_back(s[i]);
  }

  cout << ans << '\n';

  return 0;
}