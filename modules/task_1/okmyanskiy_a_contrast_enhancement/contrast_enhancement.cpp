// Copyright 2020 Okmyanskiy Andrey
#include "contrast_enhancement.h"
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::vector<int> getRandomMatrix(int width, int height) {
    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Width or height <= 0");
    }
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    std::vector<int> vec(width*height);
    for (int i = 0; i < width*height; i++) {
        vec[i] = gen() % 255;
    }
    return vec;
}

int linearHistogramStretching(int value, int max, int min) {
    if (max < 0 || min < 0 || max > 255 || min > 255) {
        throw std::runtime_error("The maximum or minimum value does not match the task");
    }

    if (max < min) {
        throw std::runtime_error("The maximum value is less than the minimum value");
    }

    if (max == min) {
        return 0;
    } else {
        float koeffA = (255.0f * min) / (min - max);
        float koeffB = 255.0f / (max - min);
        return koeffA + koeffB * value;
    }
}

std::vector<int> getResultMatrix(std::vector<int> initial, int width, int height) {
    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Width or height <= 0");
    }

    if (width * height != static_cast<int>(initial.size())) {
        throw std::runtime_error("Matrix size does not match description");
    }

    std::vector<int> result(width * height);
    int min = *std::min_element(initial.begin(), initial.end());
    int max = *std::max_element(initial.begin(), initial.end());

    for (int i = 0; i < width * height; i++) {
        result[i] = linearHistogramStretching(initial[i], max, min);
    }
    return result;
}
