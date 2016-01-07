#include "superai.h"
#include<iostream>
#include <utility>
#include <math.h>
#define Colum 7
#define COL   7
#define ROW 6
#define Row 6

using namespace std;

superai::superai() {
    depth = 4;
    //mark = 1;
    returnValue = 0;
}

superai::~superai() {}

//pair<int, int>
//superai::returnCounterget(int matrix[Row][Colum]) {
//    return valueElvau(matrix);
//}

int
superai::rowcounter(int i, int j, int matrix[Row][Colum]){
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    //row
    while(matrix[row][col-1] == color && (col-1) >= 0) {
        col--;
    }
    //this->setWindowTitle(QString::number(row)+" "+QString::number(col));
    while(matrix[row][col] == color && col<COL) {
        col++;
        counter++;
    }
    return counter;
}

int
superai::colcounter(int i, int j, int matrix[Row][Colum]) {
    //col
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row][col] == color && row < ROW) {
        row++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
    }
    return counter;
}

int
superai::leftcounter(int i, int j, int matrix[Row][Colum]) {
    //left diagonal
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row-1][col-1] == color && ((col-1)>=0 && (row-1) >= 0) ) {
        row--;
        col--;
    }
    while(matrix[row][col] == color && (col < COL && row < ROW)) {
        row++;
        col++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
    }
    return counter;
}

int
superai::rightcounter(int i, int j, int matrix[Row][Colum]) {
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row-1][col+1] == color && ((col+1) < COL && (row-1) >= 0) ) {
        row--;
        col++;
    }
    while(matrix[row][col]==color && (col >= 0 && row < ROW)) {
        row++;
        col--;
        counter++;
    }
    return counter;
}

int
superai::counterget(int i, int j, int matrix[Row][Colum]) {
    int counter = 0;

    if(counter < rowcounter(i, j ,matrix))
        counter = rowcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" rowcounter"<<endl;

    if(counter < colcounter(i, j ,matrix))
        counter = colcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" colcounter"<<endl;

    if(counter < rightcounter(i, j ,matrix))
        counter = rightcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" rightcounter"<<endl;

    if(counter < leftcounter(i, j ,matrix))
        counter = leftcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" leftcounter"<<endl;



    return counter;
}

int
superai::returnFunc() {
    return returnValue;
}

pair<int,int>
superai::valueElvau(int board[Row][Colum],int i,int j)  {

    //cout<<board[i][j]<<" board "<<i<<" "<<j<<endl;

    int blackcounter = 0;
    int redcounter = 0;

//    for(int i=0; i<Row; i++) {
//        for(int j=0; j<Colum; j++) {
//            if(board[i][j] == 1) {
//                if(blackcounter < counterget(i,j, board))
//                {
//                    blackcounter = counterget(i,j, board);

//                }
//            }
//            else if(board[i][j] == 2) {
//                if(redcounter < counterget(i,j, board))
//                {
//                    redcounter = counterget(i,j, board);
//                    //cout<<redcounter<<" redcounter"<<endl;
//                }
//            }
//        }
//    }

    if(board[i][j] == 1)
    {
        blackcounter = counterget(i,j, board);
        redcounter=0;
    }
    else if(board[i][j] == 2)
    {
        redcounter = counterget(i,j, board);
        blackcounter=0;
    }

    //cout<<blackcounter<<" blackcounter "<<redcounter<<" redcounter"<<endl;

    pair<int, int> result = make_pair(blackcounter, redcounter);
    return result;


}

/*
0: keep search
1: end with accepthing
2: end with refusuing
*/
int
superai::judgement(int board[Row][Colum],int i,int j) {
    pair<int, int>temp_value = valueElvau(board,i,j);
    if(temp_value.second >= 4) {
        return 2;
    }
    else if(temp_value.first >= 4 && temp_value.second < 4) {
        return 1;
    }
    else
        return 0;
}

