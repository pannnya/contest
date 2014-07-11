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

#define MAX_N 20
#define MAX_W 30
#define INF 10000000

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define EQV(a,b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

typedef long long int LL;
typedef complex<double> P;
typedef pair<int, int> Pair;
//typedef tuple<int, int, int> T3;

int r, n;
int m[MAX_W * 2];
int box[MAX_W * 2];
const int W = 25;

int main(){
  while (true) {
    cin >> r >> n;
    if (r == 0) break;
    fill(m, m + MAX_W * 2, INF);
    fill(box, box + MAX_W * 2, 0);
    for (int i = 0; i < n; i++) {
      int xl, xr, h;
      cin >> xl >> xr >> h;
      for (int j = xl; j < xr; j++) {
          box[j + W] = max(box[j + W], h);
      }
    }
    double ans = INF;
    m[-r + W] = max(box[-r + W], box[-r - 1 + W]);
    for (int i = -r + 1; i <= r - 1; i++) {
      m[i + W] = min(box[i + W], box[i -1 + W]);
    }
    m[r + W] = max(box[r + W], box[r - 1 + W]);
    for (int i = -r; i <= r; i++) {
      ans = min(ans, m[i + W] + r - sqrt((double)(r * r - i * i)));
    }
    printf("%.4lf\n", ans);
  }

  return 0;
}
