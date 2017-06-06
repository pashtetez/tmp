#ifndef CRYCTAL_H
#define CRYCTAL_H

#include <functional>
#include <iostream>
#include <vector>

class Crystal
{
public:
    Crystal();

    bool getPixel(uint8_t x, uint8_t y);

    void displayOnOff (bool DB0);

    void displayStartLine (uint8_t DB);

    void setPage (uint8_t DB);

    void setAddress (uint8_t DB);

    bool statusRead ();//return only on/off, cause i don't know, WHAT DA HECK ARE ANOTHER TWO

    void writeData (uint8_t DB);

    uint8_t readData();

private:

    uint8_t adress = 0;
    uint8_t startLine = 0;
    uint8_t page = 0;
    bool off = true;
    std::vector<std::vector<bool> > ram;
};

#endif // CRYCTAL_H
