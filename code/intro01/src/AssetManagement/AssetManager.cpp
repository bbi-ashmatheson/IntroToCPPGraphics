///
/// AssetManager.cpp - source code for the AssetManager System
/// Wherein we track, create and release various assets necessary for the application.
/// 

#include "stdafx.h"
#include "AssetManager.h"
#include "IResourceLoader.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}


bool AssetManager::AddPath(const char* pathname)
{
    // check to see if path exists before adding?
    mPaths.push_back(eastl::string(pathname));
    return mPaths.size() > 0;
}

bool AssetManager::LoadMesh(const char* filename)
{
    // does the file exist on-disk?

    return false;
}