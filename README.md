COMP 3016 CW2

# OpenGL
This project uses OpenGL to make a 3D enviroment and spawn in custom 3D models

github: https://github.com/BenIsTrying/Comp3016CW270-.git

​ 


# How does the user interact with your executable?  

The user can move around and view the modules loaded into the environment, most of the user's integration is by using their ‘W’ ‘A’ ‘S’ ‘D’ ‘J’ and their mouse movements to fly around the populated area, due to most of the interaction being simply viewing the 3D modules I decided the user should be able to spawn in a new module this one being a reference to the CW1 assignment I did previously for COMP3016. 

Inside the house the user can find the text “press ‘J’ and turn around, If the user does this then they will be able to spawn in a module related to CW1(shown below).  
![TextObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/54c44dc8-3ebd-4244-8826-61ea22caa8cc)
![GuyObj](https://github.com/BenIsTrying/Comp3016CW270-/assets/91667148/5923d9fb-9b4f-4a9c-91da-04232241a813)
This image is the module the user can spawn in, it is a low bit styled 3D module to give a visual indicator to its console game origins, it also comes with text describing what it is, as another detail I have given him a ’C’ which is what the player used in CW1 as cables to connect the circuit together. 

# How do you open and control the software you wrote (exe file)?  

 

You can control the software by using the ‘W’ ‘A’ ‘S’ ‘D’ ‘J’ and mouse movements to travel along the 3D environment to view each module loaded in, modules such as: 

Brick building 

Grass ground 

Wooden table 

Dark-Wooden chair 

Dark-Wooden stairs 

Signature of my name and this module 

Spawn-able low bit 3D man (Press ‘J’ to spawn him inside the house) 

Floating text with instructions 

# How does the program code work?  

 
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

 

 

# How do the classes and functions fit together and who does what?   

 

Classes such as: 

Shaders (helps with rendering the 3D modules.) 

Camera (takes mouse movement and translates them into camera movements in a 3D environment.) 

User input (takes all ‘W’ ‘A’ ‘S’ ‘D’ ‘J’ key presses and translates them into movements or interaction within the environment.) 

Frame buffer Size call back (sets the view port to size needed.) 

 

# What makes your program special and how does it compare to similar things? (Where did you get the idea from?  

The idea spawned from a simple want to put the user into a digital version of a real-world environment (however much simpler) this is a common thing within the games industry so i wish to demonstrate similar skills/ideas. The program is a simple display of 3D modules within a given space. To add more user interaction, I have also given the ability to spawn in a character and text that relates to CW1 when they press the ‘j’ key. 

In comparison to similar programs, it seems compliable to some but not all, as there are no errors or seeable issues it is basic with simple 3D modules and texture created then imported from blender (created by me, texture sourced from public domain images.) 

 

# What did you start with? How did you make yours unique? Did you start with a given project? 

  

 

I started with Lab 9 in which we learned how to import 3D objects into OpenGL and display them, I then built off this lab by improving some code by removing the rendering issue where the objects can render through another even when blocked from the camera’s view (shown below in image of lab 9’s tree). Next, I created my own models and added their corresponding textures, after they were loaded in, I set locations for them to be rendered in in relation to one another. After everything was in place, I added more user interaction with the ‘J’ key and texts explaining how they can spawn in a new module and make him disappear by pressing it.  

I then added more modules including a text module which has my name and CW2.  


## Motes from development 


Custom models from blender ported without proper rendering of textures. 

 

Model now uses texture from tree example in lab 9. 

 

Loaded  tree model to determine issues with rendering, the object is being able to render through its self 

 

Final models loaded and placed correctly into the world. 

The issue I was facing earlier with the texture being able to display over something in front of it is that i was missing  which allows the view to understand to only display stuff within the eyeline of the player’s camera. 

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
