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

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    
    vector<int> a(n), parent(n + 1), lisPosition(n + 1), inLis(n + 1);
    vector< vector<int> > ans;

    for(int i = 0; i < n; ++i){
      scanf("%d", &a[i]);
    }

    while(!a.empty()){
      vector<int> B(1);

      for(int x : a){
        int k;
        if(B.back() < x){
          k = B.size();
          B.push_back(x);
        }
        else{
          k = lower_bound(B.begin(), B.end(), x) - B.begin();
        }
        B[k] = x;
        parent[x] = B[k - 1];
        lisPosition[x] = k;
        inLis[x] = 0;
      }

      int k = 1;
      for(int s = k; s <= a.size(); ++k, s += k);

      if(B.size() <= k){
        vector< vector<int> > ansx(B.size());
        for(int x : a){
          ansx[lisPosition[x]].push_back(x);
        }
        for(int i = 1; i < ansx.size(); ++i){
          ans.push_back(ansx[i]);
        }
        a.clear();
      }
      else{
        vector<int> v, b;
        for(int x = B.back(); x; x = parent[x]){
          inLis[x] = 1;
        }

        for(int x : a){
          if(inLis[x] == 0){
            b.push_back(x);
          }
          else{
            v.push_back(x);
          }
        }

        ans.push_back(v);
        a = b;
      }
    }

    printf("%lu\n", ans.size());
    for(auto ansx : ans){
      printf("%lu ", ansx.size());
      for(int x : ansx){
        printf("%d ", x);
      }
      printf("\n");
    }
  }

  return 0;
}