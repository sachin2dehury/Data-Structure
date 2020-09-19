//============================================================================
// Name        : Stack Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Stack Problems in C++,inc[i][j][istrue]i-style
//============================================================================


#include <bits/stdc++.h>

using namespace std;

class Stack_Problems{
	public:
		vector<int> NGR(vector<int> &a,int &n)
		{
			stack<int> s;
			vector<int> v(n);
			for(int i=n-1;i>=0;i--)
			{
				if(s.empty())
					v[i]=-1;
				else if(a[i]<s.top())
					v[i]=s.top();
				else{
					while(s.empty()==0 && a[i]>=s.top())
						s.pop();
					if(s.empty())
						v[i]=-1;
					else
						v[i]=s.top();
				}
				s.push(a[i]);
			}
			return v;
		}
		vector<int> NGL(vector<int> &a,int &n)
		{
			stack<int> s;
			vector<int> v(n);
			for(int i=0;i<n;i++)
			{
				if(s.empty())
					v[i]=-1;
				else if(a[i]<s.top())
					v[i]=s.top();
				else{
					while(s.empty()==0 && a[i]>=s.top())
						s.pop();
					if(s.empty())
						v[i]=-1;
					else
						v[i]=s.top();
				}
				s.push(a[i]);
			}
			return v;
		}
		vector<int> NSR(vector<int> &a,int &n)
		{
			stack<int> s;
			vector<int> v(n);
			for(int i=n-1;i>=0;i--)
			{
				if(s.empty())
					v[i]=-1;
				else if(a[i]>s.top())
					v[i]=s.top();
				else{
					while(s.empty()==0 && a[i]<=s.top())
						s.pop();
					if(s.empty())
						v[i]=-1;
					else
						v[i]=s.top();
				}
				s.push(a[i]);
			}
			return v;
		}
		vector<int> NSL(vector<int> &a,int &n)
		{
			stack<int> s;
			vector<int> v(n);
			for(int i=0;i<n;i++)
			{
				if(s.empty())
					v[i]=-1;
				else if(a[i]>s.top())
					v[i]=s.top();
				else{
					while(s.empty()==0 && a[i]<=s.top())
						s.pop();
					if(s.empty())
						v[i]=-1;
					else
						v[i]=s.top();
				}
				s.push(a[i]);
			}
			return v;
		}
		vector<int> StockSpan(vector<int> &a,int &n)
		{
			stack<int> s;
			vector<int> v(n);
			for(int i=0;i<n;i++)
			{
				if(s.empty())
					v[i]=1;
				else if(a[i]<a[s.top()])
					v[i]=i-s.top();
				else{
					while(s.empty()==0 && a[i]>=a[s.top()])
						s.pop();
					if(s.empty())
						v[i]=1;
					else
						v[i]=i-s.top();
				}
				s.push(i);
			}
			return v;
		}
		vector<int> HistogramArea(vector<int> &a,int &n)
		{
			stack<int> sr,sl;
			vector<int> vr(n),vl(n),v(n);

			for(int i=0;i<n;i++)
			{
				if(sl.empty())
					vl[i]=-1;
				else if(a[i]>a[sl.top()])
					vl[i]=sl.top();
				else {
					while(!sl.empty() && a[i]<=a[sl.top()])
						sl.pop();
					if(sl.empty())
						vl[i]=-1;
					else
						vl[i]=sl.top();
				}
				sl.push(i);
			}

			for(int i=n-1;i>=0;i--)
			{
				if(sr.empty())
					vr[i]=n;
				else if(a[i]>a[sr.top()])
					vr[i]=sr.top();
				else {
					while(!sr.empty() && a[i]<=a[sr.top()])
						sr.pop();
					if(sr.empty())
						vr[i]=n;
					else
						vr[i]=sr.top();
				}
				sr.push(i);
			}

			for(int i=0;i<n;i++)
			{
				v[i]=((vr[i]-vl[i])-1)*a[i];
			}

			return v;
		}
		vector<vector<int>> BinaryHistogramArea(vector<vector<int>> &a,int &n)
		{
			vector<vector<int>> v(n);
			vector<vector<int>> k=a;
			for(int i=1;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(k[i][j])
						k[i][j]=k[i-1][j]+1;
					else
						k[i][j]=0;
				}
			}
			for(int i=0;i<n;i++)
			{
				v[i]=HistogramArea(k[i], n);
			}
			return v;
		}
		vector<int> RainWaterCollection(vector<int> &a,int &n)
		{
			stack<int> sr,sl;
			vector<int> vr(n),vl(n),v(n);

			for(int i=0;i<n;i++)
			{
				if(sl.empty())
					vl[i]=a[i];
				else if(a[i]<sl.top())
					vl[i]=max(vl[i-1],sl.top());
				else {
					while(!sl.empty() && a[i]>=sl.top())
						sl.pop();
					if(sl.empty())
						vl[i]=a[i];
					else
						vl[i]=max(vl[i-1],sl.top());
				}
				sl.push(a[i]);
			}

			for(int i=n-1;i>=0;i--)
			{
				if(sr.empty())
					vr[i]=a[i];
				else if(a[i]<sr.top())
					vr[i]=max(vr[i+1],sr.top());
				else {
					while(!sr.empty() && a[i]>=sr.top())
						sr.pop();
					if(sr.empty())
						vr[i]=a[i];
					else
						vr[i]=max(vr[i+1],sr.top());
				}
				sr.push(a[i]);
			}

			for(int i=0;i<n;i++)
			{
				v[i]=min(vr[i],vl[i])-a[i];
			}

			return v;
		}
};

