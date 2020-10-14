#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
/*
                block definition start
*/
////////////////////////////////////////////////////////////////////////////

class game_matrix;					// forward declaration
class block							// class block
{
    friend game_matrix;
    protected:
        bool **block_matrix;        // 4 * 4 matrix
    public:
        block();
        ~block();
        void show();
};

block::block()						// constructor
{
    block_matrix = new bool *[4];
    for (int i = 0; i < 4; i++) {
        block_matrix[i] = new bool [4];
    }
};

block::~block()						// destructor
{
    for (int i = 0; i < 4; i++) {
        delete block_matrix[i];
    }
    delete block_matrix;
};

void block::show()					// show block_matrix
{
    cout << "block_matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << block_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////////
/*
                block definition end                
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                T_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class T_block:public block
{
    public:
        T_block(int type_number);
        ~T_block();
};

T_block::T_block(int type_number)
{
    if (type_number == 1) {
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
    else if (type_number == 2) {
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
    else if (type_number == 3) {
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
    else if (type_number == 4) {
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
                T_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                L_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class L_block:public block
{
    public:
        L_block(int type_number);
        ~L_block();
};

L_block::L_block(int type_number)
{
    if (type_number == 1) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 1;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 2) {
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
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 0;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 3) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 1;
        block_matrix[1][1] = 1;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 0;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 0; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 4) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 0;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 0;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 1;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 0;
    }
    else {
        cout << "invalid type_number" << endl;
    }    
};

////////////////////////////////////////////////////////////////////////////
/*
                L_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                J_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class J_block:public block
{
    public:
        J_block(int type_number);
        ~J_block();
};

J_block::J_block(int type_number)
{
    if (type_number == 1) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 0;
        block_matrix[1][1] = 1;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 0;
        block_matrix[2][1] = 1;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 2) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 0;        
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 3) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 1;
        block_matrix[1][1] = 1;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 0;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 4) {
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
        block_matrix[3][1] = 0;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 0;
    }
    else {
        cout << "invalid type_number" << endl;
    }    
};

////////////////////////////////////////////////////////////////////////////
/*
                J_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                S_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class S_block:public block
{
    public:
        S_block(int type_number);
        ~S_block();
};

S_block::S_block(int type_number)
{
    if (type_number == 1) {
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
        block_matrix[2][2] = 1;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 2) {
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
        
        block_matrix[3][0] = 0; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }    
    else {
        cout << "invalid type_number" << endl;
    }    
};

////////////////////////////////////////////////////////////////////////////
/*
                S_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                Z_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class Z_block:public block
{
    public:
        Z_block(int type_number);
        ~Z_block();
};

Z_block::Z_block(int type_number)
{
    if (type_number == 1) {
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
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 0; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 2) {
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
                Z_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                I_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class I_block:public block
{
    public:
        I_block(int type_number);
        ~I_block();
};

I_block::I_block(int type_number)
{
    if (type_number == 1) {
        block_matrix[0][0] = 1;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 1;
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 1;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 0;
        block_matrix[3][2] = 0;
        block_matrix[3][3] = 0;
    }
    else if (type_number == 2) {
        block_matrix[0][0] = 0;
        block_matrix[0][1] = 0;
        block_matrix[0][2] = 0;
        block_matrix[0][3] = 0;
        
        block_matrix[1][0] = 0;        
        block_matrix[1][1] = 0;
        block_matrix[1][2] = 0;
        block_matrix[1][3] = 0;
        
        block_matrix[2][0] = 0;
        block_matrix[2][1] = 0;
        block_matrix[2][2] = 0;
        block_matrix[2][3] = 0;
        
        block_matrix[3][0] = 1; 
        block_matrix[3][1] = 1;
        block_matrix[3][2] = 1;
        block_matrix[3][3] = 1;
    }    
    else {
        cout << "invalid type_number" << endl;
    }    
};

////////////////////////////////////////////////////////////////////////////
/*
                I_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                O_block definition start
*/
////////////////////////////////////////////////////////////////////////////

class O_block:public block
{
    public:
        O_block();
        ~O_block();
};

O_block::O_block()
{
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
    block_matrix[2][2] = 0;
    block_matrix[2][3] = 0;
       
    block_matrix[3][0] = 1; 
    block_matrix[3][1] = 1;
    block_matrix[3][2] = 0;
    block_matrix[3][3] = 0;
};

////////////////////////////////////////////////////////////////////////////
/*
                O_block definition end
*/                
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                game_matrix definition start
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
        int drop_des(char blocktype, int type_number, int des, int startcol, block *temp);
        void check_delete(int des);
        void clear_row(int deleted_row, int number_of_deleted_row);
        bool putin_valid(int put_row, int put_col, block *temp);
        bool upboundary_valid();
        bool showvalue(int r, int c);

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
    cout << "game_matrix:" << endl;
    for (int i = 0 + 4; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << value[i][j] << " ";
        }
        cout << endl;
    }
};

bool game_matrix::showvalue(int r, int c)
{
    return value[r][c];
}

