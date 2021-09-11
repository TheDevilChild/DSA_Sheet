#ifndef totallyNotLegitStuffHere
#include <bits/stdc++.h>
using namespace std;
/***************************Start Of Template********************/
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define MAX 1e9
#define MIN -1e9

#define int long long
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<string> uss;
typedef unordered_map<int,int> umii;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second

#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define br printf("\n")

#define gtarr(arr,beg,end) for(int i = beg; i < end; i++) cin>>arr[i];
#define gta(arr,end) for(int i = 0; i < end; i++) cin>>arr[i];
#define ptarr(arr,beg,end) for(int i = beg; i < end; i++) cout<<arr[i]<<" ";
#define pta(arr,end) for(int i = 0; i < end; i++) cout<<arr[i]<<" ";
#define gtv(arr,end) for(int i=0;i<end;i++) {int temp;cin>>temp;arr.push_back(temp);}

template <typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template <typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define deb(x,n) cerr<< #x <<" "; _print(x,n); cerr<<endl;
#else
#define debug(x)
#define deb(x,n)
#endif

template<class T>void _print(T t) {cerr << t;}

template <class T> void _print(T v[], int n);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(T v[], int n){cerr << "[ ";for (int i = 0; i < n; i++){_print(v[i]);cerr << " ";}cerr << "]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*************************End Of Template*************************/
#endif


//Here we take 2 pointers start and end and start traversing as follows..
//If a[start] == a[end] then no merging is requrired and we move to next elements
//If a[start] is less then merging at start side is requrired.. So we move to start + 1 and
//add value of a[start] into it and then again compare and increase the counter for counting merges
//If a[end] is less then merging is required at end side.. So we move to end -1 and add a[end] to
//it and then again compare and increase the counter.
//Time Complexity - O(n) Space complexity - O(1)
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n;i++){
			cin >> a[i];
		}
		int start = 0, end = n - 1;
		int count = 0;
		while(start<=end){
			if(a[start]==a[end]){
				start++;
				end--;
			}else if(a[start]<a[end]){
				a[start + 1] += a[start];
				start++;
				count++;
			}else{
				a[end - 1] += a[end];
				end--;
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}