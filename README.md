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
Configure `tasks.json`, `launch.json`, `c_cpp_properties.json` files in `.vscode` folder
