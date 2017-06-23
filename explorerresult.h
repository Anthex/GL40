#ifndef EXPLORERRESULT_H
#define EXPLORERRESULT_H


class explorerResult
{
public:
    explorerResult();
    explorerResult(int nbk, int nbp, int nbm, int nbh, int real);
    explorerResult(int nbk, int nbp, int nbm, int nbh);
    explorerResult(double tk, double tp, double tm, double th);
    int nbK;
    int nbP;
    int nbM;
    int nbH;

    double tk, tp, tm, th;

    int realTime;
};

#endif // EXPLORERRESULT_H
