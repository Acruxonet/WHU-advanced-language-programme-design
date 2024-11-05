class CLIENT {
public:
    CLIENT ();
    ~CLIENT ();
    CLIENT (char sev);
    void changeServerName();
private:
    static int clientNum;
    char servername;
};
