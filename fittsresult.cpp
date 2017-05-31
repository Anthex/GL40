#include "fittsresult.h"

fittsResult::fittsResult()
{


}

fittsResult::fittsResult(int real,int theo,int dist){
    this->realTime = real;
    this->theoTime = theo;
    this->distance = dist;
}
