#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs"<<"\n";
#define sz(x) int(x.size())
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define cin(v) for(auto &x : v) cin >> x;
#define cout(v) for(auto &x : v) cout << x<<" ";
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

struct DSU{
    // containers
    public:
    vector<ll> parent, gsize;

    // constractor
    DSU(ll n)
    {
        parent.resize(n + 1);
        gsize.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i, gsize[i] = 1;
    }

    // get parent , ->> PATH COMPRESSION
    ll get_parent(ll x)
    {
        return parent[x] = (parent[x] == x ? x : get_parent(parent[x]));
    }

    // in the same group
    bool same_set(ll x , ll y)
    {
        x = get_parent(x), y = get_parent(y);
        return x == y;
    }

    // get the size
    ll set_size(ll x)
    {
        x = parent[x];
        return gsize[x];
    }
    
    // Union
    void Union(ll x , ll y)
    {
        x = get_parent(x) , y = get_parent(y);
        if(x == y)
            return;
        if (set_size(x) < set_size(y))
            swap(x , y);
        gsize[x] += gsize[y];
        parent[y] = x;

    }
};

void solve()
{
}

int main()
{
    Hosska();
    auto t1 = high_resolution_clock::now();
    ll ti = 1;
    cin >> ti;
    // int i = 1;
    while (ti--)
    {
        solve();
        newl;
        // cout << i << " ";
    }
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    #ifndef ONLINE_JUDGE
        cout << "Time Taken : " << ms_double.count() << "ms";
    #endif
}