#include <iostream>
#include <fstream>
using namespace std;

void fall();
int not_touch();
void shift();
void heck_and_clear();

////////////////////////////////////////////////////////////////////////////
/*
class SparseMatrix;             // forward declaration

class MatrixTerm
{
    friend SparseMatrix;
    private:
        int row;
        int col;
        int value;
};

class SparseMatrix
{
    private:
        int row;
        int col;
        int terms;              // total number of nonzero entries
        int capacity;           // the size of smArray
        MatrixTerm *smArray;
    public:
        SparseMatrix(int r, int c);
        ~SparseMatrix();
        void show();

};

SparseMatrix::SparseMatrix(int r, int c) :row(r), col(c) {};

SparseMatrix::~SparseMatrix()
{
    row = 0;
    col = 0;
    delete [] smArray;
}

void SparseMatrix::show()
{
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (smArray[k].row == i && smArray[k].col == j)
                cout << smArray[k++].value << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
};
*/
////////////////////////////////////////////////////////////////////////////

class game_matrix
{
    private:
        int row;
        int col;
        bool **value;
    public:
        game_matrix(int r, int c);
        ~game_matrix();
        void show();
        void clear_row(int deleted_row);

};

game_matrix::game_matrix(int r, int c): row(r),  col(c)
{
    value = new bool *[row];
    for (int i = 0; i < row; i++) {
        value[i] = new bool [col];
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            value[i][j] = 0;
        }
    }
};

game_matrix::~game_matrix()
{
    for (int i = 0; i < row; i++) {
        delete value[i];
    }
    delete value;
};

void game_matrix::show()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << value[i][j] << " ";
        }
        cout << endl;
    }
};

void game_matrix::clear_row(int deleted_row)
{
    for (int i = deleted_row; i > 0; i--) {        
        for (int j = 0; j < col; j++) {
            value[i][j] = volue[i - 1][j];
        }
    }

    for (int j = 0; j < col; j++) {
        value[0][j] = 0;
    }
}

////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////

switch (blocktype) {
    case "T1":
        break;
    case "T2":
        break;
    case "T3":
        break;
    case "T4":
        break;
    case "L1":
        break;
    case "L2":
        break;
    case "L3":
        break;
    case "L4":
        break;
    case "J1":
        break;
    case "J2":
        break;
    case "J3":
        break;
    case "J4":
        break;
    case "S1":
        break;
    case "S2":
        break;
    case "Z1":
        break;
    case "Z2":
        break;
    case "I1":
        break;
    case "I2":
        break;
    case "O":
        break;
}


int main(int argc, char *argv[])
{
    int row;
    int col;
    string blocktype;
    int startpoint;
    int shift;

    ifstream infile;                                // input data
    infile.open(argv[1]);                           // open input data
    if (!infile.is_open()) {
        cout << "Cannot open file!" << endl;
    }


    infile >> row >> col;                       // read in row and col
    game_matrix mm(row, col);                  // main matrix


    infile >> blocktype;                        // read in blocktype
    while (blocktype != "End") {
        infile >> startpoint >> shift;          // read in startpoint and shift
        move();
        game_matrix.clear_line();
        infile >> blocktype;
    }        
    infile.close();                             // close input data
    

    return 0;
}

move()
{
    while (not_touch()) {
    down();
    }
    shift();
    while (not_touch()) {
    down();
    }
}