int game_matrix::drop_des(char blocktype, int type_number, int des, int startcol, block *temp)
{
    //int des = 0;
    startcol--;
    if (blocktype == 'T') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol + 1] == 1) break;
                }
                if (value[des][startcol] == 1) break;                
                if (value[des][startcol + 2] == 1) break;
            }
            if (des == row) des--;
            cout << "T1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol + 1] == 1) break;
                }
                if (value[des][startcol] == 1) break;
            }
            if (des == row) des--;
            cout << "T2 des: " << des << endl;
        }
        else if (type_number == 3) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                    if (value[des + 1][startcol + 2] == 1) break;
                }                
            }
            if (des == row) des--;
            cout << "T3 des: " << des << endl;
        }
        else if (type_number == 4) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                }
                if (value[des][startcol + 1] == 1) break;
            }
            if (des == row) des--;
            cout << "T4 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
    }
    else if (blocktype == 'L') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "L1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                }
                if (value[des][startcol + 1] == 1) break;
                if (value[des][startcol + 2] == 1) break;
            }
            if (des == row) des--;
            cout << "L2 des: " << des << endl;
        }
        else if (type_number == 3) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol + 1] == 1) break;
                }
                if (des > 0) {
				    if (value[des - 1][startcol] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "L3 des: " << des << endl;
        }
        else if (type_number == 4) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                    if (value[des + 1][startcol + 2] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "L4 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
    }    
	else if (blocktype == 'J') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "J1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                    if (value[des + 1][startcol + 2] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "J2 des: " << des << endl;
        }
        else if (type_number == 3) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                }
                if (des > 0) {
				    if (value[des - 1][startcol + 1] == 1) break;                
                }
            }
            if (des == row) des--;
            cout << "J3 des: " << des << endl;
        }
        else if (type_number == 4) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol + 2] == 1) break;
                }
                if (value[des][startcol] == 1) break;
                if (value[des][startcol + 1] == 1) break;
            }
            if (des == row) des--;
            cout << "J4 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
    } 
	else if (blocktype == 'S') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                }
                if (value[des][startcol + 2] == 1) break;
            }
            if (des == row) des--;
            cout << "S1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol + 1] == 1) break;
                }
                if (value[des][startcol] == 1) break;
            }
            if (des == row) des--;
            cout << "S2 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
	}
	else if (blocktype == 'Z') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol + 1] == 1) break;
                    if (value[des + 1][startcol + 2] == 1) break;
                }
                if (value[des][startcol] == 1) break;
            }
            if (des == row) des--;
            cout << "Z1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                }
                if (value[des][startcol + 1] == 1) break;
            }
            if (des == row) des--;
            cout << "Z2 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
	}
	else if (blocktype == 'I') {
        if (type_number == 1) {
            for (des; des < row; des++) {
                if (des < row - 1) {                              // not touch bottom
                    if (value[des + 1][startcol] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "I1 des: " << des << endl;
        }
        else if (type_number == 2) {
            for (des; des < row; des++) {
                if (des < row - 1) {
                    if (value[des + 1][startcol] == 1) break;
                    if (value[des + 1][startcol + 1] == 1) break;
                    if (value[des + 1][startcol + 2] == 1) break;
                    if (value[des + 1][startcol + 3] == 1) break;
                }
            }
            if (des == row) des--;
            cout << "I2 des: " << des << endl;
        }
        else cout << "invalid type_number in game_matrix.drop()" << endl;
	}
	else if (blocktype == 'O') {
		for (des; des < row; des++) {
	        if (des < row - 1) {
                if (value[des + 1][startcol] == 1) break;
                if (value[des + 1][startcol + 1] == 1) break;
            }
        }
        if (des == row) des--;
        cout << "O des: " << des << endl;
	}
	else cout << "Invalid blocktype in game_matrix.drop()" << endl;

    return des;
};

bool game_matrix::putin_valid(int put_row, int put_col, block *temp)
{
    int valid = 1;
    put_col--;
    for (int i = 4 - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (temp->block_matrix[i][j] == 1 && (put_col + j >= col || put_col + j < 0)) {                
                valid = 0;
                break;
            }
            else if (temp->block_matrix[i][j] == 1 && put_col + j < col && put_col + j >= 0)
                value[put_row - 3 + i][put_col + j] = 1;
        }
    }
    if (!valid) cout << "Shift over boundary" << endl;
    return valid;
};

void game_matrix::check_delete(int des)
{
    int deleted_row = 0;
    int number_of_deleted_row = 0;
    bool need_to_delete;

    
    for (int i = des; i >= 0; i--) {
        need_to_delete = 1;
        for (int j = 0; j < col; j++) {
            if (value[i][j] == 0)
                need_to_delete = 0;
        }
        if (need_to_delete) {
            if (i > deleted_row) deleted_row = i;
            number_of_deleted_row++;
        }
    }
    if (number_of_deleted_row > 0) this->clear_row(deleted_row, number_of_deleted_row);
};

void game_matrix::clear_row(int deleted_row, int number_of_deleted_row)
{
    if (deleted_row >= number_of_deleted_row) {
        for (int i = deleted_row; i >= number_of_deleted_row; i--) {        
            for (int j = 0; j < col; j++) {
                value[i][j] = value[i - number_of_deleted_row][j];
            }
        }
        for (int i = 0; i < number_of_deleted_row; i++) {
            for (int j = 0; j < col; j++) {
                value[i][j] = 0;
            }
        }
    }
    else {
        for (int i = 0; i <= deleted_row; i++) {
            for (int j = 0; j < col; j++) {
                value[i][j] = 0;
            }
        }
    }    
};

bool game_matrix::upboundary_valid()
{
    bool valid = 1;
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            if (value[i][j] == 1)
                valid = 0;
        }
    }
    if (!valid) cout << "over up boundary" << endl;
    return valid;
};
/*
bool game_matrix::lrboundary_valid(int put_col)
{
    int valid;
    put_col--;


};
*/
////////////////////////////////////////////////////////////////////////////
/*
                game_matrix definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                main program start
*/
////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int row;                    // game matrix row
    int col;                    // game matrix column
    char blocktype;             // block type
    int type_number;            // the order of block type
    int startcol;               // the col where refrence point drop
    int shift;                  // the shift
    block *temp;                // temp store block matrix
    int des;                    // the row that the first drop
    bool valid;                 // game valid


