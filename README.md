# LatitudeLongitudeUtility

## What's this?

This library offers **conversion functions between the following geographic coordinate systems**.
This is written in C++11.

- BLH (B: latitude, L: longitude, H: height)
- ECEF (Earth Centerd, Earth Fixed: 3D Cartesian coordinate system represented by (x, y, z))
- ENU (E: east, N: north, U: up)

See [Wikipedia](https://en.wikipedia.org/wiki/Geographic_coordinate_system) for details.

## Tested Environment

- Compiler: g++ 7.4.0 with `-std=c++11` option.
- Test framework: [googletest](https://github.com/google/googletest) 1.10.0

## How to Use?

### Build

Try `make`. It will be helpful.

```Makefile
$ make
all                            make clean, build, and test
buildsample                    Build sample programs
buildtest                      Build test programs
clean                          Delete binaries
create_dirs                    Create neccesary directories to run
format                         Format with clang-format
runsample                      Run sample main program
runtest                        Run tests
```

If you try minimum sample, just do this (googletest is not necessary).

```sh
make buildsample
make runsample
```

### Functions

See [`sample_main.cc`](./sample_main.cc) about how to use conversion functions.

Its result should be as follows.

```
$ make runsample
././bin/sample.out
From Tokyo Station to Tokyo Imperial Palace:
East : -1330.698522 [m]
North: 810.056878 [m]

Let's restore lat/lon of Imperial Palace.
The same value should be obtained.
Latitude : 35.682500(raw) vs 35.682500(restored)
Longitude: 139.752100(raw) vs 139.752100(restored)
```

## Q&A

### What does BLH stands for?

I don't know why BLH means latitude/longitude (and height).
According to Google, B and L come from German words which mean latitude and longitude respectively.

