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
#define pis pair<int,string>
#define N 100001

char s[N];
vector<pii> v;
vector<pis> ans;

string GetAnsString(){
  if(v.size() <= 10){
    string t;
    for(int i = (int)v.size() - 1; i > -1; --i){
      t.push_back(s[v[i].first]);
    }
    return t;
  }

  string t;
  for(int i = v.size() - 1; t.size() < 5; --i){
    t.push_back(s[v[i].first]);
  }

  t.push_back('.');
  t.push_back('.');
  t.push_back('.');

  t.push_back(s[v[1].first]);
  t.push_back(s[v[0].first]);

  return t;
}

void CollectAns(){
  ans.push_back({v.size(), GetAnsString()});
}

int main(){
  scanf("%s", s);

  int n = strlen(s);
  for(int i = n - 1; i > -1; --i, CollectAns()){
    if(v.empty()){
      v.push_back({i, n});
      continue;
    }

    int j, pj;
    tie(j, pj) = v.back();
    int pi = s[j] == s[i] ? pj : j;

    if(j == i + 1 && s[i] == s[j] && s[pi] < s[i]){
      v.pop_back();
      continue;
    }

    v.push_back({i, pi});
  }

  reverse(ans.begin(), ans.end());
  for(auto p: ans){
    printf("%d %s\n", p.first, p.second.c_str());
  }
  return 0;
}