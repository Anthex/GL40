#ifndef FITTSRESULT_H
#define FITTSRESULT_H


class fittsResult
{
public:
    fittsResult();
    fittsResult(int real,int theo,int dist);

    int realTime; /* effective time taken by the user in milliseconds */
    int theoTime; /* theorical time in milliseconds */
    int distance;
};

#endif // FITTSRESULT_H
