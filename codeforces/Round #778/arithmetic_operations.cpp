#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX_A 100000
#define MAX_SMALL_D 320
#define BIG_D_LENGTH (MAX_A / MAX_SMALL_D + 1)

vector<int> C;

int GetMaxFrequency(){
  sort(C.begin(), C.end());

  int ans = 0;
  for(int i = 0, n = C.size(), j = 0; i < n; i = j){
    int x = C[i];
    for(j = i; j < n && C[j] == x; ++j);
    ans = max(ans, j - i);
  }

  C.clear();
  return ans;
}

int CalculateForSmallD(vector<int>&a, int d){
  for(int i = a.size() - 1; i != -1; --i){
    C.push_back(a[i] - i * d);
  }
  return GetMaxFrequency();
}

int CalculateForSmallD(vector<int>& a){
  int ans = 0;
  for(int d = 0; d <= MAX_SMALL_D; ++d){
    ans = max(ans, CalculateForSmallD(a, d));
  }
  return ans;
}

int CalculateForBigD(vector<int>& a, int i){
  for(int n = a.size(), j = i + 1, k = 1; j < n && k < BIG_D_LENGTH; ++j, ++k){
    int x = a[j] - a[i];
    if(x < 0 || x % k != 0){
      continue;
    }
    C.push_back(x / k);
  }
  return 1 + GetMaxFrequency();
}

int CalculateForBigD(vector<int>& a){
  int ans = 0;
  for(int i = a.size() - 1; i != -1; --i){
    ans = max(ans, CalculateForBigD(a, i));
  }
  return ans;
}

int Calculate(vector<int>& a){
  return max(CalculateForSmallD(a), CalculateForBigD(a));
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> b(a);
  reverse(b.begin(), b.end());

  printf("%d\n", n - max(Calculate(a), Calculate(b)));

  return 0;
}