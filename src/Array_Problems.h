//============================================================================
// Name        : Array Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Array Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

vector<int> Union(vector<int> &a, vector<int> &b){
	unordered_set<int> u;
	vector<int> v;
	u.insert(a.begin(), a.end());
	u.insert(b.begin(), b.end());
	for(int i : u)
		v.push_back(i);
	for(int i : v)
		cout<<i<<' ';
	return v;
}

vector<int> Intersection(vector<int> &a,vector<int> &b){
	unordered_set<int> u;
	vector<int> v;
	u.insert(a.begin(), a.end());
	for(int i : b)
		if(u.find(i)!=u.end())
			v.push_back(i);
	for(int i : v)
		cout<<i<<' ';
	return v;
}

vector<int> RotateArray(vector<int> &a,int k){
	int n=a.size();
	vector<int> v(n);
	k=k%n;
	for(int i=0;i<n;i++){
		v[(k+i)%n]=a[i];
	}
	for(int i : v)
		cout<<i<<' ';
	return a;
}

int MissingInt(vector<int> &a){
	int k=a[0];
	int h=a.size()-1;
	int l=0;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]!=k+m)
			h=m-1;
		else if(a[m]==k+m)
			l=m+1;
	}
	if(l>=(int)a.size())
		return -1;
	return l+k;
}

int CountPairSum(vector<int> &a,int s){
	int n=a.size();
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i!=j && a[i]+a[j]==s)
				k++;
		}
	}
	return k;
}

vector<int> DuplicatesInArray(vector<int> &a){
	unordered_set<int> v;
	vector<int> k;
	for(int i : a){
		if(v.find(i)!=v.end())
			k.push_back(i);
		else
			v.insert(i);
	}
	for(int i : k)
		cout<<i<<' ';
	return k;
}

vector<int> CommonInAll(vector<int> &a,vector<int> &b,vector<int> &c){
	unordered_set<int> u,v;
	vector<int> k;
	u.insert(a.begin(), a.end());
	v.insert(b.begin(), b.end());
	for(int i : c)
		if(u.find(i)!=u.end() && v.find(i)!=v.end())
			k.push_back(i);
	for(int i : k)
		cout<<i<<' ';
	return k;
}

int FirstRepeatingElement(vector<int> &a){
	unordered_set<int> u;
	for(int i : a){
		if(u.find(i)!=u.end())
			return i;
		u.insert(i);
	}
	return -1;
}

int FirstNonRepeatingElement(vector<int> &a){
	unordered_set<int> u;
	u.insert(a[0]);
	for(int i : a){
		if(u.find(i)==u.end())
			return i;
		u.insert(i);
	}
	return -1;
}

vector<int> LargestThree(vector<int> &a){
	int x=INT_MIN;
	int y=INT_MIN;
	int z=INT_MIN;
	vector<int> k;
	for(int i : a){
		if(i>x){
			z=y;
			y=x;
			x=i;
		}
	}
	k={x,y,z};
	for(int i : k)
		cout<<i<<' ';
	return k;
}

vector<int> RearrangeArray(vector<int> &a){
	int n=a.size();
	for(int j=0,i=0;j<n-1;j++){
		while(a[j]>0 && a[i]>0 && i<n-1)
			i++;
		while(a[j]<0 && a[i]<0 && i<n-1)
			i++;
		int t=a[j+1];
		a[j+1]=a[i];
		a[i]=t;
	}
	for(int i : a)
		cout<<i<<' ';
	return a;
}

bool isSubArraySumZero(vector<int> &a){
	int s=0;
	unordered_set<int> u;
	for(int i : a){
		s+=i;
		if(s==0 || u.find(s)!=u.end())
			return 1;
		u.insert(s);
	}
	for(int i : u)
		cout<<i<<' ';
	return 0;
}

int LargestSum(vector<int> &a){
	int n=a.size();
	int s=0;
	int m=INT_MIN;
//	int end=0,start=0;
	for(int i=0;i<n;i++){
		s+=a[i];
		if(a[i]>s){
			s=a[i];
//			start=i;
		}
		if(m<s){
			m=s;
//			end=i;
		}
	}
	return m;
}

int MaxProduct(vector<int> &a){
	int s=1;
	int m=INT_MIN;
	for(int i : a){
		s*=i;
		if(i==0)
			s=1;
		m=max(m,s);
	}
	return m;
}

int LongestConsecutiveSubSequence(vector<int> &a){
	sort(a.begin(), a.end());
	int m=0;
	int s=1;
	int n=a.size();
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]==1)
			s++;
		else
			s=1;
		m=max(m,s);
	}
	return m;
}

vector<int> FrequentElement(vector<int> &a,int k){
	unordered_map<int,int> v;
	vector<int> s;
	for(int i : a)
		v[i]++;
	int n=a.size()/k;
	for(auto i : v)
		if(i.second>n)
			s.push_back(i.first);
	for(int i : s)
		cout<<i<<' ';
	return s;
}

