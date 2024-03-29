#include "Model.h"

void DimitriEngine::Model::Draw(Transform transform, std::vector<Light> lights, Camera* cam, Projection* projection)
{
    for (unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].Draw(transform, cam, lights, projection);
}

void DimitriEngine::Model::DrawMultiple(Transform transform, Camera* cam, std::vector<Light> lights, Projection* proj, vector<glm::vec3> pos) {
    for (unsigned int i = 0; i < meshes.size(); i++)
        for (glm::vec3 p : pos) {
            transform.position = p;
            meshes[i].DrawMultiple(transform, cam, lights, proj, pos);
        }
}

void DimitriEngine::Model::Exit()
{
    for (Mesh mesh : meshes) {
        mesh.Exit();
    }
}

void DimitriEngine::Model::loadModel()
{
    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void DimitriEngine::Model::processNode(aiNode* node, const aiScene* scene)
{
    // process all the node's meshes (if any)
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

DimitriEngine::Mesh DimitriEngine::Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        // process vertex positions, normals and texture coordinates
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.Normal = vector;

        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
        }
        else
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);


        vertices.push_back(vertex);
    }
    // process indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }
    // process material
    if (mesh->mMaterialIndex >= 0)
    {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        vector<Texture> diffuseMaps = loadMaterialTextures(material,
            aiTextureType_DIFFUSE, "material.texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        vector<Texture> specularMaps = loadMaterialTextures(material,
            aiTextureType_SPECULAR, "material.texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }
    Material mat = Material(textures, glm::vec3(1.0f, 1.0f, 1.0f));
    
    // Use the user defined material if it overrides any of the textures
    if (material.textures.size() > 0) {
        
        mat = material;
    }
    // Use the user defined color if it overrides the base color
    if (material.color != glm::vec3(0)) {
        mat.color = material.color;
    }

    mat.smoothness = material.smoothness;
    mat.metallic = material.metallic;
    Mesh _mesh = Mesh(vertices, indices, mat);
    return _mesh;
}

vector<DimitriEngine::Texture> DimitriEngine::Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
{
    vector<Texture> textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for (unsigned int j = 0; j < textures_loaded.size(); j++)
        {
            if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(textures_loaded[j]);
                skip = true;
                break;
            }
        }
        if (!skip)
        {   // if texture hasn't been loaded already, load it
            Texture texture;
            texture.name = typeName;
            texture.path = str.C_Str();
            texture.LoadImageFromFile(std::string("./models/backpack/").append(texture.path));
            //texture.LoadImageFromFile(std::string("").append(texture.path));
            textures.push_back(texture);
            textures_loaded.push_back(texture); // add to loaded textures
        }
    }
    return textures;
}
