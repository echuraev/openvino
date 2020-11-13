// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "single_layer_tests/non_max_suppression.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;
using namespace InferenceEngine;
using namespace ngraph;

const std::vector<InputShapeParams> inShapeParams = {
    //InputShapeParams{3, 100, 5},
    //InputShapeParams{1, 10, 50},
    InputShapeParams{2, 5, 5}
};

const std::vector<int32_t> maxOutBoxPerClass = {5};//{5, 20};
const std::vector<float> threshold = {0.3f};//{0.3f, 0.7f};
const std::vector<float> sigmaThreshold = {0.0f};//{0.0f, 0.5f};
const std::vector<op::v5::NonMaxSuppression::BoxEncodingType> encodType = {op::v5::NonMaxSuppression::BoxEncodingType::CORNER};
const std::vector<bool> sortResDesc = {true};//, false};//op::v5::NonMaxSuppression::BoxEncodingType::CORNER};
const std::vector<element::Type> outType = {element::i32};//, element::i64};

const auto nmsParams = ::testing::Combine(::testing::ValuesIn(inShapeParams),
                                          ::testing::Combine(::testing::Values(Precision::FP32),
                                                             ::testing::Values(Precision::I32),
                                                             ::testing::Values(Precision::FP32)),
                                          ::testing::ValuesIn(maxOutBoxPerClass),
                                          ::testing::ValuesIn(threshold),
                                          ::testing::ValuesIn(threshold),
                                          ::testing::ValuesIn(sigmaThreshold),
                                          ::testing::ValuesIn(encodType),
                                          ::testing::ValuesIn(sortResDesc),
                                          ::testing::ValuesIn(outType),
                                          ::testing::Values(CommonTestUtils::DEVICE_GPU)
);

INSTANTIATE_TEST_CASE_P(smoke_NmsLayerTest, NmsLayerTest, nmsParams, NmsLayerTest::getTestCaseName);
