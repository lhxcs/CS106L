/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <numeric>
#include<algorithm>
#include<iomanip>
#include<fstream>


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
requires std::is_arithmetic_v<T> //We only want this function to take in numerical types! Use a set of constraints or a concept to handle this.
double convert_f_to_c(T f) {
    return (f - 32) * 5.0 / 9;
}


template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    // TODO: write get_forecast here!
    std::vector<double> result;
    for(auto& day: readings) {
        result.push_back(fn(day));
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::string PATH = "output.txt";
    std::ofstream file(PATH);

    // TODO: Convert temperatures to Celsius and output to output.txt
    file << "Celsius: " << std::endl;
    for(const auto &row: readings) {
        for(const auto &temp : row) {
            file << std::fixed << std::setprecision(2) << convert_f_to_c(temp) << "\t";
        }
        file << std::endl;
    }

    // TODO: Find the maximum temperature for each day and output to output.txt
    auto max = get_forecast(readings, [](const std::vector<int> &day) -> double {
        return *std::max_element(day.begin(), day.end());
    });

    file << "Maximum temperature for each day: " << std::endl;
    for(const auto &temp : max) {
        file << temp << "\t";
    }
    file << std::endl;
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto findmin = [](const std::vector<int> &day) -> double {
        return *std::min_element(day.begin(), day.end());
    };
    auto min = get_forecast(readings, findmin);
    file << "Minimum temperature for each day: " << std::endl;
    for(const auto &temp : min) {
        file << temp << "\t";
    }
    file << std::endl;
    
    // TODO: Find the average temperature for each day and output to output.txt
    auto findavg = [](const std::vector<int> &day) -> double {
        return std::accumulate(day.begin(), day.end(), 0.0) / day.size();
    };
    auto avg = get_forecast(readings, findavg);
    file << "Average temperature for each day: " << std::endl;
    for(const auto &temp : avg) {
        file << temp << "\t";
    }
    file << std::endl;

    return 0;
}