void
superai::run(int input[Row][Colum]) {
    bool mark=1;
    int dep=depth;
    dep--;
    int board[Row][Colum];
    for(int i=0; i<Row; i++) {
        for(int j=0; j<Colum; j++)
            board[i][j] = input[i][j];
    }
    int max = -10000;
    int index = 0;
    int ai_result[7];

    for(int k=0; k<7; k++)
        ai_result[k] = -10000;

    for(int j=0; j<Colum; j++) {
        for(int i=Row-1; i>=0; i--) {
            if(board[i][j] == 0) {
                //cout<<"this_node "<<i<<" "<<j<<endl;
                pair<int, int>this_nextnode = make_pair(i,j);
                ai_result[j] = run(board, this_nextnode,dep,mark);
                break;
            }
        }
    }

    for(int i=0; i<7; i++) {
        cout<<ai_result[i]<<" max "<<i<<" i"<<endl;
        if(ai_result[i] > max) {
            max = ai_result[i];

            index = i;
        }
    }
    returnValue = index;
}

int
superai::run(int temp_board[Row][Colum], pair<int, int> node,int dep,bool mark) {
    //put the next node
    //cout<<"run!!!"<<endl;
    //cout<<node.first<<" node "<<node.second<<" node"<<endl;

    int board[Row][Colum];
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Colum;j++)
        {
            board[i][j]=temp_board[i][j];
        }
    }

    int sum = 0;
    int ai_result[7];
    for(int k=0; k<7; k++)
        ai_result[k] = 0;

//    pair<int, int>abc = valueElvau(board,node.first,node.second);
//    if(dep==0)
//    {
//        cout<<abc.first<<" black "<<abc.second<<" red"<<endl;
//    }

    //cout<<board[3][0]<<" 3 0"<<endl;
    //cout<<mark<<" mark "<<dep<<endl;

    if(mark == 1)
        board[node.first][node.second] = 2;
    else
        board[node.first][node.second] = 1;

    //cout<<judgement(board)<< " !!!judge!!! "<<node.first<<" "<<node.second<<endl;
    //cout<<dep<<" dep"<<endl;

    if(dep==3)
    {
        cout<<judgement(board,node.first,node.second)<<" ~~~jidge~~~ "<<node.first<<" "<<node.second<<endl;
        pair<int, int>abc = valueElvau(board,node.first,node.second);
        cout<<abc.second<<" red "<<abc.first<<" black"<<"~~~~~~~~~~~"<<endl;
    }

    if( dep >= 0){
        //cout<<judgement(board)<< " judge"<<node.first<<" "<<node.second<<endl;
        switch (judgement(board,node.first,node.second)) {
            case 0:   {
                dep--;
                mark = !mark;
                for(int j=0; j<Colum; j++) {
                    for(int i=Row-1; i>=0; i--) {
                        if(board[i][j] == 0){
                            pair<int, int>this_nextnode = make_pair(i, j);
                            //cout<<" i j"<<i<<" "<<j<<endl;
                            ai_result[j] = run(board, this_nextnode,dep,mark);
                            //cout<<ai_result[j]<<" ai_result[j] "<<i<<" "<<j<<endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 1: {
                for(int i=0; i<7; i++)
                    sum = sum + ai_result[i];
                pair<int, int>key1 = valueElvau(board,node.first,node.second);
                int blackV = sum - (key1.second - key1.first + pow (10.0, dep+1));
                //cout<<node.first<<" "<<node.second<<" node "<<sum<<" "<<dep<<endl;
                //cout<<"blackV"<<endl;
                return blackV;
                break;
            }

            case 2: {
                if(dep==3){ cout<<node.first<<" "<<node.second<<" case2 judge!! "<<endl; }
                for(int i=0; i<7; i++)
                    sum = sum + ai_result[i];
                pair<int, int>key2 = valueElvau(board,node.first,node.second);
                int redV = sum + (key2.second - key2.first + pow (10.0, dep+1));
                if(dep==3) {cout<<redV<<" redV"<<endl;}
                //cout<<node.first<<" "<<node.second<<" node "<<sum<<" "<<dep<<endl;
                //cout<<"redV"<<endl;
                return redV;
                break;
            }
        }
    }
    else {
        pair<int, int> r_return = valueElvau(board,node.first,node.second);
        //cout<<"else~~~"<<endl;
        return r_return.second - r_return.first;
    }

    for(int i=0; i<7; i++)
        sum = sum + ai_result[i];

    //std::cout<<sum<<" sum "<<node.first<<" "<<node.second<<std::endl;
    //cout<<node.first<<" "<<node.second<<" node "<<sum<<" "<<dep<<endl;
    //cout<<"sum~~~"<<endl;
    return sum;
}



