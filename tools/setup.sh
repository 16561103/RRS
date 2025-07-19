#!/bin/bash

# Get the directory of this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Add tools directory to PATH so that scripts like clean.sh are easily accessible
export PATH="$SCRIPT_DIR:$PATH"

echo "Tools environment setup complete. Tools path added to \$PATH"

