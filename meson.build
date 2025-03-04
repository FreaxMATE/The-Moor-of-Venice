project('MyGame', 'cpp', default_options: ['cpp_std=c++17'])

# Source files
src_files = files(
  'src/main.cpp',
  'src/Game.cpp',
  'src/AI.cpp',
  'src/Board.cpp'
)

# Find SFML package
sfml = dependency('sfml-all', required: true)

# Create the executable
exe = executable('MyGame', src_files, dependencies: [sfml])