#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MINUTES_IN_A_HOUR 60
#define MINUTES_IN_A_DAY (24 * MINUTES_IN_A_HOUR)

int TotalMinutes(int h, int m){
  return (MINUTES_IN_A_HOUR * h + m) % MINUTES_IN_A_DAY;
}

string ToString(int x){
  string old_str = to_string(x);
  size_t n_zero = 2;
  return string(n_zero - min(n_zero, old_str.length()), '0') + old_str;
}

string MinutesToHourMinString(int min){
  int h = min / MINUTES_IN_A_HOUR, m = min % MINUTES_IN_A_HOUR;
  return ToString(h) + ":" + ToString(m);
}

bool IsPalindrome(string s){
  string t(s);
  reverse(t.begin(), t.end());
  return s == t;
}

int Solve(){
  int h, m, r;
  scanf("%d:%d%d", &h, &m, &r);

  set<int> S;
  for(m = TotalMinutes(h, m); S.count(m) == 0; m = TotalMinutes(0, m + r)){
    S.insert(m);
  }

  int ans = 0;
  for(int min: S){
    ans += IsPalindrome(MinutesToHourMinString(min));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}