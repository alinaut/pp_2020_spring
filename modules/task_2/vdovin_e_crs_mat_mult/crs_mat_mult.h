// Copyright 2020 Vdovin Eugene
#ifndef MODULES_TASK_2_VDOVIN_E_CRS_MAT_MULT_CRS_MAT_MULT_H_
#define MODULES_TASK_2_VDOVIN_E_CRS_MAT_MULT_CRS_MAT_MULT_H_

#include <omp.h>
#include <vector>
#include <complex>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>
#include <utility>
#include <numeric>

class CRSMatrix {
    int n;
    int nz;
    int omp_k;

    std::vector<std::complex<double>> value;
    std::vector<int> col;
    std::vector<int> rowindex;

    CRSMatrix multiplicate(const CRSMatrix &mtx) const;
    bool findElemInVector(const std::vector<std::pair<int, std::complex<double>>>& vec, const int elem);

 public:
    explicit CRSMatrix(const int n_ = 0, const int nz_ = 0);
    CRSMatrix(const int n_, const int nz_,
        const std::vector<std::complex<double>> &value_,
        const std::vector<int> col_,
        const std::vector<int> rowindex_);
    CRSMatrix(const CRSMatrix &mtx);
    ~CRSMatrix() {}

    CRSMatrix operator*(const CRSMatrix &mtx) const;
    CRSMatrix& operator=(const CRSMatrix &mtx);
    CRSMatrix transpose() const;
    void buildRandomCRSMatrix();
    void getThreads(int numTreads);

    bool operator==(const CRSMatrix &mtx) const;
    bool operator!=(const CRSMatrix &mtx) const;
};

#endif  // MODULES_TASK_2_VDOVIN_E_CRS_MAT_MULT_CRS_MAT_MULT_H_
