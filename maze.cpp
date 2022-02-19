#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<vector<int>>& M){
    int n = M.size();
    vector<vector<int>> T(n, vector<int>(n)); //T[i][j]: subproblem for moving from (0,0) to (i,j)
    T[0][0] = M[0][0]; //top-left corner
    for(int i = 1; i < n; i++){
        T[0][i] = T[0][i - 1] + M[0][i]; //top row
        T[i][0] = T[i - 1][0] + M[i][0]; //left column
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            T[i][j] = max(T[i - 1][j], T[i][j - 1]) + M[i][j];
        }
    }
    return T[n - 1][n - 1];
}

int main(){
    vector<vector<int>> M{
        {1, 3, 4, -1},
        {3, -2, -1, 5},
        {-5, 9, -3, 1},
        {5, 5, 2, -2}
    };
    int ans = max_profit(M); //expect 16
    cout << "Maximum profit: " << ans << endl;
    return 0;
}
