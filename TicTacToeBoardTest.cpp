/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// TOGGLE TURN TESTS
TEST(TicTacToeBoard, toggle_turn_O) {
	TicTacToeBoard board;
	Piece actual = board.toggleTurn();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoard, toggle_turn_X) {
	TicTacToeBoard board;
	Piece actual = board.toggleTurn();
	actual = board.toggleTurn();
	ASSERT_EQ(actual, X);
}


// PLACE PIECE TESTS
TEST(TicTacToeBoard, valid_place_piece) {
	TicTacToeBoard board;
	Piece actual = board.placePiece(2, 2);
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, invalid_place_piece) {
	TicTacToeBoard board;
	Piece actual = board.placePiece(4, 4);
	ASSERT_EQ(actual, Invalid);
}

// GET PIECE TESTS
TEST(TicTacToeBoard, valid_get_piece) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	Piece actual = board.getPiece(0, 0);
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_piece_blank) {
	TicTacToeBoard board;
	Piece actual = board.getPiece(0, 0);
	ASSERT_EQ(actual, Blank);
}

TEST(TicTacToeBoard, invalid_get_piece_row) {
	TicTacToeBoard board;
	Piece actual = board.getPiece(3, 0);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoard, invalid_get_piece_col) {
	TicTacToeBoard board;
	Piece actual = board.getPiece(0, 3);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoard, invalid_get_piece_both) {
	TicTacToeBoard board;
	Piece actual = board.getPiece(3, 3);
	ASSERT_EQ(actual, Invalid);
}

// GET WINNER TESTS
TEST(TicTacToeBoard, valid_get_winner_horizontal_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_vertical_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 0);
	board.toggleTurn();
	board.placePiece(2, 0);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_diagonal_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_horizontal_O) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoard, valid_get_winner_vertical_O) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 0);
	board.toggleTurn();
	board.placePiece(2, 0);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoard, valid_get_winner_diagonal_O) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoard, valid_get_winner_horizontal_and_vertical_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(1, 0);
	board.toggleTurn();
	board.placePiece(2, 0);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_horizontal_and_diagonal_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_vertical_and_diagonal_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 0);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	board.toggleTurn();
	board.placePiece(2, 0);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, valid_get_winner_all_X) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(0, 2);
	board.toggleTurn();
	board.placePiece(1, 0);
	board.toggleTurn();
	board.placePiece(2, 0);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoard, invalid_get_winner_no_pieces) {
	TicTacToeBoard board;
	Piece actual = board.getWinner();
	ASSERT_EQ(actual, Invalid);
}