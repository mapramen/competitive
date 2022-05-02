#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N], t[N];

char GetMissingChar(char a, char b, char c){
  for(char d = 'A'; d <= 'D'; ++d){
    if(a != d && b != d && c != d){
      return d;
    }
  }
  return '\0';
}

int main(){
  int n;
  scanf("%d%s", &n, s);

  t[2 * n] = '\0';

  for(int i = 2 * n - 1; i >= 0; i -= 2){
    t[i] = GetMissingChar(s[i - 1], s[i], t[i + 1]);
    t[i - 1] = GetMissingChar(s[i - 1], s[i], t[i]);
  }

  printf("%s\n", t);

  return 0;
}