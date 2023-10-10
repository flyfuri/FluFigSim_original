# FluFigSim_original

### What it is used for:
This software is used to learn and understand paragliding aerobatic figures by simulating them. It was my final assignment at the higher specialist school in 2004. I put it public as a showcase of my private work. 

### Functions:
- In the diagram editor, the figures can be composed by "drawing" the different rotation speeds along the three axes: pitch, roll, and yaw.
- Due to the low gravity point on a paraglider, the axis can shift around. Therefore, the position of all the tree axes of rotation can be adjusted over time, although the pitch axis is the one with the most fluctuating position.
- In a second screen, the figure is simulated with a very basic 3D model. 
- The diagrams can be saved to a file for later reuse.

[![Watch the video](https://img.youtube.com/vi/UBjrl6A0exw/maxresdefault.jpg)](https://www.youtube.com/embed/UBjrl6A0exw)

It is written in good old Borland C++ Builder 5.0. and uses OpenGL to render the graphics.

### The following third-party parts are used: 
- OpenGLPanel.cpp Version 0.5BCB5 ALPHA written by Daniel Plakosh
- NatCubeSpline algorithm written: M.B. Joshi, November 1998

### How to test the executable:
- To run it, the Borland library VCL50.BPL needs to be in the same folder as the executable. Back then, I only had a student license.
- Meanwhile, there is a Borland C++ Builder Community Edition. The recent version 11 contains a VCL280.BPL. I couldn't find the current license status for the older version VLC50.BPL. Therefore, I put it in a separate zip file. On your responsibility, you can copy it next to the exe file. I assume for noncommercial use, this should be OK.

### How to open the Borland Builder project:
Borland C++ Builder 5.0 isn't sold anymore. It can be downloaded here: https://winworldpc.com/product/borland-c-builder/5x, but I don't know whether it would need a license to run or what the legal status of that copy is. \
I didn't test to open it with the new Community Edition.
