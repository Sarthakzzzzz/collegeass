#include <bits/stdc++.h>
using namespace std;

const int MAX = 3; 
void addition_of_matrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtraction_of_matrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplication_of_matrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void display_matrix(int a[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int k;
    cout << "Enter the operation you want to perform: \n1. Addition \n2. Subtraction \n3. Multiplication \n4. Exit" << endl;
    cin >> k;

    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    
    cout << "Enter the elements in the first 3x3 matrix:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the elements in the second 3x3 matrix:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> b[i][j];
        }
    }

    while (true) {
        if (k == 1) {
            addition_of_matrices(a, b, result);
            cout << "Result of Addition: \n";
            display_matrix(result);
        } else if (k == 2) {
            subtraction_of_matrices(a, b, result);
            cout << "Result of Subtraction: \n";
            display_matrix(result);
        } else if (k == 3) {
            multiplication_of_matrices(a, b, result);
            cout << "Result of Multiplication: \n";
            display_matrix(result);
        } else if (k == 4) {
            break; 
        } else {
            cout << "Invalid operation. Please try again." << endl;
        }
        
        cout << "Enter the operation you want to perform: \n1. Addition \n2. Subtraction \n3. Multiplication \n4. Exit" << endl;
        cin >> k;
    }

    return 0;
}

