# Build

## Dependencies

 - SFML
 - CMake

Install dependencies on Ubuntu 24.04
```bash
sudo apt install git make g++ libsfml-dev cmake
```

## Compile and run game
```bash
mkdir build
cd build
cmake ..
make
./MyGame
```

## Debug
For debugging run cmake like this
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

## Nix
Setup development environment based on the flake.nix

```bash
nix develop
```
