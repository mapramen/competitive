#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1501

int a[N], p[N], dp[N][N], l[N], r[N], leftMostOverlapIndex[N], rightMostNonOverlapIndex[N];

int PreProcess(int n){
  vector< pii > v;
  for(int i = 1; i <= n; ++i){
    bool isContained = 0;
    for(int j = 1; j <= n && !isContained; ++j){
      isContained |= ((l[i] != l[j] || r[i] != r[j]) && l[j] <= l[i] && r[i] <= r[j]);
    }
    if(!isContained){
      v.PB(MP(r[i], l[i]));
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  n = v.size();
  for(int i = 1; i <= n; ++i){
    tie(r[i], l[i]) = v[i - 1];

    for(int j = 1; j < i; ++j){
      if(r[j] < l[i]){
        rightMostNonOverlapIndex[i] = j;
      }
      else{
        if(leftMostOverlapIndex[i] == 0 || l[j] < l[leftMostOverlapIndex[i]]){
          leftMostOverlapIndex[i] = j;
        }
      }
    }

    if(leftMostOverlapIndex[i] == 0){
      leftMostOverlapIndex[i] = rightMostNonOverlapIndex[i];
    }
  }

  return n;
}

int Cost(int i, int j){
  return p[j] - p[i - 1];
}

bool Check(int n, int s, int m, int k, int x){
  for(int i = 1; i <= n; ++i){
    p[i] = p[i - 1] + (a[i] <= x);
  }

  for(int i = 0; i <= s; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j] = INT_MIN;
    }
  }

  dp[0][0] = 0;
  int ans = 0;
  for(int i = 1; i <= s; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j] = dp[i - 1][j];
    }

    int nonOverlapIndex = rightMostNonOverlapIndex[i], nonOverlapCost = Cost(l[i], r[i]);
    int overlapIndex = leftMostOverlapIndex[i], overlapCost = min(nonOverlapCost, Cost(r[overlapIndex] + 1, r[i]));

    for(int j = 1; j <= m; ++j){
      dp[i][j] = max(dp[i][j], dp[overlapIndex][j - 1] + overlapCost);
      dp[i][j] = max(dp[i][j], dp[nonOverlapIndex][j - 1] + nonOverlapCost);
      ans = max(ans, dp[i][j]);
    }
  }

  return ans >= k;
}

int BinarySearch(int n, int s, int m, int k){
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    v.PB(a[i]);
  }
  sort(v.begin(), v.end());

  int x = 0, y = v.size() - 1, z = INT_MAX;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, s, m, k, v[mid])){
      z = v[mid], y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return z == INT_MAX ? -1 : z;
}

int main(){
  int n, s, m, k;

  scanf("%d%d%d%d", &n, &s, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= s; ++i){
    scanf("%d%d", &l[i], &r[i]);
  }

  s = PreProcess(s);

  printf("%d\n", BinarySearch(n, s, m, k));

  return 0;
}
