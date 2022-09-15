You are given an undirected graph of n vertices numbered from 0 to n - 1 and m edges between them.

Each edge of the graph is weighted, each weight is a positive integer.

You are given the list of edges along with their weights, but the list is damaged: some of the weights read as 0. If an edge has 0 weight, it means the information about its original weight is lost.

You want the length of the shortest path between vertices s and t in the graph to be exactly L.

Is it possible to restore some or all of the missing weights to make this happen?

Input

The first line contains five integers n, m, L, s, t (2 ≤ n ≤ 1000,  1 ≤ m ≤ 10000,  1 ≤ L ≤ 10^9,  0 ≤ s, t ≤ n - 1,  s ≠ t) — the number of vertices, number of edges, the desired length of shortest path, starting vertex and ending vertex respectively.

Then, m lines describing the edges of the graph follow. i-th of them contains three integers, ui, vi, wi (0 ≤ ui, vi ≤ n - 1,  ui ≠ vi,  0 ≤ wi ≤ 10^9). ui and vi denote the endpoints of the edge and wi denotes its weight. If wi is equal to 0 then the weight of the corresponding edge was erased.

It is guaranteed that there is at most one edge between any pair of vertices.

Output

Print "NO" (without quotes) if it's not possible to assign the missing weights to achieve the desired effect. Otherwise, print "YES".

Examples

input
5 5 13 0 4
0 1 5
2 1 2
3 2 3
1 4 0
4 3 4

output
YES

input
2 1 2390 0 1
0 1 0

output
YES

input
2 1 99 1 0
0 1 101

output
NO

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 1001;
const int M = 10001;
const ll INF = ll(1e18);

int n, m, l, s, e;

struct edge
{
	int to; ll w; int label;
	edge(int _to, int _w, int _label){to = _to, w = _w, label = _label;}
};

int edgecnt = -1;
vector<edge> adj[N];
ll dist[N];
set<ii> used;

ll dijk(int p, ll val)
{
	for(int i = 0; i < n; i++) dist[i] = INF;
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while(!pq.empty())
	{
		int u = pq.top().se; ll d = pq.top().fi; pq.pop();
		for(int i = 0; i < adj[u].size(); i++)
		{
			edge tmp = adj[u][i];
			int v = tmp.to; ll w = tmp.w; int lab = tmp.label;
			if(lab >= 0)
			{
				if(lab < p) w = 1;
				else if(lab == p) w = val;
				else w = ll(1e14);
			}
			if(d + w < dist[v])
			{
				dist[v] = d + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
	return dist[e];
}

void setw(int p, ll val)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < adj[i].size(); j++)
		{
			int lab = adj[i][j].label;
			if(lab >= 0)
			{
				if(lab < p)
				{
					adj[i][j].w = 1;
				}
				else if(lab == p)
				{
					adj[i][j].w = val;
				}
				else
				{
					adj[i][j].w = INF;
				}
			}
		}
	}
}

void print()
{
	cout << "YES\n";
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> l >> s >> e;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		int lab = -1;
		if(w == 0) 
		{
			lab = ++edgecnt;
		}
		adj[u].pb(edge(v, w, lab));
		adj[v].pb(edge(u, w, lab));
	}
	ll x = dijk(edgecnt, 1); ll y = dijk(-1, 1);
	if(!(x <= l && l <= y))
	{
		cout << "NO\n";
		return 0;
	}
	ll lo = -1; ll hi = edgecnt;
	ll mid, ans;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		if(dijk(mid, 1) <= l)
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	//now [0..ans] as 1 will give <= L whereas [0..ans - 1] as 1 will give > L
	if(ans == -1)
	{
		setw(-1, 0);
		print();
		return 0;
	}
	lo = 1; hi = INF;
	int ans2 = 0;
	while(lo <= hi)
	{
		mid = (lo+hi)>>1;
		if(dijk(ans, mid) <= l)
		{
			ans2 = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	//cerr << ans << ' ' << ans2 << '\n';
	setw(ans, ans2);
	print();
}
