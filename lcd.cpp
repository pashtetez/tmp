#include "lcd.h"

LCD::LCD()
{
}

void LCD::handle(pins a,std::function<void(int x, int y, bool i)> foo) {
    setPixel = foo;
//    for(int i=0;i<128;i++){
//        for(int j=0;j<64;j++)
//     setPixel(i,j, (i+j)%4==0);
//    }

 }


void  LCD::displayOnOff (bool DB0){

}

void  LCD::displayStartLine (char DB){

}

void  LCD::setPage (char DB){
 page=DB;
 adress=0;
}

void  LCD::setAddress (char DB){

}

void  LCD::statusRead (bool DB7, bool DB5, bool DB4){

}

void  LCD::writeData (char DB){
    for(int i=0;i<8;i++)
        if(DB & (1<<i))
            setPixel(adress,page*8+i ,1);
        else
                setPixel(adress,page*8+i ,0);
    adress+=1;
}

void  LCD::readData (char DB){

}
