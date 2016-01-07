#ifndef SUPERAI_H
#define SUPERAI_H

#define Colum 7
#define Row  6
#include <utility>
using namespace std;

class superai {
public:
    superai();
    ~superai();

    void run(int A_board[Row][Colum]);
    int returnFunc();
    pair<int, int> returnCounterget(int matrix[Row][Colum]);
private:
    //int Board[Row][Colum];
    int depth;
    //bool mark;
    int returnValue;

    int run(int A_board[Row][Colum], pair<int, int> node,int,bool);
    int counterget(int x, int y, int matrix[Row][Colum]);
    int judgement(int board[Row][Colum],int,int);

    int rowcounter(int x, int y, int matrix[Row][Colum]);
    int colcounter(int x, int y, int matrix[Row][Colum]);
    int rightcounter(int x, int y, int matrix[Row][Colum]);
    int leftcounter(int x, int y, int matrix[Row][Colum]);

    pair<int, int> valueElvau(int board[Row][Colum], int i, int j);
};

#endif // SUPERAI_H
