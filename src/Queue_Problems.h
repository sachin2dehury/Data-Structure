//============================================================================
// Name        : Queue Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Queue Problems in C++,inc[i][j][istrue]i-style
//============================================================================


#include <bits/stdc++.h>

using namespace std;

class Queue_using_Deque{
	private:
		deque<int> s;
	public:
		void push(int x){
			s.push_back(x);
		}
		void pop(){
			s.pop_front();
		}
		int front(){
			return s[0];
		}
		int size(){
			return s.size();
		}
		bool empty(){
			return s.empty();
		}
};

class Random_Problems{

	public:

		int SnakeLadder(map<int,int> &m){
			int n=0;
			int d=0;
			bool v[101];
			queue<pair<int,int>> q;
			q.push({n,d});
			v[n]=1;
			while(!q.empty()){
				n=q.front().first;
				d=q.front().second;
				q.pop();
				if(n==100)
					return d;
				for(int i=1;i<7;i++){
					int x=i+n;
					if(!v[x]){
						if(m[x])
							q.push({m[x],d+1});
						else
							q.push({x,d+1});
						v[x]=1;
					}
				}
			}
			return -1;
		}

		bool isIsland(int i,int j,int m,int n){
			return (i>=0 && j>=0 && m>i && n>j);
		}

		int Islands(vector<vector<bool>> &a,int &m,int &n){
			queue<pair<int,int>> q;
			vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
			bool v[m][n];
			memset(v,0,sizeof(v));
			int k=0;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(a[i][j] && !v[i][j]){
						q.push({i,j});
						v[i][j]=1;
						k++;
					}
				}
			}
			while(!q.empty()){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				for(auto s : moves){
					int r=x+s.first;
					int c=y+s.second;
					if(isIsland(r, c, m, n) && !v[r][c] && a[r][c]){
						v[r][c]=1;
						q.push({r,c});
					}
				}
			}
			return k;
		}

		bool isValidMin(int i,int j,int m,int n){
			return (i>=0 && j>=0 && m>i && n>j);
		}

		int MinimumPass(vector<vector<int>> &a,int &m,int &n){
			queue<pair<int,int>> q;
			vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
			bool v[m][n];
			memset(v,0,sizeof(v));
			int k=0;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(a[i][j]>0 && !v[i][j]){
						q.push({i,j});
						v[i][j]=1;
						k++;
					}
				}
			}
			while(!q.empty()){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				for(auto s : moves){
					int r=x+s.first;
					int c=y+s.second;
					if(isValidMin(r, c, m, n) && !v[r][c] && a[r][c]<0){
						v[r][c]=1;
						a[r][c]=abs(a[r][c]);
						q.push({r,c});
					}
				}
			}
			return k;
		}

		bool isLandMine(int i,int j,int m,int n){
			return (i>=0 && j>=0 && m>i && n>j);
		}

		void LandMine(vector<vector<char>> &a,int &m,int &n){
			int v[m][n];
			memset(v,-1,sizeof(v));
			queue<pair<pair<int,int>,int>> q;
			int d=0;
			vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(a[i][j]=='M'){
						q.push({{i,j},d});
						v[i][j]=d;
					}
					else if(a[i][j]=='X')
						v[i][j]=-1;
				}
			}
			while(!q.empty()){
				int x=q.front().first.first;
				int y=q.front().first.second;
				d=q.front().second;
				q.pop();
				for(auto k : moves){
					int r=x+k.first;
					int c=y+k.second;
					if(isLandMine(r, c, m, n) && a[r][c]=='O' && v[r][c]<0){
						q.push({{r,c},d+1});
						v[r][c]=d+1;
					}
				}
			}
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					cout<<v[i][j]<<' ';
				}
				cout<<endl;
			}
		}

		bool isValidChessKnight(int &n,int &i,int &j){
			return (i>=0 && j>=0 && i<n && j<n);
		}

		int ChessKnight(int i,int j,int x,int y){
			int n=8;
			vector<pair<int,int>> moves={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
			queue<pair<pair<int,int>,int>> q;
			int s=0;
			q.push({{i,j},s});
			while(!q.empty()){
				i=q.front().first.first;
				j=q.front().first.second;
				s=q.front().second;
				q.pop();
				if(i==x && j==y)
					return s;
				for(auto k : moves){
					int r=i+k.first;
					int c=j+k.second;
					if(isValidChessKnight(n, i, j)){
						q.push({{r,c},s+1});
					}
				}
			}
			return -1;
		}

		bool isValidShortestPath(int &m,int &n,int &i,int &j){
			return (i>=0 && j>=0 && i<m && j<n);
		}

		int ShortestPath(vector<vector<bool>> &a,int i,int j,int x,int y){
			int m=a.size();
			int n=a[0].size();
			bool v[m][n];
			memset(v, 0, sizeof(v));
			vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
			queue<pair<pair<int,int>,int>> q;
			int dist=0;
			q.push({{i,j},dist});
			v[i][j]=1;
			while(!q.empty()){
				i=q.front().first.first;
				j=q.front().first.second;
				dist=q.front().second;
				q.pop();
				if(i==x && j==y)
					return dist;
				for(auto k : moves){
					int r=i+k.first;
					int c=j+k.second;
					if(isValidShortestPath(m, n, r, c) && a[r][c] && !v[r][c] ){
						v[r][c]=1;
						q.push({{r,c},dist+1});
					}
				}
			}
			return -1;
		}

		string GenerateBinary(int n){
			queue<string> q;
			q.push("1");
			string s;
			int i=1;
			while(i<=n){
				s+=q.front()+'\n';
				q.push(q.front()+"0");
				q.push(q.front()+"1");
				q.pop();
				i++;
			}
			cout<<s;
			return s;
		}


		class edge{
			public:
				int src;
				int dst;
				int cost=0;
		};

		int TotalPaths(vector<edge> &e,int n,int m,int i,int d){
			bool v[n][n];
			memset(v, 0, sizeof(v));
			queue<pair<int,int>> q;
			int k=0;
			for(edge i : e)
				v[i.src][i.dst]=1;
			q.push({i,k});
			while(!q.empty()){
				i=q.front().first;
				int l=q.front().second;
				q.pop();
				if(l==m && i==d)
					k++;
				if(l>m)
					break;
				for(int j=0;j<n;j++){
					if(v[i][j])
						q.push({j,l+1});
				}
			}
			return k;
		}

		int MinimumCost(vector<edge> &e,int n,int i,int d){
			int v[n][n];
			memset(v,0,sizeof(v));
			queue<pair<int,int>> q;
			for(edge i : e)
				v[i.src][i.dst]=i.cost;
			int k=0;
			int x=INT_MAX-1;
			q.push({i,k});
			while(!q.empty()){
				i=q.front().first;
				k=q.front().second;
				q.pop();
				if(i==d)
					x=min(k,x);
				for(int j=0;j<n;j++){
					if(v[i][j])
						q.push({j,k+v[i][j]});
				}
			}
			return x;
		}

		int MinimumCost(vector<edge> &e,int n,int m,int i,int d){
			int v[n][n];
			memset(v,0,sizeof(v));
			queue<pair<pair<int,int>,int>> q;
			int l=0;
			int c=INT_MAX-1;
			int k=0;
			for(edge i : e)
				v[i.src][i.dst]=i.cost;
			q.push({{i,l},k});
			while(!q.empty()){
				i=q.front().first.first;
				l=q.front().first.second;
				k=q.front().second;
				q.pop();
				if(i==d && l==m)
					c=min(k, c);
				for(int j=0;j<n;j++){
					if(v[i][j])
						q.push({{j,l+1},k+v[i][j]});
				}
			}
			return c;
		}

};
