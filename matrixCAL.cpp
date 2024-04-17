#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> matrix2;
vector<vector<double>> matrix1;

void writeOut(int row, int colum, vector<vector<double>>& matrix); //Function to write out the contents of a matrix
void fill(int row, int colum, vector<vector<double>>& matrix); //Function to fill the matrix with data
void addition(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);
void subtraction(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);
void multiplication(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);

int main() {
    int row1, colum1, row2, colum2;

    cin >> row1 >> colum1;
    matrix1.resize(row1, vector<double>(colum1)); //resizing the matrixes

    cin >> row2 >> colum2;
    matrix2.resize(row2, vector<double>(colum2));
    

    fill(row1, colum1, matrix1);
    fill(row2, colum2, matrix2);
    multiplication(row1, colum1, row2, colum2, matrix1, matrix2);
    writeOut(row2, colum1, Bmatrix);
}

void writeOut(int row, int colum, vector<vector<double>>& matrix) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < colum; j++) {  //iterating through the array and writing out every single element 
            cout << matrix[i][j] << " ";
        }
        cout << "\n"; //writing a new line every new row
    }
}

void fill(int row, int colum, vector<vector<double>>& matrix) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < colum; j++) {  //iterating through the array and filling the matrix
            cin >> matrix[i][j];
        }
    }
}

void addition(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2){
    if(row1 == row2 && colum1 == colum2){ //checking if the matrixes are the same size
        ResultMatrix.resize(row1, vector<double>(colum1));
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < colum1; j++) {
                ResultMatrix[i][j] = matrix1[i][j] + matrix2[i][j]; //filling out the result matrix
            }
        }
    }
    else{
        cout << "\nError\n"; //error if the matrixes sizes do not match
        return; 
    }
}

void subtraction(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2){
    if(row1 == row2 && colum1 == colum2){ //checking if the matrixes are the same size
        Amatrix.resize(row1, vector<double>(colum1));
        Bmatrix.resize(row1, vector<double>(colum1));
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < colum1; j++) {
                Amatrix[i][j] = matrix1[i][j] - matrix2[i][j]; //filling out the result matrixes
                Bmatrix[i][j] = matrix2[i][j] - matrix1[i][j];
            }
        }
    }
    else{
        cout << "\nError\n"; //error if the matrixes sizes do not match
        return;
    }
}

void multiplication(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2){
    if(colum1 == row2){
        Amatrix.resize(row1, vector<double>(colum2));
        for(int i = 0; i < row1; i++){
            for(int j = 0; j < colum2; j++){
                double temp = 0;
                for(int k = 0; k < colum1; k++){
                    temp += matrix1[i][k] * matrix2[k][j];
                }
                Amatrix[i][j] = temp;
            }
        }
    }
    if(colum2 == row1){
        Bmatrix.resize(row2, vector<double>(colum1));
        for(int i = 0; i < row2; i++){
            for(int j = 0; j < colum1; j++){
                double temp = 0;
                for(int k = 0; k < colum2; k++){
                    temp += matrix2[i][k] * matrix1[k][j];
                }
                Bmatrix[i][j] = temp;
            }
        }
    }
    else{
        cout << "\nError\n"; //error if you cant multiply at all
        return;
    }
}
