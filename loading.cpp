
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int count = 0;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "                                           Loading ";
    for(count=0; count < 5; ++count){
        cout << ". " ;
        fflush(stdout);
        usleep(380000);
    }
    return 0;
}
