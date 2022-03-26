#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> subsetSums;

void PopulateSubsetSums(vector<int>& v, int i, int sum){
  if(i == v.size()){
    subsetSums.push_back(sum);
    return;
  }
  PopulateSubsetSums(v, i + 1, sum);
  PopulateSubsetSums(v, i + 1, sum + v[i]);
}

int GetLECount(int x){
  return upper_bound(subsetSums.begin(), subsetSums.end(), x) - subsetSums.begin();
}

ll GatherCount(vector<int>& v, int i, int l, int r){
  if(i == v.size()){
    return GetLECount(r) - GetLECount(l - 1);
  }
  return GatherCount(v, i + 1, l, r) + GatherCount(v, i + 1, l - v[i], r - v[i]);
}

int main(){
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  vector<int> a1 = vector<int>(a.begin(), a.begin() + (n / 2));
  vector<int> a2 = vector<int>(a.begin() + (n / 2), a.end());

  PopulateSubsetSums(a1, 0, 0);
  sort(subsetSums.begin(), subsetSums.end());

  printf("%lld\n", GatherCount(a2, 0, l, r));

  return 0;
}