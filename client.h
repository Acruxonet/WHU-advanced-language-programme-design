#ifndef CLIENT_H
#define CLIENT_H
class CLIENT {
public:
    CLIENT ();
    ~CLIENT ();
    CLIENT (char sev);
    void changeServerName(const char &c);
    static void print ();
private:
    static int clientNum;
    char servername;
};
#endif