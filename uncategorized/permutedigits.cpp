#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Length(ll n){
  int l = 0;
  while(n){
    ++l;
    n /= 10;
  }
  return l;
}

vector<int> Counts(ll n){
  vector<int> v(10);
  while(n){
    ++v[(n % 10)];
    n /= 10;
  }
  return v;
}

vector<int> DigitVector(ll n){
  vector<int> v;
  while(n){
    v.PB(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}

string MaxString(vector<int>& v){
  string ans;
  for(int i = 9; i > -1; --i){
    int x = v[i];
    while(x--){
      ans.PB('0' + i);
    }
  }
  return ans;
}

string MinString(vector<int>& v){
  string ans;
  for(int i = 0; i < 10; ++i){
    int x = v[i];
    while(x--){
      ans.PB('0' + i);
    }
  }
  return ans;
}

string GetString(vector<int>& v){
  string ans;
  for(auto i : v)
    ans.PB('0' + i);
  return ans;
}

int main(){
  ll a, b;
  string ans;

  cin >> a >> b;

  vector<int> c = Counts(a);

  if(Length(a) == Length(b)){
    vector<int> B = DigitVector(b);
    string t = GetString(B);

    for(int i = 0; i < B.size(); ++i){
      int k = 0;

      for(int j = 0; j <= B[i]; ++j){
        if(c[j] == 0)
          continue;
        string ansx = ans;
        ansx.PB('0' + j);
        --c[j];
        ansx += MinString(c);
        ++c[j];
        if(ansx <= t)
          k = j;
      }

      ans.PB('0' + k);
      --c[k];
      if(k != B[i])
        break;
    }
  }

  ans += MaxString(c);

  cout << ans << '\n';

  return 0;
}
