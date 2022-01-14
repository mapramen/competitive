#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<vector<int>>& A, int val){
  int n = A.front().size();

  int multiple = false;
  vector<bool> visited(n);

  for(vector<int>& a: A){
    int c = 0;
    for(int i = 0; i < n; ++i){
      if(a[i] >= val){
        visited[i] = true;
        ++c;
      }
    }
    multiple = multiple || (c > 1);
  }

  for(int i = 0; i < n; ++i){
    if(!visited[i]){
      return false;
    }
  }

  return multiple;
}

int BinarySearch(vector<vector<int>>& a){
  int x = 1, y = 1E9, ans = 1;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(a, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  vector<vector<int>> a(m, vector<int>(n));
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  return BinarySearch(a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}