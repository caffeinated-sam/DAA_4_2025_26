#include<bits/stdc++.h>
using namespace std;

vector<string> board;
// vector<vector<string>> result;
unordered_map<int, int> col, prim, sec;
int sz;

bool isValid(int r,int c) {
	if(col[c]) return false;
	if(prim[(r-c)+(sz-1)]) return false;
	if(sec[r+c]) return false;

	return true;
}
bool solve(int r) {
	if(r== sz) {
		// result.push_back(board);
		return true;
	}
	for(int c=0; c<sz; c++) {
		if(isValid(r,c)) {
			board[r][c]= 'Q';
			col[c]++;
			prim[(r-c)+ (sz-1)]++;
			sec[r+c]++;

			if(solve(r+1)) return true;

			board[r][c]= '.';
			col[c]--;
			prim[(r-c)+(sz-1)]--;
			sec[r+c]--;
		}
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	sz=n;
	vector<string> temp(n, string(n,'.'));
	board= temp;
	solve(0);
	for(int i=0 ; i<sz; i++) {
		for(int j=0; j<n; j++)cout<< board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}