#include "perceptron.h"
int main() {
    int x=0;
    // 从文件读取点和标签
    vector<DataPoint> data = readDataFromFile("points.txt");
    vector<DataPoint> testdata = readDataFromFile("testpoints.txt");
    while (x != 4) {
        cout << "1：专家系统" << endl;
        cout << "2: 机器学习" << endl;
        cout << "3: 任意一组数据测试" << endl;
        cout << "4: 退出" << endl;
        cout << "请选择功能：" << endl;
        cin >> x;
        switch (x) {
        case 1:
        {
            Perceptron p1(0.01, -1.0, 1.0, -0.5); //创建专家系统
            p1.train(data, 1000);
            p1.show();
            Paint(data, p1);
            break;
        }
        case 2:
        {
            Perceptron p2(0.01); // 创建感知器对象，学习率为 0.01
            p2.train(data, 1000);
            p2.show();
            Paint(data, p2);
            break;
        }
        case 3:
        {

            Perceptron p3(0.01); // 创建感知器对象，学习率为 0.01
            p3.train(testdata, 1000);
            p3.show();
            Paint(testdata, p3);
            break;
        }
        case 4:
        {
            cout << "程序退出！" << endl;
            break;
        }

        }
    }
   
    return 0;
}