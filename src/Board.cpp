#include "Board.h"

#include <exception>
#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

Board::Board(vector< vector<int> >& cells, 
             vector< vector<char> >& constraintsHorizontal, 
             vector< vector<char> >& constraintsVertical) {

    domain = cells.size();

    // Check that all the input matrices have valid sizes
    assertDimensions(cells, domain, domain, "Futoshiki");
    assertDimensions(constraintsHorizontal, domain, domain - 1, "horizontal constraints");
    assertDimensions(constraintsVertical, domain - 1, domain, "vertical constraints");

    // Intitialize cells with size domain x domain
    this -> cells = new int*[domain];
    for (int i = 0; i < domain; i++) {
        this -> cells[i] = new int[domain];
    }

    // Intitialize constraintsHorizontal with size domain x (domain - 1)
    this -> constraintsHorizontal = new char*[domain];
    for (int i = 0; i < domain; i++) {
        this -> constraintsHorizontal[i] = new char[domain - 1];
    }

    // Intitialize constraintsVertical with size (domain - 1) x domain
    this -> constraintsVertical = new char*[domain - 1];
    for (int i = 0; i < domain - 1; i++) {
        this -> constraintsVertical[i] = new char[domain];
    }

    // Copy over data into instance's board matrix
    for (int row = 0; row < domain; row++) {
        for (int column = 0; column < domain; column++) {
            this -> cells[row][column] = cells[row][column];
        }
    }
    
    // Copy over data into instance's constraintsHorizontal matrix
    for (int row = 0; row < domain; row++) {
        for (int column = 0; column < domain - 1; column++) {
            this -> constraintsHorizontal[row][column] = constraintsHorizontal[row][column];
        }
    }

    // Copy over data into instance's constraintsVertical matrix
    for (int row = 0; row < domain - 1; row++) {
        for (int column = 0; column < domain; column++) {
            this -> constraintsVertical[row][column] = constraintsVertical[row][column];
        }
    }
s
} 



template <typename T>
void Board::assertDimensions(vector< vector<T> > arr, int rows, int columns, string name) const {

    // Assert the number of rows
    if (arr.size() != rows) {
        throw runtime_error("\n\nInvalid " + name + " board: array must be of size " + to_string(rows) + " x " + to_string(columns) + " \n");
    }

    // Assert the number of columns
    for (int row = 0; row < rows; row++) {
        if (arr[row].size() != columns) {
            throw runtime_error("\n\nInvalid " + name + " board: array must be of size " + to_string(rows) + " x " + to_string(columns) + " \n");        
        }
    }

}



ostream& operator << (ostream& out, Board& b) {

    for (int row = 0; row < b.domain; row++) {
        for (int column = 0; column < b.domain; column++) {
            out << b.cells[row][column] << " ";
        }
        out << endl;
    }

    return out;
    
}