#!/bin/bash

TOOLS_BRANCH="tools"
REPO_URL="git@github.com:16561103/RRS.git"
TOOLS_DIR="tools"

echo "Setting up tools from branch '$TOOLS_BRANCH'..."

# Clone only the tools branch into a temp folder
if [ -d "$TOOLS_DIR" ]; then
    echo "Removing old tools folder..."
    rm -rf "$TOOLS_DIR"
fi

git clone --branch "$TOOLS_BRANCH" --depth 1 "$REPO_URL" "$TOOLS_DIR" > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "❌ Failed to fetch tools. Make sure SSH access is set up."
    return 1
fi

# Export tools path to PATH (for clean.sh)
TOOLS_PATH="$(pwd)/$TOOLS_DIR"
export PATH="$TOOLS_PATH:$PATH"

echo "✅ Tools setup complete."
echo "➡️  You can now run: make -C $TOOLS_DIR"

