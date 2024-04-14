# C SNAKE

This is a classic snake game written in C with ncurces.

## Command line usage

To start the program run

```
./cSnake
```

To print the current version run

```
./cSnake --version
```




## Installing nCurses

On Debian Linux or Ubuntu you can run

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

or on Fedora

```
sudo dnf install ncurses-devel
```

## Build Instructions

1. Ensure cmake is installed (at minimun version 3.15)
2. Create a directory to place the build in
3. Navigate into the build directory
4. run the following commands
```
cmake PATH_TO_PROJECT_DIRECTORY
```
```
cmake --build .
```
