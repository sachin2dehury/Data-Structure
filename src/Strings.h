//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

bool isStringRotation(string &a,string &b){
	int m=a.length();
	int n=a.length();
	if(m!=n)
		return 0;
	string t=a+a;
	return t.find(b)>0;
}

string RemoveDuplicates(string &a){
	unordered_set<char> s;
	string b="";
	for(char i : a){
		if(s.find(i)==s.end()){
			s.insert(i);
			b.push_back(i);
		}
	}
	return b;
}

bool isInterleaved(string &a,string &b,string &c){
	int i=a.length();
	int j=b.length();
	int k=c.length();
	if(i+j!=k)
		return 0;
	while(k){
		if(a[i-1]==c[k-1])
			k--,i--;
		else if(b[j-1]==c[k-1])
			k--,j--;
		else
			return 0;
	}
	return 1;
}

string LongestPalindromeSubString(string &a){
	int n=a.length();
	string b=a;
	vector<vector<int>> t(n+1,vector<int> (n+1));
	int m=0;
	reverse(b.begin(),b.end());
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=0;
//				t[i][j]=max(t[i][j-1],t[i-1][j]);
			m=t[m][m]>t[i][j] ? m : i;
		}
	}
	return a.substr(m-t[m][m],t[m][m]);
}

string LongestRecuringSubSequence(string &a){
	int n=a.length();
	vector<vector<int>> t(n+1,vector<int> (n+1));
	int m=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==a[j-1] && i!=j)
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=0;
//				t[i][j]=max(t[i][j-1],t[i-1][j]);
			m=t[m][m]>t[i][j] ? m : i;
		}
	}
	return a.substr(m-t[m][m],t[m][m]);
}

void AllSubSequence(string &a,int n,string s=""){
	if(!n){
		if(!s.empty())
			cout<<s<<'\n';
		return ;
	}
	AllSubSequence(a, n-1, s);
	AllSubSequence(a, n-1, s+a[n-1]);
}

void swap(char &a,char &b){
	char t=a;
	a=b;
	b=t;
}

void AllPermutation(string &a,int l,int h){
	if(l==h){
		cout<<a<<'\n';
		return ;
	}
	for(int i=l;i<=h;i++){
		swap(a[i],a[l]);
		AllPermutation(a, l+1, h);
		swap(a[i],a[l]);
	}
}

void SplitString(string &a){
	int n=a.length();
	int z=0;
	int o=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0')
			z++;
		else
			o++;
		if(z==o){
			cout<<a.substr(i+1-2*z, 2*z)<<'\n';
			z=0;
			o=0;
		}
	}
}

string RearrangeString(string &a){
	unordered_map<char,int> v;
	for(char i : a)
		v[i]++;
	priority_queue<pair<int,char>> q;
	for(auto i : v)
		q.push({i.second,i.first});
	string b="";
	while(q.top().first){
		auto k=q.top();
		q.pop();
		if(b[b.length()-1]==k.second) {
			auto i=q.top();
			q.pop();
			q.push(k);
			q.push({i.first-1,i.second});
			b.push_back(i.second);
		}
		else if(b.empty() || b[b.length()-1]!=k.second){
			b.push_back(k.second);
			q.push({k.first-1,k.second});
		}
		else
			return b="-1";
	}
	return b;
}

string SmallestWindowSubStirng(string &a){
	unordered_set<char> u;
	u.insert(a.begin(), a.end());
	int n=a.length();
	int m=u.size();
	for(int i=0;i<n;i++){
		unordered_set<char> s;
		for(int j=0;j<m && i+j<n;j++){
			if(s.find(a[i+j])!=s.end())
				break;
			else
				s.insert(a[i+j]);
			if((int)s.size()==m)
				return a.substr(i+j-m+1, m);
		}
	}
	return "-1";
}

string LongestCommonSubSequence(string &a,string &b){
	int n=a.length();
	int m=b.length();
	vector<vector<int>> t(n+1,vector<int> (m+1));
	int x=0,y=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
			if(t[x][y]<t[i][j])
				x=i,y=j;
		}
	}
	return a.substr(x-t[x][y],t[x][y]);
}

int EditDistance(string &a,string &b){
	int n=a.length();
	int m=b.length();
	vector<vector<int>> t(n+1,vector<int> (m+1));
	int x=0,y=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
			if(t[x][y]<t[i][j])
				x=i,y=j;
		}
	}
	return (m-t[x][y]);
}

string NumPad(string &b){
	vector<string> a={"2","22","222",
	            "3","33","333",
	            "4","44","444",
	            "5","55","555",
	            "6","66","666",
	            "7","77","777","7777",
	            "8","88","888",
	            "9","99","999","9999"
	           };
	string s="";
	for(char i : b){
		if(i==' ')
			s.push_back('0');
		else
			s+=a[i-'A'];
	}
	return s;
}

bool BalancedParenthesis(string &a){
	stack<char> s;
	for(char i : a){
		if(s.empty())
			s.push(i);
		else if(i==')' && s.top()=='(')
			s.pop();
		else if(i=='}' && s.top()=='{')
			s.pop();
		else if(i==']' && s.top()=='[')
			s.pop();
		else
			s.push(i);
	}
	return s.empty();
}

