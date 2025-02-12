# Build

## Dependencies

 - SFML
 - Meson (for compilation)

## Nix

```bash
nix develop
```

## Setup

### Using Meson (prefered)
```bash
meson setup build
meson compile -C build
./build/MyGame
```

### Using CMake
```bash
mkdir build && cd build
cmake ..
cp ./bin/MyGame .
./MyGame
```
