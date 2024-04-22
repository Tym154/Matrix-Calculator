#include <iostream>
#include <vector>

using namespace std;

int row1, colum1, row2, colum2, operation = 0, which;

vector<vector<double>> matrix2;
vector<vector<double>> matrix1;
vector<vector<double>> ResultMatrix;
vector<vector<double>> Amatrix;
vector<vector<double>> Bmatrix;

void start();
void choose();
void writeOut(int row, int colum, vector<vector<double>>& matrix); //Function to write out the contents of a matrix
void fill(int row, int colum, vector<vector<double>>& matrix); //Function to fill the matrix with data
void addition(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);
void subtraction(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);
void multiplication(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2);
void multiplicationWithNum(int row, int colum, vector<vector<double>>& matrix);
void powoftwo(int row, int colum, vector<vector<double>>& matrix);

int main() {
    start();
    choose();

}

void choose(){
cout << "What operation would you like to do? (write down the number) \n1.addition \n2.subtraction \n3.multiplication \n4.multiplication with number \n5.power of two \n";
cin >> operation;
switch (operation)
{
    case 1:
        addition(row1, colum1, row2, colum2, matrix1, matrix2);
        break;

    case 2:
        subtraction(row1, colum1, row2, colum2, matrix1, matrix2);
        break;

    case 3:
        multiplication(row1, colum1, row2, colum2, matrix1, matrix2);
        break;

    case 4:
        cout<< "What matrix do you want to multiply (1 or 2): \n";
        cin>>which;
        if(which == 0){
            cout << "Error";
            return;
        }
        else if(which == 1){
            multiplicationWithNum(row1, colum1, matrix1);
        }
        else if(which == 2){
            multiplicationWithNum(row2, colum2, matrix2);
        }
        break;
    case 5:
        cout<< "What matrix do you want to get the power of (1 or 2): \n";
        cin>>which;
        if(which == 0){
            cout << "Error";
            return;
        }
        else if(which == 1){
            powoftwo(row1, colum1, matrix1);
        }
        else if(which == 2){
            powoftwo(row2, colum2, matrix2);
        }
        break;
    default:
        cout << "Invalid operation \n";
        choose();
        break;
    }
}

void start(){
    cout << "Enter size of the first matrix (row, colum): \n";
    cin >> row1 >> colum1;
    matrix1.resize(row1, vector<double>(colum1)); //resizing the matrixes

    cout << "Enter size of the second matrix (row, colum): \n";
    cin >> row2 >> colum2;
    matrix2.resize(row2, vector<double>(colum2));
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
        cout << "\nError\n"; //error if the matrixes sizes do not match
        return;
    }
}

void powoftwo(int row, int colum, vector<vector<double>>& matrix){
    multiplication(row, colum, row, colum, matrix, matrix);
}

void multiplicationWithNum(int row, int colum, vector<vector<double>>& matrix){
    double mult;
    cout << "Enter the number you want to multiply with: \n";
    cin >> mult;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < colum; j++) {
            matrix[i][j] = matrix[i][j] * mult;
        }
    }
}
