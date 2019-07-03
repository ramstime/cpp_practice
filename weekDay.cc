// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<map>
#include<string>
#include<iostream>


string solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    std::map<std::string, unsigned int> weekStrMap;

weekStrMap["Mon"]= 1;
weekStrMap["Tue"]= 2;
weekStrMap["Wed"]= 3;
weekStrMap["Thu"]= 4;
weekStrMap["Fri"]= 5;
weekStrMap["Sat"]= 6;
weekStrMap["Sun"]= 7;
std::map<std::string,unsigned int>::iterator itStr;

std::map< unsigned int, std::string> weekEnumMap;

weekEnumMap[1] = "Mon";
weekEnumMap[2] = "Tue";
weekEnumMap[3] = "Wed";
weekEnumMap[4] = "Thu";
weekEnumMap[5] = "Fri";
weekEnumMap[6] = "Sat";
weekEnumMap[7] = "Sun";


    int weekNum =0, index =0;
    itStr = weekStrMap.find(S);
    if (itStr != weekStrMap.end()){
      weekNum = itStr->second;
    }
    int loopNum=K;
    while (loopNum > 7){
     loopNum = loopNum%7;
    }
    //cout<<"loopNum :"<<loopNum;
    index = weekNum + loopNum;
    
     if (index > 7 )
     index = index - 7;
 std::string day = weekEnumMap[index];
 
 return day;
    
}
