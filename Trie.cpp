// #include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <cstring>
#include <vector>
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
 
template <int Base = 26>
struct Trie
{
    char edit;
    struct Node
    {
        Node *ch[Base];
        int Pref, End;
        Node()
        {
            Pref = End = 0;
            memset(ch,0, sizeof ch);
        }
    };

    Node *root = new Node();
    Trie()
    {
        if(Base == 26)
            edit = 'a';
        else if(Base == 9)
            edit = '0';
    }
// __________________________________INSERTION_______________________________
    void insert(const string &g)
    {
        Node *curr = root;
        for(auto i :g)
        {
            int idx = i - edit;
            if(curr->ch[idx] == 0)
                curr->ch[idx] = new Node();
            curr->Pref++;
            curr = curr->ch[idx];
        }
        curr->End++;
    }
// ________________________________ COUNT PREFIX_____________________________
    int pref(const string &g)
    {
        Node *curr = root;
        for(auto i : g)
        {
            int idx = i - edit;
            if(curr->ch[idx] == 0)
                return 0;
            curr = curr->ch[idx];
        }
        return curr->Pref+curr->End; // if including the whole word if exist
    }
// _______________________________ COUNT WORD _______________________________
    int Word(const string &g)
    {
        Node *curr = root;
        for(auto i : g)
        {
            int idx = i - edit;
            if(curr->ch[idx] == 0)
                return 0;
            curr = curr->ch[idx];
        }
        return curr->End;
    }
};

void solve()  
{
    Trie<> tr;
    
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
