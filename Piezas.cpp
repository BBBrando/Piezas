#include "Piezas.h"
#include <vector>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  board = vector<vector<Piece>>(BOARD_ROWS,vector<Piece>(BOARD_COLS,Blank));
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  board = vector<vector<Piece>>(BOARD_ROWS, vector<Piece>(BOARD_COLS,Blank));
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
    Piece temp = turn;
    //flip turn between X and O every turn
    if (turn == X) {
      turn = O;
    }
    else if (turn == O) {
      turn = X;
    }

    for (int i = 0; i < BOARD_ROWS; i++) {
      if (board[i][column] == Blank) {//loop to find first blank and return piece
        board[i][column] = temp;
        return temp;
      }
    }

    return Blank;//if no piece found return blank
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/

Piece Piezas::gameState()
{
  int max[2] = {};
  char turncheck[2] = {'O','X'};

  for(int i = 0; i < BOARD_ROWS; i++) {
    if (board[i][BOARD_ROWS-1] == Blank) {
      return Invalid;
    }

    int current = 0;
    int curIndex = 0;

    for(int j = 0; j < BOARD_COLS; j++) {

      if (turncheck[curIndex] == board[i][j]){
        current++;
      }
      else {
         if (curIndex == 1 ) {
           curIndex = 0;
         }
         else if(curIndex == 0 && 1==1){
           curIndex = 1;
         }
         current = 1;
       }
     if (current > max[curIndex])
       max[curIndex] = current;

    }
  }

  for(int i = 0; i < BOARD_COLS; i++) {

    int current = 0;
    int curIndex = 1;

    for(int j = 0; j < BOARD_ROWS; j++) {
      if (turncheck[curIndex] == board[j][i]){
        current++;
      }
      else {
         if (curIndex == 1 ) {
           curIndex = 0;
         }
         else if(curIndex == 0 && 1==1){
           curIndex = 1;
         }
       current = 1;
     }
     if (current > max[curIndex])
       max[curIndex] = current;
    }
  }


  if (max[0] < max[1]){
      return X;
  }
  if (max[0] > max[1]){
    return O;
    }
  return Blank;

}//gameState
