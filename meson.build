project('MyGame', 'cpp', 
  version : '0.1', 
  default_options : ['cpp_std=c++17'])

# Dependencies
sfml_dep = dependency('sfml', version : '>=2.5', modules : ['system', 'window', 'graphics', 'network', 'audio'])

# Include directories
inc = include_directories('include')

# Source files
sources = files('src/main.cpp', 'src/Game.cpp', 'src/Graphics.cpp', 'src/Logic/GameLogic.cpp')

# Executable
executable('MyGame', sources, 
  include_directories : inc,
  dependencies : sfml_dep,
  install : true)

# Set the output directory for the executable
meson.add_install_script('install.sh')