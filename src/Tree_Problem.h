//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

class node{
	public:
		int data;
		node* right;
		node* left;
		node(int data){
			this->data=data;
			right=nullptr;
			left=nullptr;
		}
};

node* createTree(int data){
	node* root =new node(data);
	return root;
}

void insert(node* root,int data){
	if(!root)
		return;
	while(root){
		if(data>root->data){
			if(root->right)
				root=root->right;
			else
				root->right=new node(data);
		}
		else if(data<root->data){
			if(root->left)
				root=root->left;
			else
				root->left=new node(data);
		}
		else
			break;
	}
}

void topView(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,int> s;
	int d=0;
	int n=0,m=0;
	q.push({root,d});
	while(!q.empty()){
		root=q.front().first;
		d=q.front().second;
		q.pop();
		m=max(m,d);
		n=min(n,d);
		if(s.find(d)==s.end())
			s[d]=root->data;
		if(root->left)
			q.push({root->left,d-1});
		if(root->right)
			q.push({root->right,d+1});
	}
	for(int i=n;i<=m;i++)
		cout<<s[i]<<' ';
	cout<<endl;
}

void bottomView(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,int> s;
	int d=0;
	int n=0,m=0;
	q.push({root,d});
	while(!q.empty()){
		root=q.front().first;
		d=q.front().second;
		q.pop();
		m=max(m,d);
		n=min(n,d);
		s[d]=root->data;
		if(root->left)
			q.push({root->left,d-1});
		if(root->right)
			q.push({root->right,d+1});
	}
	for(int i=n;i<=m;i++)
		cout<<s[i]<<' ';
	cout<<endl;
}

void leftView(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,int> s;
	int l=0;
	int n=0,m=0;
	q.push({root,l});
	while(!q.empty()){
		root=q.front().first;
		l=q.front().second;
		q.pop();
		m=max(m,l);
		n=min(n,l);
		if(s.find(l)==s.end())
			s[l]=root->data;
		if(root->left)
			q.push({root->left,l+1});
		if(root->right)
			q.push({root->right,l+1});
	}
	for(int i=n;i<=m;i++)
		cout<<s[i]<<' ';
	cout<<endl;
}

void rightView(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,int> s;
	int l=0;
	int n=0,m=0;
	q.push({root,l});
	while(!q.empty()){
		root=q.front().first;
		l=q.front().second;
		q.pop();
		m=max(m,l);
		n=min(n,l);
		s[l]=root->data;
		if(root->left)
			q.push({root->left,l+1});
		if(root->right)
			q.push({root->right,l+1});
	}
	for(int i=n;i<=m;i++)
		cout<<s[i]<<' ';
	cout<<endl;
}

vector<int> preOrder(node* root){
	static vector<int> v;
	if(!root)
		return v;
	v.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
	return v;
}

vector<int> postOrder(node* root){
	static vector<int> v;
	if(!root)
		return v;
	postOrder(root->left);
	postOrder(root->right);
	v.push_back(root->data);
	return v;
}

vector<int> inOrder(node* root){
	static vector<int> v;
	if(!root)
		return v;
	inOrder(root->left);
	v.push_back(root->data);
	inOrder(root->right);
	return v;
}

void levelOrder(node* root){
	if(!root)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->data<<' ';
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}

void spiralLevelOrder(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,vector<int>> s;
	int l=0;
	q.push({root,l});
	while(!q.empty()){
		root=q.front().first;
		l=q.front().second;
		q.pop();
		s[l].push_back(root->data);
		if(root->left)
			q.push({root->left,l+1});
		if(root->right)
			q.push({root->right,l+1});
	}
	for(int i=0;i<(int)s.size();i++){
		if(i%2){
			for(int j=s[i].size()-1;j>=0;j--)
				cout<<s[i][j]<<' ';
		} else {
			for(int j : s[i])
				cout<<j<<' ';
		}
	}
}

void diagonalView(node* root){
	if(!root)
		return;
	queue<pair<node*,int>> q;
	unordered_map<int,vector<int>> s;
	int l=0;
	int m=0;
	q.push({root,l});
	while(!q.empty()){
		root=q.front().first;
		l=q.front().second;
		q.pop();
		m=max(m,l);
		s[l].push_back(root->data);
		if(root->left)
			q.push({root->left,l+1});
		if(root->right)
			q.push({root->right,l});
	}
	for(int i=0;i<=m;i++){
		for(int j : s[i])
			cout<<j<<' ';
		cout<<endl;
	}
}

