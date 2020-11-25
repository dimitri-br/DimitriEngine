#include "Mesh.h"

DimitriEngine::Mesh::Mesh()
{
}

DimitriEngine::Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, Material material)
{
    this->vertices = vertices;
    this->indices = indices;
    this->material = material;

    setupMesh();
}

void DimitriEngine::Mesh::DrawMultiple(Transform transform, Camera* cam, std::vector<Light> lights, Projection* proj, vector<glm::vec3> pos) {
    for (glm::vec3 p : pos) {
        transform.position = p;
        Draw(transform, cam, lights, proj);
    }
}

void DimitriEngine::Mesh::Draw(Transform transform, Camera* cam, std::vector<Light> lights, Projection* proj)
{
    material.shader.UseShader();
    int i = 0;
    for (Texture tex : material.textures) {
        glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
        tex.BindTexture(material.shader, i);
        i++;
    }
    i = 0;
    for (Light light : lights) {
        if (light.constant == 1.0f) {
            light.DrawPoint(material.shader, i);
            i++;
        }
        else {
            light.DrawDirectional(material.shader);
        }
    }
    // bind non-texture material properties
    material.shader.BindVec3("material.color", material.color);
    material.shader.BindFloat("material.smoothness", material.smoothness);
    material.shader.BindFloat("material.metallic", material.metallic);
    // bind projection matrix stuff
    material.shader.BindMat4("model", proj->model);
    material.shader.BindMat4("view", proj->view);
    material.shader.BindMat4("projection", proj->projection);

    // bind the object's transform and camera pos for specular
    material.shader.BindMat4("transform", transform.GetTransform());
    material.shader.BindVec3("viewPos", cam->CamPosition);
    material.shader.BindBool("useColor", false);


    // draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);
}

void DimitriEngine::Mesh::Exit()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    material.shader.Exit();
}

void DimitriEngine::Mesh::setupMesh()
{
    // Generate buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // bind buffers
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Add data to buffer
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    // Add index data to buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    // reset the binded vertex array
    glBindVertexArray(0);

    std::cout << "Mesh Stats:\nVerticies: " << vertices.size() << "\nIndicies: " << indices.size() << "\nTextures: " << material.textures.size() << std::endl;
}
