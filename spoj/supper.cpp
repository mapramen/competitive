#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> GetPrefixLIS(vector<int>& a){
  vector<int> v;
  vector<int> ans;

  for(int x: a){
    int k;
    
    if(v.empty() || v.back() < x){
      v.push_back(x);
      k = v.size();
    }
    else{
      k = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
      v[k - 1] = x;
    }

    ans.push_back(k);
  }

  return ans;
}

void NegateAndReverse(vector<int>& a){
  for(int& x: a){
    x = -x;
  }
  reverse(a.begin(), a.end());
}

vector<int> GetSuffixLIS(vector<int>& a){
  NegateAndReverse(a);
  vector<int> ans = GetPrefixLIS(a);
  NegateAndReverse(a);

  reverse(ans.begin(), ans.end());
  return ans;
}

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> prefix_lis = GetPrefixLIS(a);
  vector<int> suffix_lis = GetSuffixLIS(a);

  int lis = 0;
  for(int i = 0; i < n; ++i){
    lis = max(lis, prefix_lis[i] + suffix_lis[i] - 1);
  }

  vector<int> super_numbers;
  for(int i = 0; i < n; ++i){
    if(prefix_lis[i] + suffix_lis[i] - 1== lis){
      super_numbers.push_back(a[i]);
    }
  }
  sort(super_numbers.begin(), super_numbers.end());

  printf("%lu\n", super_numbers.size());
  for(int x: super_numbers){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t = 10;
  while(t--){
    Solve();
  }
  return 0;
}