int MinSwapsToBalance(string &a){
	stack<char> s;
	if(a.length()%2)
		return -1;
	for(char i : a){
		if(s.empty())
			s.push(i);
		else if(i==')' && s.top()=='(')
			s.pop();
		else if(i=='}' && s.top()=='{')
			s.pop();
		else if(i==']' && s.top()=='[')
			s.pop();
		else
			s.push(i);
	}
	return s.size();
}

int MinBracketReversals(string &a){
	stack<char> s;
	if(a.length()%2)
		return -1;
	for(char i : a){
		if(s.empty())
			s.push(i);
		else if(i==')' && s.top()=='(')
			s.pop();
		else if(i=='}' && s.top()=='{')
			s.pop();
		else if(i==']' && s.top()=='[')
			s.pop();
		else
			s.push(i);
	}
	int k=0;
	int m=s.size();
	while(!s.empty() && s.top()=='{'){
		s.pop();
		k++;
	}
	return m/2+k%2;
}

int MinRotationRequired(string &a){
	string t=a.substr(1, a.length()-1)+a;
	return t.find(a)+1;
}

char FirstRepeated(string &a){
	int index=0;
	int n=a.length();
	for(int i=0;i<n;i++){
		int c=a[i]-'a';
		if(index & 1<<c)
			return a[i];
		index |= 1<<c;
	}
	return 0;
}

bool isPalindrome(string &a,int i,int j){
	while(i<j){
		if(a[i]!=a[j])
			return 0;
		i++,j--;
	}
	return 1;
}

int AllPalindromeSubSequence(string &a){
	int n=a.length();
	vector<vector<int>> t(n,vector<int> (n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(i==0)
				t[j][i+j]=1;
			else if(isPalindrome(a, j, i+j))
				t[j][i+j]=t[j][i+j-1]+t[j+1][i+j]+1;
			else
				t[j][i+j]=t[j][i+j-1]+t[j+1][i+j]-t[j+1][i+j-1];
			cout<<t[j][i+j]<<' ';
		}
		cout<<endl;
	}
	return t[0][n-1];
}

void AllSubString(string &a){
	int n=a.length();
	for(int j=1;j<n;j++){
		for(int i=0;i+j<n;i++){
			cout<<a.substr(i, j)<<'\n';
		}
	}
}

int MinFlips(string &a){
	int n=a.length();
	bool f=0;
	int k=0;
	for(int i=1;i<n;i++){
		if(!(f ^ (a[i]-'0')))
			k++;
		f=!f;
	}
	f=1;
	int m=0;
	for(int i=1;i<n;i++){
		if(!(f ^ (a[i]-'0')))
			m++;
		f=!f;
	}
	return min(m,k);
}

bool WordBreak(string &a){
	unordered_set<string> s={"mobile","samsung","sam","sung","man","mango",
            "icecream","and","go","i","like","ice","cream"};
	int n=a.length();
	vector<vector<bool>> t(n,vector<bool>(n));
	for(int j=0;j<n;j++){
		for(int i=0;i+j<n;i++){
			if(s.find(a.substr(i, j+1))!=s.end())
				t[i][i+j]=1;
			else {
				for(int k=i;k<i+j;k++){
					if(t[i][k]&&t[k+1][i+j]){
						t[i][i+j]=1;
						break;
					}
				}
			}
		}
	}
	return t[0][n-1];
}

void WordSearch(vector<string> &a,string &b){
	int m=a.size();
	int n=a[0].size();
	int k=b.length();
	queue<pair<int,int>> q;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[0]==a[i][j])
				q.push({i,j});
		}
	}
	vector<pair<int,int>> moves={
			{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}
	};
	while(!q.empty()){
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		for(auto v : moves){
			int x=v.first;
			int y=v.second;
			if(i+x*k>=0 && i+x*k<m && j+y*k>=0 && j+y*k<n){
				int u=0;
				for(u=1;u<k;u++){
					if(b[u]!=a[i+u*x][j+u*y])
						break;
				}
				if(u==k)
					cout<<i<<','<<j<<'\n';
			}
		}
	}
}

int WordWrap(vector<int> &a,int k){
	int n=a.size();
	vector<int> s;
	int x=0;
	s.push_back(0);
	for(int i : a){
		x+=i;
		s.push_back(x);
	}
	vector<vector<int>> t(n,vector<int> (n));
	for(int j=0;j<n;j++){
		for(int i=0;i+j<n;i++){
			if(s[i+j+1]-s[i]+j<k)
				t[i][i+j]=(k-(s[i+j+1]-s[i]+j))*(k-(s[i+j+1]-s[i]+j));
			else {
				t[i][i+j]=INT_MAX;
				for(int k=i;k<i+j;k++){
					t[i][i+j]=min(t[i][i+j],t[i][k]+t[k+1][i+j]);
				}
			}
		}
	}
	return t[0][n-1];
}
//
//int main(int argc, char **argv) {
//	vector<int> a={3, 2, 2, 5};
//	int k=6;
//	cout<<WordWrap(a, k);
//	return 0;
//}
