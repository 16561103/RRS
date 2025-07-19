#!/bin/bash

TOOLS_BRANCH="tools"
TOOLS_DIR="tools"
FILES_TO_FETCH=("tools/clean.sh" "tools/makefile" "tools/run_tests.sh")  # Added run_tests.sh

echo "🔧 Setting up tools from branch '$TOOLS_BRANCH'..."

# Remove old tools directory
if [ -d "$TOOLS_DIR" ]; then
    echo "🧹 Removing old tools directory..."
    rm -rf "$TOOLS_DIR"
fi

mkdir -p "$TOOLS_DIR"

# Loop over each file and fetch from tools branch
for file in "${FILES_TO_FETCH[@]}"; do
    BASENAME=$(basename "$file")
    git show "$TOOLS_BRANCH:$file" > "$TOOLS_DIR/$BASENAME" 2>/dev/null

    if [ $? -ne 0 ]; then
        echo "❌ Failed to fetch $file from $TOOLS_BRANCH"
        return 1
    else
        echo "✅ Fetched $BASENAME"
    fi
done

# Export to PATH if needed
TOOLS_PATH="$(pwd)/$TOOLS_DIR"
export PATH="$TOOLS_PATH:$PATH"

echo "✅ Tools setup complete."

