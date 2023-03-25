#include <iostream>
#include <vector>

double x_1;
double x_2;
std::vector<double> input;
std::vector<double> output;

double faranheit(double);
void initialize(int);
void train(int);

int main() {
    x_1 = -50;
    x_2 = -50;
    initialize(10);
    train(10000);
    std::cout<< x_1<<std::endl<<x_2<<std::endl;

    return 0;
}

void initialize(int size){
    for(int i = 0; i<size; i++){
        double inp = -10+i*(20.0/size);
        input.push_back(inp);
        output.push_back(inp*1.8 + 32);
    }
}

void train(int iterations){
    for(int i = 0; i<iterations;i++){
        for(int j = 0; j<input.size(); j++){

            double inp = input[j];
            double outp = output[j];
            double step1 = inp * (faranheit(inp) - outp);
            double step2 = (faranheit(input[j]) - outp);

            x_2 = x_2 - step2/1000;
            x_1 = x_1 - step1/1000;
        }
    }
}

double faranheit(double C){
    return x_1*C + x_2;
}
