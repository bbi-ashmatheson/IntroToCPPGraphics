# Introduction to Graphics in C++

## Summary

This is a set of tutorials on Graphics programming. The initial main focus will be on DirectX (11, maybe 12).
Subsequent tutorials will focus on Vulkan with a possible smattering of OpenGL.

I'm doing this as more of an experiment, getting my Graphics coding up to a passible level once again,
getting familiar with more 'modern' approaches to graphics programming as well as investigating other aspects
of the genre (including GUI frameworks).

## Technology used

I'm a windows guy, so everything will be focused around the windows platform. That said, I'm not using a native
Visual Studio solution. I'm using a new build system called 'Genie'.
[link to main page](https://github.com/bkaradzic/GENie)
[link to docs](https://github.com/bkaradzic/genie/blob/master/docs/scripting-reference.md#scripting-reference)

## Building Instructions

It's pretty straight forward. I'll add a batch script at some point in time, but it would do nothing more than:

```
cd code
bin\genie.exe vs2015
```

You aren't limited to Visual Studio 2015, you can also use 2017 like so:
```
cd code
bin\genie.exe vs2017
```

Why a build system? I use Visual Studio 2015 at work and 2017 Community at home. That's the simplest answer.
