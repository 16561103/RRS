#!/bin/bash

TEST_NAME="test_userlogin"
TEST_SRC="../test/${TEST_NAME}.cpp"
TEST_BIN="../tools/build/test/${TEST_NAME}"

# Source files required for the test
USER_SRC="../src/user.cpp"
ADMIN_SRC="../src/admin.cpp"
BOOKING_SRC="../src/booking.cpp"
TRAIN_SRC="../src/train.cpp"  # 👈 Add this

echo "🛠️  Building test: $TEST_NAME"

mkdir -p ../tools/build/test

g++ -std=c++17 -g -Wall -Wextra \
    -I../include \
    "$TEST_SRC" "$USER_SRC" "$ADMIN_SRC" "$BOOKING_SRC" "$TRAIN_SRC" \
    -lgtest -lgtest_main -pthread -o "$TEST_BIN"

if [ $? -eq 0 ]; then
    echo "✅ Build successful. Running tests..."
    "$TEST_BIN"
else
    echo "❌ Build failed"
    exit 1
fi

