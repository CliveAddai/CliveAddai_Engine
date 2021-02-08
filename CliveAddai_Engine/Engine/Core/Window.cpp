#include "Window.h"

//ensures that window is automatically set to NULL.
Window::Window() : window(nullptr), context(nullptr) 
{
	window = nullptr;
}

Window::~Window() 
{
	OnDestroy();
}

bool Window::OnCreate(std::string name_, int width_, int height_) 
{
	//SDL is initialized, print to console failed to initialize
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		std::cout << "Failed to initialize SDL" << std::endl;
		return false;
	}
	//Sets width and height when SDL is initialized
	this->width = width_;
	this->height = height_;

	SetPreAttributes();

	//When window is launched it launches at center of screen and width and height are place.
	window = SDL_CreateWindow(name_.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL);

	//If window is not created "Failed to create window appears on Console.
	if (!window) 
	{
		std::cout << "Failed to create window" << std::endl;
		return false;
	}

	//context created so OpenGL can be used in engine.
	context = SDL_GL_CreateContext(window);
	SetPostAttributes();

	//Glew is initialized, if value isn't GLEW_OK "Failed to initizalize GLEW appears on console
	GLenum err = glewInit();
	if (err != GLEW_OK) 
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	//Enables Depth Test ensuring that the z value is looked at.
	glEnable(GL_DEPTH_TEST);

	//Tells us which version of OpenGL is being used.
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	return true;
}


//Deletes OpenGL context, then destroys window before setting the window to NULL
void Window::OnDestroy() 
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}

int Window::GetWidth() const 
{
	return width;
}

int Window::GetHeight() const 
{
	return height;
}

SDL_Window* Window::GetWindow() const 
{
	return window;
}

void Window::SetPreAttributes() 
{
	//Sets Profile Mask as Core Profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	//Sets OpenGL major and minor version (OpenGL 4.5)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
}

void Window::SetPostAttributes() 
{
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
}
