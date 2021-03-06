/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_ESTIMATORS_CPU_ESTIMATORS_H_
#define TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_ESTIMATORS_CPU_ESTIMATORS_H_

// CPU
constexpr float kCPUArithmeticUnitCost = 1.0;
constexpr float kCPUDefaultCost = 3.0f;

// Default values.
constexpr float kCPUDefaultFixedValuedCost = 10000.0;

// tfl.add
template <>
class TFLiteCostEstimator<AddOp, hardware::CPU> {
 public:
  static double GetCost(mlir::Operation* op) {
    int64_t count;
    if (ArithmeticCountUtilHelper::GetArithmeticCountForBroadcastableOp(op,
                                                                        &count))
      return kCPUArithmeticUnitCost * count;
    return kCPUDefaultFixedValuedCost;
  }

  static bool IsSupported(mlir::Operation* op) { return true; }
};

// tfl.mul
template <>
class TFLiteCostEstimator<MulOp, hardware::CPU> {
 public:
  static double GetCost(mlir::Operation* op) {
    int64_t count;
    if (ArithmeticCountUtilHelper::GetArithmeticCountForBroadcastableOp(op,
                                                                        &count))
      return kCPUArithmeticUnitCost * count;
    return kCPUDefaultFixedValuedCost;
  }

  static bool IsSupported(mlir::Operation* op) { return true; }
};

#endif  // TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_ESTIMATORS_CPU_ESTIMATORS_H_
