#include <iostream>
#include <iomanip>
using namespace std;

//尝试创造一个矩阵类
template <typename T>
class Matrix {
public:
    Matrix () : row(0), column(0), arr(nullptr) {};
    Matrix (int r, int c) : column(c), row (r) {
        arr = new T * [row];
        for (int i = 0; i < row; i++) {
            arr[i] = new T [column];
        }
    }

    //复制构造函数
    Matrix (const Matrix & other) {
        column = other.column;
        row = other.row;
        arr = new T*[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new T [column];
            for (int j = 0; j < column; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    ~Matrix () {
        for (int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete [] arr;
    }

    //模仿stl的resize
    void resize (int r, int c, int val = 0) {
        //多出的位置用val填充
        T** newarr = new T * [r];
        for (int i = 0; i < r; i++) {
            newarr[i] = new T[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i < row && j < column) {
                    newarr[i][j] = arr[i][j];
                } else {
                    newarr [i][j] = val;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete [] arr;
        arr = newarr;
        newarr = nullptr;
        row = r; 
        column = c;
    }

    //打印矩阵
    void print() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0 ; j < column; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    T * operator [] (const int & index) {
        return arr[index];
    }

    //table(i, j) 返回 矩阵第i行第j列
    T & table (const int &i, const int &j) {
        return arr[i][j];
    }

    // 矩阵加法
    Matrix operator + (const Matrix& mat) const{
        if (mat.row != row || mat.column != column) {
            cout << "ERROR!" << endl;
            return Matrix();
        }
        Matrix <T> tmp(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                tmp[i][j] = arr[i][j] + mat.arr[i][j];
            }
        }
        return tmp;
    } 

    //赋值号，深拷贝
    Matrix& operator = (const Matrix &mat) {
        for (int i = 0; i < row; i++) {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete [] arr;
        row = mat.row;
        column = mat.column;
        arr = new T * [row];
        for (int i = 0; i < row; i++) {
            arr[i] = new T [column];
            for (int j = 0; j < column; j++) {
                arr[i][j] = mat.arr[i][j];
            }
        }
        return *this;
    }

    Matrix& operator += (const Matrix & mat) {
        *this = *this + mat;
        return *this;
    }

    //矩阵乘法
    Matrix operator * (const Matrix & mat) const {
        if (column != mat.row) {
            cout << "ERROR!" << endl;
            return Matrix();
        }
        Matrix <T> tmp(row, mat.column);
        for (int i = 0; i < tmp.row; i++) {
            for (int j = 0; j < tmp.column; j++) {
                tmp[i][j] = 0;
                for (int k = 0; k < column; k++) {
                    tmp[i][j] += arr[i][k] * mat.arr[k][j];
                }
            }
        }
        return tmp;
    }

    Matrix& operator *= (const Matrix & mat) {
        *this = *this * mat;
        return *this;
    }

    //重载输出流
    friend ostream & operator << (ostream & os, const Matrix & mat) {
        mat.print();
        return os;
    }

    friend istream & operator >>  (istream & is, Matrix & mat) {
        //此处别忘释放内存。谨防内存泄漏。
        for (int i = 0; i < mat.row; i++) {
            delete[] mat.arr[i];
        }
        delete[] mat.arr;
        
        is >> mat.row >> mat.column;
        mat.arr = new T * [mat.row];
        for (int i = 0; i < mat.row; i++) {
            mat.arr[i] = new T [mat.column];
            for (int j = 0; j < mat.column; j++) {
                is >> mat[i][j];
            }
        }
        return is;
    }
    void printmid () {
        cout << arr[row / 2][column / 2] << endl;
    }
private:
    int column ;
    int row ;
    T** arr;
};

int main () {
    Matrix <double> a, b;
    cin >> a >> b;
    a.printmid();
    cout << (a *= b) << (a += b) << (a = b);
    return 0;
}