//
// Created by rajat joshi on 31-08-2022.
//


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sza(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define revall(x) x.rbegin(), x.rend()
#define ALL(x) sort(x.begin(), x.end())
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define PF push_front
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<long,long> PII;
typedef vector<long long> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<vector<ll>> VII;
typedef vector<pair<int,bool>>VPBI;
typedef vector<pair<int,int>>VPII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef vector<set<int>> VSI;
// typedef vector<string> VS;
typedef map<int,int> MPII;
typedef set<long long> SETI;
typedef multiset<int> MSETI;
typedef priority_queue<pair<int,int>> PQPII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ff(a,b) for(int i=a;i<b;i++)
#define nl endl


/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vd vector<double>
#define mii map<long,long>
#define MPC map<char,int>
#define miid map<double,long>
#define si set<int>
#define sc set<char>
#define vi vector<int>

/* FUNCTIONS */
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(i,s,e) for(long long int i=s;i>=e;--i)
#define For1(i,n) or(long long int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FO(i,s,e) for(long long int i=1;i*i<=y;i++)
#define rf(i,e,s) for(long long int i=n-1;i>=0;i--)
#define pass(a)  for(long long int i=n-1;i>=1;i-=2)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }


void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }




/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

bool isprime(ll n)
{
    ll x=sqrt(n);
    for(int i=2;i<=x;i++)
    {if(n%i==0)return true;}
    return false;
}


bool cmp(pair<int,int>x,pair<int,int>y){
    return x.second<y.second;
}


void two_D_PrifixSum()
{
    //prefix sum in 2 D array
    int n,m;cin>>n>>m;
    int a[n][m],prefix[n][m];
    f1(i,0,n)
    {
        f1(j,0,m)
        {
            cin>>a[i][j];
        }
    }

    //create a prefix array
    f1(i,0,n)
    {
        f1(j,0,m)
        {
            prefix[i][j]=a[i][j];
            if(i-1>=0)prefix[i][j]+=prefix[i-1][j];
            if(j-1>=0)prefix[i][j]+=prefix[i][j-1];

            if(i-1>=0 and j-1>=0)
            {
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int i1,i2,j1,j2;cin>>i1>>i2>>j1>>j2;
    }
}


//Scanline algorithm
void scanlineAlgoritm()
{
    int n;cin>>n;
    int a[n];
    f1(i,0,n)cin>>a[i];

    int prefixSum[n+1];
    int q;cin>>q;
    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        prefixSum[l]+=x;
        prefixSum[r+1]-=x;
    }
    int s=0;
    f1(i,0,n)
    {
        s+=prefixSum[i];
        a[i]+=s;
    }
    f1(i,0,n)cout<<a[i]<<" ";
}

int findMin(vector<bool>&vis,VI distance)
{
    int start=-1;
    int n=vis.size();
    f1(i,0,n)
    {
        if(start==-1 or distance[start]>distance[i])
            start=i;
    }
    return start;
}

int dist(VPII vis,int n)
{
    vector<bool>ar(n,false);
    VI temp(n,INF);
    ar[1]=0;

    int val=findMin(ar,temp);
    if(val==-1)return 0;
    ar[val]=true;
    cf(i,0,n)
    {
        return temp[n];
    }
}


bool binarySearch(ll mid,ll k,ll x)
{
    ll tot=0;
    mid-=1;
    if(mid<=k)
        tot=(mid*(mid+1))/2;
    else
    {
        tot=(k*(k+1))/2;
        mid=2*k-1-mid;
        tot+=((k*(k-1))/2-(mid*(mid+1))/2);
    }
    return tot<x;
}


/*
0 0 2 0 0 0 0 0
1 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
void test()
{
    int a[8][8];
    f1(i,0,8)
    {
        f1(j,0,8)
        {a[i][j]=0;}
    }
    int row,cols;cin>>row>>cols;
    a[row][cols]=1;
    // if(row>2 and row<8)
    if(cols>=2 and cols<=8)
    {
        /*
            case 1: n pos row and 2nd col then 2
            case 2: n-1 pos row and 2nd pos col then 2
            case 3: n pos row and m-1 col then 2
            case 4: n-1 pos row and m pos col then 2
        */
        a[row+1][cols+2]=2;
        a[row+1][cols-2]=2;
        a[row-1][cols+2]=2;
        a[row-1][cols-2]=2;
    }

    else if(cols<=2){a[row+1][cols+2]=2;a[row-1][cols+2]=2;}
    f1(i,0,8)
    {
        f1(j,0,8)
        {cout<<a[i][j]<<" ";}cout<<nl;
    }
}


void solve()
{
    int n,burstTime[1001],waitingTime[1001],turnAroundTime[1001],averageWaitingTime=0,averageTurnAroundTime=0,i,j;
    waitingTime[0]=0;
    cin>>n;
    cout<<"\nTotal number of processes:"<<n<<nl;
    f1(i,0,n){cin>>burstTime[i];}

    //display gantt chart
    puts("Gantt Chart:");
    f1(i,0,n){cout<<"\tp["<<i+1<<"]";}

    //calculating waiting time
    cout<<nl<<nl<<"\t";
    f1(i,0,n)
    {
        waitingTime[i]=0;
        f1(j,0,i)
            waitingTime[i]+=burstTime[i];
        cout<<"\t  "<<waitingTime[i];
    }

    cout<<nl<<nl<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //calculating turn-around time
    f1(i,0,n)
    {
        turnAroundTime[i]=burstTime[i]+waitingTime[i];
        averageWaitingTime+=waitingTime[i];
        averageTurnAroundTime+=turnAroundTime[i];

        cout<<nl<<"P["<<i+1<<"]"<<"\t\t"<<burstTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnAroundTime[i];
    }

    //calculating avarage of waiting time and turnaround time
    averageTurnAroundTime=averageTurnAroundTime/=i;
    averageWaitingTime=averageWaitingTime/=i;

    cout<<nl<<nl<<"Average Waiting Time:"<<averageWaitingTime;
    cout<<nl<<"Average Turnaround Time:"<<averageTurnAroundTime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif
    // int tests;
    // cin >> tests;

    // for (int tc = 1; tc <= tests; tc++) {
    solve();
    cout<<flush;
    // }
}