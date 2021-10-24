# C++ Boid Simulation with SFML

## Requirements
In order to compile you need CMake and SFML 2.5 or greater

```bash
# Mac
brew install cmake sfml

# Ubuntu
sudo apt install cmake sfml
```

## Build and Run

```bash
cd boids
mkdir build
cd build
# Configure
# cmake ../     # Debug
cmake -DCMAKE_BUILD_TYPE=Release ..
# Build
cmake --build . -j4 --target Boids
```

```bash
./Boids
```