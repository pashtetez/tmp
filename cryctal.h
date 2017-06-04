#ifndef CRYCTAL_H
#define CRYCTAL_H

#include <functional>
#include <iostream>
#include <vector>

class Crystal
{
public:
    Crystal();
    uint8_t adress = 0;
    uint8_t startLine = 0;
    uint8_t page = 0;
    std::vector<std::vector<bool> > ram;

    void displayOnOff (bool DB0);

    void displayStartLine (char DB);

    void setPage (char DB);

    void setAddress (char DB);

    void statusRead (bool DB7, bool DB5, bool DB4);

    void writeData (char DB);

    void readData (char DB);

    bool getPixel(uint8_t x, uint8_t y);
};

#endif // CRYCTAL_H
