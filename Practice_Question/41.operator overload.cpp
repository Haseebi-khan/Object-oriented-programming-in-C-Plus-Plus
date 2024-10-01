#include <iostream>
using namespace std;
class Matrix
{
private:
	int noRow;
	int noCol;
	int** ptr;
public:
	Matrix() : ptr(nullptr) {}

	Matrix(int, int);

	Matrix(const Matrix&);

	const Matrix& operator = (const Matrix&);

	const Matrix& operator + (const Matrix&);

	const Matrix& operator += (const Matrix&);

	const Matrix& operator - (const Matrix&);

	const Matrix& operator -= (const Matrix&);

	bool operator == (const Matrix&);

	const Matrix& operator *(const Matrix&);


	friend istream& operator >> (istream&, Matrix&);

	friend ostream& operator <<(ostream&, const Matrix&);
	
	int operator ()(int, int);

	int * operator [](int );
};


//PARAMETRIZED CONSTRUCTOR
Matrix::Matrix(int row, int col) 
{
	noRow = row;
	noCol = col;
	ptr = new int* [noRow];
	for (int i = 0; i < row; i++) {
		ptr[i] = new int[noCol];
		for (int j = 0; j < col; j++) {
			ptr[i][j] = 0;
		}
	}
}

//COPY CONSTRUCTOR
Matrix::Matrix(const Matrix& ref) {
	noRow = ref.noRow;
	noCol = ref.noCol;
	ptr = new int* [noRow];
	for (int i = 0; i < noRow; i++) {
		ptr[i] = new int[noCol];
		for (int j = 0; j < noCol; j++) {
			ptr[i][j] = ref.ptr[i][j];
		}
	}
}

//ASSIGNMENT OPERATOR 
const Matrix& Matrix::operator=(const Matrix& ref)
{
	if (this != &ref) {
		if (ptr) {
			for (int i = 0; i < noRow; i++) {
				delete[] ptr[i];
			}
			delete[] ptr;
		}

		noRow = ref.noRow;
		noCol = ref.noCol;
		ptr = new int*[noRow];
		for (int i = 0; i < noRow; i++) {
			ptr[i] = new int[noCol];
			for (int j = 0; j < noCol; j++) {
				ptr[i][j] = ref.ptr[i][j];
			}
		}
	}
	return *this;
}


//ADDITION OPERATOR FOR TWO MATRIX
const Matrix& Matrix::operator+(const Matrix & ref){
	if (noRow == ref.noRow && noCol == ref.noCol && ptr != NULL) {
		Matrix temp(noRow, noCol);
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				temp.ptr[i][j] = ptr[i][j] + ref.ptr[i][j];
			}
		}
		return temp;
	}
	else {
		cout << "INVALID ADDITION: ORDER OF MATRIX IS NOT MATCHING";
		return Matrix(0, 0); /// created null matrix to avoid assignment problem->  obj=obj1-obj2;
	}
}

//OPEARATOR +=
const Matrix& Matrix::operator += (const Matrix& ref) {
	if (noRow == ref.noRow && noCol == ref.noCol) {
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				ptr[i][j] = ptr[i][j] + ref.ptr[i][j];
			}
		}
		return *this;
	}
	else {
		cout << "!!!!!INVALID ADDITION: ORDER OF MATRIX IS NOT MATCHING!!!!!";
		return Matrix(0, 0); /// created null matrix to avoid assignment problem->  obj=obj1-obj2;
	}
}

//SUBTRACTION OPERATOR FOR TWO MATRIX
const Matrix& Matrix:: operator - (const Matrix& ref) {
	if (noRow == ref.noRow && noCol == ref.noCol) {
		Matrix temp(noRow, noCol);
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				temp.ptr[i][j] = ptr[i][j] - ref.ptr[i][j];
			}
		}
		return temp;
	}
	else {
		cout << "!!!!!INVALID ADDITION: ORDER OF MATRIX IS NOT MATCHING!!!!!";
		return Matrix(0, 0);
	}
}
//OPERATOR -=
const Matrix& Matrix::operator -= (const Matrix& ref) {
	if (noRow == ref.noRow && noCol == ref.noCol) {
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				ptr[i][j] = ptr[i][j] - ref.ptr[i][j];
			}
		}
		return *this;
	}
	else {
		cout << "INVALID ADDITION: ORDER OF MATRIX IS NOT MATCHING";
		return Matrix(0, 0);
	}
}

