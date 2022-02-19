#include <iostream>
#include <vector>

using namespace std;

int largest_increasing_subsequence(vector<int>& A){
    int n = A.size();
    vector<int> T(n); //T[i]: subproblem for largest increasing subsequence in A[0...i] that ends with A[i]
    T[0] = A[0]; //base case
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j] < A[i]) T[i] = max(T[i], T[j]);
        }
        T[i] += A[i];
    }
    int largest_sum = 0;
    for(int i = 0; i < n; i++) largest_sum = max(largest_sum, T[i]);
    return largest_sum;
}

int main(){
    vector<int> A{11, 1, 2, 3, 4, 12};
    int ans = largest_increasing_subsequence(A); //expect 23
    cout << "Largest sum of increasing sumsequence: " << ans << endl;
    return 0;
}
