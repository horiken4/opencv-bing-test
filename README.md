# OpenCV BING Test

## Usage
Before run this program, please install opencv with opencv_contrib module including BING objectness.

For train BING model, you shoulde use https://github.com/horiken4/BING-Objectness

After training has finished, execute the program.  
For example:
```bash
$ cmake .
$ make
$ ./bin/opencv_bing_test $HOME/repos/BING-Objectness/VOC2007/Results $HOME/repos/BING-Objectness/VOC2007/JPEGImages/000800.jpg
```
