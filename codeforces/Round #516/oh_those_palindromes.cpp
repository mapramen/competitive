#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

int a[B];

int main(){
  int n;
  string s;

  cin >> n >> s;
  for(auto c : s){
    int i = c - 'a';
    ++a[i];
  }

  for(int i = 0; i < B; ++i){
    int k = a[i];
    char c = 'a' + i;
    while(k--){
      putchar(c);
    }
  }
  putchar('\n');

  return 0;
}
