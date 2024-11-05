#include "client.h"
#include <iostream>
using namespace std;

int CLIENT :: clientNum = 0;
CLIENT :: CLIENT (){
    clientNum++;
}
CLIENT :: ~CLIENT (){
    clientNum--;
}
CLIENT :: CLIENT (char sev) : servername(sev) {}
void CLIENT :: changeServerName(const char &c) {
    servername = c;
}
void CLIENT :: print () {
    cout << clientNum << endl;
}