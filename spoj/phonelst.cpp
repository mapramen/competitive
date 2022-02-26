#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[11];

string ReadPhoneNumber(){
  scanf("%s", s);
  return string(s);
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<string> phone_numbers;
  while(n--){
    phone_numbers.push_back(ReadPhoneNumber());
  }
  sort(phone_numbers.begin(), phone_numbers.end(), [](string &a, string &b) { return a.size() < b.size(); });

  set<ll> S;
  for(string& phone_number: phone_numbers){
    ll x = 0;
    for(char c: phone_number){
      x = 11 * x + (c - '0' + 1);
      if(S.count(x) != 0){
        return false;
      }
    }
    S.insert(x);
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}