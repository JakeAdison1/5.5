//Найти норму заданной матрицы А

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;



void output_Matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        cout << matrix[i][j]<<setw(5);
        cout << endl;
    }
    cout << endl;
}

void input_Matrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

void sum_Matrix(vector<vector<int>>& matrix, vector<int>& matrixB) {
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size();j++) {

            if (j < matrix.size()-1) {
                matrixB[i] = matrix[i][j] + matrix[i][j++];
            }
            if (j = matrix.size() - 1) {
                matrixB[i] = matrixB[i]+matrix[i][j];
            }
           }

        cout << matrixB[i]<<endl;
        
    }
}


void Sort(vector<int>& Vector) {
    for (int i = 0; i < Vector.size(); i++) {//Прох. по всему массиву
        int min = Vector[i]; //Сохр знач минимального
        int iter_min = i; //сохраняем знач мин итера
        for (int j = i + 1; j < Vector.size(); j++) {
            if (Vector[j] < min) {
                min = Vector[j];
                iter_min = j;
            }
        }
        Vector[iter_min] = Vector[i];
        Vector[i] = min;
 
    }
    cout << Vector[Vector.size() - 1] << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int k;
    cout << "Введите размер квадратной матрицы:";
    cin >> k;
    vector<int>matrixB(k);
    vector<vector<int>> matrixA(k,vector<int> (k));
    input_Matrix(matrixA);
    output_Matrix(matrixA);
    cout << endl;
    cout << "Норма матрицы:";
    cout << endl;
    sum_Matrix(matrixA,matrixB);
    cout << endl;
    cout << "Максимальный элемент:";
    Sort(matrixB);
}