/*
Bria Weisblat
Section: 2
 */

#include "diamond.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Diamond::Diamond(int userSize, char borderChar, char fillChar) {
    // Make sure that the size is between 1 and 39
    if (userSize < 1){
        Diamond::size = 1;
    }
    else if (userSize > 39) {
        Diamond::size = 39;
    }
    else {
        Diamond::size = userSize;
    }
    // Store the user-entered characters in the private variables
    Diamond:: storedBorderChar = borderChar;
    Diamond:: storedFillChar = fillChar;
}

int Diamond::GetSize() const {
    return size;
}

int Diamond::Perimeter() const{
    return size * 4;
}

double Diamond::Area() const{
    // Area of these diamonds is equal to the area of two equilateral triangles
    return ( (sqrt(3.0)) / 4.0 ) * (size * size) * 2.0;

}

void Diamond::Grow(){
    // If the size is 39, do NOT increase it
    if (size == 39){
        size = size + 0;
    }
    // If the size is anything but 39, increase it by one
    else {
        size = size +1;
    }
}

void Diamond::Shrink(){
    // If the size is 1, do NOT decrease it
    if (size == 1){
        size = size + 0;
    }
    // If the size is anything but 1, decrease it by one
    else {
        size = size -1;
    }
}

void Diamond::SetBorder(char borderChar){
    // If the user-entered border character is outside the accepted ASCII range, set the stored border character to the default
    if ( (borderChar <= 33) || (borderChar >= 126)){
        Diamond::storedBorderChar = '#';
    }
    // If the user-entered border character is within the accepted ASCII range, store that character privately
    else {
        Diamond::storedBorderChar= borderChar;
    }
}

void Diamond::SetFill(char fillChar){
    // If the user-entered fill character is outside the accepted ASCII range, set the stored fill character to the default
    if ( (fillChar <= 33) || (fillChar >= 126)){
        Diamond::storedFillChar = '*';
    }
    // If the user-entered fill character is within the accepted ASCII range, store that character privately
    else {
        Diamond::storedFillChar = fillChar;
    }
}

void Diamond::Draw() const{
    // Top Half
    for (int i =1; i < size; i++ ) {
        // Print spaces for the area outside the diamond borders
        for (int j = size; j > i ; j--) {
            std::cout << " ";
        }
        // Print the top left line of the border
        if (i > 1) {
            std::cout << Diamond::storedBorderChar << " ";
        }
        // Populate the diamond with the stored fill character
        for (int k = size + i -2; k > size; k--){
            std::cout << Diamond::storedFillChar << " ";
        }
        // Print the top right line of the border
        std::cout << Diamond::storedBorderChar;

        // Move to the next line of the diamond
        std::cout << "\n";
    }


    // Bottom Half
    for (int i =0; i < size; i++ ) {
        // Print spaces for the area outside the diamond borders
        for (int j =1; j < i + 1; j++){
           std::cout << " ";
        }
        // Print the bottom left border of the diamond
        std :: cout << Diamond::storedBorderChar << " ";

        // Populate the diamond with the stored fill character
        for (int k =1; k < size - i -1; k++){
            std::cout << Diamond::storedFillChar << " ";
        }

        // Print the bottom right border of the diamond
        if (i != size -1) {
            std::cout << Diamond::storedBorderChar;
        }
        // Move to the next line of the diamond
        std :: cout << "\n";
    }
}


double Diamond::Summary() const{
    std:: cout << "Size of diamond's side = " << size << " units." << "\n";
    std:: cout << "Perimeter of diamond = " << Diamond::Perimeter() << "\n";
    std::cout << "Area of diamond = " << std::fixed << std::setprecision(2) << Diamond::Area() << "\n";
    std::cout << "Diamond looks like: " << "\n";
    Diamond::Draw();
}