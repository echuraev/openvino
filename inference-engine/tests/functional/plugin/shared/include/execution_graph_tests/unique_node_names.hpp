// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "functional_test_utils/layer_test_utils.hpp"
#include "ngraph_functions/builders.hpp"

namespace LayerTestsDefinitions {

class ExecGraphUniqueNodeNames : public testing::WithParamInterface<LayerTestsUtils::basicParams>,
                                 public CommonTestUtils::TestsCommon {
public:
    static std::string getTestCaseName(testing::TestParamInfo<LayerTestsUtils::basicParams> obj);
    std::string targetDevice;
    std::shared_ptr<ngraph::Function> fnPtr;
protected:
    void SetUp() override;

    void TearDown() override;
};

}  // namespace LayerTestsDefinitions
