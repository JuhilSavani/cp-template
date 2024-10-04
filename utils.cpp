#include <bits/stdc++.h>
using namespace std;


// Typedefs
//~~~~~~~~~~
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vint> vvi;
typedef vector<vll> vvl;


// Macros
//~~~~~~~~
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define str string
#define vec vector

#define dbg(x) cerr << (#x) << ": " << (x) << endl

#define fori(n) for(int i=0; i<n; ++i)
#define forj(n) for(int j=0; j<n; ++j)
#define fork(n) for(int k=0; k<n; ++k)
#define f(i, x, n) for(int i=x; i<n; ++i)
#define rf(i, x, n) for(int i=x; i>=n; --i)
#define each(itm, cn) for(auto &itm : cn)

#define sz(cn) ((int)(cn).size())
#define all(cn) (cn).begin(), (cn).end()
#define rall(cn) (cn).rbegin(), (cn).rend()

#define init(a, b) memset((a), (b), sizeof(a)) // Only for Arrays | TC: O(n)
#define cpy(a, b) memcpy((a), (b), sizeof(a)) // Only for Arrays | TC: O(n)

#define flush() cin.ignore()
#define prcsn(x,y) fixed<<setprecision(y)<<x
#define diglen(n) ((int)log10(n) + 1)

#define ff first
#define ss second

#define pb push_back 
#define eb emplace_back
#define mkpr make_pair
#define setct __builtin_popcountll 

#define endl '\n'
#define newl cout << '\n'

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr)

// #define ls(i) ((i) << 1)
// #define rs(i) ((i) << 1 | 1)

// Constants
//~~~~~~~~~~~
const int MN = INT_MIN;
const int MX = INT_MAX;
const int MOD=1e9+7;
const double PI=3.141592653589793238462;


/// Some Implementations 
//~~~~~~~~~~~~~~~~~~~~~~
auto lower_b(auto low, auto high, int q) {
  // lower_bound
  auto end = high;
  --high;
  if(*high < q)  return end;
  while (low <= high) {
    auto mid = low + (high-low) / 2; 
    if (*mid >= q) high = --mid;
    else low = ++mid;
  }
  return low;
}

auto upper_b(auto low, auto high, int q){
  // upper_bound
  auto end=high;
  --high;
  if(*high < q) return end;
  while(low<=high){
    auto mid = low + (high-low)/2;
    if(*mid <= q) low=(++mid);
    else high=(--mid);
  }
  return low;
}

double nth_root(double x, double n) {
  if (x == 0) return 0;  
  if (n == 0) return NAN; 
  double low=0;
  double high=max(1.0, x);
  double epsilon=1e-6; // precision level
  while (high-low > epsilon) {
    double mid=low+(high-low)/2;
    if (pow(mid, n) > x)high=mid;
    else low=mid;
  }
  // low and high will converge to the nth root
  return (low+high)/2; // return the midpoint for better precision
}


/// Bit Manipulation Tutorial 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~
int getBit(int n, int i) { 
  // cerr << "Get position " << i << endl;
  // bitset<8> before(n);
  // dbg(before);
  // bitset<8> _after(n|(1<<i));
  // dbg(_after);

  return (n&(1<<i))!=0; 
}

int setBit(int n, int i) { 
  // cerr << "Set position " << i << endl;
  // bitset<8> before(n);
  // dbg(before);
  // bitset<8> _after(n|(1<<i));
  // dbg(_after);

  return (n|(1<<i)); 
}

int altBit(int n, int i) { 
  // cerr << "Altered position " << i << endl;  
  // bitset<8> before(n);
  // dbg(before);
  // bitset<8> _after(n|(1<<i));
  // dbg(_after);

  return (n^(1<<i)); 
}

int clearBit(int n, int i) { 
  // cerr << "Cleared position " << i << endl;
  // bitset<8> before(n);
  // dbg(before);
  // bitset<8> _after(n|(1<<i));
  // dbg(_after);

  int mask=(~(1<<i)); // this called masking as the mask has "cleared" or "masked out" the ith bit of the original number.
  return (n&mask); 
}

int updateBit(int n, int i, int v){
  // cerr << "Updated position " << i << " to " << v << endl;
  // bitset<8> before(n);
  // dbg(before);
  // bitset<8> _after(n|(1<<i));
  // dbg(_after);

  // clearing 
  int mask = (~(1<<i));
  n&=mask;

  // setting value (either 0 or 1)
  return (n|(v<<i));
}

void subset(const char c[], const int& sz){
/*
  Print all the subset of the given character array
*/
  int x = (1<<sz);
  fori(x){
    forj(sz){
      if((i>>j)&1) cout << c[j];
    }
    cout << endl;
  }
}

// void slv(const vint& v){
// /*
//   You are given an array of n - 2 integers 
//   which are in the range between 1 and n. 
//   All numbers appear exactly once, except 
//   two numbers, which are missing. 
//   Find these two missing numbers.
// */

//   int xorResult=0, n=sz(v);

