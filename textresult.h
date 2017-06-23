#ifndef TEXTRESULT_H
#define TEXTRESULT_H
#include <QString>

class textResult
{
public:
    textResult();
    textResult(int time_, QString letter_);
    int time;
    QString letter;
private:
};

#endif // TEXTRESULT_H
