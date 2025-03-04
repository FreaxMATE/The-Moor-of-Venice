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


## Nix

Setup development environment based on the flake.nix

```bash
nix develop
```
