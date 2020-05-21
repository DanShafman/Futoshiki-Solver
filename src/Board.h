#ifndef FUTOSHIKI_BOARD
#define FUTOSHIKI_BOARD

#include <iostream>

// Class representing a Futoshiki puzzle board 
class Board {

public:
    // Class constructor. Will intialize all arrays and copy over input values.
    Board(std::vector< std::vector<int> >& cells, 
          std::vector< std::vector<char> >& constraintsHorizontal, 
          std::vector< std::vector<char> >& constraintsVertical);

    // Output operator for Board
    friend std::ostream& operator << (std::ostream& out, Board& b);

private:
    // Assert the dimensions of a 2D array. Used for user input error handling 
    // in the constructor.
    template <typename T>
    void assertDimensions(std::vector< std::vector<T> > arr, int rows, int columns, std::string) const;

    // These represent the parameters of the Futoshiki. 'cells' is an nxn int
    // array, representing the board itself. 'domain' is an int representing 
    // the max value a cell can hold. For an nxn board, the domain is [1,n].
    // Uninstantiated cells have a value of 0.

    // Note: all together, 'cells', 'domain', 'constraintsHorizontal', and
    // 'constraintsVertical' represent the X, D, and C variables necessary
    // for solving a constraint satisfaction problem.
    int** cells;
    int domain;

    // 'constraintsHorizontal' is a 2D char array holding the left/right 
    // inequalities the cells must conform to. The char '<' states its left
    // cell's value must be less than its right cell's value, and the opposite
    // for '>'. An nxn board will generate a nx(n-1) matrix.
    char** constraintsHorizontal;

    // 'constraintsVertical' follows the same idea as 'constraintsHorizontal'.
    // The character '^' states that the upper cell's value is less than the
    // lower cell's, and the opposite for 'v'. An nxn board will generate a 
    // (n-1)xn matrix.
    char** constraintsVertical;

};

#endif