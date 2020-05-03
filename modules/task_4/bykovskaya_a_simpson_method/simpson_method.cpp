// Copyright 2020 Bykovskaya Alina
#include "../../../modules/task_4/bykovskaya_a_simpson_method/simpson_method.h"
#include <thread>
#include <atomic>
#include <vector>
#include <functional>
#include <utility>

static const int countThreads = 2;

double calcIntegral(const std::vector<std::pair<double, double>>& scope,
        std::function<double(const std::vector<double>)> f, size_t accurancy,
        size_t level, std::vector<double> fix_var) {
    if (scope.size() == 0)
        throw "Bad scope";
    if (fix_var.size() == 0)
        for (auto i : scope)
            fix_var.push_back(i.first);
    if (level >= scope.size())
        throw "Bad level of recursion";
    double h = (scope[level].second - scope[level].first) / (2 * accurancy);
    std::vector<double> func_res(2 * accurancy);
    if (scope.size() == level + 1) {
        for (size_t i = 0; i < accurancy * 2; i++) {
            fix_var[level] = scope[level].first + i * h;
            func_res[i] = f(fix_var);
        }
    } else {
        for (size_t i = 0; i < accurancy * 2; i++) {
            fix_var[level] = scope[level].first + i * h;
            func_res[i] =  calcIntegral(scope, f, accurancy, level + 1, fix_var);
        }
    }
    std::atomic<double> res = func_res[0] + func_res[2 * accurancy - 1];
    std::thread for_thrds[countThreads];
    for (int j = 0; j < countThreads; ++j) {
        for_thrds[j] = std::thread([&](){
            for (size_t i = 0; i < 2 * accurancy - 1; ++i) {
                if (i % 2 == 1) {
                    res = res + 4 * func_res[i];
                } else {
                    res = res + 2 * func_res[i];
                }
            }
        });
    }
    // for (size_t i = 1; i < 2 * accurancy - 1; i += 2)
    //     res += 4 * func_res[i];
    // for (size_t i = 2; i < 2 * accurancy - 2; i += 2)
    //     res += 2 * func_res[i];
    res = res * h / 3.0;
    return res;
}
