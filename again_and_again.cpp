#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longest_double_palindrome(string& s){
    int n = s.size();
    vector<vector<int>> T(n, vector<int>(n)); //T[i][j]: subproblem for longest palindrome in s[i...j]
    for(int i = 0; i < n; i++) T[i][i] = 1; //base case for string with length 1
    int i, j;
    for(int l = 1; l < n; l++){
        for(i = 0; i + l < n; i++){
            j = i + l;
            if(s[i] == s[j]) T[i][j] = T[i + 1][j - 1] + 2;
            else T[i][j] = max(T[i + 1][j], T[i][j - 1]);
        }
    }
    int double_palindrome = 0;
    for(int k = 0; k + 1 < n; k++) double_palindrome = max(double_palindrome, T[0][k] + T[k + 1][n - 1]);
    return double_palindrome;
}

int main(){
    string s1 = "NaOObNcPdOeP";
    int ans1 = longest_double_palindrome(s1); //expect 7
    cout << "Length of longest double palindrome: " << ans1 << endl;
    string s2 = "PaObPcPdOeP";
    int ans2 = longest_double_palindrome(s2); //expect 6
    cout << "Length of longest double palindrome: " << ans2 << endl;
    return 0;
}
