#ifndef TIME_H
#define TIME_H
class Time
{
public:
    Time();

    void setT1();
    void setT2();
    void displayTime();
    void Save();
    void Load();

private:
    time_t t1,t2;
    int t,lT;
};
#endif
