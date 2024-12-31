#pragma once
#include "perceptron.h"
std::vector<DataPoint> readDataFromFile(const std::string& filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x1, x2;
        int label;
        if (iss >> x1 >> x2 >> label) {
            data.push_back({ x1, x2, label });
        }
        else {
            std::cerr << "Error: Invalid data format in file " << filename << std::endl;
        }
    }

    file.close();
    return data;
}
