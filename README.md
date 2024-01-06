COMP 3016 CW2

# OpenGL
This project uses OpenGL to make a 3D enviroment and spawn in custom 3D models

# What happens in the program

The program works by: 

First loading in every library/external file that needs to be used. 

Then it sets any variables needed, like integers for the window’s height and width. 

Then it set up the camera and the camera's starting location (makes sure it orientated the correct way.) 

Set time and last frame so they can be used later in the code. 

Inside main: 

Starts up GLM and the GLM window (checks if it worked and displays error message if it failed.) 

Set input for GLM windows (so it can use the mouse and keyboard inputs from the user.) 

Loads shaders 

Loads all modules used in program by going to their set folder path 

Sets a view port for items to be shown rendered in (I set it the same as the main window size.) 

Sets frame buffer and mouse call back. 

Model matrix is set (this is the position that will be used to draw in the modules.) 

Render loop begins: 

Time is used to check/set distance between the current and last frame (this prevents issues with rendering like constant rendering or frame related tick problems.) 

Begins rendering world, sets world color first (I chose a natural teal.) 

Culling and depth test are enabled (this stops modules being able to render in front of something that is in front of them.) 

Transformations are set. 

Draws the grass module. 

Sets new transformation location. 

Draws new module. 

Reverts to old transformation location (done to stop values becoming too high and flaying away from the player every new frame) 

Repeats for all remaining models (17, 18, 19.) 

Refreshes. 

Terminates window. 