/*
    cin >> row >> col;
    cout << "(row, col): (" << row << ", " << col << ")" << endl;

    game_matrix mm(row, col);
    mm.show();

    cin >> blocktype;
    while (blocktype != 'E') {
        if (blocktype == 'O') {
            cin >> startcol >> shift;
            temp = new O_block();            
        }
        else {
            cin >> type_number >> startcol >> shift;
            if (blocktype == 'T') temp = new T_block(type_number);
            else if (blocktype == 'L') temp = new L_block(type_number);
            else if (blocktype == 'J') temp = new J_block(type_number);
            else if (blocktype == 'S') temp = new S_block(type_number);
            else if (blocktype == 'Z') temp = new Z_block(type_number);
            else if (blocktype == 'I') temp = new I_block(type_number);
            else cout << "invalid blocktype" << endl;            
        }
        temp->show();


        des = mm.drop_des(blocktype, type_number, 0, startcol, temp);
        des = mm.drop_des(blocktype, type_number, des, startcol + shift, temp);
        valid = mm.putin_valid(des, startcol + shift, temp); 
        if (valid) {
            cout << "Before Clear ";
            mm.show();
            mm.check_delete(des);
        }
        else {
            cout << "Game over because touch left-right boundary" << endl;
            break;
        }
        valid = mm.upboundary_valid();
        if (valid) mm.show();
        else {
            cout << "Game Over because touch up boundary" << endl;
            break;
        }    
        cin >> blocktype;   
    }
*/


    ifstream infile;                                // input data
    infile.open(argv[1]);                           // open input data
    if (!infile.is_open()) {
        cout << "Cannot open file!" << endl;        // print error message
    }


    infile >> row >> col;                       // read in row and col
    game_matrix mm(row, col);                  // main matrix
    mm.show();


    infile >> blocktype;                        // read in blocktype
    while (blocktype != 'E') {
        if (blocktype == 'O') {
            infile >> startcol >> shift;
            temp = new O_block();
        }
        else {
            infile >> type_number >> startcol >> shift;  // read in type, startpoint and shift
            if (blocktype == 'T') temp = new T_block(type_number);
            else if (blocktype == 'L') temp = new L_block(type_number);
            else if (blocktype == 'J') temp = new J_block(type_number);
            else if (blocktype == 'S') temp = new S_block(type_number);
            else if (blocktype == 'Z') temp = new Z_block(type_number);
            else if (blocktype == 'I') temp = new I_block(type_number);
            else cout << "invalid blocktype" << endl;            
        }
        des = mm.drop_des(blocktype, type_number, 0, startcol, temp);
        des = mm.drop_des(blocktype, type_number, des, startcol + shift, temp);
        valid = mm.putin_valid(des, startcol + shift, temp); 
        if (valid) {
            cout << "Before Clear ";
            mm.show();
            mm.check_delete(des);
        }
        else {
            cout << "Game over because touch left-right boundary" << endl;
            break;
        }
        valid = mm.upboundary_valid();
        if (valid)
            mm.show();
        else {
            cout << "Game Over because touch up boundary" << endl;
            break;
        }    
        infile >> blocktype;
    }        

    infile.close();                             // close input data

    ofstream outfile ("108061201_proj1.final");
    if (outfile.is_open()) {
        for (int i = 0 + 4; i < row + 4; i++) {
            for (int j = 0; j < col; j++) {
                outfile << mm.showvalue(i, j) << " ";
            }
            outfile << endl;
        }
        outfile.close();
    }
    else cout << "Unable to open outfile";

    return 0;
}

////////////////////////////////////////////////////////////////////////////
/*
                main program end
*/
////////////////////////////////////////////////////////////////////////////