int MinInRotatedArray(vector<int> &a){
	int h=a.size()-1;
	int l=0;
	while(l<=h){
		int m=l+(h-l)/2;
		int n=(m+1)%a.size();
		int p=(a.size()+m-1)%a.size();
		if(a[m]<a[p] && a[m]<a[n])
			return a[m];
		else if(a[m]<a[h])
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}

int Gcd(int a,int b){
	int n=min(a,b);
	int k=1;
	for(int i=2;i<=n;i++)
		if(a%i==0 && b%i==0)
			k=i;
	return k;
}

int GcdArray(vector<int> &a){
	int n=a.size();
	int k=a[0];
	for(int i=0;i<n;i++)
		k=Gcd(k,a[i]);
	return k;
}

int MaxProfit(vector<int> &a){
	vector<int> v;
	vector<int> u;
	int k=a.size();
	int m=INT_MIN;
	int n=INT_MAX;
	for(int i : a){
		m=max(i,m);
		n=min(i,n);
		v.push_back(m);
		u.push_back(n);
	}
	m=INT_MIN;
	int s=0;
	for(int i=0;i<k;i++){
		if(m<v[i]-u[i]){
			m=v[i]-u[i];
			n=u[i];
		}
	}
	s+=m;
	m=INT_MIN;
	for(int i=0;i<k;i++){
		if(m<v[i]-u[i] && u[i]!=n)
			m=v[i]-u[i];
	}
	s+=m;
	return s;
}

int MinimizeMaxDifference(vector<int> &a,int k){
	int n=a.size();
	vector<bool> v(n);
	sort(a.begin(), a.end());
	for(int i=0;i<=n/2;i++){
		if(!v[n-i-1]){
			a[n-i-1]-=k;
			v[n-i-1]=1;
		}
		if(!v[i]){
			a[i]+=k;
			v[i]=1;
		}
	}
	return abs(a[n-1]-a[0]);
}

int MinJumps(vector<int> &a){
	int n=a.size();
	vector<int> v(n,INT_MAX);
	v[0]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i] && i+j<n;j++){
			v[i+j]=min(v[i+j],i+1);
		}
	}
	for(int i : v)
		cout<<i<<' ';
	return v[n-1];
}

vector<int> RepeatingElement(vector<int> &a){
	unordered_set<int> v;
	vector<int> k;
	for(int i : a){
		if(v.find(i)!=v.end())
			k.push_back(i);
		else
			v.insert(i);
	}
	for(int i : k)
		cout<<i<<' ';
	return k;
}

vector<int> TripletSum(vector<int> &a,int s){
	vector<int> v;
	int n=a.size();
	sort(a.begin(), a.end());
	for(int i=0;i<n;i++){
		int l=i+1;
		int r=n-1;
		while(l<r){
			int k=a[i]+a[l]+a[r];
			if(k==s){
				v.push_back(a[i]);
				v.push_back(a[l]);
				v.push_back(a[r]);
				break;
			}
			else if(k<s)
				l++;
			else
				r--;
		}
	}
	for(int i : v)
		cout<<i<<' ';
	return v;
}

int MaxRow(vector<vector<bool>> &a){
	int m=0;
	int s=0;
	int k=-1;
	int n=a.size();
	for(int i=0;i<n;i++){
		for(int j : a[i]){
			s+=j;
		}
		if(m<s){
			m=s;
			k=i;
		}
		s=0;
	}
	return k;
}

int Median(vector<vector<int>> &a){
	int m=a.size();
	int n=a[0].size();
	int k=m*n/2;
	return a[k/m][k%n];
}

bool isSubArray(vector<int> &a,vector<int> &b){
	unordered_set<int> v;
	v.insert(a.begin(), a.end());
	for(int i : b)
		if(v.find(i)==v.end())
			return 0;
	return 1;
}

class TwoStack{
	private:
		vector<int> v;
		int n;
		int t1;
		int t2;
	public:
		TwoStack(int n){
			this->n=n;
			t1=-1;
			t2=2*n;
			v.resize(2*n);
		}
		void push1(int i){
			if(isFull1())
				return;
			t1++;
			v[t1]=i;
		}
		int pop1(){
			if(isEmpty1())
				return -1;
			t1--;
			return v[t1+1];
		}
		void push2(int i){
			if(isFull2())
				return;
			t2--;
			v[t2]=i;
		}
		int pop2(){
			if(isEmpty2())
				return -1;
			t2++;
			return v[t2-1];
		}
		bool isEmpty1(){
			return t1==-1;
		}
		bool isEmpty2(){
			return t2==n;
		}
		bool isFull1(){
			return t1==n-1;
		}
		bool isFull2(){
			return t2==n;
		}
};

void SpiralOrder(vector<vector<int>> &a){
	int m=a.size();
	int n=a[0].size();
	int i=0,j=0,k=0;
	int x=m/2;
	while(x--)
	{
		while(j<n){
			cout<<a[i][j]<<' ';
			j++;
		}
		j--;
		i++;
		while(i<m){
			cout<<a[i][j]<<' ';
			i++;
		}
		i--;
		j--;
		while(j>=k){
			cout<<a[i][j]<<' ';
			j--;
		}
		j++;
		i--;
		k++;
		while(i>=k){
			cout<<a[i][j]<<' ';
			i--;
		}
		i++;
		j++;
		m--;
		n--;
	}
}

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}

int Partition(vector<int> &a,int l,int h){
	int i=l;
	for(int j=l;j<h;j++){
		if(a[j]<a[h]){
			swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i],a[h]);
	return i;
}

void QuickSort(vector<int> &a,int l,int h){
	if(l<h){
		int p=Partition(a, l, h);
		QuickSort(a, l, p-1);
		QuickSort(a, p+1, h);
	}
}
