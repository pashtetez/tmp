#include "lcd.h"

LCD::LCD()
{
}

void LCD::handle(pins a,std::function<void(int x, int y, bool i)> foo) {
    for(int i=0;i<128;i++){
        for(int j=0;j<64;j++)
     foo(i,j, (i+j)%4==0);
    }
 }


void  LCD::displayOnOff (bool DB0){

}

void  LCD::displayStartLine (char DB){

}

void  LCD::setPage (char DB){

}

void  LCD::setAddress (char DB){

}

void  LCD::statusRead (bool DB7, bool DB5, bool DB4){

}

void  LCD::writeData (char DB){

}

void  LCD::readData (char DB){

}
