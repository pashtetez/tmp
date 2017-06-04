#include "cryctal.h"

Crystal::Crystal()
{
    ram=std::vector<std::vector<bool> >(64, std::vector<bool>(64));
}

void  Crystal::displayOnOff (bool DB0){

}

void  Crystal::displayStartLine (char DB){

}

void  Crystal::setPage (char DB){
 page=DB;
 adress=0;
}

void  Crystal::setAddress (char DB){

}

void  Crystal::statusRead (bool DB7, bool DB5, bool DB4){

}

void  Crystal::writeData (char DB){
    for(int i=0;i<8;i++)
        if(DB & (1<<i)){
            //setPixel(adress+crystal_offset,page*8+i ,1);
            ram[adress][page*8+i] = true;
        }
        else{
            ram[adress][page*8+i] = false;
            //setPixel(adress+crystal_offset,page*8+i ,0);
        }
    adress+=1;
}

void  Crystal::readData (char DB){

}

bool Crystal::getPixel(uint8_t x, uint8_t y){
    return ram[x][(y+startLine)%64];
}
