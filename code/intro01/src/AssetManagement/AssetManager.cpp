///
/// AssetManager.cpp - source code for the AssetManager System
/// Wherein we track, create and release various assets necessary for the application.
///

#include "stdafx.h"
#include "AssetManager.h"
#include "IResourceLoader.h"
#include "utils\assert.h"
#include "utils\utils.h"

#include "assimp\cimport.h"
#include "assimp\scene.h"

#include "MeshResourceLoader.h"
#include "Graphics\Model.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
    for (auto model : mModels)
    {
        delete model;
    }
}

void AssetManager::Initialize()
{
    mBasePath = Pwd();
}

bool AssetManager::AddPath(const char* pathname)
{
    ASSERT(pathname != nullptr);

    bool result = false;
    // check to see if path exists before adding?
    if (Exists(pathname))
    {
        mPaths.push_back(eastl::string(pathname));
        result = (mPaths.size() > 0);
    }

    return result;
}

bool AssetManager::LoadMesh(const char* filename)
{
    ASSERT(filename != nullptr);

    bool result = false;
    char filepath[1024];

    result = GetPathToResource(filename, filepath, 1024);

    // Build the asset, since the file exists
    if (result)
    {
        const aiScene* scene = aiImportFile(filepath, 0);
        
        // Construct away!
        if ((scene != nullptr)
            && scene->HasMeshes()
            && scene->HasMaterials())
        {            
            MeshResourceLoader meshLoader;
            Model* model = meshLoader.Load(scene);
            mModels.push_back(model);
        }
        else
        {
            // Some quick asserts to make sure we have data to work with
            ASSERT(scene != nullptr);
            ASSERT(scene->HasMeshes());
            ASSERT(scene->HasMaterials());
        }
        aiReleaseImport(scene);
    }
    return result;
}

bool AssetManager::GetPathToResource(const char* resource, char* dest, unsigned int size)
{
    ASSERT(resource != nullptr);
    ASSERT(dest != nullptr);

    bool result = false;
    eastl::string normalized;
    for (auto path : mPaths)
    {
        eastl::string filePath;
        filePath.append_sprintf("%s\\%s\\%s", mBasePath.c_str(), path.c_str(), resource);
        if (Exists(filePath.c_str()))
        {
            normalized = filePath;
            strcpy(dest, filePath.c_str());
            result = true;
            break;
        }
    }

    return result;
}