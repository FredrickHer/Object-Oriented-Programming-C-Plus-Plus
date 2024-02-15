
#include <iostream>
using namespace std;

int main()
{
    int  x = 0;
    int  y = 5;

    while(x < y){
        cout << x << endl;

     x = x + 3;
    }
if(x % 2==0 ){
    cout << "x is even" << endl;
} else{
    cout << "x is odd" << endl;
        }
    return 0;
}
