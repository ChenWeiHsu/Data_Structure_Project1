#include <iostream>
#include <fstream>
using namespace std;

/*
typedef struct INDATA {  // input data
    int row, col;       // the number of rows and columns of the game matrix

} InDATA;

InDATA *GetData(char *inFile);
*/

int main(int argc, char *argv[])
{
    int row;
    int col;
    string blocktype;
    int startpoint;
    int shift;

    ifstream infile;
    infile.open(argv[1]);
    if (infile.is_open()) {
        infile >> row >> col;
        //infile >> blocktype >> startpoint >> shift;
        cout << "The row: " << row << endl;
        cout << "The col: " << col << endl;
        infile >> blocktype;
        while (blocktype != "End") {
            infile >> startpoint >> shift;

            cout << blocktype << " " << startpoint << " " << shift << endl;
            infile >> blocktype;
        }
        
        infile.close();
    }

    
    //cout << "The type of the block is " << blocktype << endl;
    //cout << "It starts from " << startpoint << " and shift " << shift << endl;

    return 0;
}

/*
InDATA *GetData(char *inFile)
{
    ifstream myfile;
    myfile.open(inFile);
    if (myfile.is_open()) {
        cin << 
    }
}
*/