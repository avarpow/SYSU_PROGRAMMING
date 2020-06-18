//time.h
#ifndef Time_H
#define Time_H
#include <iostream>
using namespace std;

class Time
{
public:
    void Set(int hours, int minutes, int seconds);
    void Increment();
    void Write() const;
    Time(int initHrs, int initMins, int initSecs); // constructor
    Time();                                        //  default constructor

private:
    int hrs;
    int mins;
    int secs;
};

#endif

//exttime.h
#ifndef ExtTime_H
#define ExtTime_H
#include "Time.h"
enum ZoneType
{
    EST,
    CST,
    MST,
    PST,
    EDT,
    CDT,
    MDT,
    PDT
};

class ExtTime : public Time // Time is the base class
{
public:
    ExtTime(int initHrs, int initMins, int initSecs,
            ZoneType initZone); // constructor
    ExtTime();                  // default constructor
    void Set(int hours, int minutes, int seconds,
             ZoneType timeZone);
    void Write() const;

private:
    ZoneType zone; //  added data member
};

#endif
//time.cpp
#include <iostream>
#include <iomanip>
using namespace std;
void Time::Set(int hours, int minutes, int seconds)
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}
void Time::Increment()
{
    secs++;
    if (secs == 60)
    {
        secs = 0;
        mins++;
        if (mins == 60)
        {
            hrs++;
            mins = 0;
            if (hrs == 24)
            {
                hrs = 0;
            }
        }
    }
}
void Time::Write() const
{
    cout << setfill('0') << setw(2) << hrs << ":" << setw(2) << mins << ":" << setw(2) << secs;
}
Time::Time(int initHrs, int initMins, int initSecs) : hrs(initHrs), mins(initMins), secs(initSecs) {}
Time::Time() : hrs(0), mins(0), secs(0) {}

//exttime.cpp
ExtTime::ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone) : Time(initHrs, initMins, initSecs), zone(initZone) {}
ExtTime::ExtTime() : Time(), zone(EST) {}
void ExtTime::Set(int hours, int minutes, int seconds, ZoneType timeZone)
{
    Time::Set(hours, minutes, seconds);
    zone = timeZone;
}
void ExtTime::Write() const
{
    char s[8][20] = {"EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT"};
    Time::Write();
    cout << " " << s[zone];
}

//main.cpp
#include <iostream>
#include <cstdlib>
//#include "ExtTime.h" //程序4_4
//#include "Time.h"

using namespace std;

int main()
{
    ExtTime time1(5, 30, 0, CDT);
    ExtTime time2;
    int count;

    cout << "time1: ";
    time1.Write();
    cout << endl;
    cout << "time2: ";
    time2.Write();
    cout << endl;

    time2.Set(23, 59, 55, PST);
    cout << "New time2: ";
    time2.Write();
    cout << endl;
    cout << "Incrementing time2:" << endl;
    for (count = 1; count <= 10; count++)
    {
        time2.Write();
        cout << endl;
        time2.Increment();
    }

    Time time3(1, 2, 3);
    cout << "time3: ";
    time3.Write();
    cout << endl
         << endl;
    time1.Time::Set(3, 4, 5);
    time1.Time::Write();

    cout << endl;

    return 0;
}
/*
description
需要实现的是一下两个类，time作为父类，ExtTime作为子类，以下是两个类的声明，你需要做的是，实现这两个类
class  Time
{                        
public :                 
       void  Set ( int  hours , int  minutes , int  seconds ) ;
       void  Increment ( ) ;
       void  Write ( )  const ;
       Time ( int  initHrs, int  initMins,  int  initSecs ) ;  // constructor 
       Time ( ) ;        //  default constructor

private :                
       int hrs ;           
       int mins ;          
       int     secs ;
} 
class  ExtTime  :  public  Time    // Time is the base class
{
public :
        ExtTime ( int  initHrs ,  int  initMins ,  int  initSecs ,  ZoneType    initZone ) ;      // constructor
        ExtTime ( ) ;                          // default constructor
        void Set ( int  hours,  int  minutes,  int   seconds ,  ZoneType   timeZone ) ;    
        void Write ( )  const ;

private :                
    ZoneType  zone ;    //  added data member
} ;
输出格式为：
time1: 05:30:00 CDT
time2: 00:00:00 EST
New time2: 23:59:55 PST
Incrementing time2:
23:59:55 PST
23:59:56 PST
23:59:57 PST
23:59:58 PST
23:59:59 PST
00:00:00 PST
00:00:01 PST
00:00:02 PST
00:00:03 PST
00:00:04 PST
time3: 01:02:03

03:04:05
*/
