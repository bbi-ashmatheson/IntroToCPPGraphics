#pragma once

class Mesh;
class Material;

class Model
{
public:
    Model();
    ~Model();

    void Initialize(unsigned int meshcount);
    bool AddMesh(Mesh* mesh);

private:
    Mesh** mMeshArray;
    Material* mMaterial;

    unsigned int mMeshCount;
};
