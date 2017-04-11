#include <EABase/eabase.h>
#include <EASTL/internal/config.h>
#include <new>
#include <stdio.h>

namespace Internal
{
  void* EASTLAlignedAlloc(size_t size, size_t alignment)
  {
    return _aligned_malloc(size, alignment);
  }

  void EASTLAlignedFree(void* p)
  {
    _aligned_free(p);
  }
}

void* operator new(size_t size)
  { return Internal::EASTLAlignedAlloc(size, 16); }

void* operator new[](size_t size)
  { return Internal::EASTLAlignedAlloc(size, 16); }

void* operator new[](size_t size, const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
  { return Internal::EASTLAlignedAlloc(size, 16); }

void* operator new[](size_t size, size_t alignment, size_t /*alignmentOffset*/, const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
  { return Internal::EASTLAlignedAlloc(size, alignment); }

void* operator new(size_t size, size_t alignment)
  { return Internal::EASTLAlignedAlloc(size, alignment); }

void* operator new(size_t size, size_t alignment, const std::nothrow_t&) EA_THROW_SPEC_NEW_NONE()
  { return Internal::EASTLAlignedAlloc(size, alignment); }

void* operator new[](size_t size, size_t alignment)
  { return Internal::EASTLAlignedAlloc(size, alignment); }

void* operator new[](size_t size, size_t alignment, const std::nothrow_t&)EA_THROW_SPEC_NEW_NONE()
  { return Internal::EASTLAlignedAlloc(size, alignment); }

// C++14 deleter
void operator delete(void* p, std::size_t sz ) EA_THROW_SPEC_DELETE_NONE()
{ Internal::EASTLAlignedFree(p); EA_UNUSED(sz); }

void operator delete[](void* p, std::size_t sz ) EA_THROW_SPEC_DELETE_NONE()
{ Internal::EASTLAlignedFree(p); EA_UNUSED(sz); }

void operator delete(void* p) EA_THROW_SPEC_DELETE_NONE()
  { Internal::EASTLAlignedFree(p); }

void operator delete[](void* p) EA_THROW_SPEC_DELETE_NONE()
  { Internal::EASTLAlignedFree(p); }

void EASTLTest_SetGeneralAllocator() { /* intentionally blank */ }
bool EASTLTest_ValidateHeap() { return true; }
