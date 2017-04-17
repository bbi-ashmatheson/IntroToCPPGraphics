///
/// AssetManager.h - General Asset Manager System.
/// Manage general assets in the system - allows for generation, querying, tracking and reporting
/// 
#pragma once

#include "EASTL\vector.h"
#include "EASTL\string.h"

class IResourceLoader;
class Model;

class AssetManager
{
    friend class IResourceLoader;
public:
    AssetManager();
    ~AssetManager();

    void Initialize();

    bool AddPath(const char* pathname);


    bool LoadMesh(const char* filename);

private:
    bool GetPathToResource(const char* resource, char* dest, unsigned int size);

private:
    eastl::string                   mBasePath;
    eastl::vector<eastl::string>    mPaths;

    eastl::vector<Model*>            mModels;
};
