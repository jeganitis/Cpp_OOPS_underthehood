// module1.cpp
// References weak symbols and an external undefined symbol (extVar)
#include<iostream>
extern int weakVar;      // reference to weak data (U unless defined)
extern int weakFunc();   // reference to weak function (U unless defined)
extern int extVar;       // purposely *undefined* here to show 'U' symbol

int callWeakAndExt()
{
	//Display the value of 'weakVar' and return value of weakFunc
	std::cout << "\nValue of weakVar:"<<weakVar;
    // Use weak function and weak variable; also reference extVar (undefined)
    int v = weakFunc();
	std::cout << "\nReturn Value of weakFunc:"<<v<<std::endl;
    int r = weakVar + v;
    return r + extVar; // extVar is undefined in this object -> U
}
