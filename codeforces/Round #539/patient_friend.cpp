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
#define B 19
#define M (1 << B)

int t[N], l[N], r[N], v[N], inf = 1E9;
vector<int> c;
map<int,int> flowRates;

//----------------------------------------- Segment Tree -----------------------------------------//
bool hasConstantFlowRate[M];
int leftEnd[M], rightEnd[M], length[M], lazyValue[M];
ll sum[M], prefixValue[M];

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  sum[k] = sum[k1] + sum[k2];
  prefixValue[k] = min(prefixValue[k1], sum[k1] + prefixValue[k2]);
}

void BuildSegmentTree(int k, int i, int j){
  if(i == j){
    leftEnd[k] = c[i - 1] + 1;
    rightEnd[k] = c[i];
  }
  else{
    int k1 = 2 * k + 1, k2 = 2 * k + 2;
    BuildSegmentTree(k1, i, (i + j) / 2);
    BuildSegmentTree(k2, (i + j) / 2 + 1, j);
    leftEnd[k] = leftEnd[k1];
    rightEnd[k] = rightEnd[k2];
  }
  length[k] = rightEnd[k] - leftEnd[k] + 1;
  hasConstantFlowRate[k] = true;
}

void UpdateNode(int k, int val){
  hasConstantFlowRate[k] = true;
  lazyValue[k] = val;
  sum[k] = 1ll * val * length[k];
  prefixValue[k] = sum[k];
}

void LazyUpdateChildren(int k){
  if(!hasConstantFlowRate[k]){
    return;
  }

  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);

  hasConstantFlowRate[k] = false;
}

void Update(int k, int ql, int qr, int val){
  if(qr < leftEnd[k] || rightEnd[k] < ql){
    return ;
  }

  if(ql <= leftEnd[k] && rightEnd[k] <= qr){
    UpdateNode(k, val);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, ql, qr, val);
  Update(2 * k + 2, ql, qr, val);
  Combine(k);
}

double Query(int k, int ql, int qr, ll &s){
  if(qr < ql || qr < leftEnd[k] || rightEnd[k] < ql || s <= 0){
    return -1.0;
  }

  if(ql <= leftEnd[k] && rightEnd[k] <= qr){
    if(s + prefixValue[k] > 0){
      s += sum[k];
      return -1.0;
    }

    if(hasConstantFlowRate[k]){
      double ans = (leftEnd[k] - 1) - (1.0 * s / lazyValue[k]);
      s = 0;
      return ans;
    }
  }

  LazyUpdateChildren(k);
  double ans = Query(2 * k + 1, ql, qr, s);
  ans = max(ans, Query(2 * k + 2, ql, qr, s));
  Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(int m){
  c.push_back(0);
  c.push_back(inf);

  for(int i = 1; i <= m; ++i){
    l[i] += (t[i] <= 2);
    c.push_back(l[i] - 1);
    c.push_back(r[i]);
  }

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  BuildSegmentTree(0, 1, c.size() - 1);
}

void Update(int i, int x, int s){
  flowRates.erase(i);
  auto kt = flowRates.upper_bound(i);
  auto jt = prev(kt);
  
  int j = jt->first, k = kt->first;

  if(x == 1){
    Update(0, i, k - 1, s);
    flowRates[i] = s;
  }
  else{
    Update(0, j, k - 1, jt->second);
  }
}

double Query(int i, int j, ll s){
  if(s == 0){
    return 1.0 * i;
  }
  return Query(0, flowRates.upper_bound(i)->first, j, s);
}

int main(){
  int m;

  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    scanf("%d%d", &t[i], &l[i]);
    if(t[i] == 1){
      scanf("%d", &v[i]);
    }
    if(t[i] == 3){
      scanf("%d%d", &r[i], &v[i]);
    }
  }

  PreProcess(m);

  flowRates[0] = 0;
  flowRates[inf + 2] = 0;

  for(int i = 1; i <= m; ++i){
    if(t[i] < 3){
      Update(l[i], t[i], v[i]);
    }
    else{
      printf("%lf\n", Query(l[i], r[i], 1ll * v[i]));
    }
  }
  return 0;
}