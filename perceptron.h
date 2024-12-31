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
// ��֪����
class Perceptron {
private:
    double weights[2];  // Ȩ������
    double bias;  // ƫ����
    double learningRate;  // ѧϰ��
public:
    //������ʼ���Ĺ��캯��
    Perceptron(double lr , double w1, double w2 , double b)  {
        weights[0] = w1;
        weights[1] = w2;
        learningRate = lr;
        bias = b;
    } 
    //����ʼ���Ĺ��캯��
    Perceptron(double lr = 0.01) : learningRate(lr) {
        // ��ʼ��Ȩ�غ�ƫ��
        weights[0] = ((double)rand() / (RAND_MAX)) * 2 - 1; // �����ʼ��Ȩ��
        weights[1] = ((double)rand() / (RAND_MAX)) * 2 - 1;
        bias = ((double)rand() / (RAND_MAX)) * 2 - 1;    // �����ʼ��ƫ��
    }

    int predict(const DataPoint& data) {
        double sum = data.x1 * weights[0] + data.x2 * weights[1] + bias;
        return (sum >= 0) ? 1 : -1; // �����
    }

    // ѵ������
    void train(const std::vector<DataPoint>& training_data, int max_epoch) {
        bool all_correct = false;
        int epoch = 0;
        while (!all_correct && epoch <= max_epoch)
        {   
            all_correct = true; // ��������������������ȷ

            for (const auto& data : training_data) {            
                int prediction = this->predict(data);

                if (prediction * data.label <= 0) {
                    all_correct = false; // ���������������󣬼���ѵ��
                    // ����Ȩ�غ�ƫ��
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
            // �������������������ȷ������ѵ��
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