//   // XOR the result with all numbers from 1 to n+2
//   f(i, 1, n+3) xorResult^=i;

//   // XOR all elements in the array
//   each(val, v) xorResult^=val;

//   // Find the rightmost set bit of the result
//   int pos=log2(xorResult&(~(xorResult-1))); // pos=log2((xorResult) & -(xorResult));

//   // Partition the array and numbers from 1 to n based on the differentiating bit
//   int x=0, y=0, k=(1<<pos);
//   each(val, v){
//     if(val&k)x^=val;
//     else y^=val;
//   }

//   f(i, 1, n+3){
//     if(i&k) x^=i;
//     else y^=i;
//   }

//   cout << x << ' ' << y << endl;
// }

// void slv(const vint &v) {
// /*
//   You are given an array of some integers 
//   in which all numbers appear twice except 
//   two unique numbers. Find these two numbers.
// */

//   int xorResult = 0;

//   // XOR all elements to get xorResult = x ^ y (where x and y are the two unique numbers)
//   each(val, v) xorResult ^= val;

//   // Find the rightmost set bit of the result
//   int pos=log2(xorResult&(~(xorResult-1))); // pos=log2((xorResult) & -(xorResult));

//   // int x=0, k=(1<<pos);
//   // each(val, v){
//   //   if(val&k) x^=val;
//   // }
//   // cout << x << ' ' << (xorResult^x) << endl;

//   int x = 0, y = 0, k=(1<<pos);

//   // Partition elements based on the differentiating bit and XOR separately
//   each(val, v) {
//     if (val & k) {
//       x ^= val;  // XOR in the group where the differentiating bit is set
//     } else {
//       y ^= val;  // XOR in the group where the differentiating bit is not set
//     }
//   }

//   // Print the two unique numbers
//   cout << x << ' ' << y << endl;
// }


/// primes and no. of divisors 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool isPrime_1(int n){
  // TC: O(sqrt(n)) | SC: O(1)
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;
  for(int i=5; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}

bool isPrime_2(int n){
  // 6k ± 1 Optimization
  // TC: O(sqrt(n)/3) | SC: O(1)
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;
  for (int i=5; i*i<=n; i+=6){
    if (n%i==0 || n%(i+2)==0) return false;
  }
  return true;
}

vint primeFactors(int n){
  // Return unique prime factors | TC: O(sqrt(n))
  vint factors;
  if(n%2==0){
    factors.eb(2);
    n/=(n & -n);
  }
  for(ll i=3; i*i<=n; i+=2){
    if(n%i==0){
      factors.eb((int)i);
      while(n%i==0) n/=i;
    }
  }
  if(n>2) factors.eb(n);
  return factors;
}


#ifdef PRIME_SIEVE // Sieve of Eratosthenes | TC: O(nlog(logn)) ~ O(n)
const int MAX = 1e4;  
vint is_prime(MAX+1, 1);

void primeSieve() {
  is_prime[0] = is_prime[1] = 0;

  for(ll i=2; i*i<=MAX; ++i){
    if(!is_prime[i]) continue;
    for(ll j=i*i; j<=MAX; j+=i){
      is_prime[j]=0;  
    }
  }
}
#endif

#ifdef DIVISOR_SIEVE // Divisor Counting Sieve | TC: O(nlogn)
const int MAX=1e4;
vint cnt(MAX+1);

void divisorSieve(){
  f(i, 1, MAX+1){
    for(int j=i; j<=MAX; j+=i) cnt[j]++;
  }
}
#endif

/// Smallest Prime Factor (Prime Factorization)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef PRIME_FACTORIZATION
const int MAX=1e5;
vint spf(MAX+1);
void spfSeive(){
  f(i, 1, MAX+1) spf[i]=i; // initializing the sieve

  // marking each number with its smallest prime factor
  for(ll i=2; i*i<=MAX; i++){ 
    if(spf[i]!=i) continue;
    for(ll j=i*i; j<=MAX; j+=i){
      if(spf[j]==j) spf[j]=i;
    }
  }
}

vint primeFactorization(int n){
  // TC: log2(n)
  vint result;
  while(n>1){
    // cerr << n << ' ' << spf[n] << endl; // For better understanding
    result.eb(spf[n]); // store the smallest prime factor of n
    n/=spf[n];
  }
  return result;
}
#endif

/// binary exponentiation
//~~~~~~~~~~~~~~~~~~~~~~~~
int M=INT_MAX;
int fastpow(int x, int n){  // iterative
  // TC: O(log2(n)) | SC: O(1)
  int result=1;
  while(n>0){
    if(n&1){ // n is odd
      result=(result*x)%M;
    }
    x=(x*x)%M;
    n/=2;
  }
  return result;
}

// int fastpow(int x, int n) { // recursive
//   // TC: O(log2(n)) | SC: O(log2n)
//   if(!n) return 1;  // base case
//   int result=fastpow(x, n/2); 
//   result=(result*result)%M; 
//   if(n&1) result=(result*x)%M;
//   return result;
// }

int main() {
  fastIO();
}

