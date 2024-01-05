//STD
#include <iostream>

//GLAD
#include <glad/glad.h>

//GLM
#include "glm/ext/vector_float3.hpp"
#include <glm/gtc/type_ptr.hpp> //Access to the value_ptr

//ASSIMP
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//LEARNOPENGL
#include <learnopengl/shader_m.h>
#include <learnopengl/model.h>

//GENERAL
#include "main.h"

#define STB_IMAGE_IMPLEMENTATION
#include "..\..\..\..\..\Public\OpenGL\include\learnopengl\stb_image.h"

using namespace std;
using namespace glm;

//Window
int windowWidth;
int windowHeight;

//VAO vertex attribute positions in correspondence to vertex attribute type
enum VAO_IDs { Triangles, Indices, Colours, Textures, NumVAOs = 2 };
//VAOs
GLuint VAOs[NumVAOs];

//Buffer types
enum Buffer_IDs { ArrayBuffer, NumBuffers = 4 };
//Buffer objects
GLuint Buffers[NumBuffers];

//Transformations
//Relative position within world space
vec3 cameraPosition = vec3(0.0f, 0.0f, 3.0f);
//The direction of travel
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
//Up position within world space
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

//Camera sidways rotation
float cameraYaw = -90.0f;
//Camera vertical rotation
float cameraPitch = 0.0f;
//Determines if first entry of mouse into window
bool mouseFirstEntry = true;
//Positions of camera from given last frame
float cameraLastXPos = 800.0f / 2.0f;
float cameraLastYPos = 600.0f / 2.0f;

//Time
//Time change
float deltaTime = 0.0f;
//Last value of time change
float lastFrame = 0.0f;


