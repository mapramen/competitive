#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 100002

int x1[N], x2[N], y1[N], y2[N], left[N], right[N], up[N], down[N];

int main(){
  int d, n, m, targetLeftCount, targetRightCount, targetUpCount, targetDownCount, ans = -1;

  scanf("%d%d%d", &d, &n, &m);
  for(int i = 1; i <= d; i++){
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    if(x1[i] > x2[i])
      swap(x1[i], x2[i]);
    if(y1[i] > y2[i])
      swap(y1[i], y2[i]);
    left[x1[i]]++;
    right[x2[i]]++;
    up[y1[i]]++;
    down[y2[i]]++;
  }

  scanf("%d%d%d%d", &targetLeftCount, &targetRightCount, &targetUpCount, &targetDownCount);

  for(int i = 1; i <= n; i++)
    left[i] += left[i - 1];

  for(int i = n; i > 0; i--)
    right[i] += right[i + 1];

  for(int j = 1; j <= m; j++)
    up[j] += up[j - 1];

  for(int j = m; j > 0; j--)
    down[j] += down[j + 1];

  for(int i = 1; i <= d; i++){
    int currentLeftCount = left[x2[i] - 1] - (x1[i] + 1 == x2[i]);
    int currentRightCount = right[x1[i] + 1] - (x1[i] + 1 == x2[i]);
    int currentUpCount = up[y2[i] - 1] - (y1[i] + 1 == y2[i]);
    int currentDownCount = down[y1[i] + 1] - (y1[i] + 1 == y2[i]);

    if(currentLeftCount == targetLeftCount && currentRightCount == targetRightCount && currentUpCount == targetUpCount && currentDownCount == targetDownCount)
      ans = i;
  }

  printf("%d\n", ans);

  return 0;
}
