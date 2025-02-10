#!/bin/sh

# Set the library path to include the lib directory
export LD_LIBRARY_PATH=$(dirname "$0")/lib:$LD_LIBRARY_PATH

# Run the application
$(dirname "$0")/bin/MyGame
