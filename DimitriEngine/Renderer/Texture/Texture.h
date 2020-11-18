#pragma once
#include "../backend.h"

namespace DimitriEngine {
    struct Texture {
        Texture();

        unsigned int texture;
        std::string path;
    };
}