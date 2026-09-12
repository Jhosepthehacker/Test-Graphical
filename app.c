#include <stdio.h> // Importamos la librería (o header) "stdio.h" para manejar el I/O (Input y Output) del programa.
#include <stdbool.h> // Importamos la librería (o header) "stdbool.h" para tener a nuestra disposición el tipo de dato booleans (o bool) que usaremos más adelante para manejar el estado del event loop del juego.
#include <SDL2/SDL.h> // Importamos la librería (o header) "SDL2/SDL.h" para manejar el I/O (Input y Output) de multimedia y comunicarse con el OS usar el hardware indirectamente.
#include <GLES3/gl3.h> // Importamos la librería (o header) "GLES3/gl3.h" (u OpenGL ES 3.0) que ofrece una API gráfica para enviar datos a la GPU mediante SDL2 y usar la GPU para dibujar y renderizar en la pantalla.

int main() {
	const int WIDTH_WINDOW = 632;
	const int HEIGHT_WINDOW = 626;
	
	if (SDL_Init(SDL_INIT_VIDEO)) {
	  printf("No se pudo inicializar SDL. Error: %s\n", SDL_GetError());
	 
	  return 1;
  }
  
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);

SDL_Window* window = SDL_CreateWindow("My Game",
  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
  WIDTH_WINDOW, HEIGHT_WINDOW,
  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  
  if (window == NULL) {
    printf("La ventana falló. Error: %s\n", SDL_GetError());
    SDL_Quit();
  	
    return 1;
  }
  
  SDL_GLContext context = SDL_GL_CreateContext(window);
  
  if (context == NULL) {
    printf("No se pudo crear el contexto OpenGL. Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    
    return 1;
  }
  
  bool running = true;
  SDL_Event event;
  
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
    glClearColor(0.1f, 0.2f, 0.2f, 0.8f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    SDL_GL_SwapWindow(window);
  }
  
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();

	return 0;
}
