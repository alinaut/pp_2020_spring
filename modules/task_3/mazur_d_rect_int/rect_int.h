// Copyright 2020 Mazur Daniil
#ifndef MODULES_TASK_3_MAZUR_D_RECT_INT_RECT_INT_H_
#define MODULES_TASK_3_MAZUR_D_RECT_INT_RECT_INT_H_
#include <vector>
#include <numeric>
#include <functional>
#include <utility>

double rectIntSequen(const std::function<double(const std::vector<double>&)>& f,
                     std::vector <std::pair<double, double>> cord, int cuts);
double rectIntTbb(const std::function<double(const std::vector<double>&)>& f,
                  std::vector <std::pair<double, double>> cord, int cuts);

#endif  // MODULES_TASK_3_MAZUR_D_RECT_INT_RECT_INT_H_
