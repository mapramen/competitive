#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n, s1, s2, a[N];

bool Check(int p){
  set<int> s;
  s.insert(s1);
  s.insert(s2);

  for(int i = 1; i <= n; ++i){
    while(!s.empty() && abs(*s.begin() - a[i]) > p)
      s.erase(*s.begin());

    while(!s.empty() && abs(*s.rbegin() - a[i]) > p)
      s.erase(*s.rbegin());

    if(s.empty())
      return 0;

    s.insert(a[i]);
  }

  return 1;
}

int BinarySearch(){
  int x = abs(s1 - s2), y = 1E9, ans = y;
  while(x <= y){
    int mid = (x + y) / 2;
    if(Check(mid))
      ans = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return ans;
}

int main(){
  scanf("%d%d%d", &n, &s1, &s2);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  printf("%d\n", BinarySearch());

  return 0;
}
