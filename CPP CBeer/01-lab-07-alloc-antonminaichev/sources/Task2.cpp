// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <matrix.hpp>
#include <regex>

void Construct(Matrix& out, size_t n, size_t m) {
  out.n_ = n;
  out.m_ = m;
  out.data_ = new int*[out.n_];
  for (size_t count = 0; count < out.n_; ++count) {
    out.data_[count] = new int[out.m_]();
  }
}

void Destruct(Matrix& in) {
  for (size_t i = 0; i < in.n_; ++i) {
    delete[] in.data_[i];
  }
  delete[] in.data_;
  in.data_ = nullptr;
}

Matrix Copy(const Matrix& matrix) {
  Matrix new_matrix = {
      new int*[matrix.n_],
      matrix.m_,
      matrix.n_,
  };
  for (size_t count = 0; count < new_matrix.n_; ++count) {
    new_matrix.data_[count] = new int[new_matrix.m_]();
  }
  for (size_t i = 0; i < new_matrix.n_; ++i) {
    for (size_t j = 0; j < new_matrix.m_; ++j) {
      new_matrix.data_[i][j] = matrix.data_[i][j];
    }
  }
  return new_matrix;
}

Matrix Add(const Matrix& a, const Matrix& b) {
  if (a.n_ != b.n_ || a.m_ != b.m_) {
    return Matrix{};
  }
  Matrix new_matrix = Copy(a);
  for (size_t count_row = 0; count_row < a.n_; ++count_row) {
    for (size_t count_column = 0; count_column < a.m_; ++count_column) {
      new_matrix.data_[count_row][count_column] =
          a.data_[count_row][count_column] + b.data_[count_row][count_column];
    }
  }
  return new_matrix;
}

Matrix Sub(const Matrix& a, const Matrix& b) {
  if (a.n_ != b.n_ || a.m_ != b.m_) {
    return Matrix{};
  }
  Matrix new_matrix = Copy(a);
  for (size_t count_row = 0; count_row < a.n_; ++count_row) {
    for (size_t count_column = 0; count_column < a.m_; ++count_column) {
      new_matrix.data_[count_row][count_column] =
          a.data_[count_row][count_column] - b.data_[count_row][count_column];
    }
  }
  return new_matrix;
}

Matrix Mult(const Matrix& a, const Matrix& b) {
  if (a.m_ != b.n_) {
    return Matrix{};
  }
  Matrix new_matrix;
  Construct(new_matrix, a.n_, b.m_);
  for (size_t count_row = 0; count_row < new_matrix.n_; ++count_row) {
    for (size_t count_column = 0; count_column < new_matrix.m_;
         ++count_column) {
      for (size_t i = 0; i < a.m_; ++i) {
        new_matrix.data_[count_row][count_column] +=
            a.data_[count_row][i] * b.data_[i][count_column];
      }
    }
  }
  return new_matrix;
}

void Transposition(Matrix& matrix) {
  for (size_t count_row = 0; count_row < matrix.m_; ++count_row) {
    for (size_t count_column = count_row + 1; count_column < matrix.m_;
         ++count_column) {
      std::swap(matrix.data_[count_row][count_column],
                matrix.data_[count_column][count_row]);
    }
  }
}

bool operator==(const Matrix& a, const Matrix& b) {
  if (a.n_ != b.n_ || a.m_ != b.m_) {
    return false;
  }
  for (size_t count_row = 0; count_row < a.n_; ++count_row) {
    for (size_t count_column = 0; count_column < a.m_; ++count_column) {
      if (a.data_[count_row][count_column] !=
          b.data_[count_row][count_column]) {
        return false;
      }
    }
  }
  return true;
}
