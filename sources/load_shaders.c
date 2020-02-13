#include "../includes/ft_scop.h"

// GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){
void load_shaders()
{

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	// GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
    int         fd;
    struct stat st;
    char        *vertex_shader_source;
    char        *fragment_shader_source;
    int         ret;

    if ((fd = open("./shaders/vertex_shader.glsl", O_RDONLY)) == -1)
        error_callback("cannot open vertex shader.");
    stat("./shaders/vertex_shader.glsl" , &st);
    vertex_shader_source = ft_strnew(st.st_size);
    if ((ret = read(fd, vertex_shader_source, st.st_size)) == -1)
        error_callback("cannot read vertex shader.");
    close(fd);

    if ((fd = open("./shaders/fragment_shader.glsl", O_RDONLY)) == -1)
        error_callback("cannot open fragment shader.");
    stat("./shaders/fragment_shader.glsl" , &st);
    fragment_shader_source = ft_strnew(st.st_size);
    if ((ret = read(fd, fragment_shader_source, st.st_size)) == -1)
        error_callback("cannot read fragment shader.");
    close(fd);

    printf("vertex: %s\n", vertex_shader_source);
    printf("fragment: %s\n", fragment_shader_source);

	// GLint Result = GL_FALSE;
	// int InfoLogLength;


	// Compile Vertex Shader
	// char const *VertexSourcePointer = vertex_shader_source;
	// glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	// glCompileShader(VertexShaderID);

	// Check Vertex Shader
	// glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	// glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	// if (InfoLogLength > 0)
	// 	error_callback("cannot compile vertex shader.");

	// // Compile Fragment Shader
	// printf("Compiling shader : %s\n", fragment_file_path);
	// char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	// glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	// glCompileShader(FragmentShaderID);

	// // Check Fragment Shader
	// glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	// glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	// if ( InfoLogLength > 0 ){
	// 	std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
	// 	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	// 	printf("%s\n", &FragmentShaderErrorMessage[0]);
	// }



	// // Link the program
	// printf("Linking program\n");
	// GLuint ProgramID = glCreateProgram();
	// glAttachShader(ProgramID, VertexShaderID);
	// glAttachShader(ProgramID, FragmentShaderID);
	// glLinkProgram(ProgramID);

	// // Check the program
	// glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	// glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	// if ( InfoLogLength > 0 ){
	// 	std::vector<char> ProgramErrorMessage(InfoLogLength+1);
	// 	glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	// 	printf("%s\n", &ProgramErrorMessage[0]);
	// }

	
	// glDetachShader(ProgramID, VertexShaderID);
	// glDetachShader(ProgramID, FragmentShaderID);
	
	// glDeleteShader(VertexShaderID);
	// glDeleteShader(FragmentShaderID);

	// return ProgramID;
}
