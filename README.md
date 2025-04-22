
# Concurrent Logger
    Designed to safely and efficiently record log messages for single/multi threaded applications.

## Description
    This project is a high-performance, multithreaded logger system written in C++. It enables efficient, thread-safe logging to multiple outputs (files, databases, and console) using lock-free data structures and modern C++ features. Designed for real-time applications, it minimizes logging overhead and supports both sequential and concurrent integration modes.

* Currenlty Supported outputs: File and Console.
* Future Implementations: Database and Trace

## Getting Started

### Dependencies
* C++ Version: 20 or above
* IDE: Visual Studio
* OS: Windows
* External Library: VCPkg, enable vcpkg manager in your Visual Studio Installer. 

### Installation
* Right now the project is still under implementation and you need to manually download the source code and integrate with required  application.
* Import the project as a static library.

### Configuration

#### Default
* Global:
    Integration: Sequential
    Output Type: File

* File Settings: 
    Creates a new Logs folder at your project directory
    Default file size is 1 MB
    A total of 10 files are created and these files are overwritten circularly.

### Executing program
* Download the project to your desired folder.
* Add this project to your solution and refer it in your main project.
* Now the project is integrated into your application, you need to intitialize it by calling 'Log::Configuration()' method in your main program/application startup.

## Author
* Lohith Challagundla