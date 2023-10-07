# FluFigSim_original

### What it is used for:
This software can be used to simulate paragliding aerobatic figures. It was my final assignment at the higher specialist school 2004. I put it public as a showcase of my private work. 

### Functions:
- In the curve editor the figures can be composed by "drawing" the different rotation speeds along the 3 axis pitch, roll and yaw.
- Due to the low gravity point on a paraglider, the axis can actually shift around. Therefore the positions of the axis can be adjusted over time as well.
- In a second screen the figure can be simulated with a very basic 3D model. 
- The diagrams can be saved to a file.

[![Watch the video](https://img.youtube.com/vi/UBjrl6A0exw/maxresdefault.jpg)](https://www.youtube.com/embed/UBjrl6A0exw)

### How it's done: 
It is written in good old Borland C++ Builder 5.0. and uses OpenGL to render the graphics.

### The following third party parts are used: 
- OpenGLPanel.cpp Version 0.5BCB5 ALPHA written by Daniel Plakosh
- NatCubeSpline algorithm written: M.B. Joshi, November 1998

### How to test the executable:
- In order to run it, the Borland library VCL50.BPL needs to be in the same folder as the executable. Back then I only had a student license.
- Meanwhile there is a Borland C++ Builder Community Edition. The recent version 11 contains a VCL280.BPL. I couldn't find out what the current license status is for the older version VLC50.BPL. Therefore I put it in a separate zip file. On your own responsiblility you can copy it next to the exe file. I assume for non commercial use this should be OK.

### How to open the Borland Builder project:
Borland C++ Builder 5.0 isn't sold any more. It can be downloaded here: https://winworldpc.com/product/borland-c-builder/5x, but I don't know whether it would need a license to run or what the legal status of that copy is. \
I didn't test to open it with the new Community Edition.
