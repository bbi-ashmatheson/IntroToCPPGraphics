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

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::Initialize()
{
    mBasePath = Pwd();
}

bool AssetManager::AddPath(const char* pathname)
{
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
    bool result = false;

    eastl::string normalized;
    for (auto path : mPaths)
    {
        eastl::string filePath;
        filePath.append_sprintf("%s\\%s\\%s", mBasePath.c_str(), path.c_str(), filename);
        if (Exists(filePath.c_str()))
        {
            normalized = filePath;
            break;
        }
    }

    // Build the asset, since the file exists
    if (normalized.length() != 0)
    {
        const aiScene* scene = aiImportFile(normalized.c_str(), 0);

        // Some quick asserts to make sure we have data to work with
        ASSERT(scene != nullptr);
        ASSERT(scene->HasMeshes());
        ASSERT(scene->HasMaterials());

        // Construct away!
        if ((scene != nullptr)
            && scene->HasMeshes()
            && scene->HasMaterials())
        {

        }

        result = true;
    }

    return result;
}