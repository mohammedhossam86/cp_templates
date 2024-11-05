#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs"<<"\n";
#define sz(x) int(x.size())
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
 
template < typename T , int Base = 0>
struct Segment_Tree
{
    #define DEF 0
    #define MID (lx+rx)/2
    #define Left (2 * idx)
    #define Right (2 * idx) + 1
private:
// ____________________________________________Editable Functions _____________________
    
    struct Node 
    {
        T val;
        Node(T V = 0) : val(V) {}
        Node operator = (const T rhs) {
            val = rhs;
            return *this;
        }
    };

// ____________________________________ Inisialiastion & Store the data in the tree _________________________
    void build(int n , const vector< T > &v , int idx , int lx, int rx)
    {
        if(Base ? lx >= sz(v) : lx > sz(v)) return;
        if(lx == rx)
            tree[idx] = v[lx - !Base];
        else
        {
            int m = MID;
            build(n, v, Left, lx, m);
            build(n, v, Right, m + 1, rx);
            tree[idx] = operation(tree[Left] , tree[Right]);
        }
    }

// ________________________________________ Update the value in the tree _______________________________
    
    void update(int index , T val , int idx , int lx , int rx)
    {
        if(lx == rx)
            tree[idx] = val;
        else
        {
            int m = MID;
            if(index <= m)
                update(index, val, Left, lx, m);
            else
                update(index, val, Right, m + 1, rx);
            tree[idx] = operation(tree[Left], tree[Right]);
        }
    }

// _________________________________________ Query the value in the tree _______________________________
    
    Node query(int l , int r , int idx , int lx , int rx)
    {
        if(lx > r || l > rx)
            return DEF;
        if(lx >= l and rx <= r)
            return tree[idx];
        int m = MID;
       
        return operation(query(l, r, Left, lx, m), query(l, r, Right, m + 1, rx));
    }

// _________________________________________ Operation to be performed _______________________________
    Node operation(const Node &a , Node const &b)
    {
        return (a.val + b.val);
    }

public:

// ______________________________________ Variables____________________

    int size;
    vector<Node> tree;

// ______________________________________ Constructors ______________________
    Segment_Tree(int n = 0)
    {
        size = 1;
        while(size < n) size *= 2;
        tree = vector<Node>(2 * size , DEF);
    }
    
    Segment_Tree(int n , const vector< T > &v)
    {
        size = 1;
        while(size < n) size *= 2;
        tree = vector<Node>(2 * size);
        build(n, v);
    }

// ________________________________________ Public Functions _______________________________
    void build(int n , const vector< T > &v)
    {
        build(n, v, 1, 1, size);
    }

    
    void update(const int index ,const  T val)
    {
        update(index, val, 1, 1, size);
    }
    

    T query(const int l ,const  int r )
    {
        return query(l, r, 1, 1, size).val;
    }
    
};

void solve()  
{
    
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
