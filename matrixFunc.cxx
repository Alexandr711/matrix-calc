#include "matrixFunc.hxx"
#include "format.hxx"

#include <cstdlib>


void mainMatrixFunc(){

    //приветствие
    std::cout << "┌────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                            │" << std::endl;
    std::cout << "│            ДОБРО ПОЖАЛОВАТЬ!               │" << std::endl;
    std::cout << "│ Программа: Калькулятор матриц \"Math\"       │" << std::endl;
    std::cout << "│ Версия: 1.0                                │" << std::endl;
    std::cout << "│                                            │" << std::endl;
    std::cout << "├────────────────────────────────────────────┤" << std::endl;
    std::cout << "│                                            │" << std::endl;
    std::cout << "│ Данная программа может:                    │" << std::endl;
    std::cout << "│ Складывать матрицы                         │" << std::endl;
    std::cout << "│ Умножать матрицу на число                  │" << std::endl;
    std::cout << "│ Вычитать матрицы                           │" << std::endl;
    std::cout << "│ Транспонировать матрицы                    │" << std::endl;
    std::cout << "│                                            │" << std::endl;
    std::cout << "└────────────────────────────────────────────┘" << std::endl;
    std::cout << std::endl;

    char ansver;
    //названия операций
    do{
        std::cout << std::endl;
        std::cout << print_as_color<ansi_color_code::yellow>("add") << " или " << print_as_color<ansi_color_code::yellow>("ADD") <<"- сложение;" << std::endl;
        std::cout << print_as_color<ansi_color_code::green>("sub") << " или " << print_as_color<ansi_color_code::green>("SUB") <<"- вычитание;" << std::endl;
        std::cout << print_as_color<ansi_color_code::magenta>("mulnum") << " или " << print_as_color<ansi_color_code::magenta>("MULNUM") << "- умножение на число;" << std::endl;
        std::cout << print_as_color<ansi_color_code::green>("t") << " или " << print_as_color<ansi_color_code::green>("T") << "- транспонирование;" << std::endl;
        std::cout << "q или Q- выход из программы" << std::endl;
        std::cout << std::endl;

        std::string operation;
        std::cout << " Введите название операции: ";
        std::cin >> operation;

        //выбор действий: сложение, вычитание, умножение на число, или выход
        if(operation == "add" or operation == "ADD"){
            addFunc();
        }
        else if(operation == "sub" or operation == "SUB"){
            subFunc();
        }
        else if(operation == "mulnum" or operation == "MULNUM"){
            mulNumFunc();
        }
        else if(operation == "t" or operation == "T"){
            transponitionFunc();
        }
        else if(operation == "q" or operation == "Q"){
            system("clear");
            exit(0);
        }
        else{
            system("clear");
            continue;
            
        }
       
        std::cout << std::endl;
        std::cout << "  Желаете продолжить(y/n): ";
        std::cin  >> ansver;
        system("clear");
    }while(ansver != 'n');
    
 }

//Функция сложения
void addFunc(){
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Сложение матриц                 ")<< std::endl;
    std::cout << "┌───────────────────────────────────────────────────" << std::endl;
    std::cout << "│ Введите размер матрицы" << std::endl;
    std::cout << "├───────────────────────────────────────────────────" << std::endl;
    int str;
    int cols;
    std::cout << "│ Количество строк и столбцов: ";
    std::cin >> str;
    std::cin >> cols;
    std::cout << "└───────────────────────────────────────────────────" << std::endl;   
    Matrix result(str, cols);
    Matrix valueOne(str, cols);
    Matrix valueTwo(str, cols);
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод первой матрицы            ")<< std::endl;
    valueOne.enterMatrix();
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод второй матрицы            ")<< std::endl;
    valueTwo.enterMatrix();
    result = valueOne + valueTwo;
    result.outputMatrix();
 }

//функция вычитаня
 void subFunc(){
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Вычитание матриц           ")<< std::endl;
    std::cout << "┌───────────────────────────────────────────────────" << std::endl;
    std::cout << "│ Введите размер матрицы" << std::endl;
    std::cout << "├───────────────────────────────────────────────────" << std::endl;
    int str;
    int cols;
    std::cout << "│ Количество строк и столбцов: ";
    std::cin >> str;
    std::cin >> cols;
    std::cout << "└───────────────────────────────────────────────────" << std::endl;
    Matrix result(str, cols);
    Matrix valueOne(str, cols);
    Matrix valueTwo(str, cols);
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод первой матрицы        ")<< std::endl;
    valueOne.enterMatrix();
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод второй матрицы        ")<< std::endl;
    valueTwo.enterMatrix();
    result = valueOne - valueTwo;
    result.outputMatrix();
 }

//определегие функции умножения на число
void mulNumFunc(){
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Умножение матрицы на число  ")<< std::endl;
    std::cout << "┌───────────────────────────────────────────────────" << std::endl;
    std::cout << "│ Введите размер матрицы" << std::endl;
    std::cout << "├───────────────────────────────────────────────────" << std::endl;
    int str;
    int cols;
    std::cout << "│ Количество строк и столбцов: ";
    std::cin >> str;
    std::cin >> cols;
    std::cout << "└───────────────────────────────────────────────────" << std::endl;
    Matrix result(str, cols);
    Matrix matrix(str, cols);
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод матрицы                ")<< std::endl;
    matrix.enterMatrix();
    std::cout <<"│"<<std::endl;
    float number;
    std::cout << "│ Ввод числа на которое умножается матрица: ";
    std::cin >> number;
    result = matrix.mulNum(number);
    std::cout <<"│"<<std::endl;
    result.outputMatrix();
}

//функция транспонирования матрицы
void transponitionFunc(){
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Умножение матрицы на число  ")<< std::endl;
    std::cout << "┌───────────────────────────────────────────────────" << std::endl;
    std::cout << "│ Введите размер матрицы" << std::endl;
    std::cout << "├───────────────────────────────────────────────────" << std::endl;
    int str;
    int cols;
    std::cout << "│ Количество строк и столбцов: ";
    std::cin >> str;
    std::cin >> cols;
    std::cout << "└───────────────────────────────────────────────────" << std::endl;
    Matrix result(cols, str);
    Matrix matrix(str, cols);
    std::cout << std::endl;
    std::cout << print_as_color<ansi_color_code::background_cyan>("  Ввод матрицы                ")<< std::endl;
    matrix.enterMatrix();
    result = matrix.transposition();
    result.outputMatrix();
}