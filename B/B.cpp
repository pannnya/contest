#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define EQV(a,b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

typedef long long int LL;
typedef complex<double> P;
typedef pair<int, int> Pair;
typedef tuple<int, int, int> T3;

int main(){
  int h;
  while(cin >> h, h){
    vector<vector<int> > map(h, vector<int>(5));
    for(int i = 0; i < h; i++){
      for(int j = 0; j < 5; j++){
	cin >> map[i][j];
      }
    }
    int ans = 0;
    while(1){
      bool updateFlag = false;
      for(int i = 0; i < h; i++){

	for(int j = 0; j < 5; j++){
	  if(map[i][j] == 0) continue;
	  int sameCnt = 0, val = 0, maxCnt = 0, maxVal = 0;
	  for(int k = j; k < 5; k++){
	    if(map[i][j] == map[i][k]){
	      sameCnt++;
	    } else break;
	  }
	  if(sameCnt >= 3){
	    updateFlag = true;
	    ans += map[i][j] * sameCnt;
	    for(int k = j; k < j+sameCnt; k++){
	      map[i][k] = 0;
	    }
	  }
	}
      }
      if(!updateFlag) break;
      for(int i = h-1; i >= 0; i--){
	for(int j = 0; j < 5; j++){
	  if(map[i][j] == 0){
	    for(int k = i-1; k >= 0; k--){
	      if(map[k][j] != 0) {
		map[i][j] = map[k][j];
		map[k][j] = 0;
		break;
	      }
	    }
	  }
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
