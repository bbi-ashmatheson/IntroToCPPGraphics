///
/// MeshResourceLoader.h - Declaration of the system for loading and interfacing with Mesh data
///
#pragma once

struct aiMesh;

class MeshResourceLoader
{
public:
    MeshResourceLoader();
    ~MeshResourceLoader();

    bool Load(aiMesh* mesh);

private:

};
