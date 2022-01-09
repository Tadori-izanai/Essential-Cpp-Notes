#include <iostream>
using namespace std;

const int n = 4;            // 支持的阶数
typedef double elemType;    // 方便修改 matrix 支持的类型

class Matrix {
public:
    // constructor
    Matrix(
        elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0,
        elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0, 
        elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0, 
        elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0
    ); // default constructor
    Matrix(elemType [][n]);    // 接受 4*4 的二维数组
    Matrix(elemType []);       // 接受一维数组
    
    // member fuction
    ostream &print(ostream &os = cout) const;

    // 运算符重载
    // 考虑 non-member function 和 friend
    friend Matrix operator+(const Matrix &, const Matrix &);    
    friend Matrix operator*(const Matrix &, const Matrix &);
    // 考虑 member function
    Matrix operator+=(const Matrix & rhs);  // 是自己的 member function, 可以访问 rhs 的 private
    // function call
    elemType &operator()(int row, int col);
    elemType operator()(int row, int col) const;

private:
    elemType _a[n][n];
};

// constructor
inline Matrix::Matrix(
        elemType val_11, elemType val_12, elemType val_13, elemType val_14,
        elemType val_21, elemType val_22, elemType val_23, elemType val_24,
        elemType val_31, elemType val_32, elemType val_33, elemType val_34,
        elemType val_41, elemType val_42, elemType val_43, elemType val_44
) {
    _a[0][0] = val_11;
    _a[0][1] = val_12;
    _a[0][2] = val_13;
    _a[0][3] = val_14;
    _a[1][0] = val_21;
    _a[1][1] = val_22;
    _a[1][2] = val_23;
    _a[1][3] = val_24;
    _a[2][0] = val_31;
    _a[2][1] = val_32;
    _a[2][2] = val_33;
    _a[2][3] = val_34;
    _a[3][0] = val_41;
    _a[3][1] = val_42;
    _a[3][2] = val_43;
    _a[3][3] = val_44;
}
inline Matrix::Matrix(elemType arr[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            _a[i][j] = arr[i][j];
    }
}
inline Matrix::Matrix(elemType arr[]) {
    for (int i = 0; i < n * n; i++) {
        _a[i / 4][i % 4] = arr[i];
    }
}

// member function
ostream &Matrix::print(ostream &os) const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            os << _a[i][j] << ' ';
        os << endl;
    }
    return os;
}

// 运算符重载
inline Matrix operator+(const Matrix &mat1, const Matrix &mat2) {
    Matrix sum_mat;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            sum_mat._a[i][j] = mat1._a[i][j] + mat2._a[i][j];
    }
    return sum_mat;
}
inline Matrix operator*(const Matrix &mat1, const Matrix &mat2) {
    Matrix pro_mat;     // 使用了 default constructor, 初始化为零矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                pro_mat._a[i][j] += (mat1._a[i][k] * mat2._a[k][j]);
        }
    }
    return pro_mat;
}
inline Matrix Matrix::operator+=(const Matrix &rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;  j++)
            _a[i][j] += rhs._a[i][j];
    }
    return *this;
}

inline elemType &Matrix::operator()(int row, int col) {
    return _a[row][col];
}

inline elemType Matrix::operator()(int row, int col) const {
    return _a[row][col];
}


// 利用 member function print() 来重载运算符 <<
inline ostream &operator<<(ostream &os, const Matrix rhs) {
    return rhs.print(os);
}