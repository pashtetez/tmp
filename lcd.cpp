#include "lcd.h"

LCD::LCD()
{
    //ram=std::vector<std::vector<bool> >(128, std::vector<bool>(64));
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
    l.setPage(DB);
    r.setPage(DB);
// page=DB;
 //adress=0;
}

void  LCD::setAddress (char DB){

}

void  LCD::statusRead (bool DB7, bool DB5, bool DB4){

}

void  LCD::writeData (char DB){
    l.writeData(DB);
    r.writeData(DB);
//    int crystal_offset=0;
//    for(int i=0;i<8;i++)
//        if(DB & (1<<i)){
//            //setPixel(adress+crystal_offset,page*8+i ,1);
//            ram[adress+crystal_offset][page*8+i] = true;
//        }
//        else{
//            ram[adress+crystal_offset][page*8+i] = false;
//            //setPixel(adress+crystal_offset,page*8+i ,0);
//        }
//    adress+=1;
}

void  LCD::readData (char DB){

}

bool LCD::getPixel(uint8_t x, uint8_t y){
    if(x<64)
        return l.getPixel(x,y);
    return r.getPixel(x%64,y);
}
