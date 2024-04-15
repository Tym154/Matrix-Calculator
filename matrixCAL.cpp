#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> matrix2;
vector<vector<double>> matrix1;

void writeOut(int row, int colum, vector<vector<double>>& matrix);
void fill(int row, int colum, vector<vector<double>>& matrix);

int main() {
    int row1, colum1, row2, colum2;

    cin >> row1 >> colum1;
    matrix1.resize(row1, vector<double>(colum1));

    cin >> row2 >> colum2;
    matrix2.resize(row2, vector<double>(colum2));
    

    fill(row1, colum1, matrix1);
    writeOut(row1, colum1, matrix1);
}

void writeOut(int colum, int row, vector<vector<double>>& matrix) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < colum; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void fill(int colum, int row, vector<vector<double>>& matrix) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < colum; j++) {
            cin >> matrix[i][j];
        }
    }
}

