#include<iostream>

constexpr int maxbuffer = 1024;

using namespace std;

int main()
{
    const char* filename = "whatever.txt";
    const char* info = "lorem ipsum dolor sit amet";

    // FILE* fh = fopen(filename, "a");

    // for(int i = 0; i< 50; ++i)
    // {
    //     fputs(info, fh);
    // }
    // fclose(fh);

    char buf[maxbuffer];
    FILE* fh = fopen(filename, "r");
    while(fgets(buf, maxbuffer, fh))
    {
        fputs(buf, stdout);
    }
    fclose(fh);
    return 0;
}