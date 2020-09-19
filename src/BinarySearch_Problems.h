//============================================================================
// Name        : Binary Search Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Binary Search Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

class BinarySearch_Problems{
	public:

		int BinarySearch(vector<int> &a,int n,int x){
			int l=0;
			int h=n-1;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					return m;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return -1;
		}

		int ReverseBinarySearch(vector<int> &a,int n,int x){
			int l=0;
			int h=n-1;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					return m;
				else if(x<a[m])
					l=m+1;
				else
					h=m-1;
			}
			return -1;
		}

		int UnknownOrderSearch(vector<int> &a,int n,int x){
			return a[0]<a[1] ?
					BinarySearch(a, n, x) : ReverseBinarySearch(a, n, x);
		}

		int FirstOccurance(vector<int> &a,int n,int x){
			int l=0;
			int h=n-1;
			int k=-1;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					k=m,h=m-1;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return k;
		}

		int LastOccurance(vector<int> &a,int n,int x){
			int l=0;
			int h=n-1;
			int k=-1;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					k=m,l=m+1;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return k;
		}

		int CountOfElement(vector<int> &a,int n,int x){
			int l=LastOccurance(a, n, x);
			int f=FirstOccurance(a, n, x);
			return l==-1 ? -1 : l-f+1;
		}

		int NumberOfRotation(vector<int> &a,int n){
			int l=0;
			int h=n-1;
			while(l<=h){
				int m=l+(h-l)/2;
				int p=(n+m-1)%n;
				int nx=(m+1)%n;
				if(a[m]<a[p] && a[m]<a[nx])
					return m;
				else if(a[m]>a[h])
					l=m+1;
				else
					h=m-1;
			}
			return 0;
		}

		int RotatedArraySearch(vector<int> &a,int n,int x){
			int m=NumberOfRotation(a, n);
			int k=BinarySearch(a, m-1, x);
			if(k<0){
				int h=n-1;
				int l=m+1;
				while(l<=h){
					int m=l+(h-l)/2;
					if(x==a[m])
						return m;
					else if(x<a[m])
						h=m-1;
					else
						l=m+1;
				}
			}
			return k;
		}

		int NearlySortedSearch(vector<int> &a,int n,int x){
			int h=n-1;
			int l=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					return m;
				else if(m-1>=l && a[m-1]==x)
					return m-1;
				else if(m+1<=h && a[m+1]==x)
					return m+1;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return 0;
		}

		int FloorOfElement(vector<int> &a,int n,int x){
			int h=n-1;
			int l=0;
			int k=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]==x)
					return m;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1,k=m;
			}
			return k;
		}

		int CeilOfElement(vector<int> &a,int n,int x){
			int h=n-1;
			int l=0;
			int k=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(x==a[m])
					return m;
				else if(x<a[m])
					h=m-1,k=m;
				else
					l=m+1;
			}
			return k;
		}

		int NextAlphabet(string &a,int n,char x){
			int h=n-1;
			int l=0;
			int k=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(x==a[m])
					return m+1;
				else if(x<a[m])
					h=m-1,k=m;
				else
					l=m+1;
			}
			return k;
		}

		int InfiniteArraySearch(vector<int> &a,int x){
			int h=1;
			int l=0;
			while(x>a[h]){
				l=h;
				h=2*h;
			}
			while(l<=h){
				int m=l+(h-l)/2;
				if(x==a[m])
					return m;
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return -1;
		}

		int InfiniteBinary(vector<bool> &a){
			int l=0;
			int h=1;
			int k=0;
			while(!a[h]){
				l=h;
				h=h*2;
			}
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m])
					h=m-1,k=m;
				else
					l=m+1;
			}
			return k;
		}

		int MinimumDifference(vector<int> &a,int n,int x){
			int l=0;
			int h=n-1;
			while(l<=h){
				int m=l+(h-l)/2;
				if(x==a[m])
					return a[m];
				else if(x<a[m])
					h=m-1;
				else
					l=m+1;
			}
			return a[l]-x < x-a[h] ? a[l] : a[h];
		}

		int PeakElement(vector<int> &a,int n){
			int h=n-1;
			int l=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(m>0 && m<n-1){
					if(a[m]>a[m+1] && a[m]>a[m-1])
						return m;
					else if(a[m]<a[m-1])
						h=m-1;
					else
						l=m+1;
				}
				else if(m==0)
					return a[m]>a[m+1] ? m:m+1;
				else if(m==n-1)
					return a[m]>a[m-1] ? m:m-1;
			}
			return -1;
		}

		int MaximumBitonicElement(vector<int> &a,int n){
			int h=n-1;
			int l=0;
			while(l<=h){
				int m=l+(h-l)/2;
				if(a[m]>a[m+1] && a[m]>a[m-1])
					return m;
				else if(a[m]<a[m-1])
					h=m-1;
				else
					l=m+1;
			}
			return -1;
		}

		int BitonicSeriesSearch(vector<int> &a,int n,int x){
			int m=MaximumBitonicElement(a, n);
			int k=BinarySearch(a, n, x);
			if(k<0){
				int h=n-1;
				int l=m+1;
				while(l<=h){
					int m=l+(h-l)/2;
					if(a[m]==x)
						return m;
					else if(x>a[m])
						h=m-1;
					else
						l=m+1;
				}
			}
			return k;
		}

		pair<int,int> SearchMatrix(vector<vector<int>> &a,int m,int n,int x){
			int i=0;
			int j=n-1;
			while(i<m && j>=0){
				if(x==a[i][j])
					return {i,j};
				else if(x<a[i][j])
					j--;
				else
					i++;
			}
			return {-1,-1};
		}

		bool isValidPageAlloctaion(vector<int> &a,int k,int m){
			int v=1;
			int s=0;
			for(int i : a){
				s=s+i;
				if(s>m){
					s=i;
					v++;
				}
			}
			return v>k ? 0:1;
		}

		int AllocateMinimumPages(vector<int> &a,int n,int k){
			int l=INT_MIN;
			int h=0;
			int t=-1;
			if(k>n)
				return -1;
			for(int i : a){
				l=max(l,i);
				h=h+i;
			}
			while(l<=h){
				int m=l+(h-l)/2;
				if(isValidPageAlloctaion(a, k, m))
					t=m,h=m-1;
				else
					l=m+1;
			}
			return t;
		}

};