int main()
{
    //Initialisation of GLFW
    glfwInit();
    //Initialisation of 'GLFWwindow' object
    windowWidth = 1920;
    windowHeight = 1080;
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Comp3016 CW2 BG", NULL, NULL);

    //Checks if window has been successfully instantiated
    if (window == NULL)
    {
        cout << "GLFW Window did not instantiate\n";
        glfwTerminate();
        return -1;
    }

    //Sets cursor to automatically bind to window & hides cursor pointer
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //Binds OpenGL to window
    glfwMakeContextCurrent(window);

    //Initialisation of GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "GLAD failed to initialise\n";
        return -1;
    }

    //Loading of shaders
    Shader Shaders("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
    //Model Rock("media/rock/Rock07-Base.obj"); 
    Model House("media/house/brickHouse.obj"); 
    Model Stairs("media/stairs/stairs.obj");
    Model Decor("media/decor/table-and-chair.obj");
    Model Grass("media/grass/grass.obj");
    Model Art("media/art/art.obj");
    Shaders.use();

    //Sets the viewport size within the window to match the window size of 1280x720
    glViewport(0, 0, 1920, 1080);



    //Sets the framebuffer_size_callback() function as the callback for the window resizing event
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //Sets the mouse_callback() function as the callback for the mouse movement event
    glfwSetCursorPosCallback(window, mouse_callback);


        //Model matrix
        mat4 model = mat4(2.0f);
        //Scaling to zoom in
        model = scale(model, vec3(0.025f, 0.025f, 0.025f));
        //Looking straight forward
        model = rotate(model, radians(0.0f), vec3(1.0f, 0.0f, 0.0f));
        //Elevation to look upon terrain
        model = translate(model, vec3(0.0f, 0.0f, 0.0f));

        //Projection matrix
        mat4 projection = perspective(radians(45.0f), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);


    //Render loop
    
    while (glfwWindowShouldClose(window) == false)
    {
        //Time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //Input
        ProcessUserInput(window); //Takes user input

        //Rendering
        glClearColor(0.35f, 0.5f, 0.5f, 1.0f); //Colour on window
        glClear(GL_COLOR_BUFFER_BIT); //Clears the colour buffer
        glClear(GL_DEPTH_BUFFER_BIT); //Might need


        //glFrontFace(GL_CW);
        //glCullFace(GL_BACK);
         
        glEnable(GL_DEPTH_TEST);//this was needed to not display object thru one and another
        glEnable(GL_CULL_FACE);
        //glCullFace(GL_FRONT);
        //glFrontFace(GL_CCW);


        //Transformations
        mat4 view = lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp); //Sets the position of the viewer, the movement direction in relation to it & the world up direction
        mat4 mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp); //Setting of uniform with Shader class

        //this is where the model is actual drawn into the enviroment
        //Rock.Draw(Shaders);

        /* this is attmpting to to figure out how to move objects within the enviroment
        glPushMatrix();
        glRotatef(90., 1., 0., 0.);
        gluCylinder(quad, 1, 1, 2, 36, 12);
        glPopMatrix();*/

        Grass.Draw(Shaders);

        /*
        This is a very simple way of setting the location for each of the moddels used within the program.
        the way translate works is by setting a loction insid ethe envirment and then drawign each of the modules (this also includes redrawing)
        this means it will draw every mmodule in the same area makign it over crwoded and messy.
        but I have it so it sets a new location after it draws a model so that they can be spaced apart, I also had to include
        a negitiv version of movign the translate location of else each time it redraws it will appare in a further location from the player
        this led to many times my building model would fly away
        */
        
        model = translate(model, vec3(0.0f, 0.0f, 0.0f));//orginal location
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);


        House.Draw(Shaders);
        model = translate(model, vec3(0.0f, 0.0f, 0.0f));
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);


        model = translate(model, vec3(0.0f, 2.0f, -10.0f));//new cahnged location for spaning models
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);
        Decor.Draw(Shaders);
        model = translate(model, vec3(0.0f, -2.0f, 10.0f));//must go back to origin so mut be oposit of what ever additions were made before
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);


        model = translate(model, vec3(20.0f, 3.0f, 30.0f));// this is the location format of: X - Y - Z cords 
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);
        Stairs.Draw(Shaders);
        model = translate(model, vec3(-20.0f, -3.0f, -30.0f));
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);

        model = translate(model, vec3(0.0f, 5.0f, 50.0f));//this has a high Z cordanate so that it appres outside the house and is more noticable
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);
        Art.Draw(Shaders);
        model = translate(model, vec3(0.0f, -5.0f, -50.0f));//sets back to zero for next loop
        mvp = projection * view * model;
        Shaders.setMat4("mvpIn", mvp);
      

        //Refreshing
        glfwSwapBuffers(window); //Swaps the colour buffer
        glfwPollEvents(); //Queries all GLFW events
    }



    //Safely terminates GLFW
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //Resizes window based on contemporary width & height values
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    //Initially no last positions, so sets last positions to current positions
    if (mouseFirstEntry)
    {
        cameraLastXPos = (float)xpos;
        cameraLastYPos = (float)ypos;
        mouseFirstEntry = false;
    }

    //Sets values for change in position since last frame to current frame
    float xOffset = (float)xpos - cameraLastXPos;
    float yOffset = cameraLastYPos - (float)ypos;

    //Sets last positions to current positions for next frame
    cameraLastXPos = (float)xpos;
    cameraLastYPos = (float)ypos;

    //Moderates the change in position based on sensitivity value
    const float sensitivity = 0.025f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    //Adjusts yaw & pitch values against changes in positions
    cameraYaw += xOffset;
    cameraPitch += yOffset;

    //Prevents turning up & down beyond 90 degrees to look backwards
    if (cameraPitch > 89.0f)
    {
        cameraPitch = 89.0f;
    }
    else if (cameraPitch < -89.0f)
    {
        cameraPitch = -89.0f;
    }

    //Modification of direction vector based on mouse turning
    vec3 direction;
    direction.x = cos(radians(cameraYaw)) * cos(radians(cameraPitch));
    direction.y = sin(radians(cameraPitch));
    direction.z = sin(radians(cameraYaw)) * cos(radians(cameraPitch));
    cameraFront = normalize(direction);
}

void ProcessUserInput(GLFWwindow* WindowIn)
{
    //Closes window on 'exit' key press
    if (glfwGetKey(WindowIn, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(WindowIn, true);
    }

    //Extent to which to move in one instance
    const float movementSpeed = 1.0f * deltaTime;
    //WASD controls
    if (glfwGetKey(WindowIn, GLFW_KEY_W) == GLFW_PRESS)
    {
        cameraPosition += movementSpeed * cameraFront;
    }
    if (glfwGetKey(WindowIn, GLFW_KEY_S) == GLFW_PRESS)
    {
        cameraPosition -= movementSpeed * cameraFront;
    }
    if (glfwGetKey(WindowIn, GLFW_KEY_A) == GLFW_PRESS)
    {
        cameraPosition -= normalize(cross(cameraFront, cameraUp)) * movementSpeed;
    }
    if (glfwGetKey(WindowIn, GLFW_KEY_D) == GLFW_PRESS)
    {
        cameraPosition += normalize(cross(cameraFront, cameraUp)) * movementSpeed;
    }
}