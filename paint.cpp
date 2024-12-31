#pragma once
#include "perceptron.h"
void Paint(const std::vector<DataPoint>& training_data, const Perceptron& perceptron) {

    initgraph(800, 640);  // 初始化图形模式
    setbkcolor(WHITE);
    cleardevice();
    BeginBatchDraw();

    char str[] = { '0','1','2','3','4','5','6','7','8','9' };
    // 设置坐标系范围
    int x_min = 0, x_max = 9;
    int y_min = 0, y_max = 9;

    // 绘制坐标轴
    setcolor(BLACK);
    line(60, 600, 630, 600);  // x 轴
    line(60, 600, 60, 30);  // y 轴

    // 绘制刻度
    for (int i = 0; i <= x_max; ++i) {
        line(60 + i * 60, 600, 60 + i * 60, 590);// x 轴刻度
        outtextxy(60 + i * 60, 610, str[i]);
    }
    for (int i = 0; i <= y_max; ++i) {
        line(60, 60 + i * 60, 70, 60 + i * 60);  // y 轴刻度
        outtextxy(45, 600 - i * 60, str[i]);
    }
    outtextxy(60, 10, 'y');
    outtextxy(635, 600, 'x');

    // 绘制数据点
    for (const auto& data : training_data) {
        int color = (data.label == 1) ? BLUE : RED;
        setfillcolor(color);
        solidcircle(60 + data.x1 * 60, 600 - data.x2 * 60, 8);
    }

    // 计算决策边界的直线方程：w1*x1 + w2*x2 + b = 0  ->  x2 = (-b - w1*x1) / w2
    double w1 = perceptron.weights[0];
    double w2 = perceptron.weights[1];
    double b = perceptron.bias;
    double x1_min = x_min, x1_max = x_max;
    double y1 = (-b - w1 * x1_min) / w2;
    double y2 = (-b - w1 * x1_max) / w2;

    // 绘制决策边界
    line(60 + x1_min * 60, 600 - y1 * 60, 60 + x1_max * 60, 600 - y2 * 60);

    EndBatchDraw();
    FlushBatchDraw();
    // 等待用户按键
    _getch();
    closegraph(); // 关闭图形窗口
}
