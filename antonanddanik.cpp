#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[N];

int main(){
  int n, i, ans;

  cin >> n;
  cin >> s;

  for(i = ans = 0; s[i] != '\0'; i++)
    if(s[i] == 'A')
      ans++;
    else
      ans--;

  if(ans == 0)
    cout << "Friendship\n";
  else
    if(ans > 0)
      cout << "Anton\n";
    else
      cout << "Danik\n";

  return 0;
}
