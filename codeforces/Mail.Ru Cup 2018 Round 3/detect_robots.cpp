#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define BLOCK_SIZE 550

vector< vector<int> > lightPaths, heavyPaths;
vector< vector< pii > > lightPathsInformation(N);
int marker[N], nextVertex[N], indexInPath[N];

void ResetPaths(vector< vector<int> > &paths){
    for(auto &path : paths){
        path.clear();
    }
    paths.clear();
}

void Reset(int n){
    ResetPaths(lightPaths);
    ResetPaths(heavyPaths);

    for(int i = 1; i <= n; ++i){
        lightPathsInformation[i].clear();
    }
}

void AddLightPath(vector<int> &path){
    if(path.size() < 3 || path.size() >= BLOCK_SIZE){
        return ;
    }
    int pathNumber = lightPaths.size();
    for(int x = 0; x < path.size(); ++x){
        int i = path[x];
        lightPathsInformation[i].push_back(make_pair(pathNumber, x + 1));
    }
    lightPaths.push_back(path);
}

void AddHeavyPath(vector<int> &path){
    if(path.size() < BLOCK_SIZE){
        return ;
    }
    heavyPaths.push_back(path);
}

void InputPaths(){
    int q;
    scanf("%d", &q);
    while(q--){
        int k;
        scanf("%d", &k);
        vector<int> path;
        while(k--){
            int i;
            scanf("%d", &i);
            path.push_back(i);
        }
        AddLightPath(path);
        AddHeavyPath(path);
    }
}

bool CheckLightPathForOneSource(int s, vector<int> &path, int nextIndexInPath){
    if(nextIndexInPath >= path.size()){
        return true;
    }

    for(int pathLength = path.size(), nxtVertex = path[nextIndexInPath]; nextIndexInPath < pathLength; ++nextIndexInPath){
        int i = path[nextIndexInPath];
        if(marker[i] != s){
            marker[i] = s;
            nextVertex[i] = nxtVertex;
        }
        else{
            if(nextVertex[i] != nxtVertex){
                return false;
            }
        }
    }

    return true;
}

bool CheckLightPathsForOneSource(int s, vector< pii > &lightPathsInformation){
    if(lightPathsInformation.size() < 2){
        return true;
    }

    for(auto &lightPathInformation : lightPathsInformation){
        int pathNumber, nextIndexInPath;
        tie(pathNumber, nextIndexInPath) = lightPathInformation;
        if(!CheckLightPathForOneSource(s, lightPaths[pathNumber], nextIndexInPath)){
            return false;
        }
    }

    return true;
}

bool CheckLightPaths(int n){
    for(int i = 1; i <= n; ++i){
        marker[i] = 0;
    }

    for(int i = 1; i <= n; ++i){
        if(!CheckLightPathsForOneSource(i, lightPathsInformation[i])){
            return false;
        }
    }

    return true;
}

bool CheckPathAgainstHeavyPath(vector<int> &path, vector<int> &heavyPath){
    if(path.size() < 3){
        return true;
    }

    for(int x = path.size() - 2, maxMarker = marker[path.back()]; x > -1; --x){
        int currentMarker = marker[path[x]];
        if(currentMarker == 0){
            continue;
        }
        if(maxMarker < currentMarker){
            maxMarker = currentMarker;
            continue;
        }
        if(path[x + 1] != heavyPath[currentMarker]){
            return false;
        }
    }

    return true;
}

void ResetMarker(vector<int>& heavyPath){
    for(int x = 0; x < heavyPath.size(); ++x){
        marker[heavyPath[x]] = 0;
    }
}

bool CheckHeavyPath(int n, vector<int> &heavyPath, int heavyPathIndex){
    for(int x = 0; x < heavyPath.size(); ++x){
        marker[heavyPath[x]] = x + 1;
    }

    for(int i = heavyPathIndex + 1; i < heavyPaths.size(); ++i){
        if(!CheckPathAgainstHeavyPath(heavyPaths[i], heavyPath)){
            return false;
        }
    }

    for(auto &lightPath : lightPaths){
        if(!CheckPathAgainstHeavyPath(lightPath, heavyPath)){
            return false;
        }
    }

    return true;
}

bool CheckHeavyPaths(int n){
    for(int i = 1; i <= n; ++i){
        marker[i] = 0;
    }
    for(int i = 0; i < heavyPaths.size(); ++i){
        if(!CheckHeavyPath(n, heavyPaths[i], i)){
            ResetMarker(heavyPaths[i]);
            return false;
        }
        ResetMarker(heavyPaths[i]);
    }
    return true;
}

bool Solve(){
    int n;
    scanf("%d", &n);

    Reset(n);
    InputPaths();

    return CheckLightPaths(n) && CheckHeavyPaths(n);
}

int main(){
    int t;

    scanf("%d", &t);
    while(t--){
        printf("%s\n", Solve() ? "Robot" : "Human");
    }

    return 0;
}