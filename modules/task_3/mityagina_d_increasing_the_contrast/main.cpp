// Copyright 2020 Mityagina Daria
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../../../modules/task_3/mityagina_d_increasing_the_contrast/increasing_the_contrast.h"

void testing_lab(std::vector<int> input, int width, int height) {
  ASSERT_NO_THROW(contrast_increase_parallel(input, width, height));
}

void testing_lab_2(std::vector<int> input, int width, int height) {
  ASSERT_NO_THROW(contrast_increase_sequential(input, width, height));
}

TEST(contrast_increase, cant_process_images_with_zero_size) {
  int height = 0, width = 0;

  ASSERT_ANY_THROW(contrast_increase_parallel(generate_im(width, height), width, height));
}

TEST(contrast_increase, cant_process_images_with_negative_size_1) {
  int height = -10, width = 10;

  ASSERT_ANY_THROW(contrast_increase_parallel(generate_im(width, height), width, height));
}

TEST(contrast_increase, cant_process_images_with_negative_size_2) {
  int height = 10, width = -10;

  ASSERT_ANY_THROW(contrast_increase_parallel(generate_im(width, height), width, height));
}

TEST(contrast_increase, min_is_calculated_correctly) {
  std::vector<int> input = generate_im(10, 10);

  ASSERT_EQ(*std::min_element(input.begin(), input.end()), minimum(&input));
}

TEST(contrast_increase, max_is_calculated_correctly) {
  std::vector<int> input = generate_im(10, 10);

  ASSERT_EQ(*std::max_element(input.begin(), input.end()), maximum(&input));
}

TEST(contrast_increase, simple_example) {
  std::vector<int> input = {2, 14, 5, 104, 50, 60, 26, 64, 9};
  std::vector<int> output = std::vector<int>(input);

  for (int i = 0; i < static_cast<int>(input.size()); i++) {
    output[i] = static_cast<int>(-5 + 2.5 * input[i]);
  }

  ASSERT_EQ(output, contrast_increase_parallel(input, 3, 3));
}

// TEST(contrast_increase, simple_example_parallel_1000) {
//   std::vector<int> input = generate_im(1000, 1000);
//   std::vector<int> output = std::vector<int>(input);

//   int min = *std::min_element(input.begin(), input.end());
//   int max = *std::max_element(input.begin(), input.end());
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_parallel(input, 1000, 1000));
// }

// TEST(contrast_increase, simple_example_seq_1000) {
//   std::vector<int> input = generate_im(1000, 1000);
//   std::vector<int> output = std::vector<int>(input);

//   int min = static_cast<int>(*std::min_element(input.begin(), input.end()));
//   int max = static_cast<int>(*std::max_element(input.begin(), input.end()));
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_sequential(input, 1000, 1000));
// }

// TEST(contrast_increase, simple_example_seq_10000) {
//   std::vector<int> input = generate_im(10000, 10000);
//   std::vector<int> output = std::vector<int>(input);

//   int min = static_cast<int>(*std::min_element(input.begin(), input.end()));
//   int max = static_cast<int>(*std::max_element(input.begin(), input.end()));
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_sequential(input, 10000, 10000));
// }

// TEST(contrast_increase, simple_example_parallel_10000) {
//   std::vector<int> input = generate_im(10000, 10000);
//   std::vector<int> output = std::vector<int>(input);

//   int min = *std::min_element(input.begin(), input.end());
//   int max = *std::max_element(input.begin(), input.end());
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_parallel(input, 10000, 10000));
// }

// TEST(contrast_increase, simple_example_seq_10001) {
//   std::vector<int> input = generate_im(10001, 10001);
//   std::vector<int> output = std::vector<int>(input);

//   int min = static_cast<int>(*std::min_element(input.begin(), input.end()));
//   int max = static_cast<int>(*std::max_element(input.begin(), input.end()));
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_sequential(input, 10001, 10001));
// }

// TEST(contrast_increase, simple_example_parallel_10001) {
//   std::vector<int> input = generate_im(10001, 10001);
//   std::vector<int> output = std::vector<int>(input);

//   int min = *std::min_element(input.begin(), input.end());
//   int max = *std::max_element(input.begin(), input.end());
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_parallel(input, 10001, 10001));
// }

// TEST(contrast_increase, simple_example_seq_13331) {
//   std::vector<int> input = generate_im(13331, 13331);
//   std::vector<int> output = std::vector<int>(input);

//   int min = static_cast<int>(*std::min_element(input.begin(), input.end()));
//   int max = static_cast<int>(*std::max_element(input.begin(), input.end()));
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_sequential(input, 13331, 13331));
// }

// TEST(contrast_increase, simple_example_parallel_13331) {
//   std::vector<int> input = generate_im(13331, 13331);
//   std::vector<int> output = std::vector<int>(input);

//   int min = *std::min_element(input.begin(), input.end());
//   int max = *std::max_element(input.begin(), input.end());
//   for (int i = 0; i < static_cast<int>(input.size()); i++) {
//     output[i] = static_cast<int>(use_formula(input[i], max, min));
//   }

//   ASSERT_EQ(output, contrast_increase_parallel(input, 13331, 13331));
// }

TEST(contrast_increase, min_is_greater_then_max) {
  ASSERT_ANY_THROW(use_formula(7, 2, 10));
}

TEST(contrast_increase, check_size_par_10_10) {
  testing_lab(generate_im(10, 10), 10, 10);
}

TEST(contrast_increase, check_size_seq_10_10) {
  testing_lab_2(generate_im(10, 10), 10, 10);
}

// TEST(contrast_increase, check_size_1000_1000) {
//   testing_lab(generate_im(1000, 1000), 1000, 1000);
// }

// TEST(contrast_increase, check_size_1000_1000_2) {
//   testing_lab_2(generate_im(1000, 1000), 1000, 1000);
// }

// TEST(contrast_increase, check_size_5000_5000) {
//   testing_lab(generate_im(5000, 5000), 5000, 5000);
// }

// TEST(contrast_increase, check_size_5000_5000_2) {
//   testing_lab_2(generate_im(5000, 5000), 5000, 5000);
// }

// TEST(contrast_increase, check_size_256_256) {
//   testing_lab(generate_im(256, 256), 256, 256);
// }

TEST(contrast_increase, check_size_seq_100_100) {
  testing_lab_2(generate_im(100, 100), 100, 100);
}

TEST(contrast_increase, check_size_par_100_100) {
  testing_lab(generate_im(100, 100), 100, 100);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
