#ifndef LCD_H
#define LCD_H
#include <functional>
#include <iostream>
#include <vector>
#include "cryctal.h"
#include <time.h>

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

extern "C" {
    LCD* LCD_new(){return new LCD();}
    
    void LCD_setRW(LCD* lcd,bool _RW){lcd->setRW(_RW);}
    void LCD_setA0 (LCD* lcd,bool _A0 ){lcd->setA0(_A0);}
    void LCD_setE1 (LCD* lcd,bool _E1 ){lcd->setE1(_E1);}
    void LCD_setE2 (LCD* lcd,bool _E2 ){lcd->setE2(_E2);}
    void LCD_setE  (LCD* lcd,bool _E  ){lcd->setE(_E);}
    void LCD_setRES(LCD* lcd,bool _RES){lcd->setRES(_RES);}
    void LCD_setD  (LCD* lcd,uint8_t _D){lcd->setD(_D);}

    bool LCD_getRW (LCD* lcd){ return lcd->getRW(); }
    bool LCD_getA0 (LCD* lcd){ return lcd->getA0(); }
    bool LCD_getE1 (LCD* lcd){ return lcd->getE1(); }
    bool LCD_getE2 (LCD* lcd){ return lcd->getE2(); }
    bool LCD_getE  (LCD* lcd){ return lcd->getE(); }
    bool LCD_getRES(LCD* lcd){ return lcd->getRES(); }
    uint8_t LCD_getD(LCD* lcd){ return lcd->getD(); }


    void LCD_LCDinit(LCD* lcd){lcd->LCDinit();};

    void LCD_Pset(LCD* lcd,uint8_t x, uint8_t y, bool c){lcd->Pset(x,y,c);};

    void LCD_WriteCodeL(LCD* lcd,uint8_t b){lcd->WriteCodeL(b);};
    void LCD_WriteCodeR(LCD* lcd,uint8_t b){lcd->WriteCodeR(b);};
    void LCD_WriteDataL(LCD* lcd,uint8_t b){lcd->WriteDataL(b);};
    void LCD_WriteDataR(LCD* lcd,uint8_t b){lcd->WriteDataR(b);};
    uint8_t LCD_ReadDataL(LCD* lcd){return lcd->ReadDataL();};
    uint8_t LCD_ReadDataR(LCD* lcd){return lcd->ReadDataR();};

    //Процедура выдачи байта в индикатор
    void LCD_WriteByte(LCD* lcd,uint8_t b, bool cd, bool l, bool r){lcd->WriteByte(b,cd,l,r);};

    void LCD_nanosleep(uint64_t time){
        struct timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = time;
        nanosleep(&tim , &tim2);
    }

    uint8_t LCD_ReadByte(LCD* lcd,bool cd, bool l, bool r){return lcd->ReadByte(cd,l,r);};

    void LCD_WaitReady(LCD* lcd,bool l, bool r){lcd->WaitReady(l,r);};
    
    bool LCD_getPixel(LCD* lcd,uint8_t x, uint8_t y){return lcd->getPixel(x,y);};
}


#endif // LCD_H
