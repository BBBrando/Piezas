/**
 * Unit Tests for Piezas
**/
#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(piezasTest, firstPiece)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (test == X)
    check = true;
	ASSERT_TRUE(check);
}

TEST(PiezasTest, testFirst2Moves)
{
  Piezas game;
  Piece test1 = game.dropPiece(0);
  Piece test2 = game.dropPiece(0);
  bool check = false;
  if (test1 == X && test2 == O)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, negativePlacement)
{
  Piezas game;
  Piece test = game.dropPiece(-1);
  bool check = false;
  if (test == Invalid)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, outOfBoard)
{
  Piezas game;
  Piece test = game.dropPiece(20);
  bool check = false;
  if (test == Invalid)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, testPieceAt)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(0,0) == X)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, testPieceAtneg1)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(0,-1) == Invalid)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, testPieceAt9)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(0,9) == Invalid)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, testPieceAt99)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(9,9) == Invalid)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, testPieceAtneg99)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(-9,9) == Invalid)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, testPieceAtneg9neg9)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(-9,-9) == Invalid)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, testPieceAtValid)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(0,0) == X)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, testPieceAtBlank)
{
  Piezas game;
  Piece test = game.dropPiece(0);
  bool check = false;
  if (game.pieceAt(0,2) == Blank)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, resetTest)
{
  Piezas game;
  Piece test = game.dropPiece(0);
game.reset();
  bool check = false;
  if (game.pieceAt(0,0) == Blank)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, Xwins)
{
  Piezas game;
for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLS; j++) {
      game.dropPiece(j);
      game.dropPiece(0);
    }
  }
  bool check = false;
  if (game.gameState() == X)
    check = true;
	ASSERT_TRUE(check);
}

TEST(piezasTest, Owins)
{
  Piezas game;
for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLS; j++) {
      game.dropPiece(0);
      game.dropPiece(j);
    }
  }
  bool check = false;
  if (game.gameState() == O)
    check = true;
	ASSERT_TRUE(check);
}
TEST(piezasTest, tie)
{
  Piezas game;
for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLS; j++) {
      game.dropPiece(j);
    }
  }
  bool check = false;
  if (game.gameState() == Blank)
    check = true;
	ASSERT_TRUE(check);
}
