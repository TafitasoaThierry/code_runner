#include <iostream>

using namespace std;

class Shape{
    public:
        int width;
        int height;

        bool is_square(){
            if(this->width == this->height){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    Shape ABCD;

    ABCD.width = 200;
    ABCD.height = 200;
    ABCD.is_square() ? (std::cout << "YES" << std::endl) : (std::cout << "NO" << std::endl);

    char c[5] = "jee";
    cout << c;
    return 0;
}