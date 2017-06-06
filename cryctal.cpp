#include "cryctal.h"

Crystal::Crystal()
{
    ram=std::vector<std::vector<bool> >(64, std::vector<bool>(64));
}

void  Crystal::displayOnOff (bool DB0){
    off = !DB0;
}

void  Crystal::displayStartLine (uint8_t DB){
    startLine = DB;
}

void  Crystal::setPage (uint8_t DB){
    page=DB;
}

void  Crystal::setAddress (uint8_t DB){
    adress = DB;
}

bool Crystal::statusRead(){
    return off;
}

void  Crystal::writeData (uint8_t DB){
    for(int i=0;i<8;i++)
        if(DB & (1<<i)){
            ram[adress][page*8+i] = true;
        }
        else{
            ram[adress][page*8+i] = false;
        }
    adress += 1;
    adress = adress % 64;
}

uint8_t Crystal::readData (){
    uint8_t r=0;
    for(int i=0;i<8;i++)
        if(ram[adress][page*8+i]){
            r |= 1<<i;
        }
    return r;
}

bool Crystal::getPixel(uint8_t x, uint8_t y){
    if(off)
        return false;
    return ram[x][(y+startLine)%64];
}
