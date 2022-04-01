#include <Graphics2D/Graphics/Buffer.h>

Buffer::Buffer()
{
    vao = 0;
    vbo = 0;
    ebo = 0;
}

void Buffer::init(float* vertices, unsigned int verticesSize)
{

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesSize, vertices, GL_STATIC_DRAW);
}

void Buffer::init(float* vertices, unsigned int verticesSize, unsigned int* indices, unsigned int indicesSize)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesSize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicesSize, indices, GL_STATIC_DRAW);
}

void Buffer::destroy()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void Buffer::setAttributef(int location, int size, int stride, int offset)
{
    glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(location);
}

void Buffer::use()
{
    glBindVertexArray(vao);
    //glBindBuffer(GL_ARRAY_BUFFER, vbo);
}