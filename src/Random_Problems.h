//============================================================================
// Name        : Stack Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Stack Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

struct edge{
	public:
		int src;
		int dst;
		int cost;
		edge(int i,int j,int x=1){
			src=i;
			dst=j;
			cost=x;
		}
};

void RollingHash(string &a,string &b,int m,int n){
	int ha=0;
	int hb=0;
	int p=31;
	vector<int> v;
	for(int i=0;i<n;i++){
		ha=ha+a[i]*pow(p,i);
		hb=hb+b[i]*pow(p,i);
	}
	for(int i=0;i<=m-n;i++){
		if(ha==hb){
			if(b.compare(a.substr(i, n))==0)
				v.push_back(i);
		}
		ha=(ha-a[i])/p;
		ha=ha+a[i+n]*pow(p,n-1);
	}
	for(int i : v)
		cout<<i<<'\n';
}

void Z(string &a,string &b,int m,int n){
	string c=b+'$'+a;
	int z=c.length();
	vector<int> v(z);
	v[0]=0;
	for(int i=1;i<z;i++){
		int t=i;
		int j=0;
		while(c[j]==c[t]){
			j++,t++;
		}
		v[i]=j;
		if(j==n)
			cout<<i-n-1<<'\n';
	}
}

void swap(char &a,char &b){
	char t=a;
	a=b;
	b=t;
}


bool isSafe(string &a,int i,int j){
	for(int k=i;k<j;k++)
		if(a[j]==a[k])
			return 0;
	return 1;
}

void Permutation(string &a,int i,int j){
	if(i>=j){
		cout<<a<<'\n';
		return ;
	}
	for(int k=i;k<j;k++){
		if(isSafe(a, i, k)){
			swap(a[i], a[k]);
			Permutation(a, i+1, j);
			swap(a[i], a[k]);
		}
	}
}

void BellmanFord(vector<edge> &e,int n,int s){
	vector<int> d(n,INT_MAX);
	vector<int> p(n,-1);
	d[s]=0;
	int k=n+1;
	while(k--){
		for(edge i : e){
			if(k==1 && (d[i.src]!=INT_MAX && i.cost+d[i.src]<d[i.dst])){
				cout<<"Negative\n";
				return;
			}
			else if(d[i.src]!=INT_MAX && i.cost+d[i.src]<d[i.dst]){
				d[i.dst]=i.cost+d[i.src];
				p[i.dst]=i.src;
			}
		}
	}
}

void FloydWarshall(vector<vector<int>> &e,int n){
	vector<vector<int>> d=e;
	vector<vector<int>> p;
	p.resize(n,vector<int> (n,-1));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
				else if(p[i][j]==-1)
					p[i][j]=i;
			}
		}
	}
}

class DisjoinedSet{
	private:
		unordered_map<int,int> p;
	public:
		DisjoinedSet(int n){
			for(int i=0;i<n;i++)
				p[i]=i;
		}
		void Union(int x,int y){
			int a=Find(x);
			int b=Find(y);
			p[b]=a;
		}
		int Find(int x){
			if(p[x]==x)
				return x;
			return Find(p[x]);
		}
};

struct comp{
	public:
		bool operator()(edge &a,edge &b){
			return a.cost>b.cost;
		}
};

void Kruskal(vector<edge> &e,int n){
	vector<edge> v;
	priority_queue<edge,vector<edge>,comp> q;
	for(edge i : e)
		q.push(i);
	DisjoinedSet d(n);
	while((int)v.size()!=n-1){
		auto k=q.top();
		q.pop();
		int i=d.Find(k.src);
		int j=d.Find(k.dst);
		if(i!=j){
			v.push_back(k);
			d.Union(i, j);
		}
	}
}


bool CycleDetectionUnDirected(vector<edge> &e,int n){
	DisjoinedSet d(n);
	for(edge i : e){
		int x=d.Find(i.src);
		int y=d.Find(i.dst);
		if(x!=y)
			d.Union(x, y);
		else
			return 1;
	}
	return 0;
}

void Dijkstra(vector<edge> &e,int n,int s){
	vector<vector<pair<int,int>>> v(n);
	for(edge i : e)
		v[i.src].push_back({i.dst,i.cost});
	vector<bool> t(n);
	vector<int> d(n,INT_MAX);
	vector<int> p(n,-1);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({d[s],s});
	while(!q.empty()){
		s=q.top().second;
		q.pop();
		for(auto i : v[s]){
			if(d[i.first]>d[s]+i.second && !t[i.first]){
				d[i.first]=d[s]+i.second;
				p[i.first]=s;
				q.push({d[i.first],i.first});
			}
		}
		t[s]=1;
	}
}

