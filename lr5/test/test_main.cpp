#include <gtest.h>
#include "fix_memory_res.h"
#include "stack.h"

using namespace std;

class FixedMemoryResourceTest : public ::testing::Test {
protected:
    void SetUp() override {
        resource = make_unique<FixedMemoryResource>(256);
    }

    void TearDown() override {
        resource.reset();
    }

    unique_ptr<FixedMemoryResource> resource;
};

TEST_F(FixedMemoryResourceTest, BasicAllocation) {
    void* ptr = resource->allocate(100);
    EXPECT_NE(ptr, nullptr);
    EXPECT_EQ(resource->get_used_size(), 100);
    EXPECT_EQ(resource->get_available_size(), 156);
    
    resource->deallocate(ptr, 100);
    EXPECT_EQ(resource->get_used_size(), 100);
}

TEST_F(FixedMemoryResourceTest, ResetFunctionality) {
    void* ptr1 = resource->allocate(50);
    EXPECT_EQ(resource->get_used_size(), 50);
    
    resource->deallocate(ptr1, 50);
    EXPECT_EQ(resource->get_used_size(), 50);
    
    resource->reset();
    EXPECT_EQ(resource->get_used_size(), 0);
    EXPECT_EQ(resource->get_available_size(), 256);
}

TEST_F(FixedMemoryResourceTest, OutOfMemory) {
    EXPECT_THROW(resource->allocate(300), bad_alloc);
}

TEST(StackTest, BasicOperations) {
    FixedMemoryResource resource(512);
    Stack<int> stack(&resource);
    
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(42);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 42);
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, IteratorFunctionality) {
    FixedMemoryResource resource(512);
    Stack<int> stack(&resource);
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    auto it = stack.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, stack.end());
}

TEST(StackTest, ComplexTypes) {
    FixedMemoryResource resource(1024);
    Stack<string> stack(&resource);
    
    stack.push("hello");
    stack.push("world");
    
    EXPECT_EQ(stack.top(), "world");
    stack.pop();
    EXPECT_EQ(stack.top(), "hello");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}