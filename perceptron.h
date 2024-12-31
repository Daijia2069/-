//perceptron.h
#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <graphics.h>
#include <conio.h>
#include<iomanip>
using namespace std;

struct DataPoint {
    double x1;
    double x2;
    int label;
};
// 感知器类
class Perceptron {
private:
    double weights[2];  // 权重向量
    double bias;  // 偏置项
    double learningRate;  // 学习率
public:
    //不带初始化的构造函数
    Perceptron(double lr , double w1, double w2 , double b)  {
        weights[0] = w1;
        weights[1] = w2;
        learningRate = lr;
        bias = b;
    } 
    //带初始化的构造函数
    Perceptron(double lr = 0.01) : learningRate(lr) {
        // 初始化权重和偏置
        weights[0] = ((double)rand() / (RAND_MAX)) * 2 - 1; // 随机初始化权重
        weights[1] = ((double)rand() / (RAND_MAX)) * 2 - 1;
        bias = ((double)rand() / (RAND_MAX)) * 2 - 1;    // 随机初始化偏置
    }

    int predict(const DataPoint& data) {
        double sum = data.x1 * weights[0] + data.x2 * weights[1] + bias;
        return (sum >= 0) ? 1 : -1; // 激活函数
    }

    // 训练函数
    void train(const std::vector<DataPoint>& training_data, int max_epoch) {
        bool all_correct = false;
        int epoch = 0;
        while (!all_correct && epoch <= max_epoch)
        {   
            all_correct = true; // 假设所有样本都分类正确

            for (const auto& data : training_data) {            
                int prediction = this->predict(data);

                if (prediction * data.label <= 0) {
                    all_correct = false; // 如果有样本分类错误，继续训练
                    // 更新权重和偏置
                    weights[0] += learningRate * data.label * data.x1;
                    weights[1] += learningRate * data.label * data.x2;
                    bias += learningRate * data.label;
                }
            }
            epoch++;
        }
        if (all_correct)
        {
            cout << "Training converged after " << epoch-1 << " epochs." << endl;
            // 如果所有样本都分类正确，结束训练
        }
        else {
            cout << "Training stopped after " << max_epoch << " epochs (not fully converged)." << endl;
        }
    }
   
    void show()
    {
     cout<< fixed << setprecision(4)<< "w1:" <<weights[0]<<"  w2:" << weights[1] << "  b:"<< bias << endl;
    } 
    
    friend void Paint(const vector<DataPoint>& training_data, const Perceptron& perceptron);
};

vector<DataPoint> readDataFromFile(const std::string& filename);
#endif