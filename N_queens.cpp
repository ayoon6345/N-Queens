#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int N;
int **board = NULL;
int solutions;

//checks upper and upper left, right diagonals
bool valid(int y, int x){
    for(int i = y; i>=0; i--){
        if(board[i][x] == 1) return false;
    }
   for (int i = y, j = x; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1) return false;
   }
   for (int i = y, j = x; i >= 0 && j < N; i--, j++){
        if (board[i][j] == 1) return false;
   }   
  return true;
}
//Counts all possible solutions
bool check_row(int n){
    int temp;
    if(n >= N) {solutions++;
    return true;}
    
    for(int i=0; i<N; i++){
        //Symmetry if N is odd
        if ((N%2 !=0) && (n == 0) && (i == (N/2))){
         temp = solutions;
        }
        if ((N%2 !=0) && (n == 0) && (i == (N/2)+1)){
            solutions = solutions + temp;
            return true;
        }
        //Symmetry if N is even
        if ((N%2 == 0) && (n == 0) && (i == (N/2))){
            solutions = solutions * 2;
            return true;}  
        //Places queen if space is valid and recurse    
        if(valid(n, i) == true){
            board[n][i] = 1; 
            check_row(n+1);
            board[n][i] = 0;
            }     
    }
return 0;
}


int main(int argc, char *argv[]){
    if (argc !=2){
        cout << "Usage: ./a.out <input size>\n";
        return 0;
    //initialize N*N board
    }
    N = atoi(argv[1]);
    board = (int **)malloc(N * sizeof(int *)); 
    for (int i=0; i<N; i++) {
         board[i] = (int *)malloc(N * sizeof(int)); 
    }
    //set board to 0
    memset( *board, 0, sizeof(board) );

    check_row(0);

cout << "Number of solutions: " << solutions << "\n";
return 0;
}
