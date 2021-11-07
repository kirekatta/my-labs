#include<iostream>
#include<fstream>
using namespace std;

void input_array(int** arr, int* n) {
    ifstream inf("input.txt");
    if (!inf)return;
    inf >> *n;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            inf >> arr[i][j];
}

bool check_array(int** arr, int n) {
    bool check_sign;
    int a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j || (i + j) == n - 1) {
                check_sign = false;
                if (arr[i][j] < 0)return false;
                else {
                    a = arr[i][j];
                    while (a > 0) {
                        if (a % 10 == 3 || a % 10 == 5)
                            check_sign = true;
                        a /= 10;
                    }
                    if (!check_sign)return false;
                }
            }
        }
    return true;
}

void process_array(int** arr, int n) {
    int min, k;
    for (int i = 0; i < n; i++) {
        min = arr[0][i];
        k = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j][i] < min) {
                min = arr[j][i];
                k = j;
            }
            arr[k][i] = 0;
            for (int j = 0; j < n; j++) {
                if (k != j)
                    arr[k][i] += arr[j][i] * arr[j][i];
            }
            arr[k][i] += min * min;
        }
    }

}

void output_array(int** arr, int n) {
    ofstream outf("output.txt");
    if (!outf)return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            outf << arr[i][j] << " ";
        outf << endl;
    }
}

int main()
{
    int** arr = new int* [10];
    int n;
    for (int i = 0; i < 10; i++)
        arr[i] = new int[10];
    input_array(arr, &n);
    if (check_array(arr, n))
        process_array(arr, n);
    output_array(arr, n);
    return 0;
}
