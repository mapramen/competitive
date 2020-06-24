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
#define B 14
#define N (1 << B)
#define M (2 * N)

vector<vector<int>> edgeNos(N);
int edgeTo[M], nextIndex[N];
vector<int> ans;

void DFS(int i){
  while(nextIndex[i] < edgeNos[i].size()){
    int j = edgeTo[edgeNos[i][nextIndex[i]]];
    ++nextIndex[i];
    DFS(j);
  }
  ans.push_back(i);
}

int main(){
  int n;

  cin >> n;
  for(int mask = 0, edgeNo = 0; mask < (1 << (n - 1)); ++mask){
    for(int nmask = (mask << 1) & ((1 << (n - 1)) - 1), x = 0; x < 2; ++nmask, ++x){
      edgeNos[mask].push_back(edgeNo);
      edgeTo[edgeNo] = nmask;
      ++edgeNo;
    }
  }

  DFS(0);
  reverse(ans.begin(), ans.end());

  string s;
  for(int x = ans.front(), i = 0; i < (n - 1); ++i, x /= 2){
    s.push_back('0' + x % 2);
  }
  reverse(s.begin(), s.end());

  for(int i = 1; i < ans.size(); ++i){
    s.push_back('0' + (ans[i] % 2));
  }

  cout << s << '\n';

  return 0;
}