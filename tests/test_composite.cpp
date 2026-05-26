#include <gtest/gtest.h>
#include "Composite.h"
#include "Leaf.h"

TEST(CompositeTest, SingleLeafOutput) {
    Leaf leaf("leaf1");
    testing::internal::CaptureStdout();
    leaf.Operation();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Leaf: leaf1\n");
}

TEST(CompositeTest, CompositeOutput) {
    Composite root("root");
    Composite sub = std::make_shared<Composite>("sub");
    sub.Add(std::make_shared<Leaf>("leafA"));

    root.Add(sub);

    root.Add(std::make_shared<Leaf>("leafB"));

    testing::internal::CaptureStdout();
    root.Operation();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected =
        "Composite: root\n"
        "Composite: sub\n"
        "Leaf: leafA\n"
        "Leaf: leafB\n";
    EXPECT_EQ(output, expected);
}
