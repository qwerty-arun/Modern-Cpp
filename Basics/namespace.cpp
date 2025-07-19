# include <iostream>

namespace login{
    int login_id;
    void getTicket()
    {
        std::cout<<"This is login ticket."<<std::endl;
    }
};

namespace signup{
    int signup_id;
    void getTicket()
    {
        std::cout<<"This is Signup ticket"<<std::endl;
    }
};

int main()
{
    signup::getTicket(); 
    login::getTicket();

    return 0;
}