class MinStack{
	private:
		stack<int> s;
		stack<int> v;
	public:
		bool empty(){
			return s.size()==0;
		}
		void pop(){
			s.pop();
			v.pop();
		}
		int top(){
			return s.top();
		}
		void push(int x){
			if(empty())
				s.push(x),v.push(x);
			else if(x<v.top())
				s.push(x),v.push(x);
			else
				s.push(x),v.push(v.top());
		}
		int min(){
			return v.top();
		}
		int size(){
			return s.size();
		}
};

class MinStackWithoutSpace{
	private:
		stack<int> s;
		int v;
	public:
		bool empty(){
			return s.size()==0;
		}
		void pop(){
			if(v>s.top())
				v=2*v-s.top();
			s.pop();
		}
		int top(){
			if(v>s.top())
				return v;
			else
				return s.top();
		}
		void push(int x){
			if(empty())
				s.push(x),v=x;
			else if(x>v)
				s.push(x);
			else
				s.push(2*x-v),v=x;
		}
		int min(){
			return v;
		}
		int size(){
			return s.size();
		}
};

class Stack_Using_Queue{
	private:
		queue<int> q;
		queue<int> s;
		void stackify(){

		}
	public:
		void push(int x){
			q.push(x);
			while(q.size()>1){
				s.push(q.front());
				q.pop();
			}
			while(!s.empty()){
				q.push(s.front());
				s.pop();
			}
		}
		void pop(){
			q.pop();
		}
		int top(){
			return q.front();
		}
		bool empty(){
			return q.empty();
		}
		int size(){
			return q.size();
		}
};

