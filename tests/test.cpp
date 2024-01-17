#include <iostream>
#include <random>

int main(){
    srand(time(NULL));
    float x = static_cast<float> (rand()) / RAND_MAX;
    std::cout << x << std::endl;
    return 0;
}




void test(){

}