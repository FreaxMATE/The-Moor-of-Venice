project('MyGame', 'cpp', default_options: ['cpp_std=c++17'])

# Source files
src_files = files(
  'src/main.cpp',
  'src/Game.cpp',
  'src/AI.cpp',
  'src/Board.cpp'
)

# Create the executable
exe = executable('MyGame', src_files, link_args: [
#  '-L/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib',
  '-lsfml-graphics',
  '-lsfml-window',
  '-lsfml-audio',
  '-lsfml-network',
  '-lsfml-system',
  '-lstdc++fs',  # Add this if you use filesystem library
  '-static-libgcc',
  '-static-libstdc++'
])
