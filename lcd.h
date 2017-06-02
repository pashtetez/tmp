#ifndef LCD_H
#define LCD_H
#include <functional>
#include <iostream>

struct pins {
    //Common pin (CP)
    bool GND;

    //Display module power supply (digital part)
    bool Ucc;

    //LCD power input
    bool U0;

    //Choice of register data / commands
    bool A0;

    //Read / Write
    bool read_or_write;

    //Data strobing
    bool E;

    //Data bus 0-7
    union {
        char DB;
        struct {
            bool DB7:1;
            bool DB6:1;
            bool DB5:1;
            bool DB4:1;
            bool DB3:1;
            bool DB2:1;
            bool DB1:1;
            bool DB0:1;
        };
    } data;

    //Select crystal 1
    bool E1;

    //Select crystal 2
    bool E2;

    //Initialization
    bool RES;

    //Crystal select
    bool Uee;

    //– of the backlight power supply
    bool K;

    //+ of the backlight power supply
    bool A;
};

class LCD
{
public:
    LCD();

    uint8_t adress=0;
    uint8_t page=0;

    void handle (pins a, std::function<void (int, int, bool)> foo);


    void displayOnOff (bool DB0);

    void displayStartLine (char DB);

    void setPage (char DB);

    void setAddress (char DB);

    void statusRead (bool DB7, bool DB5, bool DB4);

    void writeData (char DB);

    void readData (char DB);

    std::function<void(int x, int y, bool i)> setPixel;
};


#endif // LCD_H
