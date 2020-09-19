//============================================================================
// Name        : DP Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : DP Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int Knapsack(vector<int> &w,vector<int> &v,int s,int n){
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(j<w[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=max(t[i-1][j],t[i-1][j-w[i-1]]+v[i-1]);
		}
	}
	return t[n][s];
}

bool SubSetSum(vector<int> &a,int s,int n){
	bool t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(a[i-1]>j)
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j] || t[i-1][j-a[i-1]];
		}
	}
	return t[n][s];
}

bool EqualSumPartition(vector<int> &a,int n){
	int s=0;
	for(int i : a)
		s+=i;
	if(s%2==1)
		return 0;
	s=s/2;
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(j<a[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j] || t[i-1][j-a[i-1]];
		}
	}
	return t[n][s];
}

int CountOfSubSetSum(vector<int> &a,int n,int s){
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(j<a[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j]+t[i-1][j-a[i-1]];
		}
	}
	return t[n][s];
}

int MinimumSubSetDifference(vector<int> &a,int n){
	int s=0;
	for(int i : a)
		s+=i;
	bool t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(s<a[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j] || t[i-1][j-a[i-1]];
		}
	}
	for(int i=s/2;i<=s;i++){
		if(t[n][i]){
			return abs(s-2*i);
		}
	}
	return INT_MAX;
}

int CountOfSubSetDifference(vector<int> &a,int n,int d){
	int s=0;
	for(int i : a)
		s+=i;
	s=(s+d)/2;
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(j<a[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j]+t[i-1][j-a[i-1]];
		}
	}
	return t[n][s];
}

int TargetSum(vector<int> &a,int n,int d){
	int s=0;
	for(int i : a)
		s+=i;
	s=(s+d)/2;
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(j<a[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j]+t[i-1][j-a[i-1]];
		}
	}
	return t[n][s];
}

int UnBoundedKnapsack(vector<int> &w,vector<int> &v,int n,int s){
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(j<w[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=max(t[i-1][j],t[i][j-w[i-1]]+v[i-1]);
		}
	}
	return t[n][s];
}

int RodCutting(vector<int> &v,int n){
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(j<i)
				t[i][j]=t[i-1][j];
			else
				t[i][j]=max(t[i-1][j],t[i][j-i]+v[i-1]);
		}
	}
	return t[n][n];
}

int CoinChange(vector<int> &v,int n,int s){
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=1;
			else if(i==0)
				t[i][j]=0;
			else if(j<v[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i-1][j]+t[i][j-v[i-1]];
		}
	}
	return t[n][s];
}

int MinimumCoins(vector<int> v,int n,int s){
	int t[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)
				t[i][j]=0;
			else if(i==0)
				t[i][j]=INT_MAX-1;
			else if(j<v[i-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=min(t[i-1][j],1+t[i][j-v[i-1]]);
		}
	}
	return t[n][s];
}

int LongestCommonSubSequence(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return t[m][n];
}

int LongestCommonSubString(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	int k=0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=0;
			k=max(t[i][j],k);
		}
	}
	return k;
}

string PrintLongestCommonSubSequence(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	string s;
	for(int i=m;i>0;){
		for(int j=n;j>0;){
			if(a[i-1]==b[j-1]){
				s.push_back(a[i-1]);
				i--,j--;
			}
			else if(t[i][j-1] > t[i-1][j])
				j--;
			else
				i--;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int ShortestCommonSuperSequence(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return m+n-t[m][n];
}

string PrintShortestCommonSuperSequence(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	string s;
	int i=m;
	int j=n;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			s.push_back(a[i-1]);
			i--,j--;
		}
		else if(t[i-1][j] > t[i][j-1])
			i--,s.push_back(a[i]);
		else
			j--,s.push_back(b[j]);
	}
	while(i>0){
		s.push_back(a[i-1]);
		i--;
	}
	while(j>0){
		s.push_back(b[j-1]);
		j--;
	}
	reverse(s.begin(), s.end());
	return s;
}

string PrintLongestCommonSubString(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	int k=0;
	int v=0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=0;
			if(t[i][j]>t[k][v]){
				k=i;
				v=j;
			}
		}
	}
	return a.substr(k-t[k][v], t[k][v]);
}

int MinimumDeletion(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return m-t[m][n];
}

int MinimumInsertion(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return n-t[m][n];
}

int LongestPallendromicSequence(string &a,int n){
	string b=a;
	reverse(b.begin(), b.end());
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return t[n][n];
}

int MinimumPallendromeDeletion(string &a,int n){
	string b=a;
	reverse(b.begin(), b.end());
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return n-t[n][n];
}

int MinimumPallendromeInsertion(string &a,int n){
	string b=a;
	reverse(b.begin(), b.end());
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return n-t[n][n];
}

int LongestRepeatingSubSequence(string &a,int n){
	string b=a;
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1] && i!=j)
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
			cout<<t[i][j]<<' ';
		}
		cout<<'\n';
	}
	return t[n][n];
}

bool SequencePatternMatch(string &a,string &b,int m,int n){
	int t[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	}
	return m==t[m][n];
}

int MatrixChainMultiplication(vector<int> &a,int n){
	int t[n][n];
	for(int i=0;i<n;i++)
		t[i][i]=0;
	for(int j=1;j<n-1;j++){
		for(int i=1;i<n-j;i++){
			t[i][i+j]=min(t[i+1][i+j]+a[i-1]*a[i]*a[i+j],
					t[i][i+j-1]+a[i-1]*a[i+j-1]*a[i+j]);
		}
	}
	return t[1][n-1];
}

bool isPalindrome(string &a,int i,int j){
	while(i<j){
		if(a[i++]!=a[j--])
			return 0;
	}
	return 1;
}

int PalindromePartition(string &a,int n){
	int t[n][n];
	for(int j=0;j<n;j++){
		for(int i=0;i<n-j;i++){
			if(i==i+j)
				t[i][i+j]=0;
			else if(isPalindrome(a, i, i+j))
				t[i][i+j]=0;
			else
				t[i][i+j]=min(t[i][i+j-1],t[i+1][i+j])+1;
		}
	}
	return t[0][n-1];
}

