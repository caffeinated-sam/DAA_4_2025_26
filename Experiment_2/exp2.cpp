#include<bits/stdc++.h>
using namespace std;

struct Node{
	char ch;
	int freq;
	Node *left;
	Node *right;
	Node(char ch, int freq){
		this->freq= freq;
		this->ch= ch;
		left=NULL;
		right=NULL;
	}
};


void print(Node *root, string str, unordered_map<char, string> &m){
	if(!root) return;
	if(!root->left && !root->right){
		m[root->ch] = str;
	}
	print(root->left, str+'0', m);
	print(root->right, str+'1', m);
}

struct Compare{
    bool operator()(Node *a , Node *b){
        return a->freq > b->freq;
    }
};

int main(){
	string s; 
	cin>>s;
	unordered_map<char, int> m;
	vector<pair<int, int>> arr;
	for(auto i:s) m[i]++;
	for(auto i:m) arr.push_back({i.first, i.second});
	priority_queue<Node *,vector<Node *>, Compare> min_heap;
	for(auto i:arr){
		min_heap.push(new Node(i.first, i.second));
	}
	while(min_heap.size() > 1){
		Node *left= min_heap.top();
		min_heap.pop();
		Node*right= min_heap.top();
		min_heap.pop();
		Node *merge= new Node('#', left->freq+right->freq);
		merge->left= left;
		merge->right= right;
		min_heap.push(merge);
	}
	cout << min_heap.top()->freq << endl;
    unordered_map<char , string> map;
    print(min_heap.top() , "" , map);
    string ans;
    for(int i= 0 ; i< s.length() ; i++){
        ans += map[s[i]];
    }
    cout << "The encoded string is "<<endl << ans << endl;
}
