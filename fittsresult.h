#ifndef FITTSRESULT_H
#define FITTSRESULT_H

class fittsResult
{
public:
    fittsResult();
    fittsResult(int real,int theo,int dist, int width);

    int realTime; /* effective time taken by the user in milliseconds */
    mutable int theoTime; /* theorical time in milliseconds */
    int distance;

    int size; /* size of the target to recalculate a and b*/
};

#endif // FITTSRESULT_H