void leafNodes(node* root){
	if(!root)
		return;
	leafNodes(root->left);
	if(!root->left && !root->right)
		cout<<root->data<<' ';
	leafNodes(root->right);
}

void boundaryTraversal(node* root){
	if(!root)
		return;
	stack<node*> s;
	node* temp=root;
	s.push(root);
	while(!s.empty()){
		root=s.top();
		s.pop();
		cout<<root->data<<' ';
		if(root->left)
			s.push(root->left);
	}
	leafNodes(temp);
	root=temp->right;
	s.push(root);
	while(root->right){
		s.push(root->right);
	}
	while(!s.empty()){
		cout<<s.top()->data<<' ';
		s.pop();
	}
}

void buildTreeHelper(unordered_map<int,int> &s,int i,node* root){
	if(s[i]<s[root->data] && !root->left)
		root->left=new node(i);
	else if(s[i]>s[root->data] && !root->right)
		root->right=new node(i);
	else if(s[i]<s[root->data])
		buildTreeHelper(s, i,root->left);
	else
		buildTreeHelper(s, i, root->right);
}

node* buildTree(){
	vector<int> pre={ 5, 6, 7, 8, 9, 10, 11 };
	vector<int> in={ 5, 6, 7, 8, 9, 10, 11 };
	unordered_map<int,int> s;
	for(int i=0;i<(int)in.size();i++){
		s[in[i]]=i;
	}
	node* root=createTree(pre[0]);
	for(int i=1;i<(int)pre.size();i++)
		buildTreeHelper(s,pre[i] , root);
	return root;
}

void stringToTree(){
	stack<node*> s;
	string a="4(2(3)(1))(6(5))";
	node* root=createTree(a[0]-'0');
	int n=a.length();
	for(int i=1;i<n;i++){
		if(a[i]==')') {
			root=s.top();
			s.pop();
		} else if(a[i]=='(') {
			s.push(root);
		} else {
			if(!root->left){
				root->left=new node(a[i]-'0');
				root=root->left;
			}
			else {
				root->right=new node(a[i]-'0');
				root=root->right;
			}
		}
	}
	levelOrder(root);
}

void treeToLinkedList(node* root){
	if(!root)
		return;
	stack<node*> s;
	vector<node*> v;
	while(root || s.size()){
		if(!root){
			root=s.top();
			s.pop();
			v.push_back(root);
			root=root->right;
		} else {
			s.push(root);
			root=root->left;
		}
	}
	int n=v.size();
	for(int i=0;i<n;i++){
		v[i]->left=v[i-1];
		v[i]->right=v[i+1];
	}
	v[0]->left=nullptr;
	v[n-1]->right=nullptr;
	root=v[0];
	while(root){
		cout<<root->data<<' ';
		root=root->right;
	}
}

int sumTree(node* root){
	if(!root)
		return 0;
	int t=root->data;
	root->data=sumTree(root->left)+sumTree(root->right);
	return root->data+t;
}

int isSumTree(node* root){
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	if(root->data == isSumTree(root->left)+isSumTree(root->right))
		return 2* root->data;
	return INT_MIN;
}

vector<int> inOrder(vector<int> &a,int i=0){
	static vector<int> v;
	if(i>=(int)a.size())
		return v;
	inOrder(a, 2*i+1);
	v.push_back(a[i]);
	inOrder(a, 2*i+2);
	return v;
}

int minSwap(){
	vector<int> tree={ 5, 6, 7, 8, 9, 10, 11 };
	vector<int> in=tree;
	sort(in.begin(), in.end());
	vector<int> v= inOrder(tree);
	int k=0;
	int n=tree.size();
	for(int i=0;i<n;i++){
		if(v[i]!=in[i])
			k++;
	}
	k=(k%2)+k/2;
	cout<<k;
	return k;
}

bool isSameLevel(node* root){
	if(!root)
		return 1;
	queue<pair<node*,int>> q;
	int l=0;
	int d=-1;
	q.push({root,l});
	while(q.size()){
		root=q.front().first;
		l=q.front().second;
		q.pop();
		if(!root->left && !root->right){
			if(d<0)
				d=l;
			else if(d!=l)
				return 0;
		}
		if(root->left)
			q.push({root->left,l+1});
		if(root->right)
			q.push({root->right,l+1});
	}
	return 1;
}

