#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 120001

int a[N];
vector< tiii > queries;
ll ans[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int value;
  int lazyValue;
  int count;
  int times;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->value = 0;
  temp->lazyValue = 0;
  temp->count = rightEnd - leftEnd + 1;
  temp->times = 0;
  temp->ans = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void LazyUpdateValue(node *currentNode, int lazyValue){
  if(lazyValue == 0){
    return ;
  }

  currentNode->value += lazyValue;
  currentNode->lazyValue += lazyValue;
}

void LazyUpdateTimes(node *currentNode, int times){
  if(times == 0){
    return ;
  }

  currentNode->times += times;
  currentNode->ans += 1ll * times * currentNode->count;
}

void LazyUpdateChild(node *parentNode, node *childNode){
  LazyUpdateValue(childNode, parentNode->lazyValue);
  if(childNode->value == parentNode->value){
    LazyUpdateTimes(childNode, parentNode->times);
  }
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyValue = 0;
  currentNode->times = 0;
}

void Combine(node *currentNode){
  node *leftChild = currentNode->leftChild;
  node *rightChild = currentNode->rightChild;

  currentNode->value = min(leftChild->value, rightChild->value);
  currentNode->ans = leftChild->ans + rightChild->ans;
  currentNode->count = 0;

  if(leftChild->value == currentNode->value){
    currentNode->count += leftChild->count;
  }

  if(rightChild->value == currentNode->value){
    currentNode->count += rightChild->count;
  }
}

void Update(node *currentNode, int l, int r, int lazyValue){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }

  if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
    LazyUpdateValue(currentNode, lazyValue);
  }
  else{
    LazyUpdateChildren(currentNode);
    Update(currentNode->leftChild, l, r, lazyValue);
    Update(currentNode->rightChild, l, r, lazyValue);
    Combine(currentNode);
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l){
    return 0ll;
  }

  if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
    return currentNode->ans;
  }
  else{
    LazyUpdateChildren(currentNode);
    ll ans = Query(currentNode->leftChild, l, r) + Query(currentNode->rightChild, l, r);
    Combine(currentNode);
    return ans;
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//
node *root;

void Solve(){
  int i = 1;
  stack<int> minStack, maxStack;

  for(auto query : queries){
    int l, r, k;
    tie(r, l, k) = query;

    for( ; i <= r; ++i){
      while(!minStack.empty() && a[minStack.top()] > a[i]){
        int y = minStack.top();
        minStack.pop();
        int x = minStack.empty() ? 1 : minStack.top() + 1;
        Update(root, x, y, a[y] - a[i]);
      }
      minStack.push(i);

      while(!maxStack.empty() && a[maxStack.top()] < a[i]){
        int y = maxStack.top();
        maxStack.pop();
        int x = maxStack.empty() ? 1 : maxStack.top() + 1;
        Update(root, x, y, a[i] - a[y]);
      }
      maxStack.push(i);

      Update(root, 1, i, -1);
      LazyUpdateTimes(root, 1);
    }

    ans[k] = Query(root, l, r);
  }
}

int main(){
  int n, q;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  scanf("%d", &q);
  for(int i = 1; i <= q; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    queries.PB(MT(r, l, i));
  }

  sort(queries.begin(), queries.end());

  root = BuildSegmentTree(1, n);

  Solve();

  for(int i = 1; i <= q; ++i){
    printf("%lld\n", ans[i]);
  }

  return 0;
}
