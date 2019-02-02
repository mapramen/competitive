#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 25

int a[N], b[N];

int c[6][8] =
{
  {13, 14, 5, 6, 17, 18, 21, 22},
  {15, 16, 7, 8, 19, 20, 23, 24},
  {1, 3, 5, 7, 9, 11, 24, 22},
  {2, 4, 6, 8, 10, 12, 23, 21},
  {3, 4, 17, 19, 10, 9, 16, 14},
  {1, 2, 18, 20, 12, 11, 15, 13}
};

bool Check(){
  bool check = 1;
  for(int i = 1; i < N && check == 1; i += 4)
    for(int j = i, k = 0; k < 4 && check == 1; ++k, ++j)
      check = (b[j] == b[i]);
  return check;
}

bool DisplaceAndCheck(int c[], int d){
  for(int i = 1; i < N; ++i)
    b[i] = i;
  for(int i = 0; i < 8; ++i)
    b[c[i]] = c[(i + d) % 8];
  for(int i = 1; i < N; ++i)
    b[i] = a[b[i]];
  return Check();
}

int main(){
  bool check = 0;

  for(int i = 1; i < N; ++i)
    scanf("%d", &a[i]);

  for(int i = 0; i < 6; ++i){
    check |= DisplaceAndCheck(c[i], 2);
    check |= DisplaceAndCheck(c[i], 6);
  }

  if(check)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
