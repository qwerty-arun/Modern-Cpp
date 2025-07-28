#include<iostream>
#include<string>
#include<cstdint>

#define END return 0
#define ENDMESSAGE std::cout << "Program ends here\n"<<std::endl;

#define LCOINT int32_t //very efficient
#define CCPC const char* const

#define console_log(a) std::cout << a << std::endl //creates confusion, don't do it

int main()
{
    int score = 400;
    console_log(score);
    std::string name = "ram";
    console_log(name);
    LCOINT a,b; 
    ENDMESSAGE;
    END;
}