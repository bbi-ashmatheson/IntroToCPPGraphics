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
    return false;
}

bool AssetManager::LoadMesh(const char* filename)
{
    return false;
}