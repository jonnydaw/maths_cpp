#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <string>


double get_ratio(const std::vector<double>& sequence){
    return sequence[1] / sequence[0];
}

std::vector<double> get_next_three_in_sequence(const std::vector<double>& sequence, double ratio){
    double lastInSequence = sequence.back();
    std::vector<double> res = {lastInSequence * ratio};
    for(std::size_t i = 0; i < 2; ++i){
        double current = res[i];
        current *= ratio;
        res.push_back(current);
    }
    return res;
}
std::string vector_to_string(const std::vector<double>& vec) {
    std::string res = "{";
    for(std::size_t i = 0 ; i < vec.size(); ++i){
        res += std::to_string(vec[i]);
        if(i < vec.size() - 1){
            res += ", ";
        }else{
            res += "}";
        }
    }
    return res;
}



int main(){


    std::vector<std::vector<double>> questions = {
        {5, 15,45},
        {4,-8,16},
        {60,30,15},
        {1,0.25,0.0625}
    };

    char questionLabel = 'a';
    for(const auto& question : questions){
        double currentRatio = get_ratio(question);
        std::vector<double> resVec = get_next_three_in_sequence(question,currentRatio);
        std::string res = vector_to_string(resVec);
        std::cout << questionLabel++ << ". " << res << "\n";
    }

    return 0;
}