#include <iostream>
#include <fstream>
using namespace std;

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
/*
                game_matrix class definition start
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
        void drop(block &b);
        void clear_row(int deleted_row);

};

game_matrix::game_matrix(int r, int c): row(r + 4),  col(c)
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

void game_matrix::show() // show whole
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
            value[i][j] = value[i - 1][j];
        }
    }

    for (int j = 0; j < col; j++) {
        value[0][j] = 0;
    }
}

////////////////////////////////////////////////////////////////////////////
/*
                game_matrix definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                block definition start
*/
////////////////////////////////////////////////////////////////////////////

class block
{
    protected:
        bool **block_matrix;        // 4 * 4 matrix
        int refrence_row;
        int refrence_col;
    public:
        block();
        ~block();
        void show();
};

block::block()
{
    block_matrix = new bool *[4];
    for (int i = 0; i < 4; i++) {
        block_matrix[i] = new bool [4];
    }
};

block::~block()
{
    for (int i = 0; i < 4; i++) {
        delete block_matrix[i];
    }
    delete block_matrix;
};

void block::show()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << block_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

class T_block:public block
{
    public:
        T_block();
        T_block(int type_number, int stratcol);
        ~T_block();
};

T_block::T_block()
{
    refrence_row = 0;
    refrence_col = 0;
};

T_block::T_block(int type, int startcol)
{
    refrence_row = 0;
    refrence_col = startcol - 1;
    if (type == 1) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        block_matrix[1][0] = 0;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 1;
        block_matrix[2][3] = 0;
        block_matrix[3][0] = 0; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type == 2) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        block_matrix[1][0] = 0;
        block_matrix[1][1] = 1;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        block_matrix[3][0] = 0; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type == 3) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        block_matrix[1][0] = 0;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        block_matrix[2][0] = 0;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 0;
    }
    else if (type == 4) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        block_matrix[1][0] = 1;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 0;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else {
        cout << "invalid type_number" << endl;
    }
    
};

////////////////////////////////////////////////////////////////////////////
/*
                block definition end
*/                
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[])
{
    int row;
    int col;
    char blocktype;
    int type_number;
    int startcol;
    int shift;
    block *temp;

    cin >> row >> col;
    cout << "(row, col): (" << row << ", " << col << ")" << endl;
    game_matrix mm(row, col);
    mm.show();
    cin >> blocktype >> type_number >> startcol >> shift;
    cout << "bolcktype: " << blocktype << endl;
    cout << "type_number: " << type_number << endl;
    while (blocktype != 'E') {
        if (blocktype == 'T') {
            temp = new T_block(type_number, startcol);
        }
        else {
            cout << "invalid blocktype" << endl;
        }
        temp->show();
        cin >> blocktype >> type_number >> startcol >> shift;
        cout << "bolcktype: " << blocktype << endl;
        cout << "type_number: " << type_number << endl;
    }
//    gernerate_block();
/*
    ifstream infile;                                // input data
    infile.open(argv[1]);                           // open input data
    if (!infile.is_open()) {
        cout << "Cannot open file!" << endl;
    }


    infile >> row >> col;                       // read in row and col
    game_matrix mm(row, col);                  // main matrix
    mm.show();
*/
/*
    infile >> blocktype;                        // read in blocktype
    while (blocktype != 'E') {
        infile >> type_number >> startpoint >> shift;  // read in type, startpoint and shift

        if (blocktype == 'T')
            tempblock = new T_block(type_number, startpoint);
        move();
        game_matrix.clear_line();
        infile >> blocktype;
    }        
*/
//    infile.close();                             // close input data


    return 0;
}

/*
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
*/