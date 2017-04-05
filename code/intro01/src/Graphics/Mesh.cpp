#include "StdAfx.h"
#include "assimp\Importer.hpp"
#include "Mesh.h"

const aiScene* scene = nullptr;
Assimp::Importer importer;

Mesh::Mesh()
{
    scene = importer.ReadFile("empty", 0);
}

Mesh::~Mesh()
{
}