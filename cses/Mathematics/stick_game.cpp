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
#define N 1000001

bool win[N];

int main(){
  int n, m;

  cin >> n >> m;

  vector<int> v;
  while(m--){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());

  string s;

  for(int i = 1; i <= n; ++i){
    bool ans = false;
    for(int j: v){
      if(j > i){
        break;
      }
      if(!win[i - j]){
        ans = true;
        break;
      }
    }

    win[i] = ans;
    s.push_back(ans ? 'W' : 'L');
  }

  cout << s << '\n';

  return 0;
}