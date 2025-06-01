#include <iostream>
#include <vector>
#include <set>
#include <limits>



double get_r_double(const std::vector<double>& sequence){
    std::set<double> ratios;
    for(std::size_t i = 1; i < sequence.size(); i++){
        ratios.insert(sequence[i] / sequence[i-1]);
    }
    return ratios.size() > 1 ? std::numeric_limits<double>::lowest() : *ratios.begin();

}

int main(){
    std::vector<std::vector<double>> questions = {
        {1,2,4,8,16,32},
        {2,5,8,11,14},
        {40, 36, 32, 28},
        {2,6,18,54,162},
        {10.0,5.0,2.5,1.25},
        {5,-5,5,-5,5},
        {3,3,3,3,3},
        {4,-1,0.25,-0.0625}

    };


    char questionLabel = 'a';
    for(const auto& question : questions){
        double r = get_r_double(question);
        std::cout << questionLabel++ << ". " << r << "\n";
    }

    return 0;
}

