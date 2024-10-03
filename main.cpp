#include <bits/stdc++.h>
using namespace std;
 
//~~~---------------------~~~---------------------~~~---------------------~~~---------------------~~~---------------------~~~

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
typedef vector<vint> vvi; // v(n, vint(m));
typedef vector<vll> vvl; // v(n, vll(m));


// Macros
//~~~~~~~~
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define str string
#define vec vector
 
#define yn(flag) cout << (flag?"YES":"NO") << endl

#define fori(n) for(int i=0; i<n; ++i)
#define forj(n) for(int j=0; j<n; ++j)
#define fork(n) for(int k=0; k<n; ++k)
#define f(i, x, n) for(int i=x; i<n; ++i)
#define rf(i, x, n) for(int i=x; i>=n; --i)
#define each(itm, cn) for(auto &itm : cn)

#define sz(cn) ((int)(cn).size()) // size() | TC: O(1)
#define len(arr) ((int)(sizeof(arr)/sizeof((arr)[0]))) // length of an array | TC: O(1)

#define all(cn) (cn).begin(), (cn).end()
#define rall(cn) (cn).rbegin(), (cn).rend()

#define minel(cn) min_element(all(cn))
#define maxel(cn) max_element(all(cn))

#define unq(v) { sort(all(v)); (v).resize(unique(all(v)) - (v).begin()); } // Only for Vectors | TC: O(nlogn);
#define fill(a, b) memset((a), (b), sizeof(a)) // Only for Arrays | TC: O(n)
#define cpy(a, b) memcpy((a), (b), sizeof(a)) // Only for Arrays | TC: O(n)

#define prcsn(x,y) fixed<<setprecision(y)<<x
#define diglen(n) ((int)log10(n) + 1)

#define lowbit(x) log2((x)&(-x)) // Returns the position of right most set bit
#define bits(num, bits) bitset<bits>(num)

#define flush() cin.ignore()

#define ff first
#define ss second
#define mkpr make_pair

#define pp pop_back
#define pf push_front
#define pb push_back 
#define eb emplace_back

#define endl '\n'
#define newl cout << '\n'

#define popct __builtin_popcountll // Returns the population of the set bits 

// #define lcm(a, b) (a && b ? (a/gcd(a, b))*b : 0) 


// Debuggers
//~~~~~~~~~~~
void _print() { cerr << endl; }

template<typename T, typename... Ts>
void _print(T var, Ts... vars){
  cerr << var;
  if(sizeof...(vars)) cerr << ", ";
  _print(vars...);
}

#define dbg(x...) cerr << (#x) << " = ", _print(x)

#define dbgcs(cs, x...) cerr << cs << ": " << (#x) << " = ", _print(x)


// Reader
//~~~~~~~~
template<typename T>
void _read(T& t) { cin >> t; }

template<typename T, typename... Args>
void _read(T& first, Args&... args){
  cin >> first;
  _read(args...);
}

#define read(type, ...) type __VA_ARGS__; _read(__VA_ARGS__);


// Constants
//~~~~~~~~~~~
const int MN = INT_MIN;
const int MX = INT_MAX;
const ll LL_MN = LLONG_MIN;
const ll LL_MX = LLONG_MAX;
const int MOD=1e9+7;


// Fast I/O: https://www.youtube.com/watch?v=aNF4DEluWnI
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void fastIO(){ 
  // 1st way
  cin.tie(nullptr)->sync_with_stdio(false);

  // 2nd way
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr); 

  // 3rd way
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
}
 

// Utils 
//~~~~~~~
ll safe_lcm(const ll& a, const ll& b){
  if(!a || !b) return 0;
  ll x=a/gcd(a, b);
  if(x > LL_MX/b) return LL_MX;
  return x*b;
}

int binarySearch(const vint& v, const int& q) {
  // two pointers
  int st=0;
  int en=sz(v)-1;
  while(st<=en){
    int mid=st+(en-st)/2;
    if(v[mid]==q) return mid;
    else if(q>v[mid]) st=mid+1;
    else en=mid-1;
  }
  return -1;
}

ull largestDivisor(ull n){
  // 6k ± 1 Optimization
  if(n%2==0) return n/2;
  if(n%3==0) return n/3;
  ull largest=1;
  ull limit=sqrt(n);
  for(int i=5; i<=limit; i+=6){
    if(n%i==0 && n/i!=n) largest=max(largest, n/i);
    if(n%(i+2)==0 && n/(i+2)!=n) largest=max(largest, n/(i+2));
  }
  return largest > 1 ? largest : 1;
}

bool isPrime(int n){
  // 6k ± 1 Optimization
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;
  for(int i=5; i*i<=n; i+=6){
    if (n%i==0 || n%(i+2)==0) return false;
  }
  return true;
}

vint primeFactors(int n){
  // prime factorization
  // Returns unique prime factors 
  vint prf;
  if(n%2==0){
    prf.eb(2);
    n/=(n & -n);
  }
  for(ll i=3; i*i<=n; i+=2){
    if(n%i==0){
      prf.eb((int)i);
      while(n%i==0) n/=i;
    }
  }
  if(n>2) prf.eb(n);
  return prf;
}

// #define PRIME_SIEVE // Sieve of Eratosthenes | TC: O(nlog(logn)) ~ O(n)
#ifdef PRIME_SIEVE 
const int MAX = 1e4;  
vint is_prime(MAX+1, 1);

void primeSieve() {
  is_prime[0] = is_prime[1] = 0;
  for(ll i=2; i*i<=MAX; ++i){
    if(!is_prime[i]) continue;
    for(ll j=i*i; j<=MAX; j+=i) is_prime[j]=0; 
  }
}

// const int MAX = 1e5;
// vint is_prime(MAX+1, 1), primes;
// void primeSieve() {
//   is_prime[0] = is_prime[1] = 0;
//   for(ll i=2; i<=MAX; ++i){
//     if(!is_prime[i]) continue;
//     primes.eb(i);
//     for(ll j=i*i; j<=MAX; j+=i) is_prime[j]=0; 
//   }
// }
#endif

//~~~---------------------~~~---------------------~~~---------------------~~~---------------------~~~---------------------~~~


// Entering the Code's Temenos:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// int cs=1;
void solve(){
  // cerr << cs << ": ";
  
  // cerr << endl; ++cs;
}


int main() {
  // auto start = chrono::high_resolution_clock::now(); 
  fastIO(); // Setup fast I/O
  int tc; cin >> tc; 
  while(tc--){ 
    solve(); 
  } 
  // auto end = chrono::high_resolution_clock::now();
  // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); 
  // cerr << duration.count() << " ms" << endl; 
  return 0; 
} 