bool isMirror(node* a,node* b){
	if(!a && !b)
		return 1;
	if(a->data!=b->data)
		return 0;
	return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

void longetPath(node* root){
	if(!root)
		return;
	queue<pair<node*,pair<int,int>>> q;
	int l=0;
	int s=0;
	int m=0;
	int n=0;
	q.push({root,{l,s}});
	while(q.size()){
		root=q.front().first;
		l=q.front().second.first;
		s=q.front().second.second+root->data;
		q.pop();
		if(l>m){
			m=l;
			n=max(n,s);
		}
		if(root->left)
			q.push({root->left,{l+1,s}});
		if(root->right)
			q.push({root->right,{l+1,s}});
	}
	cout<<n;
}

int largestSumSubTree(node* root){
	if(!root)
		return 0;
	int l=largestSumSubTree(root->left);
	int r=largestSumSubTree(root->right);
	int s=0;
	if(root->data>0)
		s+=root->data;
	if(l>0)
		s+=l;
	if(r>0)
		s+=r;
	return s;
}

void LCA(node* root,int a,int b){
	if(!root)
		return;
	stack<node*> s;
	unordered_map<int,int> v;
	s.push(root);
	v[root->data]=-1;
	while(s.size()){
		root=s.top();
		s.pop();
		if(root->left)
			s.push(root->left),v[root->left->data]=root->data;
		if(root->right)
			s.push(root->right),v[root->right->data]=root->data;
	}
	unordered_set<int> u;
	while(a!=-1){
		u.insert(a);
		a=v[a];
	}
	while(b!=-1){
		if(u.find(b)!=u.end()){
			cout<<b<<'\n';
			return;
		}
		b=v[b];
	}
}

void dist(node* root,int a,int b){
	if(!root)
		return;
	stack<node*> s;
	unordered_map<int,int> v;
	s.push(root);
	v[root->data]=-1;
	while(s.size()){
		root=s.top();
		s.pop();
		if(root->left)
			s.push(root->left),v[root->left->data]=root->data;
		if(root->right)
			s.push(root->right),v[root->right->data]=root->data;
	}
	unordered_map<int,int> u;
	int i=0;
	while(a!=-1){
		u[a]=i;
		a=v[a];
		i++;
	}
	i=0;
	while(b!=-1){
		if(u.find(b)!=u.end()){
			cout<<u[b]+i<<'\n';
			return;
		}
		i++;
		b=v[b];
	}
}

void kAncestor(node* root,int a,int k){
	if(!root)
		return;
	stack<node*> s;
	unordered_map<int,int> v;
	s.push(root);
	v[root->data]=-1;
	while(s.size()){
		root=s.top();
		s.pop();
		if(root->left)
			s.push(root->left),v[root->left->data]=root->data;
		if(root->right)
			s.push(root->right),v[root->right->data]=root->data;
	}
	for(int i=0;i<k;i++){
		a=v[a];
		if(v[a]!=-1)
			return;
	}
	cout<<a;
}

void duplicates(node* root){
	if(!root)
		return;
	stack<node*> s;
	unordered_map<int,int> v;
	s.push(root);
	while(s.size()){
		root=s.top();
		s.pop();
		v[root->data]++;
		if(root->left)
			s.push(root->left);
		if(root->right)
			s.push(root->right);
	}
	for(auto i : v)
		if(i.second>1)
			cout<<i.first<<' ';
}

void bST(){
	vector<int> v={10, 5, 1, 7, 40, 50};
	node* root=createTree(v[0]);
	for(int i : v)
		insert(root, i);
	auto k=inOrder(root);
	for(int i : k)
		cout<<i<<' ';
}

void treeToBST(node* root){
	vector<int> v=inOrder(root);
	sort(v.begin(),v.end());
	stack<node*> s;
	int i=0;
	node* t=root;
	levelOrder(t);
	cout<<endl;
	while(root || s.size()){
		if(root){
			s.push(root);
			root=root->left;
		} else {
			root=s.top();
			root->data=v[i];
			i++;
			s.pop();
			root=root->right;
		}
	}
	levelOrder(t);
}

void bSTFromArray(node* root,vector<int> v,int i,int n){
	if(i>n)
		return;
	int m= i+(n-i)/2;
	insert(root, v[m]);
	bSTFromArray(root,v, i, m-1);
	bSTFromArray(root,v, m+1, n);
}

void balancedBST(node* root){
	vector<int> v=inOrder(root);
	int n=v.size();
	levelOrder(root);
	cout<<endl;
	node* t=createTree(v[n/2]);
	bSTFromArray(t, v, 0, n/2-1);
	bSTFromArray(t, v, n/2+1, n-1);
	levelOrder(t);
}

void mergeBST(node* root){
	vector<int> v={10,12,13,15};
	for(int i : v)
		insert(root, i);
}

void LCA_BST(node* root,int a,int b){
	if(!root)
		return;
	auto k=inOrder(root);
	unordered_set<int> s;
	s.insert(k.begin(), k.end());
	if(s.find(a)==s.end() || s.find(b)==s.end())
		return;
	int d=root->data;
	while(root){
		d=root->data;
		if(a<d && b<d)
			root=root->left;
		else if(a>d && b>d)
			root=root->right;
		else
			break;
	}
	cout<<d<<'\n';
}

void kLargest(node* root,int k){
	auto v=inOrder(root);
	int n=v.size();
	cout<<v[n-k]<<' ';
}

void countPairs(node* root,int k){
	if(!root)
		return;
	stack<node*> s;
	unordered_set<int> q;
	int c=0;
	while(root || s.size()){
		if(root){
			s.push(root);
			root=root->left;
		} else {
			root=s.top();
			s.pop();
			if(q.find(k-root->data)!=q.end())
				c++;
			q.insert(root->data);
			root=root->right;
		}
	}
	cout<<c<<' ';
}

void median(node* root){
	if(!root)
		return;
	stack<node*> s;
	int c=0;
	node* t=root;
	while(root || s.size()){
		if(root){
			s.push(root);
			root=root->left;
		} else {
			root=s.top();
			s.pop();
			c++;
			root=root->right;
		}
	}
	root=t;
	int k=0;
	int m=0,n=0;
	while(root || s.size()){
		if(root){
			s.push(root);
			root=root->left;
		} else {
			root=s.top();
			s.pop();
			k++;
			if(k==c/2){
				m=root->data;
			}else if(k==c/2+1){
				n=root->data;
				break;
			}
			root=root->right;
		}
	}
	if(c%2)
		cout<<n;
	else
		cout<<(m+n)/2;
}

void countRange(node* root,int a,int b){
	if(!root)
		return;
	stack<node*> s;
	int c=0;
	while(root || s.size()){
		if(root){
			s.push(root);
			root=root->left;
		} else {
			root=s.top();
			s.pop();
			if(root->data>a && root->data<b)
				c++;
			root=root->right;
		}
	}
	cout<<c;
}

void inOrderSuccesser(){
	vector<int> v={8, 58, 71, 18, 31, 32, 63, 92,
	         43, 3, 91, 93, 25, 80, 28};
	node* root=createTree(v[0]);
	for(int i : v)
		insert(root, i);
	node* t=root;
	for(int &i : v){
		cout<<i<<' ';
		while(root && root->data!=i){
			if(root->data>i)
				root=root->left;
			else
				root=root->right;
		}
		if(root->right){
			root=root->right;
			while(root->left)
				root=root->left;
			i=root->data;
		} else
			i=-1;
		root=t;
		cout<<i<<'\n';
	}
}

void replaceNextGreatest(){
//todo()
}

void isDead(node* root){
	if(!root)
		return;
	stack<pair<node*,pair<int,int>>> s;
	int m=INT_MAX;
	int n=0;
	s.push({root,{n,m}});
	while(s.size()){
		root=s.top().first;
		m=s.top().second.second;
		n=s.top().second.first;
		s.pop();
		if(m-1==root->data && root->data==n+1){
//			cout<<root->data<<' '<<n<<' '<<m<<'\n';
			cout<<"yes";
			return;
		}
		if(root->left)
			s.push({root->left,{n,root->data}});
		if(root->right)
			s.push({root->right,{root->data,m}});
	}
	cout<<"no";
}

void validPreorder(){
	vector<int> pre= {40, 30, 35, 80, 100};
	auto a=inOrder(pre);
	int n=a.size();
	for(int i=1;i<n;i++){
		if(a[i-1]>a[i]){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
}
//
//int main(int argc, char **argv) {
//	node* root=createTree(5);
//	insert(root, 3);
//	insert(root, 1);
//	insert(root, 4);
//	insert(root, 2);
//	insert(root, 8);
//	insert(root, 6);
//	insert(root, 7);
//	validPreorder();
//	return 0;
//}


