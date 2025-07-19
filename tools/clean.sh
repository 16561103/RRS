#!/bin/bash

# Directories to clean relative to tools/
BUILD_DIR="../build"
BIN_DIR="../bin"

echo "Cleaning build artifacts..."

# Remove directories if they exist
[ -d "$BUILD_DIR" ] && rm -rf "$BUILD_DIR" && echo "Removed $BUILD_DIR"
[ -d "$BIN_DIR" ] && rm -rf "$BIN_DIR" && echo "Removed $BIN_DIR"

echo "Cleanup done."

