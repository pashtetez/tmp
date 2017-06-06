#ifndef LCD_H
#define LCD_H
#include <functional>
#include <iostream>
#include <vector>
#include <cryctal.h>
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
        uint8_t DB;
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

    bool RW, A0, E1, E2, E, RES;
    uint8_t D;

    void setRW (bool _RW ){ RW  = _RW;  }
    void setA0 (bool _A0 ){ A0  = _A0;  }
    void setE1 (bool _E1 ){ E1  = _E1;  }
    void setE2 (bool _E2 ){ E2  = _E2;  }
    void setE  (bool _E  ){ if (_E == 1 && E == 0) handle(); E = _E ;  }
    void setRES(bool _RES){ RES = _RES; }
    void setD  (uint8_t _D){ D  = _D;   }

    bool getRW (){ return RW ; }
    bool getA0 (){ return A0 ; }
    bool getE1 (){ return E1 ; }
    bool getE2 (){ return E2 ; }
    bool getE  (){ return E  ; }
    bool getRES(){ return RES; }
    uint8_t getD(){ return D ; }

    void LCDinit(void);

    void Pset(uint8_t x, uint8_t y, bool c);

    void WriteCodeL(uint8_t b);
    void WriteCodeR(uint8_t b);
    void WriteDataL(uint8_t b);
    void WriteDataR(uint8_t b);
    uint8_t ReadDataL(void);
    uint8_t ReadDataR(void);

    //Процедура выдачи байта в индикатор
    void WriteByte(uint8_t b, bool cd, bool l, bool r);

    uint8_t ReadByte(bool cd, bool l, bool r);

    void WaitReady(bool l, bool r);

    void handle();


    Crystal l,r;

    bool getPixel(uint8_t x, uint8_t y);
};


#endif // LCD_H
