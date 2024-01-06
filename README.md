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

# Models used

### Stairs - 
Basic stairs with a dark wood texture.
![StairsObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/778b1d30-e7cc-4475-87b1-afcfac2b2341)

### Art -
Basic text for my sginiture and to verify the work is mine.
![ArtObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/cfb78dbe-16df-409d-88ba-59436da82686)

### Decor - 
Set of table and chair usign the wood and dark wood texture respectfuly,
![DecorObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/6cc1b6a6-7eaf-4538-9bd1-0ac741327799)

### Grass - 
Large plane of grass using close up of grass blades as the texture.
![GrassObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/ec2df481-e983-473f-aefe-abe86b584570)

### Guy - 
Low poly model with text used for user interaction and refernse to CW1.
![GuyObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/5923d9fb-9b4f-4a9c-91da-04232241a813)

### BrickHouse - 
Simple cube object with hallowed inside and gaps to work as the indoors, window and front door.
![BrickHouseObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/7587dd52-ac43-45e1-97ec-a70fda2dd947)



### Text - 
Basic module of text on how to spawn the guy.
![TextObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/54c44dc8-3ebd-4244-8826-61ea22caa8cc)




# Video Link:
https://youtu.be/9I2GSpfaopE
