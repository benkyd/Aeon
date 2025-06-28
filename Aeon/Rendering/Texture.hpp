#ifndef AEON_RENDERING_TEXTURE_H_
#define AEON_RENDERING_TEXTURE_H_

#include <Aeon/Includes.hpp>
#include <Aeon/Handle.hpp>

enum class TextureType {
    Albedo,
    Normal,
    Metallic,
    Roughness,
    AO,
    Emissive,
    Custom
};

struct TextureDesc
{

};

struct Texture
{
    Handle handle;
};

#endif

