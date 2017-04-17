///
/// MeshResourceLoader.h - Declaration of the system for loading and interfacing with Mesh data
///
#pragma once

struct aiScene;
class Model;

class MeshResourceLoader
{
public:
    MeshResourceLoader();
    ~MeshResourceLoader();

    Model* Load(const aiScene* scene);

private:

};
