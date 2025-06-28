#ifndef AEON_ENTITY_CORECOMPONENTS_TRANSFORM_H_
#define AEON_ENTITY_CORECOMPONENTS_TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace EC
{

struct Transform
{
    Transform(glm::vec3 position) : Position(position)
    {
    }

    glm::vec3 Position;
    glm::quat Rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    float Scale = 1.0f;

    glm::mat4 Model;
};

} // namespace EC

#endif
