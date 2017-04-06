///
/// IResource.h - Interface all Resources must derive from
///

#pragma once

class IResource
{
public:
    IResource();
    virtual ~IResource() = 0;

    virtual void LoadFromFile(const char* filename) = 0;

    unsigned int GetID() { return mResourceID; }

private:
   void SetID(unsigned int id) { mResourceID = id; }

protected:
    unsigned int mResourceID;
};

IResource::IResource()
{
}
