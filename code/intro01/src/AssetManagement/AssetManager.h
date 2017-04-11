///
/// AssetManager.h - General Asset Manager System.
/// Manage general assets in the system - allows for generation, querying, tracking and reporting
/// 
#pragma once

#include "EASTL\vector.h"
#include "EASTL\string.h"

class IResource;

class AssetManager
{
    friend class IResource;
public:
    AssetManager();
    ~AssetManager();

    void Initialize();

    bool AddPath(const char* pathname);
    bool LoadMesh(const char* filename);

private:
    eastl::string                   mBasePath;
    eastl::vector<eastl::string>    mPaths;
};
