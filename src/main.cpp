#include <vox2D/vox2D.h>

struct Camera
{
	glm::vec3 Pos = glm::vec3(0.f, 0.f, 5.f);
	glm::vec3 Front = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 Up = glm::vec3(0.f, 1.f, 0.f);
	float pitch = 0.f;
	float yam = 0.f;
};

struct MVP
{
	glm::mat4 model = glm::mat4(1.f);
	glm::mat4 view  = glm::mat4(1.f);
	glm::mat4 proj  = glm::mat4(1.f);
};

Camera camera;
MVP mvp;
int main()
{
	srand48(time(0));
	vxInit(800, 600, "Hell9");
	Vertex vertex[4];
	vertex[0] = setVertex(glm::vec3( 0.5f, 0.5f, 0.f ), glm::vec2( 1.f, 1.f ), glm::vec4(glm::vec3(drand48(),drand48(),drand48()), 1.f));
	vertex[1] = setVertex(glm::vec3( 0.5f,-0.5f, 0.f ), glm::vec2( 1.f, 0.f ), glm::vec4(glm::vec3(drand48(),drand48(),drand48()), 1.f));
	vertex[2] = setVertex(glm::vec3(-0.5f,-0.5f, 0.f ), glm::vec2( 0.f, 0.f ), glm::vec4(glm::vec3(drand48(),drand48(),drand48()), 1.f));
	vertex[3] = setVertex(glm::vec3(-0.5f, 0.5f, 0.f ), glm::vec2( 0.f, 1.f ), glm::vec4(glm::vec3(drand48(),drand48(),drand48()), 1.f));

	unsigned int index[] = 
	{
		0,1,2,
		2,3,0
	};

	uint32_t vbo = CreateVBO(sizeof(vertex), vertex);
	Attrib(0, 3, sizeof(Vertex), offsetof(Vertex, Pos), vbo);
	Attrib(1, 2, sizeof(Vertex), offsetof(Vertex, Tex), vbo);
	Attrib(2, 4, sizeof(Vertex), offsetof(Vertex, Col), vbo);
	uint32_t ebo = CreateEBO(sizeof(index), index);
	uint32_t shaderProgram = CreateShader("res/shader/main.vert", "res/shader/main.frag");
	

	LoadTexture(0, GL_RGB, "res/texture/t.png");

	int numFPS = 0;
	auto start = std::chrono::high_resolution_clock::now();
	while(!vxShouldClose())
	{
		vxPollEvent();
		camera.yam += 0.5f;
		logl(camera.yam);
		int width, height;
		vxGetWindowWidth(width, height);
		glViewport(0, 0, width, height);
		camera.Front.x = glm::cos(glm::radians(camera.yam)) * glm::cos(glm::radians(camera.pitch));
		camera.Front.y = glm::sin(glm::radians(camera.pitch));
		camera.Front.z = glm::sin(glm::radians(camera.yam)) * glm::cos(glm::radians(camera.pitch));
		

		mvp.model = glm::translate(mvp.model, glm::vec3(0.f));
		mvp.view = glm::lookAt(camera.Pos, camera.Front + camera.Pos, camera.Up);
		mvp.proj = glm::perspective(glm::radians(90.f), float(width) / float(height), 0.01f, 100.f);

		ShaderSetMatrix(shaderProgram, "model", mvp.model);
		ShaderSetMatrix(shaderProgram, "view",  mvp.view);
		ShaderSetMatrix(shaderProgram, "proj",  mvp.proj);

		vxClearBackground(0.12, 0.16, 0.26, 1);
		Draw(vbo, ebo, shaderProgram, sizeof(index) / sizeof(int));
		vxSwapBuffer();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> dur = end - start;
		if(dur.count() >= 1.f)
		{
			start = std::chrono::high_resolution_clock::now();
			vxSetWindowTitle(std::to_string(numFPS).c_str());
		}
		numFPS++;
	}
	vxTerminate();
    return 0;
}

