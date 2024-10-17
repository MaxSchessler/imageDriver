# Computer Science I
## Hack 7.0 - Arrays - Repository
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

This project contains starter code and image library functionality
(from https://github.com/nothings/stb) for Hack 7.0 from
[Computer Science I](https://github.com/cbourke/ComputerScienceI/).

We have provided a full `makefile` that you can use to build all
testing code and programs.

* To build *everything* run the command `make all`

* To build the array tester: `make arrayUtilsTester` which
  will produce a program named `arrayUtilsTester`

* To build the image driver program (to test your flip and
  rotate functions visually) use `make imageDriver` which
  will produce a program named `imageDriver`.  See `imageDriver.c`
  for the full usage of this program.  Some examples:

  * Flip `avery.jpg` horizontally, saving to a file named `avery-horizontal.jpg`:  
  `./imageDriver avery.jpg avery-horizontal.jpg 1`

  * Flip `avery.jpg` vertically, saving to a file named `avery-vertical.jpg`:  
  `./imageDriver avery.jpg avery-vertical.jpg 2`

  * Rotate `avery.jpg`, saving to a file named `avery-rotate.jpg`:  
  `./imageDriver avery.jpg avery-rotate.jpg 3`