// OPERATION *
const Matrix& Matrix :: operator *(const Matrix& ref) {
		Matrix tempMatrix(noRow, ref.noCol);
	if (noCol == ref.noRow) {
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				int temp = 0;
				for (int k = 0; k < noCol; k++) {
					temp += ptr[i][k] * ref.ptr[k][j];
				}
				tempMatrix.ptr[i][j] = temp;
			}
		}
		return tempMatrix;
	}
	else {
		cout << "BOTH MATRICES ARE NOT COMPATIBLE FOR MULTIPLICATION";
		return Matrix(0, 0);
	}
}
// == OPERATOR 
bool Matrix :: operator == (const Matrix& ref) {
	if (noRow == ref.noRow && noCol == ref.noCol) {
		for (int i = 0; i < noRow; i++) {
			for (int j = 0; j < noCol; j++) {
				if (ptr[i][j] != ref.ptr[i][j])
					return false;
			}
		}
		return true;
	}
	else
		return false;
}

//EXTRACTION OPERATOR
ostream& operator << (ostream& out, const Matrix& ref) {
	if (ref.ptr) {
		for (int i = 0; i < ref.noRow; i++) {
			cout << "|";
			for (int j = 0; j < ref.noCol; j++) {
				out << ref.ptr[i][j] << " ";
			}
			cout << "|" << endl;
		}
	}
	else {
		out << "MATRIX IS EMPTY";
	}
	return out;
}
//INSERTION OPERATON
istream& operator >> (istream& in, Matrix& ref) {
	if (ref.ptr) {
		cout << "ENTER ELEMENTS FOR ORDER" << ref.noRow << "-by-" << ref.noCol << endl;
		for (int i = 0; i < ref.noRow; i++) {
			for (int j = 0; j < ref.noCol; j++) {
				in >> ref.ptr[i][j];
			}
		}
		in.ignore(50, '\n');
	}
	else {
		cout << "ENTER NUMBER OF ROWS: ";
		in >> ref.noRow;
		in.ignore(50, '\n');
		cout << "ENTER NUMBER OF COLUMNS: ";
		in.ignore(50, '\n');
		in >> ref.noCol;
		cout << "ENTER MATRIX ELEMENTS: " << endl;
		ref.ptr = new int* [ref.noRow];
		for (int i = 0; i < ref.noRow; i++) {
			ref.ptr[i] = new int[ref.noCol];
			for (int j = 0; j < ref.noCol; j++) {
				in >> ref.ptr[i][j];
			}
		}

	}
	return in;
}

//() Function
int Matrix::operator ()(int ith, int jth) {
	return ptr[ith][jth];
}

//SUBSCRIPT OPERATOR []
int * Matrix::operator [](int ind) {
	return ptr[ind];
}


int main() {
	int row, col;
	cout << "***  ENTER NUMBER OF ROWS: ";
	cin >> row;
	cout << "***  ENTER NUMBER OF COLUMNS: ";
	cin >> col;
	Matrix m1(row, col);
	cout << "**  ENTER MATRIX 1 ELEMENTS  **\n";
	cin >> m1;
	cout << "**  OUTPUT OF MATRIX 1  **\n";
	cout << m1 << endl;
	Matrix m2(2, 3);
	cout << "**  ENTER MATRIX 2 ELEMENTS  **\n";
	cin >> m2;
	cout << "**  OUTPUT OF MATRIX 2  **\n";
	cout << m2 << endl;
	Matrix m3(2, 3);
	cout << "**  ENTER MATRIX 2 ELEMENTS  **\n";
	cin >> m3;
	cout << "**  OUTPUT OF MATRIX 2  **\n";
	cout << m3 << endl;
	Matrix m4;
	m4 = m1 + m2;
	cout << "****  ADDITION  ****\n" << m4;
	cout << "****  += Operation m1+=m2 ****" << endl;
	m1 += m2;
	cout << "**  OUTPUT OF MATRIX 1 AFTER m1+=m2  **\n";
	cout << m1 << endl;
	cout << "****  -= Operation m1-=m2 ****" << endl;
	m1 -= m2;
	cout << "**  OUTPUT OF MATRIX 1 AFTER m1-=m2  **\n";
	cout << m1;
	cout << "**** MATRIX EQUALITY CHECKING **** " << endl;
	if (m2 == m3) {
		cout << "BOTH OBJECTS ARE EQUAL" << endl;
	}
	else {
		cout << "BOTH OBJECTS ARE NOT EQUAL" << endl;
	}
	Matrix m5;
	m5 = m2 * m3;
	cout << "****  MULTIPLICAIION  ****\n" << m5 << endl;
	cout << "****  OBJECT AS FUNCTION CALL *****" << endl;
	cout << m5(0, 1) << endl;
	cout << "****  SUBSCRIPT ACCESSING *****" << endl;
	cout << m2[0][2];

}