class Stack_using_Deque{
	private:
		deque<int> s;
	public:
		void push(int x){
			s.push_front(x);
		}
		void pop(){
			s.pop_front();
		}
		int top(){
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

		int QuickSortPartition(vector<int> &a,int start,int end){
			int pivot=a[end];
			int index=start;
			for(int i=start;i<end;i++)
			{
				if(a[i]<=pivot)
				{
					int t=a[i];
					a[i]=a[index];
					a[index]=t;
					index++;
				}
			}
			int t=a[end];
			a[end]=a[index];
			a[index]=t;
			return index;
		}

		vector<int> QuickSort(vector<int> &a,int &n){
			stack<pair<int,int>> s;
			int start=0;
			int end=n-1;
			s.push({start,end});
			while(!s.empty()){
				start=s.top().first;
				end=s.top().second;
				s.pop();
				int p=QuickSortPartition(a,start,end);
				if(p-1>start)
					s.push({start,p-1});
				if(p+1<end)
					s.push({p+1,end});
			}
			return a;
		}

		int LIS(vector<int> &a,int &n){
			set<int> s;
			for(int i : a){
				if(s.find(i)==s.end())
				{
					auto k=s.insert(i).first;
					k++;
					if(k!=s.end())
						s.erase(k);
				}
			}
			return s.size();
		}

		void PreOrder
		(int start,int end,int &n,vector<int> &postorder,unordered_map<int,int> &m,stack<int> &s){
			if(start>end)
				return ;
			int v=postorder[n];
			n--;
			int k=m[v];
			PreOrder(k+1, end, n, postorder, m, s);
			PreOrder(start, k-1, n, postorder, m, s);
			s.push(v);
		}

		vector<int> PreOrderFromPostOrder(vector<int> &inorder,vector<int> &postorder,int n) {
			unordered_map<int,int> m;
			vector<int> v;
			stack<int> s;
			for(int i=0;i<n;i++){
				m[inorder[i]]=i;
			}
			n--;
			PreOrder(0, n, n, postorder, m, s);
			while(!s.empty()){
				v.push_back(s.top());
				s.pop();
			}
			return v;
		}

		int LongestBalancedParenthesis(string a){
			int n=a.length();
			stack<int> s;
			s.push(-1);
			int k=0;
			for(int i=0;i<n;i++){
				if(a[i]=='(')
					s.push(i);
				else if(a[i]==')'){
					s.pop();
					if(s.empty())
						s.push(i);
					k=max(k,i-s.top());
				}
			}
			return k;
		}

		vector<int> SortStack(vector<int> &a,int n){
			stack<int> s;
			stack<int> v;
			vector<int> t;
			for(int i : a)
			{
				if(s.empty() || s.top()>i)
					s.push(i);
				else{
					while(!s.empty() && s.top()<=i){
						v.push(s.top());
						s.pop();
					}
					s.push(i);
					while(!v.empty())
					{
						s.push(v.top());
						v.pop();
					}
				}
			}
			while(!s.empty()){
				t.push_back(s.top());
				s.pop();
			}
			return t;
		}

		bool BalancedExpression(string &a,int &n){
			stack<char> s;
			for(char i : a){
				if( (i=='(') || (i=='{') || (i=='[') )
					s.push(i);
				else if(i==')' && s.top()=='(')
					s.pop();
				else if(i=='}' && s.top()=='{')
					s.pop();
				else if(i==']' && s.top()=='[')
					s.pop();
			}
			return s.empty();
		}

		string DuplicateParenthesis(string &a,int &n){
			stack<char> s;
			for(int i=0;i<n;i++){
				if( (a[i]=='(') || (a[i]=='{') || (a[i]=='[') )
					s.push(i);
				else if(a[i]==')' && a[s.top()]=='(' && a[i+1]==')' && a[s.top()-1]=='(')
					return a.substr(s.top(), i-s.top()+1);
				else if(a[i]=='}' && a[s.top()]=='{' && a[i+1]=='}' && a[s.top()-1]=='{')
					return a.substr(s.top(), i-s.top()+1);
				else if(a[i]==']' && a[s.top()]=='['  && a[i+1]==']' && a[s.top()-1]=='[')
					return a.substr(s.top(), i-s.top()+1);
			}
			return "";
		}

		int PostfixEvaluate(string &a,int &n){
			stack<int> s;
			for(char c : a)
			{
				s.push(c);
				if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
				{
					s.pop();
					int r=s.top()-'0';
					s.pop();
					int l=s.top()-'0';
					s.pop();
					switch (c) {
						case '+':
							s.push(l+r);
							break;
						case '-':
							s.push(l-r);
							break;
						case '*':
							s.push(l*r);
							break;
						case '/':
							s.push(l/r);
							break;
						case '^':
							s.push(pow(l, r));
							break;
					}
				}
			}
			return s.top();
		}

		vector<int> Decode(string &a,int &n){
			stack<int> s;
			vector<int> v;
			for(int i=0;i<=n;i++)
			{
				s.push(i+1);
				if(i==n || a[i]=='I')
				{
					while(!s.empty())
					{
						v.push_back(s.top());
						s.pop();
					}
				}
			}

			for(int i : v)
				cout<<i<<' ';
			return v;
		}

		string ReverseParagraph(string &a,int &n){
			string v;
			int k=0;
			for(int i=0;i<n;i++){
				if(a[i]==' '){
					v+=a.substr(k, i-k);
					k=i;
				}
			}
			return v;
		}

		vector<string> AllPattern(string a,int n){
			stack<string> s;
			vector<string> v;
			s.push(a);
			int k=0;
			while(!s.empty()){
				a=s.top();
				s.pop();
				k=a.find_first_of('?');
				if(k!=-1){
					for(int i=0;i<2;i++){
						a[k]=i+'0';
						s.push(a);
					}
				}
				else
					v.push_back(a);
			}
			return v;
		}

		vector<pair<int,int>> MergeIntervals(vector<pair<int,int>> a,int &n){
			vector<pair<int,int>> v;
			stack<pair<int,int>> s;
			sort(a.begin(), a.end(), [](auto &x,auto &y){return x.second > y.second;});
			for(auto i : a)
			{
				if(!s.empty() && i.second>=s.top().first)
				{
					auto t=s.top();
					s.pop();
					s.push({min(t.first,i.first),max(t.second,i.second)});
				}
				else
					s.push(i);
			}
			while(!s.empty())
			{
				v.push_back(s.top());
				s.pop();
			}
			return v;
		}

};

class K_Stacks{
	private:
		int k;
		int n;
		vector<int> v;
		vector<int> t;
	public:
		K_Stacks(int n,int k){
			this->n=n;
			this->k=k;
			v=vector<int> (n*k);
			t=vector<int> (k);
			for(int i=0;i<k;i++)
				t[i]=n*i-1;
		}
		void push(int x,int k){
			if(full(k))
				return;
			t[k]++;
			v[t[k]]=x;
		}
		void pop(int k){
			t[k]--;
		}
		int top(int k){
			return v[t[k]];
		}
		bool empty(int k){
			return t[k]==k*n-1;
		}
		int size(int k){
			return t[k]-k*n;
		}
		bool full(int k){
			return t[k]==(k+1)*n-1;
		}
};
