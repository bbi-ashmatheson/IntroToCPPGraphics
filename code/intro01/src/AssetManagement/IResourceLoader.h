///
/// IResource.h - Interface all Resources must derive from
///

#pragma once

class IResourceLoader
{
public:
    IResourceLoader();
    virtual ~IResourceLoader() = 0;

    virtual void LoadFromFile(const char* filename) = 0;
};

IResourceLoader::IResourceLoader() {}
IResourceLoader::~IResourceLoader() {}