void CycleDetectionDirected(vector<edge> &e,int n){
	vector<vector<pair<int,int>>> v(n);
	for(edge i : e)
		v[i.src].push_back({i.dst,i.cost});
	vector<bool> t(n);
	vector<int> d(n,INT_MAX);
	int s=0;
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({d[s],s});
	while(!q.empty()){
		int s=q.top().second;
		q.pop();
		for(auto i : v[s]){
			if(d[i.first]>d[s]+i.second && !t[i.first]){
				d[i.first]=d[s]+i.second;
				q.push({d[i.first],i.first});
			}
			else if(t[i.first]){
				cout<<"Cycle Found.\n";
				return;
			}
		}
		t[s]=1;
	}
}

bool isQueenSafe(vector<vector<char>> &v,int r,int c){
	for(int i=0;i<r;i++)
		if(v[i][c]=='Q')
			return 0;

	for(int i=r,j=c;i>=0 && j>=0;i--,j--)
		if(v[i][j]=='Q')
			return 0;

	for(int i=r,j=c;i>=0 && j>=0;i--,j++)
		if(v[i][j]=='Q')
			return 0;

	return 1;
}

void NQueenRecursion(vector<vector<char>> &v,int s,int n){
	if(s==n){
		for(auto i : v){
			for(auto j : i)
				cout<<j<<' ';
			cout<<'\n';
		}
		cout<<'\n';
	}
	for(int i=0;i<n;i++){
		if(isQueenSafe(v, s, i)){
			v[s][i]='Q';
			NQueenRecursion(v, s+1, n);
			v[s][i]='_';
		}
	}
}

void NQueen(int n){
	vector<vector<char>> v(n,vector<char> (n,'_'));
	int s=0;
	NQueenRecursion(v, s, n);
}

void KMP(string &a,string &b,int m,int n){
	vector<int> v(n);
	vector<int> t;
	for(int i=0,j=1;j<n;j++){
		if(b[i]==b[j] && j<n){
			v[j]=i+1;
			i++;
		}
		else {
			v[j]=0;
			i=0;
		}
	}
	for(int i=0,j=0;i<m;i++){
		if(a[i]==b[j]){
			if(++j==n)
				t.push_back(i-n+1);
		}
		else if(j>0){
			j=v[j-1];
			i--;
		}
	}

	for(int i : t)
		cout<<i<<' ';
}

void HamiltonianCycleRecursion(vector<vector<int>> &a,int &n,int s,vector<bool> &v,
		vector<int> &p){

	if(n==(int)p.size()){
		for(int i : p)
			cout<<i<<' ';
		cout<<'\n';
		return ;
	}
	for(int i=0;i<n;i++){
		if(!v[i] && a[s][i]){
			v[i]=1;
			p.push_back(i);
			HamiltonianCycleRecursion(a, n, i, v, p);
			p.pop_back();
			v[i]=0;
		}
	}
}

void HamiltonianCycle(vector<vector<int>> &a,int n){
	int s=0;
	vector<bool> v(n);
	vector<int> p;
	v[s]=1;
	p.push_back(s);
	HamiltonianCycleRecursion(a, n, s, v, p);
}

void TravellingSalesManRecursion(vector<vector<int>> &a,int &n, vector<bool> &v,
		vector<int> &p, int &s, int c,int &m){

	if(n==(int)p.size()){
		c+=a[s][0];
		m=min(m,c);
		for(int i : p)
			cout<<i<<' ';
		cout<<c<<'\n';
		return;
	}

	for(int i=0;i<n;i++){
		if(!v[i] && a[s][i]){
			v[i]=1;
			c+=a[s][i];
			p.push_back(i);
			TravellingSalesManRecursion(a, n, v, p, i, c, m);
			p.pop_back();
			c-=a[s][i];
			v[i]=0;
		}
	}
}

void TravellingSalesMan(vector<vector<int>> &a,int &n){
	int s=0;
	int c=0;
	int m=INT_MAX;
	vector<bool> v(n);
	vector<int> p;
	v[s]=1;
	p.push_back(s);
	TravellingSalesManRecursion(a, n, v, p, s, c, m);
	cout<<m<<'\n';
}

void DFS(vector<vector<int>> &a,int &n,stack<int> &s,vector<bool> &v,int &i){
	v[i]=1;
	for(int j=0;j<n;j++){
		if(!v[j] && a[i][j]){
			DFS(a, n, s, v, j);
		}
	}
	s.push(i);
}

void TopologicalSort(vector<vector<int>> &a,int &n){
	stack<int> s;
	vector<bool> v(n);

	for(int i=0;i<n;i++){
		if(!v[i]){
			DFS(a, n, s, v, i);
		}
	}
	while(!s.empty()){
		cout<<s.top()<<'\n';
		s.pop();
	}
}
