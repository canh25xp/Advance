#define _CRT_SECURE_NO_WARNINGS // Suppress Warning	C4996: 'freopen': This function or variable may be unsafe. Consider using freopen_s instead.
#include <iostream>
using namespace std;

const int DIV = 12;         // should be 100000007
const int MAX_N = 2;      // should be 100
const int MAX_M = 10000000; // should be 10.000.000

template <typename T=unsigned long long, unsigned int MAX=MAX_N>
class Matrix{
private:
    unsigned int size;
    T data[MAX][MAX];
        
public:
    Matrix();
    Matrix(unsigned int size);

    T& operator()(int i, int j);
    T operator()(int i, int j) const;
    Matrix operator*(const Matrix& mat) const;
    void operator*=(const Matrix& mat);
    Matrix operator^(int exp) const; // Power operator, not XOR operator.
    Matrix operator%(const int& div) const;
    bool operator==(const int& rhs) const;
    friend ostream& operator<<(ostream& os, const Matrix& mat);
    friend istream& operator>>(istream& is, Matrix& mat);

    Matrix QuickModular(int exp, const int& div) const;
    int Size() const;
    void Reset();
};



int main(){
    //freopen("MatrixProduct1_input.txt", "r", stdin);
    //freopen("MatrixProduct1_input_small.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    int T; cin >> T;

    for (int tc = 0; tc < T; tc++){
        int N, M;
        cin >> N >> M;

        Matrix<> mat(N);
        cin >> mat;

        //Matrix res = mat ^ M;

        //Matrix rem1 = res % DIV;

        //Matrix rem = mat.QuickModular(M, DIV);

        cout << "Case #" << tc + 1 << endl;
        //cout << rem;
    }

    return 0;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX>::Matrix(){
    size = MAX;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            this->data[i][j] = 0;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX>::Matrix(unsigned int size){
    this->size = size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = 0;
}

template <typename T, unsigned int MAX>
T& Matrix<T, MAX>::operator()(int i, int j){
    return data[i][j];
}

template <typename T, unsigned int MAX>
T Matrix<T, MAX>::operator()(int i, int j) const{
    return data[i][j];
}

ostream& operator<<(ostream& os, const Matrix<>& mat){
    for (int i = 0; i < mat.Size(); i++){
        for (int j = 0; j < mat.Size(); j++)
            cout << mat(i, j) << " ";
        cout << endl;
    }

    return os;
}

istream& operator>>(istream& is, Matrix<>& mat){
    for (int i = 0; i < mat.Size(); i++)
        for (int j = 0; j < mat.Size(); j++)
            is >> mat(i,j);

    return is;
}

template <typename T, unsigned int MAX>
int Matrix<T, MAX>::Size() const{
    return this->size;
}

template <typename T, unsigned int MAX>
void Matrix<T, MAX>::Reset(){
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            this->data[i][j] = 0;
}

//Matrix Matrix::operator*(const Matrix& mat) const{
//    Matrix mat_res(size);
//    for (int i = 0; i < size; i++)
//        for (int j = 0; j < size; j++)
//            for (int k = 0; k < size; k++)
//                mat_res(i, j) += (((*this)(i, k)*mat(k, j)) % MOD) % MOD;
//
//    return mat_res;
//}
//
//Matrix Matrix::operator^(const int& exp) const{
//    if(exp == 1)
//        return (*this);
//
//    Matrix ans = (*this)^(exp/2);
//    ans = ans*ans;
//
//    if (exp % 2 == 1)
//        ans = ans*(*this);
//
//    return ans;
//}


template <typename T, unsigned int MAX>
Matrix Matrix<T, MAX>::operator*(const Matrix& mat) const{
    Matrix mat_res(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                mat_res(i, j) += (*this)(i, k)*mat(k, j);

    return mat_res;
}

template <typename T, unsigned int MAX>
void Matrix<T, MAX>::operator*=(const Matrix& mat){
    (*this) = (*this)*mat;
}

//Matrix Matrix::operator^(const int& exp) const{
//    if(exp==1)
//        return (*this);
//
//    return (*this)*((*this)^(exp-1));
//}

template <typename T, unsigned int MAX>
Matrix Matrix<T, MAX>::operator^(int exp) const{
    int size = this->Size();
    Matrix res(size);

    // Initialize res as an Identity matrix.
    for (int i = 0; i < size; i++)
            res(i,i) = 1;

    Matrix x = (*this);

    while (exp > 0){
        if (exp % 2 == 1)
            res *= x;
        
        exp /= 2;
        x*=x;
    }

    return res;
}

template <typename T, unsigned int MAX>
Matrix Matrix<T, MAX>::QuickModular(int exp, const int& div) const{
    int size = this->Size();
    Matrix rem(size);

    // Initialize res as an Identity matrix.
    for (int i = 0; i < size; i++)
            rem(i,i) = 1;

    Matrix x = (*this);

    x = x % div;

    if (x == 0)
        return x;

    while (exp > 0){
        if (exp % 2 == 1){
            rem *= x;
            rem = rem % div;
        }
        
        exp /= 2;
        x *= x;
        x = x % div;
    }

    return rem;
}

template <typename T, unsigned int MAX>
Matrix Matrix<T, MAX>::operator%(const int& div) const{
    Matrix rem = *this;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rem(i,j) %= div;

    return rem;
}

template <typename T, unsigned int MAX>
bool Matrix<T, MAX>::operator==(const int& rhs) const{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (this->data[i][j] != rhs)
                return false;

    return true;
}
