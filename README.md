# ASCII_Webcam
A c++/openCV project that captures the webcam stream and prints it as ASCII grayscale with VS Code

## Installation
*This installation section is relative to a Visual Studio Code implamentation*

- Install compiler and debugger for c++: [VS Code Documentation](https://code.visualstudio.com/docs/languages/cpp)

- Download MinGW-OpenCV package: OpenCV-4.5.2-x64
```
git clone -b OpenCV-4.5.2-x64 https://github.com/huihut/OpenCV-MinGW-Build.git
```

Add to Path the *Compiler Path* and the *OpenCv binaries Path* ( [How to edit Path](https://www.howtogeek.com/118594/how-to-edit-your-system-path-for-easy-command-line-access/) )

Example:
- Compiler path: ```C:\msys64\mingw64\bin```
- OpenCv binaries Path: ```C:\opencv\OpenCV-MinGW-Build\x64\mingw\bin```

## Setup
Open the project folder in VS Code

Configure `tasks.json`, `launch.json`, `c_cpp_properties.json` files in `.vscode` folder as they are in this repository

Restart the system

## Compile and run
With the c++ file opened:
- To just compile, on VS Code click on `Terminal > Run Task` or `Ctrl + Shift + B`, then choose `build opencv`
- To compile and run, on VS Code click on `Terminal > Run Task` then choose `run opencv`

*Quick tips:*
- In `Terminal > Configure Default Build Task` choose `run opencv`, then press `Ctrl + Shift + B` to build and run the code
- To best view the *ASCII webcam* printed on the terminal, use at least a 1920x1080 screen and expand the teminal window in VS Code

## Possible Issues
If a diffrent version of OpenCV-MinGW-Build is choosen, make sure to update the lib versions in the `tasks.json` file

Example:
- OpenCV-MinGW-Build version 4.1.1:
```
...

"-llibopencv_calib3d411",

...
```
- OpenCV-MinGW-Build version 4.5.2:
```
...

"-llibopencv_calib3d452",

...
```
