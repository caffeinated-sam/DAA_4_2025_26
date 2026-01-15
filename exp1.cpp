#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int mxdep=0;
void complexRec(int n, int *cnt, int dep) {
	mxdep= max(mxdep, dep);
   if (n <= 2) {
       	return;
   }

   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           (*cnt)++;
       }
       p >>= 1;
   }

   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       (*cnt)++;
   }

    reverse(small.begin(), small.end());
    (*cnt)+= n/2;  //the reverse funcn also does  n/2 operations

   	complexRec(n / 2, cnt, dep+1);
   	complexRec(n / 2, cnt, dep+1);
   	complexRec(n / 2, cnt, dep+1);
}

int main(){
	int n; cin>>n;
    auto start = high_resolution_clock::now();
	int cnt=0;
    complexRec(n, &cnt, 1);
    cout<<"Num of operations:"<<cnt<<endl;
    cout<<"Depth of rec tree:"<<mxdep<<endl;
    auto end = high_resolution_clock::now();
   	auto duration = duration_cast<microseconds>(end - start);
   	cout << "Execution time: " << duration.count() << " ms" <<endl;
}
/*
Recurance relation: 3 T(n/2) + 2n
We have used Master's Therorems Case:1 
where  3 > 2^1 -> O(n^ log_b a)
for n= 16
Num of operations: 398
Depth of rec tree: 4 
time required: 92 ms
*/