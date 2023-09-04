#include "matrix.hxx"

//конструктор по умолчанию
Matrix::Matrix(){
    str = 0;
    cols = 0;
    matrix = nullptr;
}

//конструктор с двумя параметрами
Matrix::Matrix(int str, int cols){
    this->str = str;
    this->cols = cols;
    matrix = new float*[str];
    for(int i = 0; i < str; i++){
        matrix[i] = new float[cols];
    }
}

//конструктор копирования
Matrix::Matrix(const Matrix &mat){
    str = mat.str;
    cols = mat.cols;
    matrix = new float*[str];
    for(int i = 0; i < str; i++){
        matrix[i] = new float[cols];
    }
    for(int i = 0; i < str; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = mat.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < str; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

//функция ввода матрицы
void Matrix::enterMatrix(){
    std::cout << "┌───────────────────────────────────────────────────" << std::endl;
    for(int i = 0; i < str; i++){
        int count = i + 1;
        std::cout << "│ " << count << "-я строка(" << cols << " элементов): ";
        for(int j = 0; j < cols; j++){
            std::cin >> matrix[i][j];
        }
        std::cout << "├───────────────────────────────────────────────────" << std::endl;
    }
}

//функция вывода на экран
void Matrix::outputMatrix(){
    std::cout << "│" << std::endl;
    std::cout << "│ Результат" << std::endl;
    for(int i = 0; i < str; i++){
        std::cout << "├";
        for(int k = 0; k < cols; k++){
            std::cout << "─────────┐";
        }
        std::cout << std::endl;
        std::cout << "│";
        for(int j = 0; j < cols; j++){
            std::cout << std::setw(9) << matrix[i][j] << "│"; 
        }
        std::cout << std::endl;
    }
    std::cout << "├";
    for(int k = 0; k < cols; k++){
        std::cout << "─────────┘";
    }
    std::cout << std::endl;

}

Matrix Matrix::operator+(const Matrix &op){
    str = op.str;
    cols = op.cols;
    Matrix temp(op.str, op.cols);
    for(int i = 0; i < op.str; i++){
        for(int j = 0; j < op.cols; j++){
            temp.matrix[i][j] = op.matrix[i][j] + matrix[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator=(const Matrix &other){
     str = other.str;
     cols = other.cols;
     matrix = new float*[str];
     for(int i = 0; i < str; i++){
        matrix[i] = new float[cols];
     }
     for(int i = 0; i < str; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = other.matrix[i][j];
        }
     }
     return *this;
}

Matrix Matrix::operator-(const Matrix &other){
    str = other.str;
    cols = other.cols;
    Matrix temp(other.str, other.cols);
    for(int i = 0; i < other.str; i++){
        for(int j = 0; j < other.cols; j++){
            temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return temp;
}

//функция умножения матрицы на число
Matrix Matrix::mulNum(float number){
    Matrix temp(str, cols);
    for(int i = 0; i < str; i++){
        for(int j = 0; j < cols; j++){
            temp.matrix[i][j] = matrix[i][j] * number;
        }
    }
    return temp;
}

//функция транспонирования
Matrix Matrix::transposition(){
    Matrix temp(cols, str);
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < str; j++){
            temp.matrix[i][j] = matrix[j][i];
        }
    }
    return temp;
}