#include "explorerresult.h"

explorerResult::explorerResult()
{

}

explorerResult::explorerResult(int nbk, int nbp, int nbm, int nbh, int real){
    this->nbH = nbh;
    this->nbK = nbk;
    this->nbM = nbm;
    this->nbP = nbp;
    this->realTime = real;
}

explorerResult::explorerResult(int nbk, int nbp, int nbm, int nbh){
    this->nbH = nbh;
    this->nbK = nbk;
    this->nbM = nbm;
    this->nbP = nbp;
}
