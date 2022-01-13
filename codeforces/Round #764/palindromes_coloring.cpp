#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

int c[B];

void ReadString(){
  string s;
  cin >> s;

  for(int i = 0; i < B; ++i){
    c[i] = 0;
  }

  for(char x: s){
    ++c[x - 'a'];
  }
}

int GetLength(int k, int even, int odd){
  vector<int> a(k, 2 * (even / k));
  even %= k;

  for(int i = a.size() - 1; i != -1; --i){
    a[i] += 2 * max(0, min(1, even));
    --even;
  }

  for(int &ai: a){
    ai += max(0, min(1, odd));
    --odd;
  }

  return *min_element(a.begin(), a.end());
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  ReadString();

  int even = 0, odd = 0;
  for(int i = 0; i < B; ++i){
    int x = c[i];
    c[i] = 0;

    even += (x / 2);
    odd += (x % 2);
  }

  int r = max(0, (k - odd + 1) / 2);

  return max(GetLength(k, even, odd), GetLength(k, max(0, even - r), odd + 2 * min(r, even)));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}