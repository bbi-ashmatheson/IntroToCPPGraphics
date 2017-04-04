#pragma once

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();

    bool Initialize(ID3D11Device* device, void* buffer, unsigned int bufferSize);

private:
    ID3D11Device*   mD3DDevice;
    ID3D11Buffer*   mVertexBuffer;
};

