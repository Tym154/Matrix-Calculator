#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> matrix2;
vector<vector<double>> matrix1;

void writeOut(int row, int colum, vector<vector<double>>& matrix); //Function to write out the contents of a matrix
void fill(int row, int colum, vector<vector<double>>& matrix); //Function to fill the matrix with data
void addition(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2); //function to add the matrixes
void subtraction(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2); //function to subtract the matrixes
void multiplication(int row1, int colum1, int row2, int colum2, vector<vector<double>>& matrix1, vector<vector<double>>& matrix2); //function to multiply the matrixes
void powoftwo(int row, int colum, vector<vector<double>>& matrix);

int main() {

    //isnt working now, im gonna do it later
}

void choose(){
cout << "What operation would you like to do? (write down the number) \n1.addition \n2.subtraction \n3.addition \n4.multiplication \n5.multiplication with number \n6.power \n";
cin >> operation;
switch (operation)
{
    case 0:
        cout << "Error, Restart! \n"; 
        break;

    case 1:
        
        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:

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
    if(colum1 == row2){ //checking if the number of colums in the first matrix are same as the number of the rows in secend matrix
        Amatrix.resize(row1, vector<double>(colum2)); //creating Amatrix with the oposite colums/rows from both of the matrixes
        for(int i = 0; i < row1; i++){
            for(int j = 0; j < colum2; j++){ //iterate throught the created Amatrix
                double temp = 0; //reseting the temporary variable
                for(int k = 0; k < colum1; k++){ //iterating through the rows from matrix1 and colums from matrix2
                    temp += matrix1[i][k] * matrix2[k][j]; //multiplying the row from matrix1, colum from matrix2 and adding them to the temporary variable
                }
                Amatrix[i][j] = temp; //after all elements from the row and colum from the matrixes are multiplyed and added to the temporary variable. we assign the value to the coresponding Amatrix field
            }
        }
    }
    if(colum2 == row1){ //the same thing but reversed and with Bmatrix
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

void powoftwo(int row, int colum, vector<vector<double>>& matrix){
    multiplication(row, colum, row, colum, matrix, matrix);
}

