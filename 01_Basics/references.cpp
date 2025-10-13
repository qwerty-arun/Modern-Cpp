#include <iostream>

int main()
{
    int score = 200;
    int *ptr = &score; //pointer
    printf("Value of score is %d\n", score);
    printf("Value of pointer is %p\n", ptr);

    int &another_score = score; //reference
    another_score = 800; //this will update score too
    printf("Value of score is %d\n", score);
    printf("Value of pointer is %p\n", ptr);
    printf("Value of anotherscore is %d\n", another_score);
    printf("Address of anotherscore is %p\n", &another_score);
    return 0;
}