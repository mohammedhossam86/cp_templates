#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs"<<"\n";
#define sz(x) int(x.size())
#define rv(x) return void(cout << x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v, n) memset(v, n, sizeof(v))
// #define fix_mod(a,b) ((a %))
#define newl cout << "\n" ;
#define ull unsigned ll
using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
void Hosska() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x <<" ";  
    return out;
}
 
const int N = 200000 + 5, LOG = 23;
int n, q;
vector<ll> adj[N];
ll anc[N][LOG], depth[N];
void getAncestors(int node, int par)
{
    depth[node] = depth[par] + 1;
    anc[node][0] = par;
    for (int i = 1; i < LOG; i++)
    {
        int p = anc[node][i - 1];
        anc[node][i] = anc[p][i - 1];
    }
    for(auto child : adj[node])
    {
        if(child != par)
            getAncestors(child , node);
    }
}
 
int kthAncestor(int node , int k)
{
    for (int i = LOG - 1; i >= 0; i--)
    {
        if((k >> i) & 1)
        {
            node = anc[node][i];
        }
    }
    return node;
}
 
void solve()  
{
    cin >> n >> q;
    
}
 
int main()
{
    Hosska();
    auto t1 = high_resolution_clock::now();
    int test = 1;
    // cin >> test;
    for(int i = 1; i <= test; i++){
        solve();
        cout << "\n";
        // cout << "Case #" << i << ": ";
    }
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    #ifndef ONLINE_JUDGE
        cout << "Time Taken : " << ms_double.count() << "ms";
    #endif
    return 0;
}
