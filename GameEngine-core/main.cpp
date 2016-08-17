#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 960, 450);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 a(1.0f, 2.0f);
	vec2 b(1, 2);

	while (!window.closed())
	{
		window.clear();

		std::cout << (a == b) << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f,  -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	return 0;
}