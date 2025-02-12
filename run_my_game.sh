#!/bin/sh

# Set the library path to include the lib directory
export LD_LIBRARY_PATH=$(dirname "$0")/../lib:$(dirname "$0")

# Run the application with the correct dynamic linker
$(dirname "$0")/build/MyGame
