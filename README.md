# FaceDetection

Detect faces on video stream or camera

## Description

Uses OpenCV as driver

## Installation

### Linux

1. If no `git` installed, install it:

	```bash
	$ sudo apt install git
	```	

1. Make sure you have cmake installed. If no - install it:

	```bash
	$ sudo apt-get -y install cmake
	```	

1. Create and enter directory for project to install into

	```bash
	$ mkdir FaceDetection
	$ cd FaceDetection
	```	

1. Clone project onto your current directory

	```bash
	$ git clone https://github.com/TutyhinAlexander/FaceDetection.git .
	```	

1. Create a new build directory:

	```bash
	$ mkdir build
	```	

1. Run cmake on the parent directory to build:

	```bash
	$ cmake -B ./build .
	$ cmake --build ./build
	```

1. To run app:

	```bash
	$ ./FaceDetection
	```	

## Using

1. Attach camera to PC

1. Start app


## Dependencies
	
	Project uses `OpenCV` so you need to install it first:

	```bash	
	$ sudo apt update
	$ sudo apt-get install libopencv-dev
	```		


