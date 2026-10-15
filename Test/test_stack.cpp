#include "pch.h"
#include <gtest/gtest.h>
#include "Stack.h"

#include <string>
#include <stdexcept>

TEST(StackTest, ZeroSizeThrows) {
    EXPECT_THROW(StackOnMass<int>(0), std::invalid_argument);
}

TEST(StackTest, NewStackIsEmpty) {
    StackOnMass<int> s(5);
    EXPECT_TRUE(s.is_empty());
    EXPECT_FALSE(s.is_full());
}

TEST(StackTest, PushToFullThrows) {
    StackOnMass<int> s(2);
    s.push(1);
    s.push(2);
    EXPECT_TRUE(s.is_full());
    EXPECT_THROW(s.push(3), std::overflow_error);
}

TEST(StackTest, PopFromEmptyThrows) {
    StackOnMass<int> s(3);
    EXPECT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, TopOnEmptyThrows) {
    StackOnMass<int> s(3);
    EXPECT_THROW(s.top(), std::underflow_error);
}

TEST(StackTest, PushMakesNonEmpty) {
    StackOnMass<int> s(5);
    EXPECT_TRUE(s.is_empty());
    s.push(1);
    EXPECT_FALSE(s.is_empty());
}

TEST(StackTest, CopyConstructorCopiesSize) {
    StackOnMass<int> s(5);
    StackOnMass<int> copy(s);
    EXPECT_TRUE(copy.is_empty());
    EXPECT_FALSE(copy.is_full());
}

TEST(StackTest, CopyConstructorIndependent) {
    StackOnMass<int> s(5);
    s.push(10);

    StackOnMass<int> copy(s);
    copy.push(20);

    EXPECT_FALSE(s.is_empty());
    EXPECT_FALSE(copy.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_FALSE(copy.is_full());
}

TEST(StackTest, WorksWithStrings) {
    StackOnMass<std::string> s(3);
    s.push("hello");
    EXPECT_FALSE(s.is_empty());
    s.push("world");
    EXPECT_FALSE(s.is_full());
}