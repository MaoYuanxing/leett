#include <cstdio>
#include <string>
#include <cstdlib>

int LeakTest(char *Para)
{
    if (NULL == Para)
    {
        // local_log("LeakTest Func: empty parameter\n");
        return -1;
    }
    char *Logmsg = new char[128];
    if (NULL == Logmsg)
    {
        // local_log("memeory allocation failed\n");
        return -2;
    }
    sprintf(Logmsg, "LeakTest routine exit: '%s'.\n", Para);
    // local_log(Logmsg);
    return 0;
}
int main(int argc, char **argv)
{
    char szInit[] = "testcase1";
    LeakTest(szInit);
    return 0;
}