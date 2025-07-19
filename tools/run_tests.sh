#!/bin/bash

WORKSPACE=$(pwd)

TEST_NAME="test_userlogin"
TEST_SRC="${WORKSPACE}/test/${TEST_NAME}.cpp"
TEST_BIN="${WORKSPACE}/build/test/${TEST_NAME}"

# Source files
USER_SRC="${WORKSPACE}/src/user.cpp"
ADMIN_SRC="${WORKSPACE}/src/admin.cpp"
BOOKING_SRC="${WORKSPACE}/src/booking.cpp"
TRAIN_SRC="${WORKSPACE}/src/train.cpp"

# Include
INCLUDE_DIR="${WORKSPACE}/include"

echo "🛠️  Building test: $TEST_NAME"

mkdir -p "${WORKSPACE}/build/test"

g++ -std=c++17 -g -Wall -Wextra \
    -I"${INCLUDE_DIR}" \
    "$TEST_SRC" "$USER_SRC" "$ADMIN_SRC" "$BOOKING_SRC" "$TRAIN_SRC" \
    -lgtest -lgtest_main -pthread -o "$TEST_BIN"

if [ $? -eq 0 ]; then
    echo "✅ Build successful. Running tests..."
    "$TEST_BIN"
else
    echo "❌ Build failed"
    exit 1
fi

