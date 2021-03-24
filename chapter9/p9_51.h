#ifndef C__PRIMER_P7_51_H
#define C__PRIMER_P7_51_H

#include <string>
using namespace std;

class Date {
public:
    Date() = default;
    Date(const string& s) 
    {
        int mode = 0;
        if (s.find_first_of('/') != string::npos) 
        {
            mode = 1;
        } else if (s.find_first_of(',') != string::npos) 
        {
            mode = 2;
        } else 
        {
            mode = 3;
        }
        string days;
        switch (mode)
        {
        case 1://1/1/1990
            year = stoi(s.substr(s.find_last_of("/")+1));
            day = stoi(s.substr(s.find_first_of("/")+1,s.find_last_of("/")));
            month = stoi(s.substr(0, s.find_first_of("/")));
            break;
        case 2://January 1,1900
            year = stoi(s.substr(s.find_last_of(",")+1));
            day = stoi(s.substr(s.find_first_of(" "),s.find_last_of(",")));
            days = s.substr(0, s.find_first_of(" "));
            if( days.find("Jan") < s.size() )  month = 1;
            if( days.find("Feb") < s.size() )  month = 2;
            if( days.find("Mar") < s.size() )  month = 3;
            if( days.find("Apr") < s.size() )  month = 4;
            if( days.find("May") < s.size() )  month = 5;
            if( days.find("Jun") < s.size() )  month = 6;
            if( days.find("Jul") < s.size() )  month = 7;
            if( days.find("Aug") < s.size() )  month = 8;
            if( days.find("Sep") < s.size() )  month = 9;
            if( days.find("Oct") < s.size() )  month =10;
            if( days.find("Nov") < s.size() )  month =11;
            if( days.find("Dec") < s.size() )  month =12;
            break;
        default://Jan 1 1990
            year = stoi(s.substr(s.find_last_of(" ")+1));
            day = stoi(s.substr(s.find_first_of(" "),s.find_last_of(" ")));
            days = s.substr(0, s.find_first_of(" "));
            if( days.find("Jan") < s.size() )  month = 1;
            if( days.find("Feb") < s.size() )  month = 2;
            if( days.find("Mar") < s.size() )  month = 3;
            if( days.find("Apr") < s.size() )  month = 4;
            if( days.find("May") < s.size() )  month = 5;
            if( days.find("Jun") < s.size() )  month = 6;
            if( days.find("Jul") < s.size() )  month = 7;
            if( days.find("Aug") < s.size() )  month = 8;
            if( days.find("Sep") < s.size() )  month = 9;
            if( days.find("Oct") < s.size() )  month =10;
            if( days.find("Nov") < s.size() )  month =11;
            if( days.find("Dec") < s.size() )  month =12;
            break;
        }
    }
    unsigned year;
    unsigned month;
    unsigned day;
};
#endif