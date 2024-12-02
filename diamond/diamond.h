/*
Bria Weisblat
Section: 2
 */

class Diamond {
public:
    Diamond(int userSize, char borderChar = '#', char fillChar = '*');

   // Return functions
    int GetSize() const;          //returns the size of a side
    int Perimeter() const;        //returns the perimeter of the diamond
    double Area() const;          //returns the area of the diamond

    // Size altering functions
    void Grow();            //increases the size of the side by 1
    void Shrink();          //decreases the size of the side by 1

    // Set functions
    void SetBorder(char borderChar);        //allows a new border character to be passed in as a parameter
    void SetFill(char fillChar);          //allow a new border fill character to be passed in as a parameter

    // Display functions
    void Draw() const;            //displays a picture of the diamond on the screen
    double Summary() const;       //displays the size, perimeter, area, and picture of the diamond

private:
    int size;
    char storedBorderChar;
    char storedFillChar;

    char format;
};
