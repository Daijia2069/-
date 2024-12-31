#include "perceptron.h"
int main() {
    int x=0;
    // ���ļ���ȡ��ͱ�ǩ
    vector<DataPoint> data = readDataFromFile("points.txt");
    vector<DataPoint> testdata = readDataFromFile("testpoints.txt");
    while (x != 4) {
        cout << "1��ר��ϵͳ" << endl;
        cout << "2: ����ѧϰ" << endl;
        cout << "3: ����һ�����ݲ���" << endl;
        cout << "4: �˳�" << endl;
        cout << "��ѡ���ܣ�" << endl;
        cin >> x;
        switch (x) {
        case 1:
        {
            Perceptron p1(0.01, -1.0, 1.0, -0.5); //����ר��ϵͳ
            p1.train(data, 1000);
            p1.show();
            Paint(data, p1);
            break;
        }
        case 2:
        {
            Perceptron p2(0.01); // ������֪������ѧϰ��Ϊ 0.01
            p2.train(data, 1000);
            p2.show();
            Paint(data, p2);
            break;
        }
        case 3:
        {

            Perceptron p3(0.01); // ������֪������ѧϰ��Ϊ 0.01
            p3.train(testdata, 1000);
            p3.show();
            Paint(testdata, p3);
            break;
        }
        case 4:
        {
            cout << "�����˳���" << endl;
            break;
        }

        }
    }
   
    return 0;
}