/*
#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <time.h>
#include <vector>
// #include <sys/time.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
//#define lgLowestBit(x) __builtin_ctz(x)
//#define bitCount(x) __builtin_popcount(x)
//#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
//#define me (*this)
//#define PQ(t) priority_queue< t, vector< t >, greater< t > >
//#define CLR(a, v) memset(a, v, sizeof(a))
//#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
//#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
//#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }
/*
char systemBuffer[1<<10];
#define execute(...) {\
  sprintf(systemBuffer, __VA_ARGS__); \
  system(systemBuffer); \
}

#ifdef LOCAL
  #define debug(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#else
  #define debug(msg, ...)
#endif
*/

typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< bool > vb;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }

/* 
struct timeval startTime, finishTime;
double timeElapsed(){
  gettimeofday(&finishTime, NULL);
  int top = finishTime.tv_sec-startTime.tv_sec-(startTime.tv_usec > finishTime.tv_usec);
  int bot = finishTime.tv_usec-startTime.tv_usec;
  if(bot < 0)
    bot += 1e6;
  return top+bot/1e6;
}
*/
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}


int sign(double x) { return x > EPS ? 1 : (x < -EPS ? -1 : 0); }
typedef pair< double,double > Pt;
Pt operator-(const Pt &a, const Pt &b){ return mp(a.x-b.x, a.y-b.y); }
Pt operator+(const Pt &a, const Pt &b){ return mp(a.x+b.x, a.y+b.y); }
double operator*(const Pt &a, const Pt &b){ return a.x*b.x + a.y*b.y; }
double operator^(const Pt &a, const Pt &b){ return a.x*b.y - a.y*b.x; }
double operator!(const Pt &a){ return sqrt(a.x*a.x + a.y*a.y); }
Pt operator&(const Pt &a){ return mp(a.y, -a.x); }
Pt operator/(const Pt &p, double d){ return mp(p.x/d, p.y/d); }
Pt operator*(double d, const Pt &p){ return mp(d*p.x, d*p.y); }
Pt operator|(const Pt &u, const Pt &v){ return ((u*v)/(v*v))*v; }
Pt operator~(const Pt &a){ return a/!a; }
inline int ccw(Pt a, Pt b, Pt c){ return sign((b-a)^(c-a)); }                   //                              < O(1), O(n^2) >

struct Seg {
  Seg(Pt aa, Pt bb): a(aa), b(bb){}
  inline int onLine(Pt p){ return ccw(p,a,b)==0; }       // N.B. undefined for a==b   //      point on Line           < O(1), O(n^2) >
  inline int LLIntersect(Seg s, Pt *ret){                                             //      line-line intersect     < O(n), O(n^2) >
    Pt c=s.a, d=s.b;
    // handle lines parallel
    if(sign((b-a)^(d-c))==0){
      if(onLine(c)) return 2;
      else return 0;
    }
    // area top / area bottom - ACD & BCD are triangles with same base
    // therefore ratio of areas is ratios of heights is ration lengths along AB
    double t = ((c-a)^(d-c)) / ((b-a)^(d-c));
    *ret = Pt(a+t*((b-a)));
    return 1;
  }
  Pt a, b;
};

struct Circle {
  Circle(Pt &a, Pt &b, Pt &c){
    // find perpendicular bisectors of AB and BC, and intersect to get centre
    Seg bisAB((a+b)/2, (a+b)/2+&(b-a));
    Seg bisBC((b+c)/2, (b+c)/2+&(c-b));
    Pt *p = new Pt();
    int npts = bisAB.LLIntersect(bisBC, p);
    if(npts == 1) {
      this->c = *p;
      this->x = p->x;
      this->y = p->y;
    } else {
      fi(1e9)
        printf("%d\n", i);
    }
    r = !(a - this->c);
  }
  Pt c;
  double r;
  double x, y;
};

double getTheta(const Pt& a, const Pt& b) {
  return atan2(a.y - b.y, a.x - b.x);
}

bool isInside(double a, double b, double c) {
  return a < b && b < c;
}

int cl(double x) {
  if (x > -EPS)
    return x + 1 - EPS;
  return x - EPS;
}

int fl(double x) {
  if (x < EPS)
    return x - 1 + EPS;
  return x + EPS;
}

void myCode() {
  cout.precision(20);
  Pt a, b, c;
  a.x = getdouble();
  a.y = getdouble();
  b.x = getdouble();
  b.y = getdouble();
  c.x = getdouble();
  c.y = getdouble();
  Circle circle(a, b, c);
  double ta = getTheta(a, circle.c);
  double tb = getTheta(b, circle.c);
  double tc = getTheta(c, circle.c);
  double tlo = min(ta, tb);
  double thi = max(ta, tb);
  bool inside = isInside(tlo, tc, thi);
  double xlo = min(a.x, b.x);
  double ylo = min(a.y, b.y);
  double xhi = max(a.x, b.x);
  double yhi = max(a.y, b.y);
  vector<Pt> pts = {
    Pt(circle.x + circle.r, circle.y),
    Pt(circle.x - circle.r, circle.y),
    Pt(circle.x, circle.y + circle.r),
    Pt(circle.x, circle.y - circle.r)
  };
  for (const auto p : pts) {
    double theta = getTheta(p, circle.c);
    if (inside == isInside(tlo, theta, thi)) {
      xlo = min(xlo, p.x);
      xhi = max(xhi, p.x);
      ylo = min(ylo, p.y);
      yhi = max(yhi, p.y);
    }
  }
  printf("%d\n", (cl(xhi) - fl(xlo)) * (cl(yhi) - fl(ylo)));
}

int main() {
/*
  // seed the random number generator with microseconds
  gettimeofday(&startTime, NULL);
  srand(startTime.tv_usec);
*/
  myCode();
  return 0;
}










