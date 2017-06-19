#include "fittsresult.h"

fittsResult::fittsResult()
{


}

fittsResult::fittsResult(int real,int theo,int dist, int width){
    this->realTime = real;
    this->theoTime = theo;
    this->distance = dist;
    this->size = width;
}
